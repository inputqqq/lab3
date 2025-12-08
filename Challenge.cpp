#include "Challenge.hpp"


Challenge::Challenge() : durationDays(0) {}
Challenge::Challenge(const std::string& id_, const std::string& t_, const std::string& desc_, int dur)
	: id(id_), title(t_), description(desc_), durationDays(dur) {
}


Challenge::Challenge(const Challenge& other)
	: id(other.id), title(other.title), description(other.description), durationDays(other.durationDays), participants(other.participants), progressMap(other.progressMap) {
}


Challenge Challenge::createChallenge(const std::string& id_, const std::string& t_, const std::string& desc_, int dur) {
	return Challenge(id_, t_, desc_, dur);
}


void Challenge::join(const std::string& userId) {
	participants.push_back(userId);
	progressMap[userId] = 0.0;
}


void Challenge::setProgress(const std::string& userId, double value) {
	progressMap[userId] = value;
}


double Challenge::getProgress(const std::string& userId) const {
	auto it = progressMap.find(userId);
	if (it != progressMap.end()) return it->second;
	return 0.0;
}


void Challenge::showChallengeInfo() const {
	std::cout << "Challenge: " << title << " (" << id << ")"
		<< " Description: " << description << ""
		<< " Duration: " << durationDays << " days"
		<< " Participants: " << participants.size() << "";
}


Challenge& Challenge::operator+=(const Challenge& rhs) {
	// combine participants (avoid duplicates simply)
	for (const auto& p : rhs.participants) {
		participants.push_back(p);
		progressMap[p] = rhs.progressMap.at(p);
	}
	return *this;
}


std::ostream& operator<<(std::ostream& os, const Challenge& c) {
	os << c.title << "(" << c.id << ")";
	return os;
}