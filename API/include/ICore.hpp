//
// Created by Pierre Bougon on 31/10/17.
//

#ifndef CLIENTAI_ICORE_HPP_
#define CLIENTAI_ICORE_HPP_

namespace xzia
{
    enum Step {
        CONTINUE,
        STOP,
        ERROR
    };
    class ICore
    {
        virtual void run() = 0;
    };
}

#endif // !CLIENTAI_ICORE_HPP_
