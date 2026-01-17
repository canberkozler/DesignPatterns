#include "car.hpp"

int main() {
	auto car = Car::Builder{}
				   .color("red")
				   .size(4.5, 2.0)
				   .doors(2)
				   .sunroof(true)
				   .build();

}