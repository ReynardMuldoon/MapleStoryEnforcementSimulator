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
	cout << "� ������ ��ȭ�� �õ��Ͻðڽ��ϱ�?" << endl;
	cout << "1: ��Ÿ����" << endl;
	cout << "2: ����ɼ�(�̱���)" << endl;
	cout << "3: �߰��ɼ�(�̱���)" << endl;
	cout << "4: ���α׷� ����" << endl;
	
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
		cout << "���� �������� �ʾҽ��ϴ�. �˼��մϴ�. �ٽ� �������ּ���." << endl << endl;
		run();
	}
}

void Simulator::startStarForceSimulation()
{
	// �Է� �ޱ� 
	int equipLevel;
	long long spareCost;
	int startStarForce;
	int goalStarForce;
	int simulationCount;

	cout << "��� ����: "; cin >> equipLevel;
	cout << "�ı� ���� ���(�޼�): "; cin >> spareCost;
	cout << "���� ��Ÿ����(0 �̻� 21 ����): "; cin >> startStarForce;
	cout << "��ǥ ��Ÿ����(1 �̻� 22 ����): "; cin >> goalStarForce;
	cout << "�ùķ��̼� Ƚ��(�⺻ 10��ȸ): "; cin >> simulationCount;

	// starForceSimulator ���� �ʱ�ȭ �� ����
	starForceSimulator = new StarForceSimulator(equipLevel, spareCost, startStarForce, goalStarForce, simulationCount);
	starForceSimulator->run();

	long long averageCost = starForceSimulator->TotalCost() / starForceSimulator->SimulationCount();
	cout << "���(�ùķ��̼� ���): " << averageCost << "�޼�" << endl;

	double averageDestroy = starForceSimulator->TotalDestroy() / double(starForceSimulator->SimulationCount());
	cout << "��� �ı� Ƚ��: " << averageDestroy << "ȸ" << endl;

	run();
}
