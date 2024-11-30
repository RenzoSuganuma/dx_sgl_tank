#pragma once

// 有限オートマトンのビヘイビア
class StateMachineBehaviour {
	bool yieldManually_;

public:
	bool yieldManually() { return yieldManually_; }
	void SetYieldMode(bool condition) { yieldManually_ = condition; }

	virtual void Begin() {}
	virtual void Update() {}
	virtual void End() {}
};

