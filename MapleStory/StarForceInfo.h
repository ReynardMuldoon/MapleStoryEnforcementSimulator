#pragma once 
#include <array>

const std::array<double, 30> SuccessProb = 
{
	0.95,	// 0 -> 1
	0.90,	// 1 -> 2
	0.85,	// 2 -> 3
	0.85,	// 3 -> 4
	0.80,	// 4 -> 5
	0.75,	// 5 -> 6 
	0.70,	// 6 -> 7 
	0.65,	// 7 -> 8
	0.60,	// 8 -> 9
	0.55,	// 9 -> 10
	0.50,	// 10 -> 11
	0.45,	// 11 -> 12
	0.40,	// 12 -> 13 
	0.35,	// 13 -> 14
	0.30,	// 14 -> 15 
	0.30,	// 15 -> 16
	0.30,	// 16 -> 17 
	0.15,	// 17 -> 18
	0.15,	// 18 -> 19		
	0.15,	// 19 -> 20
	0.30,	// 20 -> 21
	0.15,	// 21 -> 22
	0.15,	// 22 -> 23
	0.10,	// 23 -> 24
	0.10,	// 24 -> 25 
	0.10,	// 25 -> 26 
	0.07,	// 26 -> 27 
	0.05,	// 27 -> 28 
	0.03,	// 28 -> 29
	0.01	// 29 -> 30
};

const std::array<double, 30> DestroyProb =
{
	0.00,	// 0 -> 1
	0.00,	// 1 -> 2
	0.00,	// 2 -> 3
	0.00,	// 3 -> 4
	0.00,	// 4 -> 5
	0.00,	// 5 -> 6
	0.00,	// 6 -> 7 
	0.00,	// 7 -> 8
	0.00,	// 8 -> 9 
	0.00,	// 9 -> 10
	0.00,	// 10 -> 11 
	0.00,	// 11 -> 12
	0.00,	// 12 -> 13
	0.00,	// 13 -> 14
	0.00,	// 14 -> 15
	0.021,	// 15 -> 16
	0.021,	// 16 -> 17
	0.068,	// 17 -> 18
	0.068,	// 18 -> 19
	0.085,	// 19 -> 20
	0.105,	// 20 -> 21
	0.1275,	// 21 -> 22
	0.17,	// 22 -> 23 
	0.18,	// 23 -> 24 
	0.18,	// 24 -> 25
	0.18,	// 25 -> 26
	0.186,	// 26 -> 27 
	0.19,	// 27 -> 28
	0.194,	// 28 -> 29 
	0.198	// 29 -> 30
};

const std::array<int, 30> costFactor =
{
	36,	// 0 -> 1
	36, // 1 -> 2
	36, // 2 -> 3
	36, // 3 -> 4
	36, // 4 -> 5
	36, // 5 -> 6
	36, // 6 -> 7
	36, // 7 -> 8
	36,	// 8 -> 9
	36,	// 9 -> 10
	571,// 10 -> 11
	314,// 11 -> 12
	214,// 12 -> 13
	157,// 13 -> 14
	107,// 14 -> 15
	200,// 15 -> 16
	200,// 16 -> 17
	150,// 17 -> 18
	70,	// 18 -> 19
	45,	// 19 -> 20
	200,// 20 -> 21
	125,// 21 -> 22

};

constexpr int GetMaxStarForce(int level)
{
	if (0 <= level && level < 95) return 5;	// 0 ~ 94: 5
	else if (level < 108) return 8;			// 95 ~ 107: 8
	else if (level < 118) return 10;		// 108 ~ 117: 10 
	else if (level < 128) return 15;		// 118 ~ 127: 15 
	else if (level < 138) return 20;		// 128 ~ 137: 20 
	else if (level < 301) return 30;		// 138 ~ 300: 30
};