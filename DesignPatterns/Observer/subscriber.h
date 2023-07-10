#pragma once

#include <string>
#include <iostream>
#include "subject.h"

class ISubscriber {
public:
    virtual ~ISubscriber() {}
    friend class Subject;
protected:
    virtual void update(const std::string& message) const = 0;
};

class Subscriber : public ISubscriber {
public:
    Subscriber() : id { _unique_subscribers++ } {}

protected:
    void update(const std::string& message) const override {
        std::cout << "SUBID: \"" << id << "\" recieved message -> " << message << '\n';
    };

private:
    std::size_t id;
    static std::size_t _unique_subscribers;
};

std::size_t Subscriber::_unique_subscribers = 0;