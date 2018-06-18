// A.h
//

#pragma once

#include <vector>
#include <string>
#include <cstdint>

namespace moduleA
{    
class A {
public:
    A() = default;
    A(std::vector<std::string> directory_contents);

    void add_directory_content(std::string const &content_item);

    template <typename L>
    void for_contents(L &&lambda) const;

    uint32_t num_items() const;

private:
    std::vector<std::string> m_contents;    
};

template <typename L>
void A::for_contents(L &&lambda) const {
    for (auto const &content_item : m_contents)
    {
        lambda(content_item);
    }    
}
}  // namespace moduleA 

