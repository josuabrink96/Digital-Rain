#include "droplet.h"

int main() {
	std::vector<Droplet> rain;
	rain.resize(100);

	static std::default_random_engine engine;
	static std::uniform_int_distribution <int> position(0, 99);
	static std::uniform_int_distribution <int> colour(1, 5);

	int newPosition = 0;
	int newColour = 0;
	bool containsDroplet = false;

	while(true) {
		newPosition = position(engine);
		newColour = colour(engine);
		for (auto& d : rain) {
			if (d.getPos() == newPosition) {
				if (d.getCurrentLength() > 0) {
					containsDroplet = true;
					break;
				}
				break;
			}
		}
		if (!containsDroplet) {
			rain.at(newPosition) = Droplet(newPosition, newColour);
		}

		for (auto& d : rain) {
			if (d.getCurrentLength() > 0) {
				d.printDroplet();
			}
			else {
				std::cout << " ";
			}
		}
		containsDroplet = false;
		std::cout << std::endl;
		Sleep(10);
	}

	return 0;
}