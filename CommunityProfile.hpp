#ifndef COMMUNITYPROFILE_HPP
#define COMMUNITYPROFILE_HPP

#include <string>
#include <vector>
#include <iostream>

class CommunityProfile {
private:
    std::string id;
    std::string nickname;
    std::string joinedDate; // строка вместо std::tm
    std::vector<std::string> friends;
    std::vector<std::string> badges;

public:
    CommunityProfile(const std::string& id, const std::string& nickname, const std::string& joinedDate);
    void addFriend(const std::string& friendId);
    void awardBadge(const std::string& badge);
    void showProfileInfo() const;
    ~CommunityProfile() = default;
};

#endif // COMMUNITYPROFILE_HPP