//
// Created by Pierre Bougon on 20/11/17.
//

#include "http/Message.hpp"

xzia::Message::Message(xzia::Client client) : client(client)
{

}

bool xzia::Message::hasBody() const
{
    return !body.empty();
}

