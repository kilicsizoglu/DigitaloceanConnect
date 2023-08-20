#pragma once

#include <cstdio>
#include <string>

#include "SpecResult.h"


class AppResult {

public:
	std::string id;
	std::string owner_uuid;
	std::string default_ingress;
	std::string created_at;
	std::string updated_at;
	std::string cause;
	std::string last_deployment_created_at;
	std::string live_url;
	std::string tier_slug;
	std::string live_url_base;
	std::string live_domain;


};