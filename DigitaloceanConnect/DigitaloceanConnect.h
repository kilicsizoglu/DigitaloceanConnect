#pragma once

class DigitaloceanConnect {
public:
	static std::list<OneClickResult> OneClickList(std::string type);
	static bool OneClickInstall(std::string type);
	static AccountResult GetUserInformation();
};