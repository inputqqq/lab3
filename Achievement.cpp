#include "Achievement.hpp"


Achievement::Achievement() = default;


Achievement::Achievement(const std::string& id_, const std::string& name_, const std::string& criteria_, int points)
	: id(id_), name(name_), criteria(criteria_), rewardPoints(points) {
}


// Copy constructor demonstration
Achievement::Achievement(const Achievement& other)
	: id(other.id), name(other.name), criteria(other.criteria), rewardPoints(other.rewardPoints) {
}


Achievement Achievement::createAchievement(const std::string& id_, const std::string& name_, const std::string& criteria_, int points) {
	return Achievement(id_, name_, criteria_, points);
}


bool Achievement::checkEligibility() const {
	// placeholder logic
	return rewardPoints > 0;
}


void Achievement::showAchievementInfo() const {
	std::cout << "Achievement: " << name << " (" << id << ") - " << criteria << ", " << rewardPoints << " pts";
}


bool Achievement::operator==(const Achievement& rhs) const {
	return id == rhs.id && name == rhs.name && rewardPoints == rhs.rewardPoints;
}


bool Achievement::operator!=(const Achievement& rhs) const {
	return !(*this == rhs);
}


std::ostream& operator<<(std::ostream& os, const Achievement& a) {
	os << a.name << "(" << a.id << ")";
	return os;
}