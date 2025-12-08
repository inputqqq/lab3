#include "CommunityProfile.hpp"


CommunityProfile::CommunityProfile() = default;
CommunityProfile::CommunityProfile(const std::string& id_, const std::string& nick_, const std::string& joined)
	: id(id_), nickname(nick_), joinedDate(joined) {
}


CommunityProfile::CommunityProfile(const CommunityProfile& other)
	: id(other.id), nickname(other.nickname), joinedDate(other.joinedDate), friends(other.friends), badges(other.badges) {
}


CommunityProfile CommunityProfile::createProfile(const std::string& id_, const std::string& nick_, const std::string& joined) {
	return CommunityProfile(id_, nick_, joined);
}


void CommunityProfile::addFriend(const std::string& friendId) {
	friends.push_back(friendId);
}


void CommunityProfile::awardBadge(const Achievement& badge) {
	badges.push_back(badge);
}


void CommunityProfile::showProfileInfo() const {
	std::cout << "Profile: " << nickname << " (" << id << ")"
		<< " Joined: " << joinedDate << ""
		<< " Friends: " << friends.size() << " Badges: " << badges.size() << "";
}


// Example operator+: combines nicknames with '+' (toy example demonstrating operator overloading)
CommunityProfile CommunityProfile::operator+(const CommunityProfile& rhs) const {
	CommunityProfile res;
	res.id = this->id + "+" + rhs.id;
	res.nickname = this->nickname + "+" + rhs.nickname; // string concat (feature: std::string usage)
	res.joinedDate = this->joinedDate; // preserve left date
	return res;
}


std::ostream& operator<<(std::ostream& os, const CommunityProfile& p) {
	os << p.nickname << "(" << p.id << ")";
	return os;
}