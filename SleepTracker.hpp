#ifndef SLEEPTRACKER_HPP
#define SLEEPTRACKER_HPP


#include <string>
#include <vector>
#include <numeric>
#include <iostream>


// Demonstrate inheritance: BaseTracker -> SleepTracker
class BaseTracker {
protected:
	std::string userId;
public:
	BaseTracker() = default;
	explicit BaseTracker(const std::string& uid) : userId(uid) {}
	virtual ~BaseTracker() = default;
};


class SleepTracker : public BaseTracker {
public:
	std::vector<int> sleepRecords;


	SleepTracker();
	explicit SleepTracker(const std::string& uid); // calls base ctor (feature)
	SleepTracker(const SleepTracker& other); // copy ctor
	~SleepTracker() = default;


	static SleepTracker createSleepTracker(const std::string& userId);
	void logSleep(int hours);
	double averageSleep(size_t days) const;
	void showSleepStats() const;
};


#endif // SLEEPTRACKER_HPP