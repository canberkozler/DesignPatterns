#pragma once
#include <memory>
#include <iostream>
#include <typeinfo>

class Engine;

class State {
public:
	virtual ~State() = default;
	void set_engine(Engine* eng) {
		eng_ptr = eng;
	}

	virtual void realizeA() = 0;
	virtual void realizeB() = 0;
protected:
	Engine* eng_ptr;
};

using Sptr = std::unique_ptr<State>;

class Engine {
public:
	Engine(Sptr sp) noexcept : sta_uptr{ nullptr } {
		Transition2(std::move(sp));
	}
	Engine(const Engine&) = delete;
	Engine& operator=(const Engine&) = delete;

	void Transition2(Sptr sta) {
		sta_uptr = std::move(sta);
		sta_uptr->set_engine(this);
	}

	void RequestA() {
		std::cout << "A is called...\n";
		sta_uptr->realizeA();
	}
	void RequestB() {
		std::cout << "B is called...\n";
		sta_uptr->realizeB();
	}
private:
	Sptr sta_uptr;
};


class StateA : public State {
public:
	void realizeA() override {
		std::cout << typeid(this).name() << " is called. A is done.\n";
	}
	void realizeB() override;
};

class StateB : public State {
public:
	virtual void realizeA() override {
		std::cout << typeid(this).name() << " is called. A is done.\n";
		eng_ptr->Transition2(std::make_unique<StateA>());
	}
	virtual void realizeB() override {
		std::cout << typeid(this).name() << " is called. B is done.\n";
	}
};

inline void StateA::realizeB() {
	std::cout << typeid(this).name() << " is called. B is done.\n";
	eng_ptr->Transition2(std::make_unique<StateB>());
}