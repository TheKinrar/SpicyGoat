//
// Created by thekinrar on 31/03/19.
//

#include <stdexcept>
#include "ServerBoundPacket.h"

std::vector<std::byte> ServerBoundPacket::bytes() {
    throw std::runtime_error("Called bytes() on server-bound packet");
}

ServerBoundPacket::ServerBoundPacket(int id) : Packet(id) {}

ServerBoundPacket::ServerBoundPacket() : Packet(-1) {}
