//
// Created by thekinrar on 19/09/2020.
//

#include "PacketEntityLook.h"

PacketEntityLook::PacketEntityLook(int32_t eid, Location &from, Location &to, bool onGround) : ClientBoundPacket(0x29), eid(eid), from(from), to(to), onGround(onGround) {}

std::vector<std::byte> PacketEntityLook::bytes() {
    std::vector<std::byte> array;
    PacketData::writeVarInt(0x29, array);
    PacketData::writeVarInt(eid, array);
    PacketData::writeByte(to.getYaw(), array);
    PacketData::writeByte(to.getPitch(), array);
    PacketData::writeBoolean(onGround, array);
    return array;
}

std::string PacketEntityLook::toString() const {
    return std::string("PacketEntityLook{eid=") + std::to_string(eid) + ",...}";
}
