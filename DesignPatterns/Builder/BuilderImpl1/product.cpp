#include "product.hpp"
#include <format>
#include <iostream>

void Product::AddPart(const char* part) {
	parts_ += part;
	parts_ += " ";
}

void Product::show() const {
	std::cout << std::format("Product parts: {}\n", parts_);
}
