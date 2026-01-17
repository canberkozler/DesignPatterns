#include <iostream>
#include "person.hpp"
#include "personBuilder.hpp"

std::ostream& operator<<(std::ostream& os, const Person& obj) {
	os << "Name: " << obj.m_name << "\n"
	   << "Address: " << obj.m_street << ", " << obj.m_postcode << ", " << obj.m_town << "\n"
	   << "Employment: " << obj.m_company << ", " << obj.m_income;
	return os;
}

PersonBuilder Person::create(const std::string& name) {
	return PersonBuilder{name};
}