//
// Created by Pierre Bougon on 10/12/17.
//

#include "http/Message.hpp"
#include "http/Response.hpp"
#include "client/Client.hpp"

xzia::Response::Response(xzia::Client client) : xzia::Message(client)
{
}
