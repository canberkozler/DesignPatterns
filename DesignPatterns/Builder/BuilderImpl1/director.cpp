#include "director.hpp"
#include "builder.hpp"

Director::Director(IBuilder* pbuilder) : p_builder{ pbuilder } {}

void Director::construct() {
	p_builder->BuildPartA();
	p_builder->BuildPartB();
	p_builder->BuildPartC();
}
