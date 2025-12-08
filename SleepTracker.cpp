#include "SleepTracker.hpp"


SleepTracker::SleepTracker() = default;
SleepTracker::SleepTracker(const std::string& uid) : BaseTracker(uid) {}


SleepTracker::SleepTracker(const SleepTracker& other) : BaseTracker(other.userId), sleepRecords(other.sleepRecords) {}


SleepTracker SleepTracker::createSleepTracker(const std::string& userId) {
	return SleepTracker(userId);
}


void SleepTracker::logSleep(int hours) {
	sleepRecords.push_back(hours);
}


double SleepTracker::averageSleep(size_t days) const {
	if (sleepRecords.empty()) return 0.0;
	size_t take = std::min(days, sleepRecords.size());
	double sum = 0.0;
	for (size_t i = sleepRecords.size() - take; i < sleepRecords.size(); ++i) sum += sleepRecords[i];
	return sum / static_cast<double>(take);
}


void SleepTracker::showSleepStats() const {
	std::cout << "Sleep stats for " << userId << ":";
		for (auto it = sleepRecords.rbegin(); it != sleepRecords.rend() && it - sleepRecords.rbegin() < 5; ++it) {
			std::cout << " " << *it << " h";
		}
	std::cout << " Average (last up to 7 days): " << averageSleep(7) << " h";
}