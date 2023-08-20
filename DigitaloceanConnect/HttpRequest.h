#pragma once

#include <cstdio>
#include <cpr/cpr.h>

class HttpRequest
{
public:
	bool error;
	cpr::Response Res;
	std::string ResponseText;
	int Status;
	HttpRequest(std::string req_type, std::string url, std::string key, cpr::Parameters param);

};

