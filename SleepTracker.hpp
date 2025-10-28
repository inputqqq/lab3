#ifndef SLEEPTRACKER_HPP
#define SLEEPTRACKER_HPP

#include <string>
#include <iostream>

class SleepTracker {
private:
    std::string userId;
    double lastLoggedHours = 0.0;

public:
    SleepTracker(const std::string& userId);
    void logSleep(double hours);
    double averageSleep(int days) const;
    void showSleepStats() const;
    ~SleepTracker() = default;
};

#endif // SLEEPTRACKER_HPP