#include "droplet.h"

Droplet::Droplet() {
	pos = 0;
	lineLength = 0;
	charColour = 0;
	numSet.resize(0);
}

Droplet::Droplet(int p) {
	dropletCount++;
	pos = p;
	charColour = 2;

	static std::default_random_engine e;
	static std::uniform_int_distribution <int> u(0, 20);
	numSet.resize(u(e));
	lineLength = numSet.size();

	for (auto& n : numSet) {
		n = u(e) % 9;
	}
	lineLength--;
}

Droplet::Droplet(int p, int c) {
	dropletCount++;
	pos = p;
	charColour = c;

	static std::default_random_engine e;
	static std::uniform_int_distribution <int> u(0, 20);
	numSet.resize(u(e));
	lineLength = numSet.size();

	for (auto& n : numSet) {
		n = u(e) % 9;
	}
	lineLength--;
}

Droplet::~Droplet() {
	dropletCount--;
}

int Droplet::getDropletCount() {
	return dropletCount;
}

void Droplet::getDroplet() {
	SetConsoleTextAttribute(consoleHandle, colourSet.at(charColour));

	int num = numSet.at(lineLength);
	std::cout << num;

	pos++;
	lineLength--;
}

int Droplet::getLineLength() {
	return lineLength;
}

int Droplet::getPos() {
	return pos;
}




