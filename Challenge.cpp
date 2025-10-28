#include "Challenge.hpp"

Challenge::Challenge(const std::string& id, const std::string& title, const std::string& description, int durationDays)
    : id(id), title(title), description(description), durationDays(durationDays) {
}

void Challenge::join(const std::string& userId) {
    participants.push_back(userId);
}

double Challenge::getProgress(const std::string&) const {
    return 65.0; // заглушка
}

void Challenge::showChallengeInfo() const {
    std::cout << "=== Челлендж ===\n";
    std::cout << "Название: " << title << "\n";
    std::cout << "Описание: " << description << "\n";
    std::cout << "Длительность: " << durationDays << " дней\n";
    std::cout << "Участников: " << participants.size() << "\n\n";
}