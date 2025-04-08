#include "Equipment.h"
#include "StarForce.h"

Equipment::Equipment(int _level, int _currentStarForce, long long _spareCost)
	: level(_level), starForce(_level, _currentStarForce, _spareCost)
{
}
