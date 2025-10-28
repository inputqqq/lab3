#include "CommunityProfile.hpp"

CommunityProfile::CommunityProfile(const std::string& id, const std::string& nickname, const std::string& joinedDate)
    : id(id), nickname(nickname), joinedDate(joinedDate) {
}

void CommunityProfile::addFriend(const std::string& friendId) {
    friends.push_back(friendId);
}

void CommunityProfile::awardBadge(const std::string& badge) {
    badges.push_back(badge);
}

void CommunityProfile::showProfileInfo() const {
    std::cout << "=== Профиль ===\n";
    std::cout << "ID: " << id << "\n";
    std::cout << "Ник: " << nickname << "\n";
    std::cout << "Регистрация: " << joinedDate << "\n";
    std::cout << "Друзей: " << friends.size() << ", Достижений: " << badges.size() << "\n\n";
}