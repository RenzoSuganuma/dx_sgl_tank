#pragma once

#include "sgl_stateMachineBehaviour.h"

// 有限オートマトンのトランジション
class SMTransition {
public:
	StateMachineBehaviour* from_;
	StateMachineBehaviour* to_;
	int id_;

	SMTransition(StateMachineBehaviour* from, StateMachineBehaviour* to, int id)
		: from_(from), to_(to), id_(id) {}
};

