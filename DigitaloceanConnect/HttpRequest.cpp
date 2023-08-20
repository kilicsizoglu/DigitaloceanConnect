#include "HttpRequest.h"

HttpRequest::HttpRequest(std::string req_type, std::string url, std::string key, cpr::Parameters param)
{
	if (req_type == "GET") {
		this->Res = cpr::Get(
			cpr::Url{ url },
			cpr::Bearer{ key },
			param
		);
		this->Status = this->Res.status_code;
		this->ResponseText = this->Res.text;
		this->error = false;
	}
	else if (req_type == "POST") {
		this->Res = cpr::Post(
			cpr::Url{ url },
			cpr::Bearer{ key },
			param
		);
		this->Status = this->Res.status_code;
		this->ResponseText = this->Res.text;
		this->error = false;
	}
	else if (req_type == "DELETE") {
		this->Res = cpr::Delete(
			cpr::Url{ url },
			cpr::Bearer{ key },
			param
		);
		this->Status = this->Res.status_code;
		this->ResponseText = this->Res.text;
		this->error = false;
	}
	else if (req_type == "PATCH") {
		this->Res = cpr::Patch(
			cpr::Url{ url },
			cpr::Bearer{ key },
			param
		);
		this->Status = this->Res.status_code;
		this->ResponseText = this->Res.text;
		this->error = false;
	}
	else if (req_type == "HEAD") {
		this->Res = cpr::Head(
			cpr::Url{ url },
			cpr::Bearer{ key },
			param
		);
		this->Status = this->Res.status_code;
		this->ResponseText = this->Res.text;
		this->error = false;
	}
	else if (req_type == "PUT") {
		this->Res = cpr::Put(
			cpr::Url{ url },
			cpr::Bearer{ key },
			param
		);
		this->Status = this->Res.status_code;
		this->ResponseText = this->Res.text;
		this->error = false;
	}
	else {
		this->error = true;
		this->Status = -1;
	}
}
