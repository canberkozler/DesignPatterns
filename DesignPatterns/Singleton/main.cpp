#include"singleton.h"

int main() {
	Manager::Instance().add(Tea{2,3,4});
	
	auto list = Manager::Instance().getTeaList();

	size_t idx{ 1 };
	for (const auto& tea : list) {
		std::cout << "Index: " << idx++ << ", Str: " << tea.strength
			<< ", Cost: " << tea.cost << ", Quat: " << tea.quantity << "\n";
	}

	// ----------------------------------------------------------------

	MeyersSingleton::get_instance().func();
	MeyersSingleton::get_instance().func();
	MeyersSingleton::get_instance().func();
	MeyersSingleton::get_instance().foo();
}