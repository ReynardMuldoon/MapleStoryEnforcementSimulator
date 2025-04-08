#pragma once
#include "StarForceInfo.h"
#include <tuple>

class StarForce
{
private:
	int currentStarForce;
	int maxStarForce;
	long long spareCost;
	long long totalCost;
	int destroyCount;

public:
	StarForce(int level, int currentStarForce, long long spareCost);

	// 멤버 변수에 대한 Getter 메서드들 
	int CurrentStarForce() const { return currentStarForce; }
	int MaxStarForce() const { return maxStarForce; }
	long long SpareCost() const { return spareCost; }
	long long TotalCost() const { return totalCost; }
	int DestroyCount() const { return destroyCount; }

	bool TryEnchant(int level);		// 강화 1회 시도 

private:
	void Succeeded();					// 강화 성공 시
	void Failed();						// 강화 실패 시
	void Destroyed();					// 아이템 파괴 시

	long long GetCost(int level) const;				// 스타포스 비용
};