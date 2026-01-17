#include "director.hpp"
#include "product.hpp"
#include "concreteBuilder.hpp"

int main() {
	ConcreteBuilder builder;
	Director director(&builder);
	director.construct();
	Product* product = builder.getProduct();
	product->show();


}