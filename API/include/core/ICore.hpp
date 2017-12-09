#ifndef ZIA_ICORE_HPP_
#define ZIA_ICORE_HPP_

/**
 * \file ICore.hpp
 * \brief Interface of the main class of the API
 * \author Pierre.B
 * \version 0.1
 * \date 17 novembre 2017
 * \namespace xzia
 * \class ICore ICore.hpp ICore.hpp
 */
namespace xzia
{
    class ICore
    {
    public:

        /**
        *
        * \fn run
        * \brief This method run the core of this API. We can adapt this method for the type of request we want to implement
        *
        */
        virtual void run() = 0;
    };
}

#endif // !ZIA_ICORE_HPP_
