//
// Created by thekinrar on 19/09/2020.
//

#ifndef SPICYGOAT_PACKETENTITYMOVE_H
#define SPICYGOAT_PACKETENTITYMOVE_H


#include "../../ClientBoundPacket.h"
#include "../../../../world/geo/Location.h"

class PacketEntityMove : public ClientBoundPacket {
public:
    PacketEntityMove(int32_t eid, double dx, double dy, double dz, bool onGround);

    std::vector<std::byte> bytes() override;

    std::string toString() const override;

private:
    int32_t eid;
    double dx, dy, dz;
    bool onGround;
};


#endif //SPICYGOAT_PACKETENTITYMOVE_H
