#include "SleepTracker.hpp"

SleepTracker::SleepTracker(const std::string& userId) : userId(userId) {}

void SleepTracker::logSleep(double hours) {
    lastLoggedHours = hours;
}

double SleepTracker::averageSleep(int) const {
    return lastLoggedHours; // заглушка
}

void SleepTracker::showSleepStats() const {
    std::cout << "=== Сон (" << userId << ") ===\n";
    std::cout << "Последняя запись: " << lastLoggedHours << " ч\n";
    std::cout << "Среднее (заглушка): " << lastLoggedHours << " ч\n\n";
}