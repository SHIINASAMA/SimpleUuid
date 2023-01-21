#include "SimpleUuid/Uuid.h"

#ifdef WIN32
#pragma warning(disable : 4146)
#pragma warning(disable : 4244)
#endif

uuid::Uuid::Uuid(uint8_t selfId, uint64_t timestamp, uint8_t r) noexcept {
    this->selfId = selfId;
    this->timestamp = timestamp;
    this->r = r;
}

uint8_t uuid::Uuid::getSelfId() const noexcept {
    return selfId;
}

void uuid::Uuid::setSelfId(uint8_t selfId) noexcept {
    Uuid::selfId = selfId;
}

uint8_t uuid::Uuid::getR() const noexcept {
    return r;
}

void uuid::Uuid::setR(uint8_t r) noexcept {
    Uuid::r = r;
}

uint64_t uuid::Uuid::getTimestamp() const noexcept {
    return timestamp;
}

void uuid::Uuid::setTimestamp(uint64_t timestamp) noexcept {
    Uuid::timestamp = timestamp;
}

uint64_t uuid::Uuid::toNumber() const noexcept {
    return ((selfId & -1ULL) << 56) | ((r & -1ULL) << 48) | (timestamp & 0x00FF'FFFF'FFFF'FFFF);
}

void uuid::Uuid::parse(uint64_t number) noexcept {
    selfId = (number & 0xFF00'0000'0000'0000) >> 56;
    r = (number & 0x00FF'0000'0000'0000) >> 48;
    timestamp = number & 0x0000'FFFF'FFFF'FFFF;
}
