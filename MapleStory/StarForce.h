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

	// ��� ������ ���� Getter �޼���� 
	int CurrentStarForce() const { return currentStarForce; }
	int MaxStarForce() const { return maxStarForce; }
	long long SpareCost() const { return spareCost; }
	long long TotalCost() const { return totalCost; }
	int DestroyCount() const { return destroyCount; }

	bool TryEnchant(int level);		// ��ȭ 1ȸ �õ� 

private:
	void Succeeded();					// ��ȭ ���� ��
	void Failed();						// ��ȭ ���� ��
	void Destroyed();					// ������ �ı� ��

	long long GetCost(int level) const;				// ��Ÿ���� ���
};