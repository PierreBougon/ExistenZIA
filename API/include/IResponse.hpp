//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_IRESPONSE_HPP
#define EXISTENZIA_IRESPONSE_HPP

#include "IMessage.hpp"

namespace xzia {
    class IResponse : IMessage {
    public:
        bool hasBody() override = 0;

        std::string &getBody() override = 0;

        void setBody(std::string const &string) override = 0;

        std::string &getHeader() override = 0;

        void setHeader(std::string const &string) override = 0;

        virtual void setCode(std::string const &) = 0;

        virtual std::string &getCode() const = 0;
    };
}
#endif //EXISTENZIA_IRESPONSE_HPP
