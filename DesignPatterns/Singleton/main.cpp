#include"templateSingleton.hpp"
#include <iostream>

class MyService
{
public:
	void sayHi() const
	{
		std::cout << "Hello from MyService singleton!\n";
	}
};

int main() {
	Singleton3::doSth();
	
	//impl10 usage
	Singleton10Provider::register_type("DerivedSingleton10A", &DerivedSingleton10A::get_instance);
	Singleton10Provider::register_type("DerivedSingleton10B", &DerivedSingleton10B::get_instance);
	// Singleton10Provider::register_type("d", &DerivedSingleton10B::get_instance); will fix later

	auto singletonA = Singleton10Provider::get_singleton("DerivedSingleton10A");
	if(singletonA) singletonA->doSth();

	auto singletonB = Singleton10Provider::get_singleton("DerivedSingleton10B");
	if (singletonB) singletonB->doSth();
	// auto x = *singletonA; can not copy
	
	// impl11 usage
	auto& svc = Singleton11<MyService>::Instance();
	svc.sayHi();

	std::cout << "Already exists: "
		<< Singleton11<MyService>::Exists() << "\n";

	// Cleanup
	SingletonManager::Shutdown();

}