#pragma once
#include <cstdio>
#include <string>

#include "RegionResult.h"

class ActionResult {

public:
	int id;
	std::string status;
	std::string type;
	std::string started_at;
	std::string completed_at;
	int resource_id;
	std::string resource_type;
	std::string region_slug;
	RegionResult region;

};