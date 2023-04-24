#pragma once
#include "Waypoint.h"
#include <iostream>
#include <vector>

struct Path
{
	std::string name;
	std::vector<Waypoint> waypoint;
};