#include "RecoverySession.hpp"


RecoverySession::RecoverySession() = default;


RecoverySession::RecoverySession(const std::string& id_, const std::string& date_, const std::string& type_, int dur, const std::string& notes_)
	: id(id_), date(date_), type(type_), durationMin(dur), notes(notes_) {
}


RecoverySession::RecoverySession(const RecoverySession& other)
	: id(other.id), date(other.date), type(other.type), durationMin(other.durationMin), notes(other.notes) {
}


RecoverySession RecoverySession::createSession(const std::string& id_, const std::string& date_, const std::string& type_, int dur, const std::string& notes_) {
	return RecoverySession(id_, date_, type_, dur, notes_);
}


void RecoverySession::logCompletion() const {
	std::cout << "Session " << id << " completed: " << type << " for " << durationMin << " min";
}


std::string RecoverySession::getBenefits() const {
	if (type == "sleep" || type == "Sleep") return "Restores energy and aids recovery.";
	if (type == "yoga" || type == "Yoga") return "Improves flexibility and reduces stress.";
	if (type == "meditation" || type == "Meditation") return "Reduces stress and improves focus.";
	return "General recovery benefits.";
}


void RecoverySession::showSessionInfo() const {
	std::cout << "Recovery session: " << type << " on " << date << ", duration " << durationMin << " min"
		<< " Notes: " << notes << "";
}


bool RecoverySession::operator<(const RecoverySession& rhs) const {
	return durationMin < rhs.durationMin;
}