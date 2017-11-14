//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ADATASTORE_HPP
#define EXISTENZIA_ADATASTORE_HPP

#include <iostream>
#include <vector>

namespace xzia {
    namespace data {
        enum class DataType : unsigned char{
            CHAR,
            INT,
            FLOAT,
            LONG,
            DOUBLE,
            STRING
        };

        union DataValue {
            char        c;
            int         i;
            float       f;
            long        l;
            double      d;
            std::string s;
        };

        struct Data {
            DataType    type;
            DataValue   value;
        };

        class ADataStore {
        protected:
            std::vector<Data> datas;
        public:
            void        addInt(int i);
            void        addChar(char c);
            void        addLong(long l);
            void        addStr(std::string const &s);
            void        addFloat(float f);
            void        addDouble(double d);
            int         getInt() const;
            char        getChar() const;
            long        getLong() const;
            std::string &getStr() const;
            float       getFloat() const;
            double      getDouble() const;
        };
    }
}

#endif //EXISTENZIA_ADATASTORE_HPP
