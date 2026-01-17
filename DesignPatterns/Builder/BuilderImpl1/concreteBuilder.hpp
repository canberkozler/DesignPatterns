#include "builder.hpp"

class Product;

class ConcreteBuilder : public IBuilder {
public:
	ConcreteBuilder();
	~ConcreteBuilder() override;
	void BuildPartA() override;
	void BuildPartB() override;
	void BuildPartC() override;
	Product* getProduct();
private:
	Product* product_;
};