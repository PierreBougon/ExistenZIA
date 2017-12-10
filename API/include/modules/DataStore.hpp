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
 * \file DataStore.hpp
 * \brief Used to store various types of data
 * \author Marc.B
 * \version 0.1
 * \date 17 novembre 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \namespace data
 * \class DataStore DataStore.hpp
 *
 */
namespace xzia
{
    using variant = boost::variant<char, int, float, long, double, std::string>;

    class DataStore
    {
    public:
        DataStore() = default;

        virtual ~DataStore() = default;

        /**
         *
         * \fn addData
         * \brief Add data of any type
         * @param data Data to be added
         * @param key Key associated to the data adding
         *
         */
        template <typename T>
        void        addData(std::string const& key, T data)
        {
            datas[key] = variant(data);
        }

        /**
         *
         * \fn getData
         * \brief Get data of any type
         * @param key Key associated to the data to get
         * @return The data to get
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
