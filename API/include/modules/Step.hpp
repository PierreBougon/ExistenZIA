//
// Created by Pierre Bougon on 20/11/17.
//

#ifndef ZIA_STEP_HPP_
#define ZIA_STEP_HPP_

/**
 * \file Step.hpp
 * \brief
 * \author Mathieu.S
 * \version 0.2
 * \date 10 December 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \enum Step Step.hpp Step.hpp
 *
 */
namespace xzia
{
    enum class Step : unsigned char
    {
        Continue = 0,
        Stop,
        Error
    };
}

#endif // !ZIA_STEP_HPP_
