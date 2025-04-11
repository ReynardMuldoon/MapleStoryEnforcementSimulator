#include "StarForceSimulator.h"
#include <thread>
#include <vector>

StarForceSimulator::StarForceSimulator(int _equipLevel, long long _spareCost, int _startStarForce, int _goalStarForce, int _simulationCount = 100000)
	: equipLevel(_equipLevel), spareCost(_spareCost), startStarForce(_startStarForce), goalStarForce(_goalStarForce), simulationCount(_simulationCount), totalCost(0), totalDestroy(0)
{

}

void StarForceSimulator::run()
{
	std::vector<std::thread> threads;
	int threadCount = std::thread::hardware_concurrency(); // 자동 감지
	if (threadCount == 0) threadCount = 4;

	int perThread = simulationCount / threadCount;
	simulationCount = perThread * threadCount;

	for (int i = 0; i < threadCount; i++)
	{
		threads.emplace_back([&, i]() {
			long long localCost = 0;
			int localDestroy = 0;

			for (int j = 0; j < perThread; j++)
			{
				Equipment* equipment = new Equipment(equipLevel, startStarForce, spareCost);

				while (equipment->StarForce().CurrentStarForce() < goalStarForce)
				{
					equipment->StarForce().TryEnchant(equipLevel);
				}

				localCost += equipment->StarForce().TotalCost();
				localDestroy += equipment->StarForce().DestroyCount();
			}

			std::lock_guard<std::mutex> lock(mtx);
			totalCost += localCost;
			totalDestroy += localDestroy;
		});
	}

	for (auto& t : threads) t.join();
}