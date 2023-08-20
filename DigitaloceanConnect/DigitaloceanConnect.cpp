#include "DigitaloceanConnect.h"
#include "HttpRequest.h"
#include "OneClickResult.h"
#include "AccountResult.h"
#include "TeamResult.h"
#include "ActionResult.h"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

static std::list<OneClickResult> OneClickList(std::string key, std::string type)
{
	std::list<OneClickResult> lists;
	std::string MainUrl = "https://api.digitalocean.com";
	HttpRequest req = HttpRequest("GET", MainUrl.append("/v2/1-clicks"), key, cpr::Parameters{
		{
			"type", type,
		}
		});
	if (req.Status == 200) {

		json rootJSON = json::parse(req.ResponseText);
		json parentJSON = rootJSON;
		int i = 0;
		while (true) {

			if (parentJSON[i] == NULL) {

				break;

			}
			else {

				auto list = OneClickResult(parentJSON[i]["slug"], parentJSON[i]["type"]);

				lists.push_back(list);

			}

		}

	}

	return lists;
}

static bool OneClickInstall(std::string key, std::string addon_slugs, std::string cluster_uuid)
{
	std::string MainUrl = "https://api.digitalocean.com";
	HttpRequest req = HttpRequest("POST", MainUrl.append("/v2/1-clicks"), key, cpr::Parameters{
		{
			"addon_slugs", addon_slugs,
		}, 
		{
			"cluster_uuid", cluster_uuid
		}
		});
	if (req.Status == 200) {

		return true;

	}
	else {

		return false;

	}
		
}

static bool OneClickInstall(std::string key, std::string addon_slugs, std::string cluster_uuid)
{
	std::string MainUrl = "https://api.digitalocean.com";
	HttpRequest req = HttpRequest("POST", MainUrl.append("/v2/account"), key, cpr::Parameters{});
	if (req.Status == 200) {

		return true;

	}
	else {

		return false;

	}

}

static AccountResult GetUserInformation(std::string key, int per_page, int page)
{
	AccountResult account;
	std::string MainUrl = "https://api.digitalocean.com";
	HttpRequest req = HttpRequest("POST", MainUrl.append("/v2/account"), key, cpr::Parameters{});
	if (req.Status == 200) {

		json rootJson = json::parse(req.ResponseText);
		json jsonAccount = rootJson["account"];

		
		account.droplet_limit = jsonAccount["droplet_limit"];
		account.floating_ip_limit = jsonAccount["floating_ip_limit"];
		account.email = jsonAccount["email"];
		account.name = jsonAccount["name"];
		account.uuid = jsonAccount["uuid"];
		account.email_verified = jsonAccount["email_verified"];
		account.status = jsonAccount["status"];
		account.status_message = jsonAccount["status_message"];

		json team = jsonAccount["team"];

		account.team.name = team["uuid"];
		account.team.name = team["name"];

	}
	
	return account;

}

static ActionResult ActionExist(std::string key, int action_id)
{
	ActionResult action;
	std::string MainUrl = "https://api.digitalocean.com";
	HttpRequest req = HttpRequest("POST", MainUrl.append("/v2/account"), key, cpr::Parameters{
		{
			"action_id", std::to_string(action_id)
		}
	});
	if (req.Status == 200) {

		json rootJson = json::parse(req.ResponseText);
		json actionJson = rootJson["action"];
		
		action.id = actionJson["id"];
		action.status = actionJson["status"];
		action.type = actionJson["type"];
		action.started_at = actionJson["started_at"];
		action.completed_at = actionJson["completed_at"];
		action.resource_id = actionJson["resource_id"];
		action.resource_type = actionJson["resource_type"];
		action.region_slug = actionJson["region_slug"];
		action.region_slug = actionJson["region_slug"];

		json regionJson = actionJson["region"];
		action.region.name = regionJson["name"];
		action.region.slug = regionJson["slug"];
		
		int i = 0;
		while (true) {

			if (regionJson["features"][i] == NULL) {
				break;
			}
			action.region.features.push_back(regionJson["features"][i]);
			i++;

		}
	}

	return action;

}

static ActionResult ActionExist(std::string key, int page, int per_page, bool with_projects)
{
	ActionResult action;
	std::string MainUrl = "https://api.digitalocean.com";
	HttpRequest req = HttpRequest("POST", MainUrl.append("/v2/account"), key, cpr::Parameters{
		{
			"page", page
		}, 
		{
			"per_page", per_page
		},
		{
			"with_projects", with_projects
		}
		});
	if (req.Status == 200) {

		json rootJson = json::parse(req.ResponseText);
		
	}

	return action;

}