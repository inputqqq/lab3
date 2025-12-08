#ifndef RECOVERYSESSION_HPP
#define RECOVERYSESSION_HPP


#include <string>
#include <iostream>


class RecoverySession {
public:
	std::string id;
	std::string date;
	std::string type;
	int durationMin{ 0 };
	std::string notes;


	RecoverySession();
	RecoverySession(const std::string& id_, const std::string& date_, const std::string& type_, int dur, const std::string& notes_);
	RecoverySession(const RecoverySession& other);
	~RecoverySession() = default;


	static RecoverySession createSession(const std::string& id_, const std::string& date_, const std::string& type_, int dur, const std::string& notes_);
	void logCompletion() const;
	std::string getBenefits() const;
	void showSessionInfo() const;


	// operator overload: comparison by duration
	bool operator<(const RecoverySession& rhs) const;
};


#endif // RECOVERYSESSION_HPP