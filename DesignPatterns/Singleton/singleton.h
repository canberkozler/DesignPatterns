#pragma once
#include "tea.h"
#include <vector>
#include<iostream>

// example of a singleton manager
class Manager {
public:
    // call this to get access to the public functions
    static Manager& Instance() {
        static Manager* instance = new Manager();
        return *instance;
    }

    Manager(const Manager&) = delete; // delete copy ctor
    Manager& operator=(const Manager&) = delete; // delete copy assignment

    void add(Tea tea) {
        teas.push_back(tea);
    }

    void remove(Tea tea) {

    }

    std::vector<Tea> getTeaList()const {
        return teas;
    }

private:
    Manager() {}
    ~Manager(){}
    std::vector<Tea> teas;
};

//---------------------------------------------------------------------------------------------

class MeyersSingleton{
private:
    MeyersSingleton() = default;
    ~MeyersSingleton() { std::cout << "Meyers Dtor is called"; }; // Make Dtor private or deleted to prevent deletion by connecting to meyer singleton with reference semantics
    mutable int cnt{};
public:
    MeyersSingleton(const MeyersSingleton&)=delete; // delete copy ctor
    MeyersSingleton& operator=(const MeyersSingleton&)=delete; // delete copy assignment
    static MeyersSingleton& get_instance();

    void func()const{
        std::cout<<"func is called.\n"<<++cnt <<"\n";
    }
    void foo()const {
        std::cout<<"foo is called.\n";
    }
};

MeyersSingleton& MeyersSingleton::get_instance(){
    static MeyersSingleton s;
    return s;
}