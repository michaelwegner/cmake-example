// A_unittest.cpp
//

#include <catch/catch.hpp>

#include <moduleA/A.h>

#include <cstdint>

TEST_CASE("A::ctor", "[A]") {
    // default ctor
    moduleA::A const default_a;
    REQUIRE(default_a.num_items() == 0);

    moduleA::A const empty_a{{}};
    REQUIRE(empty_a.num_items() == 0);

    std::vector<std::string> directory = {"Folder1", "Folder2", "File1"};
    moduleA::A const a{directory};
    REQUIRE(a.num_items() == 3);
}

TEST_CASE("A::add_directory_content", "[A]") {
    moduleA::A a;
    REQUIRE(a.num_items() == 0);

    a.add_directory_content("Folder1");
    REQUIRE(a.num_items() == 1);

    a.add_directory_content("Folder2");
    REQUIRE(a.num_items() == 2);

    a.add_directory_content("File1");
    REQUIRE(a.num_items() == 3);
}

TEST_CASE("A::for_contents", "[A]") {
    moduleA::A a;
    uint32_t num_calls = 0;
    auto const call_incrementor = [&num_calls](std::string const &) {
        ++num_calls;
    };

    SECTION("empty directory") {        
        a.for_contents(call_incrementor);
        REQUIRE(num_calls == 0);
        REQUIRE(a.num_items() == num_calls);
    }

    SECTION("non-empty directory") {
        a.add_directory_content("File1");
        a.for_contents(call_incrementor);
        REQUIRE(num_calls == 1);
        REQUIRE(a.num_items() == num_calls);
    }
}