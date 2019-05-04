//
// Created by thekinrar on 02/04/19.
//

#include <iostream>
#include "PacketChunkData.h"

PacketChunkData::PacketChunkData(ChunkColumn &chunkColumn) : chunkColumn(chunkColumn) {}

std::vector<std::byte> PacketChunkData::bytes() {
    std::vector<std::byte> array;
    PacketData::writeVarInt(0x21, array);
    PacketData::writeInt(chunkColumn.getX(), array);
    PacketData::writeInt(chunkColumn.getZ(), array);
    PacketData::writeBoolean(true, array); // full chunk

    std::vector<std::byte> data;
    uint16_t mask = chunkColumn.writeToByteArray(data);

    PacketData::writeVarInt(mask, array);
    chunkColumn.writeHeightMapsToByteArray(array);
    PacketData::writeVarInt(data.size(), array);
    PacketData::writeByteArray(data, array);

    PacketData::writeVarInt(0, array); // TODO: block entities
    return array;
}

std::string PacketChunkData::toString() const {
    return std::string("PacketChunkData{") + std::to_string(chunkColumn.getX()) + "," + std::to_string(chunkColumn.getZ()) + "}";
}
