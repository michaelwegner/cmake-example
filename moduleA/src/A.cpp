// A.cpp
//

#include <moduleA/A.h>

#include <utility>

namespace moduleA {
A::A(std::vector<std::string> directory_contents) : m_contents(std::move(directory_contents)) {
} 

void A::add_directory_content(std::string const &content_item) {
    m_contents.emplace_back(content_item);
}

uint32_t A::num_items() const {    
    return m_contents.size();
}
}  // namespace moduleA






