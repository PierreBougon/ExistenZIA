//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ADATASTORE_HPP
#define EXISTENZIA_ADATASTORE_HPP

#include <iostream>
#include <map>

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
    /**
    * \enum DataType
    */
    enum class DataType : unsigned char{
        CHAR,
        INT,
        FLOAT,
        LONG,
        DOUBLE,
        STRING
    };

    /**
    * \union DataValue
    */
    union DataValue {
        char        c;
        int         i;
        float       f;
        long        l;
        double      d;
        std::string s;
    };

    /**
    * \struct Data
    */
    struct Data
    {
        DataType        type;
        boost::variant  value;
    };

    class ADataStore {
    protected:
        std::map<std::string, Data> datas;
    public:

        /**
        *
        * \fn addInt
        * \brief Add data of type int
        * @param i Data of type int
        * @param key Key associated to the data adding
        *
        */
        void        addInt(int i, std::string const& key);

        /**
        *
        * \addChar
        * \brief Add data of type char
        * @param c Data of type char
        * @param key Key associated to the data adding
        *
        */
        void        addChar(char c, std::string const& key);

        /**
        *
        * \fn addLong
        * \brief Add data of type long
        * @param l Data of type long
        * @param key Key associated to the data adding
        *
        */
        void        addLong(long l, std::string const& key);

        /**
        *
        * \fn addStr
        * \brief Add data of type string
        * @param s Data of type string
        * @param key Key associated to the data adding
        *
        */
        void        addStr(std::string const &s, std::string const& key);

        /**
        *
        * \fn addFloat
        * \brief Add data of type float
        * @param f Data of type float
        * @param key Key associated to the data adding
        *
        */
        void        addFloat(float f, std::string const& key);

        /**
        *
        * \fn addDouble
        * \brief Add data of type double
        * @param d Data of type double
        * @param key Key associated to the data adding
        *
        */
        void        addDouble(double d, std::string const& key);

        /**
        *
        * \fn getInt
        * \brief Get the data of type int asking
        * @param key Key associated to the data adding
        * @return Return the specific data of type int determined by the key
        *
        */
        int         getInt(std::string const& key) const;

        /**
        *
        * \fn getChar
        * \brief Get the data of type char asking
        * @param key Key associated to the data adding
        * @return Return the specific data of type char determined by the key
        *
        */
        char        getChar(std::string const& key) const;

        /**
        *
        * \fn getLong
        * \brief Get the data of type long asking
        * @param key Key associated to the data adding
        * @return Return the specific data of type long determined by the key
        *
        */
        long        getLong(std::string const& key) const;

        /**
        *
        * \fn getStr
        * \brief Get the data of type string asking
        * @param key Key associated to the data adding
        * @return Return the specific data of type string determined by the key
        *
        */
        std::string &getStr(std::string const& key) const;

        /**
        *
        * \fn getFloat
        * \brief Get the data of type float asking
        * @param key Key associated to the data adding
        * @return Return the specific data of type float determined by the key
        *
        */
        float       getFloat(std::string const& key) const;

        /**
        *
        * \fn getDouble
        * \brief Get the data of type double asking
        * @param key Key associated to the data adding
        * @return Return the specific data of type double determined by the key
        *
        */
        double      getDouble(std::string const& key) const;
    };
}

#endif //EXISTENZIA_ADATASTORE_HPP
