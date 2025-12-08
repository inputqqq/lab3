#include "HydrationTracker.hpp"
#include <iostream>
#include <numeric>


HydrationTracker::HydrationTracker() :  dailyGoalMl(2000) {}
HydrationTracker::HydrationTracker(const std::string& uid, int goal) :  dailyGoalMl(goal) {}
HydrationTracker::HydrationTracker(const HydrationTracker& other) :  dailyGoalMl(other.dailyGoalMl), logs(other.logs) {}


HydrationTracker HydrationTracker::createHydrationTracker(const std::string& uid, int goalMl) {
	return HydrationTracker(uid, goalMl);
}


void HydrationTracker::addDrink(int amountMl) {
	// feature: throw exception on invalid input
	if (amountMl <= 0) {
		throw std::invalid_argument("amountMl must be positive");
	}
	logs.push_back(amountMl); // std::string not needed here
}


double HydrationTracker::progressToday() const {
	int total = std::accumulate(logs.begin(), logs.end(), 0);
	if (dailyGoalMl == 0) return 0.0;
	return static_cast<double>(total) / dailyGoalMl * 100.0;
}


void HydrationTracker::showHydrationInfo() const {
	int total = std::accumulate(logs.begin(), logs.end(), 0);
	std::cout << " Daily goal: " << dailyGoalMl << " ml"
		<< " Total consumed: " << total << " ml"
		<< " Progress: " << progressToday() << "%";
}