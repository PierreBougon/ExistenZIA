//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ICLIENT_HPP
#define EXISTENZIA_ICLIENT_HPP

namespace xzia {
    class IRequest;
    class IResponse;

    class IClient {
        virtual void pushRequest(IRequest &req) = 0;
        virtual IRequest &getRequest() = 0;
        virtual IResponse &getResponse() = 0;
        virtual void popRequest() = 0;
    };
}

#endif //EXISTENZIA_ICLIENT_HPP
