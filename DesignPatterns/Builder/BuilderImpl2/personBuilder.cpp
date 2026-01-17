#include "personBuilder.hpp"

PersonBuilder::operator Person&&() {
	return std::move(m_person);
}


PersonBuilder& PersonBuilder::lives() {
	return *this;
}
PersonBuilder& PersonBuilder::works() {
	return *this;
}

PersonBuilder& PersonBuilder::at(std::string street) {
	m_person.m_street = std::move(street);
	return *this;
}

PersonBuilder& PersonBuilder::with_postcode(std::string postcode) {
	m_person.m_postcode = std::move(postcode);
	return *this;
}

PersonBuilder& PersonBuilder::in(std::string town) {
	m_person.m_town = std::move(town);
	return *this;
}

PersonBuilder& PersonBuilder::with_company(std::string company) {
	m_person.m_company = std::move(company);
	return *this;
}
PersonBuilder& PersonBuilder::earning(std::string income) {
	m_person.m_income = std::move(income);
	return *this;
}

