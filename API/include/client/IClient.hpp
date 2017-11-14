//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ICLIENT_HPP
#define EXISTENZIA_ICLIENT_HPP

/**
 * \file IClient.hpp
 * \brief
 * \author Benjamin.D
 * \version 0.1
 * \date 13 novembre 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \class IClient IClient.hpp IClient.hpp
 * \class IRequest IRequest.hpp IRequest.hpp
 * \class IResponse IResponse.hpp IResponse.hpp
 *
 */
namespace xzia {
    class IRequest;
    class IResponse;

    class IClient {

        /**
         *
         * \fn pushRequest
         * \brief
         * @param req Reference to a request
         *
         */
        virtual void pushRequest(IRequest &req) = 0;

        /**
         *
         * \fn getRequest
         * \brief Get the last request
         * @return Return a request of type IRequest
         *
         */
        virtual IRequest &getRequest() = 0;

        /**
         *
         * \fn getResponse
         * \brief Get the last response
         * @return Return a response of type IResponse
         *
         */
        virtual IResponse &getResponse() = 0;

        /**
         * \fn popRequest
         * \brief Remove the last request
         */
        virtual void popRequest() = 0;
    };
}

#endif //EXISTENZIA_ICLIENT_HPP
