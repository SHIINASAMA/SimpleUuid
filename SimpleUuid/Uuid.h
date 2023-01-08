#pragma once

#include <cstdint>

namespace uuid {
    class Uuid;
}

class uuid::Uuid {
public:
    Uuid() noexcept = default;
    Uuid(uint8_t selfId, uint64_t timestamp, uint8_t r = 0) noexcept;

    [[nodiscard]] uint8_t getSelfId() const noexcept;
    void setSelfId(uint8_t selfId) noexcept;
    [[nodiscard]] uint8_t getR() const noexcept;
    void setR(uint8_t r) noexcept;
    [[nodiscard]] uint64_t getTimestamp() const noexcept;
    void setTimestamp(uint64_t timestamp) noexcept;

    [[nodiscard]] uint64_t toNumber() const noexcept;
    void parse(uint64_t number) noexcept;

protected:
    uint8_t selfId = 0;
    uint8_t r = 0;
    uint64_t timestamp = 0;
};