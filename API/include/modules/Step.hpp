//
// Created by Pierre Bougon on 20/11/17.
//

#ifndef ZIA_STEP_HPP_
#define ZIA_STEP_HPP_

namespace xzia
{
    /**
     * \enum Step
     */
    enum class Step : unsigned char
    {
        Continue = 0,
        Stop,
        Error
    };
}

#endif // !ZIA_STEP_HPP_
