#include <iostream>
#include <memory>
#include <string>

namespace ex2 {

class Engine {
public:
    int hp_{0};

    /**
     * Define constructor, copy constructor and destructor for demonstration purpose only.
     * In other words, compiler will define those automatically and implement those correctly.
     * Commenting out the following code will not cause any error.
     */

    // Constructor
    Engine() {
        std::cout << "Created Engine  (at " << this << ")" << std::endl;
    }

    // Copy constructor
    Engine(const Engine& e) : hp_{e.hp_} {
        std::cout << "Created Engine  (at " << this << " copied from " << &e << ")" << std::endl;
    }

    // Destructor
    ~Engine() {
        std::cout << "Deleted Engine  (at " << this << ")" << std::endl;
    }
};

class Vehicle {
public:
    std::unique_ptr<Engine> engine_;

    /**
     * Need to explicitly implement at least the constructor and copy constructor manually because the presence of
     * unique pointer. In other words, compiler will NOT implicitly implement those automatically.
     */

    // Constructor
    // Triggers compile time error if not defined (since the defaulted constructor is implicitly deleted)
    // Using Vehicle() = default will cause run time error since the address of unique pointer will be set to 0 (Hence
    // SEGV fault)
    Vehicle() : engine_{std::make_unique<Engine>()} {
        std::cout << "Created Vehicle (at " << this << ")" << std::endl;
    }

    // Copy constructor
    // Triggers compile error if not defined (since the defaulted copy constructor is implicitly deleted)
    Vehicle(const Vehicle& v) : engine_{std::make_unique<Engine>(*v.engine_)} {
        std::cout << "Created Vehicle (at " << this << " copied from " << &v << ")" << std::endl;
    }

    // Copy assignment operator
    // The copy constructor will be invoked if not defined
    // Comment out and see what happens
    Vehicle& operator=(const Vehicle& v) {
        std::cout << "Created Vehicle (at " << this << " copied from " << &v << ")" << std::endl;
        engine_ = std::make_unique<Engine>(*v.engine_);
        return *this;
    }

    // Move constructor
    // The copy constructor will be invoked if not defined
    // Comment out and see what happens
    Vehicle(Vehicle&& v) : engine_{std::move(v.engine_)} {
        std::cout << "Created Vehicle (at " << this << " moved  from " << &v << ")" << std::endl;
    }

    // Move assignment operator
    // The move constructor will be invoked if not defined
    // The copy constructor will be invoked if the move constructor is not defined
    // Comment out and see what happens
    Vehicle& operator=(Vehicle&& v) {
        std::cout << "Moved   Vehicle (to " << this << " from " << &v << ")" << std::endl;
        engine_ = std::move(v.engine_);
        return *this;
    }

    // Destructor
    // The default destructor will be invoked if not defined
    // Comment out and see what happens
    ~Vehicle() {
        std::cout << "Deleted Vehicle (at " << this << ")" << std::endl;
    }
};

}  // namespace ex2
