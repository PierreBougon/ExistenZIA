//
// Created by puillandre on 13/11/2017.
//

#ifndef EXISTENZIA_IHEADER_HPP
#define EXISTENZIA_IHEADER_HPP

#include <iostream>

/**
 * \file IHeader.hpp
 * \brief
 * \author Marc.B
 * \version 0.1
 * \date 13 novembre 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \class IHeader IHeader.hpp IHeader.hpp
 */
namespace xzia {
    class IHeader {
    public:
        virtual void setField(std::string const & field, std::string const & value) = 0;

        /**
         *
         * \fn setField
         * \brief
         * @param field //TODO Describe this param here
         * @param value //TODO Describe this param here
         *
         */
        virtual void setField(std::string const & field, std::string const & value) = 0;

        /**
         *
         * \fn getField
         * \brief
         * @param field //TODO Describe this param here
         * @return Return the name of the field
         *
         */
        virtual std::string & getField(std::string const & field) const = 0;

        /**
         *
         * \fn addField
         * \brief
         * @param field //TODO Describe this param here
         *
         */
        virtual void addField(std::string const & field) = 0;
<<<<<<< HEAD
        virtual void deleteField(std::string const & field) = 0;
=======

        /**
         *
         * \fn setField
         * \brief
         * @param field //TODO Describe this param here
         *
         */
        virtual void setField(std::string const & field) = 0;
>>>>>>> 5da95a53d4e6a54fee682fe84a604f885dce5892
    };
}

#endif /* !EXISTENZIA_IHEADER_HPP */
