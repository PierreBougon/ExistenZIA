//
// Created by Pierre Bougon on 21/11/17.
//

#ifndef ZIA_IDATASTORE_HPP_
#define ZIA_IDATASTORE_HPP_

#include <string>

namespace xzia
{
    class IDataStore
    {
        /**
         *
         * \fn addInt
         * \brief Add data of type int
         * @param i Data of type int
         * @param key Key associated to the data adding
         *
         */
        template <typename T>
        virtual void        addData(T data, std::string const& key) = 0;

        /**
         *
         * \addChar
         * \brief Add data of type char
         * @param c Data of type char
         * @param key Key associated to the data adding
         *
         */
        template <typename T>
        virtual T        getData(std::string const& key) = 0;

    };
}

#endif // !ZIA_IDATASTORE_HPP_
