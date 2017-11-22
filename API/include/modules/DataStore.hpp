//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ADATASTORE_HPP
#define EXISTENZIA_ADATASTORE_HPP

#include <map>
#include <boost/variant/variant.hpp>
#include <boost/variant/get.hpp>
#include "DataStore.hpp"

/**
 * \file ADataStore.hpp
 * \brief
 * \author Marc.B
 * \version 0.1
 * \date 17 novembre 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \namespace data
 * \class ADataStore ADataStore.hpp ADataStore.hpp
 *
 */
namespace xzia
{
    using variant = boost::variant<char, int, float, long, double, std::string>;

    class DataStore
    {
    public:
        /**
         *
         * \fn addInt
         * \brief Add data of type int
         * @param i Data of type int
         * @param key Key associated to the data adding
         *
         */
        template <typename T>
        void        addData(T data, std::string const& key)
        {
            datas[key] = variant(data);
        }

        /**
         *
         * \addChar
         * \brief Add data of type char
         * @param c Data of type char
         * @param key Key associated to the data adding
         *
         */
        template <typename T>
        T        getData(std::string const& key)
        {
            return boost::get<T>(datas[key]);
        }

    protected:
        std::map<std::string, variant> datas;
    };
}

#endif //EXISTENZIA_ADATASTORE_HPP
