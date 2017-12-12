#ifndef EXISTENZIA_CORE_HPP
#define EXISTENZIA_CORE_HPP

#include "core/ACore.hpp"

namespace xzia {
    class BasicCore : public ACore {
    public:
        BasicCore(const std::string &config);

        void run() override;
    };
}

#endif //EXISTENZIA_CORE_HPP
