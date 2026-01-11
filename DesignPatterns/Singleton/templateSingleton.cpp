#include "templateSingleton.hpp"
#include <iostream>
#include <new>


// impl3
Singleton3::Singleton3() {
	if (!instance)
		instance = new Singleton3;
}

void Singleton3::doSth_impl() {
	std::cout << "Doing some stuff...\n";
}

void Singleton3::doSth() {
	instance->doSth_impl();
}

// impl4
namespace Singleton4{
	namespace {
		int ival{};
		double dval{};
	}

	void instance() { // calls Singleton4::instance();
		std::cout << (++ival) << '\n';
	}
}


// impl5
Singleton5 Singleton5::instance;

Singleton5& Singleton5::get_instance() {
	return instance;
}


// impl6
Singleton6& Singleton6::get_instance() {
	static Singleton6 s; // creation is thread-safe (in modern cpp)
	return s;
}

// impl7
Singleton7& Singleton7::get_instance() {
	static Singleton7* p = new Singleton7;
	return *p;
}

// impl8
std::once_flag flag;

Singleton8& Singleton8::get_instance() {
	std::call_once(flag, []() {
		instance = new Singleton8; });
}

// impl9
Singleton9& Singleton9::get_instance() {
	if (!instance) instance.reset(new Singleton9);

	return *instance;
}


// impl10
void Singleton10::doSth() {
	std::cout << "Singleton10 doing sth...\n";
}

void Singleton10Provider::register_type(const std::string& type_name, CreateSingleton10Func func) {
	if (!registry.contains(type_name)) {
		registry[type_name].creator = func;
	}
	else
	{
		std::cout << "Type already registered: " << type_name << '\n';
	}
}

Singleton10Ptr Singleton10Provider::get_singleton(const std::string& type_name) {
	if (registry.contains(type_name)) {
		if(!registry[type_name].instance) {
			registry[type_name].instance = registry[type_name].creator();
		}
		return registry[type_name].instance;
	}
	
	std::cout << "Type not registered: " << type_name << '\n';
	return {}; // nullptr
}

Singleton10Ptr DerivedSingleton10A::get_instance() {
	return Singleton10Ptr{new DerivedSingleton10A };
}

void DerivedSingleton10A::doSth() {
	std::cout << "DerivedSingleton10A doing sth...AAAA\n";
}

Singleton10Ptr DerivedSingleton10B::get_instance() {
	return Singleton10Ptr{ new DerivedSingleton10B };
}

void DerivedSingleton10B::doSth() {
	std::cout << "DerivedSingleton10B doing sth...BBBB\n";
}