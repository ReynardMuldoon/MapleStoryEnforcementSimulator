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
	// 예외 조건 확인 (이미 최대 스타포스 강화 완료 등)
	if (currentStarForce == maxStarForce)
	{
		std::cout << "이미 최대 스타포스 강화에 도달하였습니다!" << std::endl;
		return false;
	}

	// 난수 생성 
	std::random_device rd;
	std::mt19937 gen(rd()); // Mersenne Twister 엔진

	// 실수 난수: 예를 들어 0.0부터 1.0 사이의 실수
	std::uniform_real_distribution<> realDist(0.0, 1.0);
	double randomDouble = realDist(gen);
	
	// 비용 계산하여 totalCost에 추가
	totalCost += GetCost(level);

	// 확률 참조하여 생성된 난수에 따라 결과로 이동 (성공, 실패, 파괴)
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
	// 스타포스 1 증가
	currentStarForce++;
}

void StarForce::Failed()
{
	// 스타포스 유지 
}

void StarForce::Destroyed()
{
	// 스타포스 12로 하락 
	currentStarForce = 12;
	destroyCount++;
	// totalCost에 spareCost 추가 
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
		std::cout << "현재 미구현된 스타포스 단계에 대한 비용 측정입니다. 죄송합니다." << std::endl;
		return -1;
	}

	// 10의 자리에서 반올림 
	long long realCost = std::round(long long(cost) / 10) * 10;

	return realCost;
}
