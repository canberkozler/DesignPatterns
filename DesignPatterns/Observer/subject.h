#pragma once

#include "subscriber.h"
#include <list>
#include <memory>

using s_uptr = std::unique_ptr<ISubscriber>;
using UniqueList = std::list<s_uptr>;

class ISubject {
public:
    virtual ~ISubject() {};
    virtual void Add(s_uptr sub) = 0;
    virtual void Remove(s_uptr sub) = 0;
    virtual void Notify() const = 0;
};

class Subject : public ISubject {
public:
    void Add(s_uptr sub) override {
        subs_list.push_back(std::move(sub));
    };
    void Remove(s_uptr sub) override {
        subs_list.remove(std::move(sub));
    };
    void Notify() const override {
        if (subs_list.empty()) {
            std::cout << "No Subscriber is available.\n";
            return;
        }

        for (auto it = subs_list.cbegin(); it != subs_list.cend(); ++it) {
            (*it)->Update(latest_message);
        }
    };

    void AdvanceAndUpdateAll() {
        static int num_updates = 0;
        latest_message = "Update Number \"";
        latest_message += std::to_string(++num_updates);
        latest_message += "\" Processed!";
        Notify();
    }
private:
    UniqueList subs_list;
    std::string latest_message = "default message";
};
