/*
Josua Brink
Digital Rain
*/


#ifndef RAIN_H
#define RAIN_H

#include "droplet.h"

class Rain {
private:
	std::vector<Droplet> rain;

public:
	Rain();
	Rain(const int);
	void rainLoop();
	bool checkPos(const int);
};


#endif