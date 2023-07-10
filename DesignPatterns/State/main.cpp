#include "state.h"


int main() {
	StateB X;
	Engine engine1{std::make_unique<StateB>()};

	engine1.RequestA();
	engine1.RequestB();
}