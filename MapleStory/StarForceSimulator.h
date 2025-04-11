#pragma once

#include "Equipment.h"
#include <mutex>

class StarForceSimulator
{
private:
	int equipLevel;
	long long spareCost;
	int startStarForce;
	int goalStarForce;
	int simulationCount;

	long long totalCost;
	int totalDestroy;
	std::mutex mtx;

public:
	StarForceSimulator(int _equipLevel, long long _spareCost, int _startStarForce, int _goalStarForce, int _simulationCount);

	long long TotalCost() const { return totalCost; }
	int TotalDestroy() const { return totalDestroy; }
	int SimulationCount() const { return simulationCount; }

	void run();
};