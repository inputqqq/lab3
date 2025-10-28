#ifndef CHALLENGE_HPP
#define CHALLENGE_HPP

#include <string>
#include <vector>
#include <iostream>

class Challenge {
private:
    std::string id;
    std::string title;
    std::string description;
    int durationDays;
    std::vector<std::string> participants;

public:
    Challenge(const std::string& id, const std::string& title, const std::string& description, int durationDays);
    void join(const std::string& userId);
    double getProgress(const std::string& userId) const;
    void showChallengeInfo() const;
    ~Challenge() = default;
};

#endif // CHALLENGE_HPP