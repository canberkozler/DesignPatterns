#include "concreteBuilder.hpp"
#include "product.hpp"

ConcreteBuilder::ConcreteBuilder() : product_(new Product()) {}

ConcreteBuilder::~ConcreteBuilder() {
	delete product_;
}
void ConcreteBuilder::BuildPartA() {
	product_->AddPart("PartA");
}
void ConcreteBuilder::BuildPartB() {
	product_->AddPart("PartB");
}
void ConcreteBuilder::BuildPartC(){
	product_->AddPart("PartC");
}
Product* ConcreteBuilder::getProduct() {
	Product* result = product_;
	product_ = new Product();
	return result;
}