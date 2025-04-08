#include "StarForceSimulator.h"

StarForceSimulator::StarForceSimulator(int _equipLevel, long long _spareCost, int _startStarForce, int _goalStarForce, int _simulationCount = 100000)
	: equipLevel(_equipLevel), spareCost(_spareCost), startStarForce(_startStarForce), goalStarForce(_goalStarForce), simulationCount(_simulationCount), totalCost(0), totalDestroy(0)
{

}

void StarForceSimulator::run()
{
	for (int i = 0; i < simulationCount; i++)
	{
		Equipment* equipment = new Equipment(equipLevel, startStarForce, spareCost);
		equipments.push_back(equipment);

		while (equipment->StarForce().CurrentStarForce() < goalStarForce)
		{
			equipment->StarForce().TryEnchant(equipLevel);
		}

		totalCost += equipment->StarForce().TotalCost();
		totalDestroy += equipment->StarForce().DestroyCount();
	}
}

StarForceSimulator::~StarForceSimulator()
{
	for (Equipment* equipment : equipments)
		delete equipment;
}
