//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_IRESPONSE_HPP
#define EXISTENZIA_IRESPONSE_HPP

#include "IMessage.hpp"

namespace xzia {
    class IResponse : IMessage {
    public:
        virtual bool            hasBody() = 0;
        virtual std::string     &getBody() = 0;
        virtual void            setBody(std::string const &string) = 0;

        virtual std::string     &getHeader() = 0;
        virtual void            setHeader(std::string const &string) = 0;

        virtual void            setCode(std::string const&) = 0;
        virtual std::string     &getCode() const = 0;
    };
}

#endif //EXISTENZIA_IRESPONSE_HPP
