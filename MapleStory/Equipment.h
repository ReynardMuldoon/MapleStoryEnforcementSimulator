#pragma once

#include "StarForce.h"

class Equipment
{
private:
	int level;
	StarForce starForce;

public:
	Equipment(int _level, int _currentStarForce, long long _spareCost);

	StarForce& StarForce() { return starForce; }
};