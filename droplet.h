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
	Droplet(const int);
	Droplet(const int, const int);
	Droplet(const Droplet&);
	~Droplet();

	void printDroplet();

	void setPos(const int);
	void setColour(const int);
	void setCharset();

	int getCurrentLength();
	int getPos();
	int getColour();

	static int getDropletCount();

private:
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	std::vector<int> numSet;
	int lineLength = 0;
	int currentLength = 0;
	int pos = 0;
	int charColour = 0;
};

#endif