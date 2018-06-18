// B.h
//

#pragma once

#include <moduleA/A.h>

#include <string>

namespace moduleB {
class B
{
public: 
    bool fetch_directory_contents(std::string const &parent_directory);

    std::string get_directory_contents() const;

private:
    std::string m_parent_dir;
    moduleA::A m_a;
};
}