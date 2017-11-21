//
// Created by Pierre Bougon on 21/11/17.
//

#ifndef ZIA_THREADSTATE_HPP_
#define ZIA_THREADSTATE_HPP_

namespace xzia
{
    enum class ThreadState : unsigned char
    {
        working,
        sleeping
    };
}

#endif // !ZIA_THREADSTATE_HPP_
