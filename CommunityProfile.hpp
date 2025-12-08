#ifndef COMMUNITYPROFILE_HPP
#define COMMUNITYPROFILE_HPP


#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "Achievement.hpp"


class CommunityProfile {
public:
	std::string id;
	std::string nickname;
	std::string joinedDate;
	std::vector<std::string> friends; // store friend ids
	std::vector<Achievement> badges;


	CommunityProfile();
	CommunityProfile(const std::string& id_, const std::string& nick_, const std::string& joined);
	// Copy constructor (feature)
	CommunityProfile(const CommunityProfile& other);
	~CommunityProfile() = default;


	static CommunityProfile createProfile(const std::string& id_, const std::string& nick_, const std::string& joined);
	void addFriend(const std::string& friendId);
	void awardBadge(const Achievement& badge);
	void showProfileInfo() const;


	// operator overload: concatenate nicknames (example)
	CommunityProfile operator+(const CommunityProfile& rhs) const; // returns a combined profile (demo only)


	// friend output
	friend std::ostream& operator<<(std::ostream& os, const CommunityProfile& p);
};


#endif // COMMUNITYPROFILE_HPP