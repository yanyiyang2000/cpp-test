#include <iostream>
#include <memory>
#include <string>

namespace ex1 {

class Base {
private:
    int private_val{0}; // not accessible from Derived

protected:
    int protected_val{0}; // not accessible from Derived

public:
    int public_val{0};

    // Constructor
    Base() {
        std::cout << "Created Base     (at " << this << ")" << std::endl;
    }

    // Destructor
    ~Base() {
        std::cout << "Deleted Base     (at " << this << ")" << std::endl;
    }

    // Accessor (pure virtual)
    virtual void get_id() = 0;
};

class Derived1 : public Base {
public:
    inline static int id{1};

    // Constructor
    Derived1() {
        std::cout << "Created Derived1 (at " << this << ")" << std::endl;
    }

    // Destructor
    ~Derived1() {
        std::cout << "Deleted Derived1 (at " << this << ")" << std::endl;
    }

    // Accessor
    void get_id() override {
        std::cout << "ID is " << id << "          (at " << this << ")" << std::endl;
    }
};

class Derived2 : public Base {
public:
    inline static int id{2};

    // Constructor
    Derived2() {
        std::cout << "Created Derived2 (at " << this << ")" << std::endl;
    }

    // Destructor
    ~Derived2() {
        std::cout << "Deleted Derived2 (at " << this << ")" << std::endl;
    }

    // Accessor
    void get_id() override{
        std::cout << "ID is " << id << "          (at " << this << ")" << std::endl;
    }
};

}  // namespace ex1
