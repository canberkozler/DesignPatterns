#ifndef TEMPLATE_SINGLETON_HPP_
#define TEMPLATE_SINGLETON_HPP_
#include <memory>
#include <functional>
#include <unordered_map>
#include <string>
#include <typeindex>
#include <stdexcept>
#include <mutex>

// impl1
class Singleton1 {
public:
    static Singleton1& get_instance() {
        static Singleton1* instance = new Singleton1();
        return *instance;
    }

    Singleton1(const Singleton1&) = delete; // delete copy ctor
    Singleton1& operator=(const Singleton1&) = delete; // delete copy assignment

private:
    Singleton1() = default;
};

// impl2
class Singleton2 {
public:
    static Singleton2& get_instance() {
           if(!instance) instance = new Singleton2;

        return *instance;
    }

    Singleton2(const Singleton2&) = delete; // delete copy ctor
    Singleton2& operator=(const Singleton2&) = delete; // delete copy assignment

private:
    Singleton2() = default;

    inline static Singleton2* instance{};
};

//impl3
class Singleton3 {
public:
    static void doSth();
private:
    Singleton3();
    void doSth_impl();
    inline static Singleton3* instance{};
};

// impl4 in cpp file
// ------ >>>>>><<<<<< ------


//impl5
class Singleton5 {
public:
    Singleton5(const Singleton5&) = delete;
    Singleton5& operator=(const Singleton5&) = delete;
    
    ~Singleton5() = default;
    static Singleton5& get_instance();

private:
    Singleton5() = default;
    static Singleton5 instance;
};

// impl6
class Singleton6 {
public:
    Singleton6(const Singleton6&) = delete; // delete copy ctor
    Singleton6& operator=(const Singleton6&) = delete; // delete copy assignment
    static Singleton6& get_instance();
private:
    Singleton6() = default;
    ~Singleton6() = default; // Make Dtor private or deleted to prevent deletion by connecting to meyer singleton with reference semantics
};

// impl7
class Singleton7 {
public:
    Singleton7(const Singleton7&) = delete; // delete copy ctor
    Singleton7& operator=(const Singleton7&) = delete; // delete copy assignment
    static Singleton7& get_instance();
private:
    Singleton7() = default;
    ~Singleton7() = default;
};

// impl8
class Singleton8 {
public:
    Singleton8(const Singleton8&) = delete;
    Singleton8& operator=(const Singleton8&) = delete;
    static Singleton8& get_instance();
private:
    Singleton8() = default;
    inline static Singleton8* instance{};
};

// impl9
class Singleton9 {
public:
    Singleton9(const Singleton9&) = delete;
    Singleton9& operator=(const Singleton9&) = delete;
    static Singleton9& get_instance();
private:
    struct my_deleter {
        void operator()(Singleton9* p) {
            delete p;
        }
	};
    Singleton9() = default;
    ~Singleton9() = default;
    inline static std::unique_ptr<Singleton9, my_deleter> instance{};
};

//impl10
class Singleton10 {
public:
	Singleton10(const Singleton10&) = delete;
	Singleton10& operator=(const Singleton10&) = delete;
	virtual void doSth();

    virtual ~Singleton10() = default;
protected:
    Singleton10() = default;
	inline static std::unique_ptr<Singleton10> instance{};
};
using Singleton10Ptr = std::shared_ptr<Singleton10>;

// using CreateSingleton10Func = Singleton10Ptr(*)();
using CreateSingleton10Func = std::function<Singleton10Ptr()>;
class Singleton10Provider {
public:
	static void register_type(const std::string& type_name, CreateSingleton10Func func);
	static Singleton10Ptr get_singleton(const std::string& type_name);
private:
    struct InstanceData{
		Singleton10Ptr instance;
        CreateSingleton10Func creator;
    };

	inline static std::unordered_map<std::string, InstanceData> registry{};
};

class DerivedSingleton10A : public Singleton10 {
public:
	DerivedSingleton10A() = default;
	static Singleton10Ptr get_instance();
	void doSth() override;
};

class DerivedSingleton10B : public Singleton10 {
public:
    DerivedSingleton10B() = default;
	static Singleton10Ptr get_instance();
	void doSth() override;
};

// impl11
// https://github.com/AlexWorx/ALib-Singletons/tree/master
class SingletonManager
{
private:
    inline static std::unordered_map<std::type_index, void*> instances{};
    inline static std::mutex mutex_{};

public:
    template<typename T>
    static T& Get()
    {
        std::lock_guard<std::mutex> lock(mutex_);

        std::type_index key(typeid(T));
        auto it = instances.find(key);

        if (it != instances.end())
        {
            return *static_cast<T*>(it->second);
        }

        T* obj = new T();
        instances[key] = obj;
        return *obj;
    }

    template<typename T>
    static bool Exists()
    {
        std::lock_guard<std::mutex> lock(mutex_);
        std::type_index key(typeid(T));
        return instances.find(key) != instances.end();
    }

    static void Shutdown()
    {
        std::lock_guard<std::mutex> lock(mutex_);
        for (auto& kv : instances)
            delete static_cast<char*>(kv.second);
        instances.clear();
    }
};

template<typename T>
class Singleton11
{
public:
    static T& Instance()
    {
        return SingletonManager::Get<T>();
    }

    static bool Exists()
    {
        return SingletonManager::Exists<T>();
    }
};


#endif // !TEMPLATE_SINGLETON_HPP_
