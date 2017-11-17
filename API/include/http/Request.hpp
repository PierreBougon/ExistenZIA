//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_IREQUEST_HPP
#define EXISTENZIA_IREQUEST_HPP

#include <iostream>
#include "Message.hpp"

/**
 * \file Request.hpp
 * \brief
 * \author Benjamin.D
 * \version 0.1
 * \date 17 novembre 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \class Request Request.hpp Request.hpp
 */

namespace xzia {

    class Request : Message {
    private:
        std::string                             method;
        std::string                             version;
        std::string                             host;
        std::string                             port;
        std::string                             path;
        std::map<std::string, std::string>      query;
    public:

        /**
         *
         * \fn Request
         * \brief Constructor of the class Request, where we set all attributes with the string message
         * @param message
         *
         */
        Request(std::string message);

    };
}
#endif //EXISTENZIA_IREQUEST_HPP
