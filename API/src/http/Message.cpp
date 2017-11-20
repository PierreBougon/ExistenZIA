//
// Created by Pierre Bougon on 20/11/17.
//

#include "http/Message.hpp"

bool xzia::Message::hasBody()
{
    return !body.empty();
}
