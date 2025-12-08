#include "Leaderboard.hpp"


// initialize static member
int Leaderboard::totalLeaderboards = 0;


Leaderboard::Leaderboard() { ++totalLeaderboards; }
Leaderboard::Leaderboard(const std::string& id_, const std::string& period_) : id(id_), period(period_) { ++totalLeaderboards; }


Leaderboard::Leaderboard(const Leaderboard& other) : id(other.id), period(other.period), scores(other.scores) { ++totalLeaderboards; }


Leaderboard Leaderboard::createLeaderboard(const std::string& id_, const std::string& period_) {
	return Leaderboard(id_, period_);
}


void Leaderboard::addScore(const std::string& userId, int points) {
	// accumulate points if exists
	for (auto& p : scores) {
		if (p.first == userId) { p.second += points; return; }
	}
	scores.emplace_back(userId, points);
}


std::vector<std::pair<std::string, int>> Leaderboard::top(size_t n) const {
	auto copy = scores;
	std::sort(copy.begin(), copy.end(), [](auto& a, auto& b) { return a.second > b.second; });
	if (n < copy.size()) copy.resize(n);
	return copy;
}


void Leaderboard::showLeaderboard() const {
	std::cout << "Leaderboard (" << period << "):";
		auto t = top(scores.size());
	size_t place = 1;
	for (const auto& p : t) {
		std::cout << " " << place++ << ". " << p.first << " - " << p.second << "";
	}
}


int Leaderboard::GetTotalLeaderboards() { return totalLeaderboards; }


Leaderboard& Leaderboard::operator+=(const std::pair<std::string, int>& p) {
	addScore(p.first, p.second);
	return *this;
}


std::pair<std::string, int> Leaderboard::operator[](size_t idx) const {
	if (idx >= scores.size()) throw std::out_of_range("Leaderboard index out of range");
	return scores[idx];
}