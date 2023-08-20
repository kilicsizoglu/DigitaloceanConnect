#pragma once

#include <cstdio>
#include <string>

class OneClickResult {

public:
	std::string slug;
	std::string type;
	OneClickResult(std::string slug, std::string type);
};