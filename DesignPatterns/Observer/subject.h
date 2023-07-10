#pragma once

#include "subscriber.h"
#include <list>
#include <memory>

using s_uptr = std::unique_ptr<ISubscriber>;
using UniqueList = std::list<s_uptr>;

class ISubject {
public:
    virtual ~ISubject() {};
    virtual void add(s_uptr sub) = 0;
    virtual void remove(s_uptr sub) = 0;
    virtual void notify() const = 0;
};

class Subject : public ISubject {
public:
    void add(s_uptr sub) override {
        subs_list.push_back(std::move(sub));
    };
    void remove(s_uptr sub) override {
        subs_list.remove(std::move(sub));
    };
    void notify() const override {
        if (subs_list.empty()) {
            std::cout << "No Subscriber is available.\n";
            return;
        }

        for (const auto& sub : subs_list) {
            sub->update(latest_message);
        }
    };

    void AdvanceAndUpdateAll() {
        static int num_updates = 0;
        latest_message = "Update Number \"";
        latest_message += std::to_string(++num_updates);
        latest_message += "\" Processed!";
        notify();
    }
private:
    UniqueList subs_list;
    std::string latest_message = "default message";
};
