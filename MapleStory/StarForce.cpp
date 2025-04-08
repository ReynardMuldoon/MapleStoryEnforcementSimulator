#include "StarForce.h"
#include <iostream>
#include <cmath>
#include <random>

StarForce::StarForce(int level, int _currentStarForce, long long _spareCost)
	: currentStarForce(_currentStarForce), maxStarForce(GetMaxStarForce(level)), spareCost(_spareCost), totalCost(0), destroyCount(0)
{
}

bool StarForce::TryEnchant(int level)
{
	// ���� ���� Ȯ�� (�̹� �ִ� ��Ÿ���� ��ȭ �Ϸ� ��)
	if (currentStarForce == maxStarForce)
	{
		std::cout << "�̹� �ִ� ��Ÿ���� ��ȭ�� �����Ͽ����ϴ�!" << std::endl;
		return false;
	}

	// ���� ���� 
	std::random_device rd;
	std::mt19937 gen(rd()); // Mersenne Twister ����

	// �Ǽ� ����: ���� ��� 0.0���� 1.0 ������ �Ǽ�
	std::uniform_real_distribution<> realDist(0.0, 1.0);
	double randomDouble = realDist(gen);
	
	// ��� ����Ͽ� totalCost�� �߰�
	totalCost += GetCost(level);

	// Ȯ�� �����Ͽ� ������ ������ ���� ����� �̵� (����, ����, �ı�)
	double successProb = SuccessProb[currentStarForce];
	double destroyProb = DestroyProb[currentStarForce];

	if (randomDouble < successProb)
	{
		Succeeded();
	}

	else if (randomDouble < successProb + destroyProb)
	{
		Destroyed();
	}

	else
	{
		Failed();
	}

	return true;
}

void StarForce::Succeeded()
{
	// ��Ÿ���� 1 ����
	currentStarForce++;
}

void StarForce::Failed()
{
	// ��Ÿ���� ���� 
}

void StarForce::Destroyed()
{
	// ��Ÿ���� 12�� �϶� 
	currentStarForce = 12;
	destroyCount++;
	// totalCost�� spareCost �߰� 
	totalCost += spareCost;
}

long long StarForce::GetCost(int level) const
{
	double cost = 1000;
	if (currentStarForce < 10)
	{
		cost += (pow(level, 3) * (currentStarForce + 1) / costFactor[currentStarForce]);
	}

	else if (currentStarForce < 22)
	{
		cost += (pow(level, 3) * pow((currentStarForce + 1), 2.7) / costFactor[currentStarForce]);
	}

	else
	{
		std::cout << "���� �̱����� ��Ÿ���� �ܰ迡 ���� ��� �����Դϴ�. �˼��մϴ�." << std::endl;
		return -1;
	}

	// 10�� �ڸ����� �ݿø� 
	long long realCost = std::round(long long(cost) / 10) * 10;

	return realCost;
}
