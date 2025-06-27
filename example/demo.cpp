#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <assert.h>

#include "ex1.hpp"
#include "ex2.hpp"

int main(int argc, char** argv) {
#if 1
    std::cout << "------------- Default -------------" << std::endl;
    {
        ex1::Derived1 d1{};
        d1.get_id();
        ex1::Derived2 d2{};
        d2.get_id();
    }

    // std::cout << "------------- Illegal -------------" << std::endl;
    // {
        // ex1::Derived1 d1{};
        // ex1::Derived2 d2{};
        // std::vector<ex1::Base> vec{};

        // vec.push_back(d1);
        // vec.push_back(d2);

        // for (auto& i : vec) {
        //     i.get_id();
        // }
    // }

    std::cout << "---- Add Unique Ptr to Vector -----" << std::endl;
    {
        std::vector<std::unique_ptr<ex1::Base>> vec{};

        vec.push_back(std::make_unique<ex1::Derived1>());
        vec.push_back(std::make_unique<ex1::Derived2>());

        for (const auto& i : vec) {
            i->get_id();
        }
    }

    std::cout << "- Add Unique Ptr to Vector (Move) -" << std::endl;
    {
        std::unique_ptr d1_ptr{std::make_unique<ex1::Derived1>()};
        std::unique_ptr d2_ptr{std::make_unique<ex1::Derived2>()};
        std::vector<std::unique_ptr<ex1::Base>> vec{};

        vec.push_back(std::move(d1_ptr));
        vec.push_back(std::move(d2_ptr));

        for (const auto& i : vec) {
            i->get_id();
        }
    }
#endif

#if 0
    std::cout << "------------- Default -------------" << std::endl;
    {
        ex2::Vehicle v1{};
    }

    std::cout << "----- Invoke Copy Constructor -----" << std::endl;
    {
        ex2::Vehicle v2_tmp{};
        v2_tmp.engine_->hp_ = 2;
        ex2::Vehicle v2{v2_tmp};
        assert(v2_tmp.engine_.get() != nullptr); // unique pointer retained after copied
        assert(v2.engine_.get() != v2_tmp.engine_.get());
        assert(v2.engine_->hp_ == v2_tmp.engine_->hp_);
    }

    std::cout << "---- Invoke Copy Assignment Op ----" << std::endl;
    {
        ex2::Vehicle v3_tmp{};
        v3_tmp.engine_->hp_ = 3;
        ex2::Vehicle v3 = v3_tmp;
        assert(v3_tmp.engine_.get() != nullptr); // unique pointer retained after copied
        assert(v3.engine_.get() != v3_tmp.engine_.get());
        assert(v3.engine_->hp_ == 3);
    }

    std::cout << "----- Invoke Move Constructor -----" << std::endl;
    {
        ex2::Vehicle v4_tmp{};
        v4_tmp.engine_->hp_ = 4;
        ex2::Vehicle v4{std::move(v4_tmp)};
        assert(v4_tmp.engine_.get() == nullptr); // unique pointer destroyed after moved
        assert(v4.engine_.get() != v4_tmp.engine_.get());
        assert(v4.engine_->hp_ == 4);
    }

    std::cout << "---- Invoke Move Assignment Op ----" << std::endl;
    {
        ex2::Vehicle v5_tmp{};
        v5_tmp.engine_->hp_ = 5;
        ex2::Vehicle v5 = std::move(v5_tmp);
        assert(v5_tmp.engine_.get() == nullptr); // unique pointer destroyed after moved
        assert(v5.engine_.get() != v5_tmp.engine_.get());
        assert(v5.engine_->hp_ == 5);
    }

    std::cout << "-----------------------------------" << std::endl;
#endif

#if 0
    std::cout << "--------- Use Raw Pointer ---------" << std::endl;
    {
        ex2::Vehicle *v = new ex2::Vehicle{};
        assert(v != nullptr);
        delete v; // raw pointer wouldn't delete itself when going out of scope
        assert(v != nullptr);
    }

    std::cout << "------- Use Unique Pointer --------" << std::endl;
    {
        std::unique_ptr v = std::make_unique<ex2::Vehicle>();
        assert(v != nullptr);
        v.reset();
        assert(v == nullptr);
    }

    std::cout << "--- Add Rvalue to Vector (Move) ---" << std::endl;
    {
        std::vector<ex2::Vehicle> vec{};
        vec.push_back(ex2::Vehicle{}); // invoke move constructor if defined
    }

    std::cout << "--- Add Lvalue to Vector (Copy) ---" << std::endl;
    {
        std::vector<ex2::Vehicle> vec{};
        ex2::Vehicle v{};
        vec.push_back(v); // invoke copy constructor if defined
        assert(&v != nullptr);
        assert(&(vec[0]) != &v);
    }

    std::cout << "--- Add Lvalue to Vector (Move) ---" << std::endl;
    {
        std::vector<ex2::Vehicle> vec{};
        ex2::Vehicle v{};
        vec.push_back(std::move(v)); // invoke move constructor if defined
        assert(&v != nullptr);
        assert(&(vec[0]) != &v);
    }

    std::cout << "- Add Unique Ptr to Vector (Move) -" << std::endl;
    {
        std::vector<std::unique_ptr<ex2::Vehicle>> vec{};
        std::unique_ptr v_ptr{std::make_unique<ex2::Vehicle>()};
        vec.push_back(std::move(v_ptr)); // unique pointer must be moved, not copied
        assert(v_ptr.get() == nullptr);
        assert(vec[0].get() != v_ptr.get());
    }

    std::cout << "- Add Shared Ptr to Vector (Move) -" << std::endl;
    {
        std::vector<std::shared_ptr<ex2::Vehicle>> vec{};
        auto v_ptr{std::make_shared<ex2::Vehicle>()};
        vec.push_back(v_ptr); // shared pointer can be copied
        assert(v_ptr.get() != nullptr);
        assert(vec[0].get() == v_ptr.get());
    }
#endif

    return 0;
}