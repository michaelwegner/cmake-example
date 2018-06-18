// main.cpp
//

#include <moduleB/B.h>

#include <cassert>
#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
    assert(argc == 1);
    std::string executable_path{argv[0]};
    auto const directory = executable_path.substr(0, executable_path.find_last_of("/"));

    moduleB::B b;
    bool const result = b.fetch_directory_contents(directory);
    if (!result)
    {
        std::cout << "Could not fetch directory contents from " << directory << std::endl;
        return 1;
    }

    std::cout << b.get_directory_contents() << std::endl;
    return 0;    
}