#pragma once
#include <string>
#include <iostream>

class BaseComponent;

class IController {
public:
    virtual ~IController() = default;
    virtual void notify(BaseComponent* sender, std::string event) const = 0;

};

class BaseComponent {
public:
	BaseComponent(IController* controller = nullptr) : controller_(controller) {}

	void set_controller(IController* controller) {
		controller_ = controller;
	}
protected:
	IController* controller_;
};

class AirplaneComponent : public BaseComponent {
public:
	void take_off() {
		std::cout << "Airplane was taken off.\n";
		controller_->notify(this, "Airplane is mid-air.");
	}

	void land() {
		std::cout << "Airplane was landed.\n";
		controller_->notify(this, "Airplane is on ground.");
	}
};


class WeatherComponent : public BaseComponent {
public:
	void raining() {
		std::cout << "Thunderclap.\n";
		controller_->notify(this, "Weather is rainy.");
	}
	void sunshine() {
		std::cout << "The sun shines.\n";
		controller_->notify(this, "What a sunny day.");
	}
};


class ConcreteController : public IController {
private:
	AirplaneComponent* airplanecomp;
	WeatherComponent* weathercomp;
public:
	ConcreteController(AirplaneComponent* ac, WeatherComponent* wc) : airplanecomp(ac), weathercomp(wc) {
		airplanecomp->set_controller(this);
		weathercomp->set_controller(this);
	}

	void notify(BaseComponent* sender, std::string event) const override {
		std::cout << "event recieved: " << event << std::endl;

		if (event == "What a sunny day.") {
			airplanecomp->take_off();
		}
		else if (event == "Weather is rainy.") {
			airplanecomp->land();
		}
	}
};
