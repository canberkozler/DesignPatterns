#include "personBuilder.hpp"
#include <iostream>

int main(){
	// due to operator Person&&(), we can directly initialize Person p
	Person p = Person::create("John Doe")
				   .lives()
					   .at("123 London Road")
					   .with_postcode("SW1 1AA")
					   .in("London")
				   .works()
					   .with_company("SomeJob")
					   .earning("$10000");
	std::cout << p << std::endl;
	return 0;
}