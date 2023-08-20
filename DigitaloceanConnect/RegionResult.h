#pragma once
#include <cstdio>
#include <string>
#include <list>

class RegionResult {

public:
	std::string name;
	std::string slug;
	std::list<std::string> features;
	std::string features;
	bool available;
	std::list<std::string> sizes;

};