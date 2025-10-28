#ifndef RECOVERYSESSION_HPP
#define RECOVERYSESSION_HPP

#include <string>
#include <iostream>

class RecoverySession {
private:
    std::string id;
    std::string date;
    std::string type;
    int durationMin;
    std::string notes;

public:
    RecoverySession(const std::string& id, const std::string& date, const std::string& type, int durationMin, const std::string& notes);
    void logCompletion();
    void getBenefits() const;
    void showSessionInfo() const;
    ~RecoverySession() = default;
};

#endif // RECOVERYSESSION_HPP