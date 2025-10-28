#ifndef HYDRATIONTRACKER_HPP
#define HYDRATIONTRACKER_HPP

#include <string>
#include <iostream>

class HydrationTracker {
private:
    std::string userId;
    double dailyGoalMl;
    double todayTotalMl = 0.0;

public:
    HydrationTracker(const std::string& userId, double dailyGoalMl);
    void addDrink(double amountMl);
    double progressToday() const;
    void showHydrationInfo() const;
    ~HydrationTracker() = default;
};

#endif // HYDRATIONTRACKER_HPP