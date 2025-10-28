#include "Achievement.hpp"

Achievement::Achievement(const std::string& id, const std::string& name, const std::string& criteria, int rewardPoints)
    : id(id), name(name), criteria(criteria), rewardPoints(rewardPoints) {
}

bool Achievement::checkEligibility(const std::string&) const {
    return true; 
}

void Achievement::showAchievementInfo() const {
    std::cout << "=== Достижение ===\n";
    std::cout << "Название: " << name << "\n";
    std::cout << "Условие: " << criteria << "\n";
    std::cout << "Очки: " << rewardPoints << "\n\n";
}