#ifndef LEADERBOARD_HPP
#define LEADERBOARD_HPP

#include <string>
#include <vector>
#include <iostream>

class Leaderboard {
private:
    std::string id;
    std::string period;
    std::vector<std::pair<std::string, int>> scores;

public:
    Leaderboard(const std::string& id, const std::string& period);
    void addScore(const std::string& userId, int points);
    void showLeaderboard() const;
    ~Leaderboard() = default;
};

#endif // LEADERBOARD_HPP