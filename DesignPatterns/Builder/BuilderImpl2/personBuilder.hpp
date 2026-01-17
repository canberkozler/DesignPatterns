#pragma once

#include "person.hpp"

class PersonBuilder {
public:
	explicit PersonBuilder(const std::string& name) : m_person(name) {}
	operator Person && ();

	PersonBuilder& lives();
	PersonBuilder& works();
	PersonBuilder& at(std::string street);
	PersonBuilder& with_postcode(std::string postcode);
	PersonBuilder& in(std::string town);
	PersonBuilder& with_company(std::string company);
	PersonBuilder& earning(std::string income);

private:
	Person m_person;
};