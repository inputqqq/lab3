#ifndef ACHIEVEMENT_HPP
#define ACHIEVEMENT_HPP


#include <string>
#include <iostream>


class Achievement {
public:
	std::string id;
	std::string name;
	std::string criteria;
	int rewardPoints{ 0 };


	Achievement();
	Achievement(const std::string& id_, const std::string& name_, const std::string& criteria_, int points);
	// Copy constructor (feature)
	Achievement(const Achievement& other);
	~Achievement() = default;


	static Achievement createAchievement(const std::string& id_, const std::string& name_, const std::string& criteria_, int points);
	bool checkEligibility() const; // stub
	void showAchievementInfo() const;


	// Operator overload: equality
	bool operator==(const Achievement& rhs) const;
	bool operator!=(const Achievement& rhs) const;


	// Friend function to stream print (example of friend function)
	friend std::ostream& operator<<(std::ostream& os, const Achievement& a);
};


#endif // ACHIEVEMENT_HPP