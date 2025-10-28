#ifndef ACHIEVEMENT_HPP
#define ACHIEVEMENT_HPP

#include <string>
#include <iostream>

class Achievement {
private:
    std::string id;
    std::string name;
    std::string criteria;
    int rewardPoints;

public:
    Achievement(const std::string& id, const std::string& name, const std::string& criteria, int rewardPoints);
    bool checkEligibility(const std::string& user) const;
    void showAchievementInfo() const;
    ~Achievement() = default;
};

#endif // ACHIEVEMENT_HPP