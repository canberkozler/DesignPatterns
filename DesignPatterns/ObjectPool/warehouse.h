#include "resource.h"
#include <list>

// WareHouse is a singleton
class Warehouse {
private:
    static Warehouse* instance;
    std::list<Resource*> resources;
    Warehouse() {}
    ~Warehouse() {}

public:
    static Warehouse* getInstance() {
        if (instance == 0) {
            instance = new Warehouse;
        }
        return instance;
    }

    Warehouse(const Warehouse&) = delete; // delete copy ctor
    Warehouse& operator=(const Warehouse&) = delete; // delete copy assignment

    Resource* getResource() {
        if (resources.empty()) {
            std::cout << "Creating new." << '\n';
            return new Resource();
        }
        else {
            std::cout << "Reusing existing." << '\n';
            Resource* resource = resources.front();
            resources.pop_front();
            return resource;
        }
    }

    void returnResource(Resource* object) {
        object->reset();
        resources.push_back(object);
    }
};

inline Warehouse* Warehouse::instance = nullptr;