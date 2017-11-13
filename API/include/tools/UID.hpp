//
// Created by Pierre Bougon on 13/11/17.
//

#ifndef ZIA_UID_HPP_
#define ZIA_UID_HPP_

namespace xzia
{
    struct uid
    {
    public:
        static uid generateUID();

        int id;
    };
}

#endif // !ZIA_UID_HPP_
