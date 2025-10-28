#include "HydrationTracker.hpp"

HydrationTracker::HydrationTracker(const std::string& userId, double dailyGoalMl)
    : userId(userId), dailyGoalMl(dailyGoalMl) {
}

void HydrationTracker::addDrink(double amountMl) {
    todayTotalMl += amountMl;
}

double HydrationTracker::progressToday() const {
    return (todayTotalMl / dailyGoalMl) * 100.0;
}

void HydrationTracker::showHydrationInfo() const {
    std::cout << "=== Вода (" << userId << ") ===\n";
    std::cout << "Цель: " << dailyGoalMl << " мл\n";
    std::cout << "Выпито: " << todayTotalMl << " мл (" << static_cast<int>(progressToday()) << "%)\n\n";
}