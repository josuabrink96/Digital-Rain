#ifndef DROPLET_H
#define DROPLET_H

#include <vector>

static int dropletCount = 0;

class Droplet {
public:
	Droplet(int);
	~Droplet();
	static int getDropletCount();
	int getDroplet();
	int getLineLength();
	int getPos();
private:
	std::vector<int> numSet;
	int lineLength = 0;
	int lineCount = 0;
	int pos = 0;
};

#endif