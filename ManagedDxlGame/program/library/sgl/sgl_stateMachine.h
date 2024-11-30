#pragma once

#include "map"
#include "list"
#include "string"
#include "sgl_smTransition.h"
#include "sgl_lang_extention.h"
#include "sgl_stateMachineBehaviour.h"

// 有限オートマトンの機能を提供する ※C++20のバージョン以上
class StateMachine {
	std::map< std::string, int > transitionsName_Id_;
	std::list< StateMachineBehaviour* > behaviours_; /* これは外部からポインタのコピーが渡される。スマートポインタの可能性もあるので解放をしない */
	std::list< SMTransition* > transitions_;
	StateMachineBehaviour* currentBehaviour_ = nullptr; /* これは外部からポインタのコピーが渡される。スマートポインタの可能性もあるので解放をしない */
	StateMachineBehaviour* currentYieldedBehaviour_ = nullptr; /* これは外部からポインタのコピーが渡される。スマートポインタの可能性もあるので解放をしない */
	bool isPausing_;
	bool isYieldToEvent_;

public:
	bool isPaused() { return isPausing_; }
	int behaviourCount() { return behaviours_.size(); }
	StateMachineBehaviour* CurrentBehaviour() { return currentBehaviour_; }
	StateMachineBehaviour* CurrentYieldedEvent() { return currentYieldedBehaviour_; }


	// 配列で登録をする
	void const ResistBehaviours(std::list<StateMachineBehaviour*>  behaviours);
	// ビヘイビアを登録する
	void const ResistBehaviour(StateMachineBehaviour* behaviours);
	// 遷移を登録する
	void const MakeTransition(StateMachineBehaviour* from, StateMachineBehaviour* to, std::string name);
	// 指定した遷移名のトランジションを更新してみる
	void const UpdateTransition(std::string name, bool& condition, bool equalsTo = true, bool isTrigger = false);
	// 割り込みイベントを更新
	void const UpdateEventsYield();
	// 現在のビヘイビアを更新
	void const JumpTo(StateMachineBehaviour* behaviour);
	// イベントを新しく割り込ませる
	void const YieldAllBehaviourTo(StateMachineBehaviour* behaviour);
	// 割り込んでたイベントから抜ける
	void const EndYieldAllBehaviourFrom(StateMachineBehaviour* behaviour);
	// 有限オートマトンを開始する
	void const Start();
	// 有限オートマトンを停止する
	void const Pause();
	// 破棄（解放）処理
	void const Dispose() {
		transitionsName_Id_.clear(); // 解放
		transitions_.clear(); // 解放
		currentBehaviour_ = nullptr;
		currentYieldedBehaviour_ = nullptr;
	}
};

