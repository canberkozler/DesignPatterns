#pragma once

#include <string>
#include <ostream>

class PersonBuilder;

class Person {
public:
	friend class PersonBuilder;
	friend std::ostream& operator<<(std::ostream& os, const Person& obj);
	static PersonBuilder create(const std::string& name);

private:
	Person(std::string name) : m_name(std::move(name)) {}

	std::string m_name;
	std::string m_street;
	std::string m_postcode;
	std::string m_town;
	std::string m_company;
	std::string m_income;
};