// B.cpp
//

#include <moduleB/B.h>

#include <iostream>

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

namespace moduleB {

bool B::fetch_directory_contents(std::string const &parent_directory) {    
    if(!boost::filesystem::is_directory(parent_directory) || !boost::filesystem::exists(parent_directory))
    {
        std::cout << parent_directory << " not a valid directory\n";
        return false;
    }

    m_parent_dir = parent_directory;
    for(auto const &entry : boost::make_iterator_range(boost::filesystem::directory_iterator(m_parent_dir), {})) {
        m_a.add_directory_content(entry.path().string());
    }

    return true;
}

std::string B::get_directory_contents() const {
    std::string out = m_parent_dir + "/";
    m_a.for_contents([&out](std::string const &content_item){        
        out += "\n\t" + content_item.substr(content_item.find_last_of("/") + 1);
    });    

    return out;
}
}

