#include "Leaderboard.hpp"

Leaderboard::Leaderboard(const std::string& id, const std::string& period)
    : id(id), period(period) {
}

void Leaderboard::addScore(const std::string& userId, int points) {
    scores.push_back({ userId, points });
}

void Leaderboard::showLeaderboard() const {
    std::cout << "=== –ейтинг (" << period << ") ===\n";
    for (size_t i = 0; i < scores.size(); ++i) {
        std::cout << (i + 1) << ". " << scores[i].first << " Ч " << scores[i].second << " очков\n";
    }
    std::cout << "\n";
}