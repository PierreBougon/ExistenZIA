//
// Created by puillandre on 13/11/2017.
//

#ifndef EXISTENZIA_IHEADER_HPP
#define EXISTENZIA_IHEADER_HPP

#include <iostream>

namespace xzia {
    class IHeader {
    public:
        virtual void setField(std::string const & field, std::string const & value) = 0;
        virtual std::string & getField(std::string const & field) const = 0;
        virtual void addField(std::string const & field) = 0;
        virtual void deleteField(std::string const & field) = 0;
    };
}

#endif /* !EXISTENZIA_IHEADER_HPP */
