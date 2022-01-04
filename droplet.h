#ifndef DROPLET_H
#define DROPLET_H

#include <vector>
#include <iostream>
#include <random>
#include <windows.h>

static int dropletCount = 0;

class Droplet {
public:
	Droplet();
	Droplet(int);
	Droplet(int, int);
	~Droplet();

	void getDroplet();

	int getLineLength();
	int getPos();

	static int getDropletCount();

private:
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	std::vector<int> colourSet{ 1, 2, 3, 4, 5, 6 };
	std::vector<int> numSet;
	int lineLength = 0;
	int pos = 0;
	int charColour = 0;
};

#endif