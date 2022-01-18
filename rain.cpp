/*
Josua Brink
Digital Rain
*/

#include "rain.h"

Rain::Rain() {
	rain.resize(100);
}

Rain::Rain(const int size) {
	rain.resize(size);
}

void Rain::rainLoop() {
	static std::default_random_engine engine;
	static std::uniform_int_distribution <int> position(0, 99);
	static std::uniform_int_distribution <int> colour(1, 5);

	int newPosition = 0;

	while (true) {
		newPosition = position(engine);

		if (checkPos(newPosition)) {
			rain.at(newPosition) = Droplet(newPosition, colour(engine));
		}

		for (auto& d : rain) {
			if (d.getCurrentLength() > 0) {
				d.printDroplet();
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
		Sleep(10);
	}
}

bool Rain::checkPos(const int newPos) {
	for (auto& d : rain) {
		if (d.getPos() == newPos) {
			if (d.getCurrentLength() > 0) {
				return false;
			}
			return true;
		}
	}
}