#ifndef PRODUCT_HPP_
#define PRODUCT_HPP_
#include <string>

class Product {
public:
	void AddPart(const char* part);

	void show() const;
private:
	std::string parts_;
};

#endif