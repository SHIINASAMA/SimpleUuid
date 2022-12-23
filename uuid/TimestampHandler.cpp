#include "TimestampHandler.h"

uuid::TimestampHandler::TimestampHandler(std::chrono::system_clock::time_point point) noexcept {
    latest = point;
}

uint64_t uuid::TimestampHandler::getCurrentTimestamp() noexcept {
    latest = std::chrono::system_clock::now();
    return latest.time_since_epoch().count();
}

uint64_t uuid::TimestampHandler::tryGetCurrentTimestamp() noexcept {
    auto newPoint = std::chrono::system_clock::now();
    if (newPoint > latest) {
        latest = newPoint;
        return newPoint.time_since_epoch().count();
    } else {
        if (latest - newPoint > std::chrono::seconds(5)) {
            return UINT64_MAX;
        } else {
            return 0;
        }
    }
}