#ifndef CHALLENGE_HPP
#define CHALLENGE_HPP


#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>


class Challenge {
public:
	std::string id;
	std::string title;
	std::string description;
	int durationDays{ 0 };
	std::vector<std::string> participants;
	std::unordered_map<std::string, double> progressMap;


	Challenge();
	Challenge(const std::string& id_, const std::string& t_, const std::string& desc_, int dur);
	Challenge(const Challenge& other);
	~Challenge() = default;


	static Challenge createChallenge(const std::string& id_, const std::string& t_, const std::string& desc_, int dur);
	void join(const std::string& userId);
	void setProgress(const std::string& userId, double value);
	double getProgress(const std::string& userId) const;
	void showChallengeInfo() const;


	// operator overload: add participants from another challenge
	Challenge& operator+=(const Challenge& rhs);


	// friend to print
	friend std::ostream& operator<<(std::ostream& os, const Challenge& c);
};


#endif // CHALLENGE_HPP