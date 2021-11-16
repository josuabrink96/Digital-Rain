#include "droplet.h"
#include <random>

Droplet::Droplet(int p) {
	dropletCount++;
	pos = p;
	lineCount = 0;

	static std::default_random_engine e;
	static std::uniform_int_distribution <int> u(1, 20);
	numSet.resize(u(e));
	lineLength = numSet.size();

	for (auto& n : numSet) {
		n = u(e) % 9;
	}
}

Droplet::~Droplet() {
	dropletCount--;
}

int Droplet::getDropletCount() {
	return dropletCount;
}

int Droplet::getDroplet() {
	int num = numSet.at(lineCount);
	lineCount++;
	return num;
}

int Droplet::getLineLength() {
	return lineLength;
}

int Droplet::getPos() {
	return pos;
}


