#include "droplet.h"


//The difference in value between the dark and light colours is 8
#define colourOffset 8

Droplet::Droplet() {
	numSet.resize(0);
}

Droplet::Droplet(const int p) {
	dropletCount++;
	pos = p;
	charColour = 2;

	setCharset();
}

Droplet::Droplet(const int p, const int c) {
	dropletCount++;
	pos = p;
	charColour = c;

	setCharset();
}

Droplet::Droplet(const Droplet& d) {
	dropletCount++;
	pos = d.pos;
	charColour = d.charColour;

	setCharset();
}

Droplet::~Droplet() {
	dropletCount--;
}

void Droplet::printDroplet() {
	if (lineLength - currentLength <= 2) {
		SetConsoleTextAttribute(consoleHandle, charColour);
	}
	else {
		SetConsoleTextAttribute(consoleHandle, charColour + colourOffset);
	}

	std::cout << numSet.at(currentLength);

	currentLength--;
}

int Droplet::getCurrentLength() {
	return currentLength;
}

int Droplet::getPos() {
	return pos;
}

int Droplet::getColour() {
	return charColour;
}

int Droplet::getDropletCount() {
	return dropletCount;
}

void Droplet::setColour(const int c) {
	charColour = c;
}

void Droplet::setPos(const int p) {
	pos = p;
}

void Droplet::setCharset() {
	static std::default_random_engine e;
	static std::uniform_int_distribution <int> u(5, 30);
	numSet.resize(u(e));
	lineLength = numSet.size() - 1;
	currentLength = lineLength;

	for (auto& n : numSet) {
		n = u(e) % 9;
	}
}
