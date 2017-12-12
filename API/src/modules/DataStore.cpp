#include "modules/DataStore.hpp"

bool xzia::DataStore::hasData(const std::string &key) const {
    return (datas.find(key) != datas.cend());
}
