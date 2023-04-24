// Tool subdirectory
#pragma once
#include <iostream>
#include "Waypoint.h"

int main(void)
{
	std::cout << "Hello world\n";
	
	Waypoint w1{ 10.0, 27.3, "waypoint1" };

	std::cout << w1.name << " : " << w1.x << "," << w1.y << '\n';

	return 0;
}