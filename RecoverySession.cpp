#include "RecoverySession.hpp"

RecoverySession::RecoverySession(const std::string& id, const std::string& date, const std::string& type, int durationMin, const std::string& notes)
    : id(id), date(date), type(type), durationMin(durationMin), notes(notes) {
}

void RecoverySession::logCompletion() {
    std::cout << "Сессия '" << type << "' завершена.\n";
}

void RecoverySession::getBenefits() const {
    std::cout << "Польза от '" << type << "': восстановление тела и разума.\n";
}

void RecoverySession::showSessionInfo() const {
    std::cout << "=== Сессия ===\n";
    std::cout << "Тип: " << type << "\n";
    std::cout << "Дата: " << date << "\n";
    std::cout << "Длительность: " << durationMin << " мин\n";
    std::cout << "Заметки: " << notes << "\n\n";
}