// B_unittest.cpp
//

#include <catch/catch.hpp>

#include <moduleB/B.h>

#include <boost/filesystem.hpp>

TEST_CASE("B::fetch_directory_contents", "[B]") {
    moduleB::B b;
    SECTION("non-existent directory") {                
        bool const result = b.fetch_directory_contents("./test-dir");
        REQUIRE(result == false);
    }

    SECTION("empty directory") {
        boost::filesystem::create_directory("./test-dir");
        
        bool const result = b.fetch_directory_contents("./test-dir");
        REQUIRE(result == true);
        
        auto const string_representation = b.get_directory_contents();
        REQUIRE(!string_representation.empty());
        REQUIRE(string_representation == "./test-dir/");

        boost::filesystem::remove_all("./test-dir");
    }

    SECTION("non-empty directory") {
        boost::filesystem::create_directory("./test-dir");
        boost::filesystem::create_directory("./test-dir/tmp");

        bool const result = b.fetch_directory_contents("./test-dir");
        REQUIRE(result == true);
        
        auto const string_representation = b.get_directory_contents();
        REQUIRE(!string_representation.empty());
        REQUIRE(string_representation == "./test-dir/\n\ttmp");
        
        boost::filesystem::remove_all("./test-dir");   
    }
}