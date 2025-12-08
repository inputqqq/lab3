#ifndef LEADERBOARD_HPP
#define LEADERBOARD_HPP


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


class Leaderboard {
public:
	std::string id;
	std::string period; // week / month
	std::vector<std::pair<std::string, int>> scores; // userId, points


	static int totalLeaderboards; // static field (feature)


	Leaderboard();
	Leaderboard(const std::string& id_, const std::string& period_);
	Leaderboard(const Leaderboard& other);
	~Leaderboard() = default;


	static Leaderboard createLeaderboard(const std::string& id_, const std::string& period_);
	void addScore(const std::string& userId, int points);
	std::vector<std::pair<std::string, int>> top(size_t n) const;
	void showLeaderboard() const;


	// static method (feature)
	static int GetTotalLeaderboards();


	// operator overload: += to add score pair
	Leaderboard& operator+=(const std::pair<std::string, int>& p);


	// operator[] to get points by index
	std::pair<std::string, int> operator[](size_t idx) const;
};


#endif // LEADERBOARD_HPP