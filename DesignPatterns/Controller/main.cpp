#include "controller.hpp"

int main() {
	AirplaneComponent* airplane = new AirplaneComponent;
	WeatherComponent* weather = new WeatherComponent;

	ConcreteController* controller = new ConcreteController(airplane, weather);

	airplane->land();

	weather->sunshine();

	weather->raining();

	airplane->take_off();

	delete controller;
	delete weather;
	delete airplane;
}