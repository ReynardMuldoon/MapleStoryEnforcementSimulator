#pragma once 

#include "StarForceSimulator.h"

class Simulator
{
	StarForceSimulator* starForceSimulator;

public:
	~Simulator();
	void run();

private:
	void startStarForceSimulation();
};