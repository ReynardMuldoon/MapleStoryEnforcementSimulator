#pragma once

#include <vector>
#include "Equipment.h"

class StarForceSimulator
{
private:
	std::vector<Equipment*> equipments;
	int equipLevel;
	long long spareCost;
	int startStarForce;
	int goalStarForce;
	int simulationCount;

	long long totalCost;
	int totalDestroy;

public:
	StarForceSimulator(int _equipLevel, long long _spareCost, int _startStarForce, int _goalStarForce, int _simulationCount);

	long long TotalCost() const { return totalCost; }
	int TotalDestroy() const { return totalDestroy; }
	int SimulationCount() const { return simulationCount; }

	void run();

	~StarForceSimulator();
};