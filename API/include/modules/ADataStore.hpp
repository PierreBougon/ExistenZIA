//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ADATASTORE_HPP
#define EXISTENZIA_ADATASTORE_HPP

#include <map>
#include <boost/variant/variant.hpp>
#include "IDataStore.hpp"

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
    using variant = boost::variant<char, int, float, long, double, std::string>

    class ADataStore : public IDataStore
    {
    protected:
        std::map<std::string, variant> datas;
    };
}

#endif //EXISTENZIA_ADATASTORE_HPP
