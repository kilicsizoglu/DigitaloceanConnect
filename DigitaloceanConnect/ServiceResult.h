#pragma once

#include <cstdio>
#include <string>

#include "GitResult.h"
#include "RouterResult.h"

class ServiceResult {

public:
	std::string name;
	GitResult git;
	std::string run_command;
	std::string environment_slug;
	std::string instance_size_slug;
	int instance_count;
	int http_port;
	RouterResult router;

};