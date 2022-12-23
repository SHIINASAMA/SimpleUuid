#include "uuid/TimestampHandler.h"
#include "uuid/Uuid.h"

#include <iostream>

void test_chrono();

void test_timestamp_handler();

void test_uuid();

int main() {
    test_chrono();
    test_timestamp_handler();
    test_uuid();
    return 0;
}

void test_chrono() {
    std::time_t tm;
    std::time(&tm);
    std::cout << "std::time_t -> " << tm << "\n";

    auto point1 = std::chrono::high_resolution_clock::now();
    std::cout << "std::chrono::high_resolution_clock -> " << point1.time_since_epoch().count() << "\n";

    auto point2 = std::chrono::system_clock::now();
    std::cout << "std::chrono::system_clock -> " << point2.time_since_epoch().count() << "\n";

    auto point3 = std::chrono::steady_clock::now();
    std::cout << "std::chrono::steady_clock -> " << point3.time_since_epoch().count() << "\n";
}

/// \note 此处仅简单的调用一下接口。若要复现在时间回拨时的处理，需要另外编写测试程序，并且手动使操作系统时间回拨，其他基于 TimestampHandler 的功能同理
void test_timestamp_handler() {
    uuid::TimestampHandler timestampHandler(std::chrono::system_clock::now());

    auto p1 = timestampHandler.getCurrentTimestamp();
    auto p2 = timestampHandler.tryGetCurrentTimestamp();

    std::cout << "p1 -> " << p1 << "\n";
    std::cout << "p2 -> " << p2 << "\n";
}

void test_uuid() {
    uint8_t selfId = 0x23;
    uuid::TimestampHandler timestampHandler(std::chrono::system_clock::now());

    auto uuid0 = uuid::Uuid(selfId, timestampHandler.getCurrentTimestamp(), 0x45);
    auto number = uuid0.toNumber();

    auto uuid1 = uuid::Uuid();
    uuid1.parse(number);
    std::cout << "uuid0.selfId -> " << uuid0.getSelfId() << "\n";
    std::cout << "uuid1.selfId -> " << uuid1.getSelfId() << "\n";
    std::cout << "uuid0.r -> " << uuid0.getR() << "\n";
    std::cout << "uuid1.r -> " << uuid1.getR() << "\n";
    std::cout << "uuid0.timestamp -> " << uuid0.getTimestamp() << "\n";
    std::cout << "uuid1.timestamp -> " << uuid1.getTimestamp() << "\n";
}