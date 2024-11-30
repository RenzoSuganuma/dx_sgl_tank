#include "sgl_StateMachine.h"
#include "sgl_smTransition.h"

// 配列で登録をする
void const StateMachine::ResistBehaviours(std::list<StateMachineBehaviour*> behaviours) {
	behaviours_ = behaviours;
	if (currentBehaviour_ == nullptr) currentBehaviour_ = (*behaviours_.begin());
}
// ビヘイビアを登録する
void const StateMachine::ResistBehaviour(StateMachineBehaviour* behaviours) {
	behaviours_.emplace_back(behaviours);
}
// 遷移を登録する
void const StateMachine::MakeTransition(StateMachineBehaviour* from, StateMachineBehaviour* to, std::string name) {
	if (!transitionsName_Id_.contains(name)) {
		transitionsName_Id_.insert(std::make_pair(name, transitionsName_Id_.size()));
	}

	transitions_.emplace_back(new SMTransition(from, to, transitionsName_Id_[name]));
}
// 指定した遷移名のトランジションを更新してみる
void const StateMachine::UpdateTransition(std::string name, bool& condition, bool equalsTo, bool isTrigger) {
	if (isPausing_ || isYieldToEvent_) { return; }

	for (auto transition : transitions_) {
		if ((condition == equalsTo) && transition->id_ == transitionsName_Id_[name]) {
			if (transition->from_ == currentBehaviour_) {
				currentBehaviour_->End();
				if (isTrigger) { condition = !equalsTo; }
				currentBehaviour_ = transition->to_;
				currentBehaviour_->Begin();
			}
		}
		else {
			currentBehaviour_->Update();
		}
	}
}
// 割り込みイベントを更新
void const StateMachine::UpdateEventsYield() {
	if (isPausing_) return;

	if (isYieldToEvent_) {
		currentYieldedBehaviour_->Update();
		if (!currentYieldedBehaviour_->yieldManually()) {
			isYieldToEvent_ = false;
		}
	}
}
// 現在のビヘイビアを更新
void const StateMachine::JumpTo(StateMachineBehaviour* behaviour) {
	auto it = behaviours_.begin();
	while (it != behaviours_.end()) {
		if (*it == behaviour) {
			currentBehaviour_ = behaviour;
			break;
		}
		it++;
	}
}
// イベントを新しく割り込ませる
void const StateMachine::YieldAllBehaviourTo(StateMachineBehaviour* behaviour) {
	auto it = behaviours_.begin();
	while (it != behaviours_.end()) {
		if (*it == behaviour) {
			isYieldToEvent_ = true;
			currentYieldedBehaviour_ = behaviour;
			currentYieldedBehaviour_->Begin();
			break;
		}
		it++;
	}
}
// 割り込んでたイベントから抜ける
void const StateMachine::EndYieldAllBehaviourFrom(StateMachineBehaviour* behaviour) {
	auto it = behaviours_.begin();
	while (it != behaviours_.end()) {
		if (*it == behaviour) {
			isYieldToEvent_ = false;
			currentYieldedBehaviour_->End();
			break;
		}
		it++;
	}
}
// 有限オートマトンを開始する
void const StateMachine::Start() {
	isPausing_ = false;
	currentBehaviour_->Begin();
}
// 有限オートマトンを停止する
void const StateMachine::Pause() {
	isPausing_ = true;
}