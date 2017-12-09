//
// Created by Pierre Bougon on 21/11/17.
//

#ifndef ZIA_THREADSTATE_HPP_
#define ZIA_THREADSTATE_HPP_

/**
 * \file ThreadState.hpp
 * \brief
 * \author Benjamin.D
 * \version 0.2
 * \date 10 December 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \enum ThreadState ThreadState.hpp ThreadState.hpp
 *
 */
namespace xzia
{
    enum class ThreadState : unsigned char
    {
        working,
        sleeping
    };
}

#endif // !ZIA_THREADSTATE_HPP_
