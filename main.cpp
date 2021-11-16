#include <vector>
#include "droplet.h"
#include <iostream>

int main() {
	
	Droplet d(5);
	for (int i = 0; i < d.getLineLength(); i++) {
		for (int i = 0; i != d.getPos(); i++) {
			std::cout << " ";
		}
		std::cout << d.getDroplet() << std::endl;
	}
	return 0;
}