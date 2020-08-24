#include "phone_number.h"
#include<sstream>
#include <exception>

PhoneNumber::PhoneNumber(const string& international_number) {
	stringstream ss;
	ss << international_number;
	char plus;
	ss >> plus;
	if (plus != '+') {
		throw invalid_argument("");
	}

	int country_code;
	ss >> country_code;
	country_code_ = to_string(country_code);
	if (country_code_.empty()) {
		throw invalid_argument("");
	}

	char minus;
	ss >> minus;
	if (minus != '-') {
		throw invalid_argument("");
	}

	int city_code;
	ss >> city_code;
	city_code_ = to_string(city_code);
	if (city_code_.empty()) {
		throw invalid_argument("");
	}

	char minus1;
	ss >> minus1;
	if (minus1 != '-') {
		throw invalid_argument("");
	}

	ss >> local_number_;
	if (local_number_.empty()) {
		throw invalid_argument("");
	}
}

string PhoneNumber::GetCityCode() const {
	return city_code_;
}

string PhoneNumber::GetCountryCode() const {
	return country_code_;
}

string PhoneNumber::GetLocalNumber() const {
	return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
	return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}

