#ifndef HYDRATIONTRACKER_HPP
#define HYDRATIONTRACKER_HPP


#include <string>
#include <vector>


class HydrationTracker{
public:
	int dailyGoalMl{ 2000 };
	std::vector<int> logs; // store amounts (ml)


	HydrationTracker();
	HydrationTracker(const std::string& uid, int goal);
	HydrationTracker(const HydrationTracker& other);
	~HydrationTracker() = default;


	static HydrationTracker createHydrationTracker(const std::string& uid, int goalMl);


	// throws if amount negative (feature: exceptions)
	void addDrink(int amountMl);


	double progressToday() const;
	void showHydrationInfo() const;
};


#endif // HYDRATIONTRACKER_HPP