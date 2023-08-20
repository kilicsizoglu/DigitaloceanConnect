#pragma once

#include <cstdio>
#include <string>

#include "TeamResult.h"

class AccountResult {

public:
	int droplet_limit;
	int floating_ip_limit;
	std::string email;
	std::string name;
	std::string uuid;
	bool email_verified;
	std::string status;
	std::string status_message;
	TeamResult team;

};