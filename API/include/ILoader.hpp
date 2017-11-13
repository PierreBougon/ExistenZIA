//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ILOADER_HPP
#define EXISTENZIA_ILOADER_HPP

#include <iostream>

namespace xzia {
    class ILoader {
        virtual explicit ILoader(std::string const &file) = 0;
        virtual void reload() = 0;
        virtual std::string &getCoreField(std::string const &field) = 0;
        virtual std::string &getModuleField(std::string const &module, std::string const &field) = 0;
    };
}
#endif //EXISTENZIA_ILOADER_HPP
