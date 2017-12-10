//
// Created by Pierre Bougon on 20/11/17.
//

#ifndef ZIA_STEP_HPP_
#define ZIA_STEP_HPP_

/**
 * \file Step.hpp
 * \brief Used to see the step of ATask
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
    /**
     * \enum Step
     *  Continue :proceed to next module or send back response if the end of the ATask execution list is reached
     *  Stop : stop here and send back response
     *  Error : error occurred, send server error response
     */
    enum class Step : unsigned char
    {
        Continue = 0,
        Stop,
        Error
    };
}

#endif // !ZIA_STEP_HPP_
