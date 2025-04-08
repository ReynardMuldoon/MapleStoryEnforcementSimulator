#include "Simulator.h"
#include <iostream>

using namespace std;

Simulator::~Simulator()
{
	delete starForceSimulator;
}

void Simulator::run()
{
	cout << endl << endl;
	cout << "어떤 종류의 강화를 시도하시겠습니까?" << endl;
	cout << "1: 스타포스" << endl;
	cout << "2: 잠재옵션(미구현)" << endl;
	cout << "3: 추가옵션(미구현)" << endl;
	cout << "4: 프로그램 종료" << endl;
	
	int choice;
	cin >> choice;

	if (choice == 1)
	{
		startStarForceSimulation();
	}

	else if (choice == 4)
	{
		exit(0);
	}

	else
	{
		cout << "아직 구현되지 않았습니다. 죄송합니다. 다시 선택해주세요." << endl << endl;
		run();
	}
}

void Simulator::startStarForceSimulation()
{
	// 입력 받기 
	int equipLevel;
	long long spareCost;
	int startStarForce;
	int goalStarForce;
	int simulationCount;

	cout << "장비 레벨: "; cin >> equipLevel;
	cout << "파괴 복구 비용(메소): "; cin >> spareCost;
	cout << "시작 스타포스(0 이상 21 이하): "; cin >> startStarForce;
	cout << "목표 스타포스(1 이상 22 이하): "; cin >> goalStarForce;
	cout << "시뮬레이션 횟수(기본 10만회): "; cin >> simulationCount;

	// starForceSimulator 변수 초기화 및 실행
	starForceSimulator = new StarForceSimulator(equipLevel, spareCost, startStarForce, goalStarForce, simulationCount);
	starForceSimulator->run();

	long long averageCost = starForceSimulator->TotalCost() / starForceSimulator->SimulationCount();
	cout << "기댓값(시뮬레이션 평균): " << averageCost << "메소" << endl;

	double averageDestroy = starForceSimulator->TotalDestroy() / double(starForceSimulator->SimulationCount());
	cout << "평균 파괴 횟수: " << averageDestroy << "회" << endl;

	run();
}
