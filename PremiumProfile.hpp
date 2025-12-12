// PremiumProfile.hpp
#pragma once
#include "CommunityProfile.hpp"
#include <string>

class PremiumProfile : public CommunityProfile {
public:
    std::string subscriptionLevel;

    // ¬ызов конструктора базового класса из конструктора производного (feature)
    PremiumProfile(const std::string& id_, const std::string& nick_, const std::string& joined, const std::string& level)
        : CommunityProfile(id_, nick_, joined), subscriptionLevel(level) {
        // комментарий: вызов конструктора базового выполнен в списке инициализации
    }

    PremiumProfile(const PremiumProfile& other)
        : CommunityProfile(other), subscriptionLevel(other.subscriptionLevel) {
        // демонстраци€ вызова конструктора базового в copy ctor
    }

    ~PremiumProfile() = default;

    // ѕереопределение виртуального метода (вариант с вызовом базового)
    void showProfileInfo() const override {
        // можно сначала вызвать базовый метод, а затем добавить дополнительную информацию
        CommunityProfile::showProfileInfo(); // €вный вызов базового метода
        std::cout << "  Subscription: " << subscriptionLevel << "\n";
    }

    // ѕерегрузка оператора присваивани€: присвоение базового в производный
    PremiumProfile& operator=(const CommunityProfile& base) {
        // копируем пол€ из базового класса
        this->id = base.id;
        this->nickname = base.nickname;
        this->joinedDate = base.joinedDate;
        // friends и badges protected Ч можем обращатьс€ (feature: protected)

        // note Ч сделаем глубокую копию, если base.note существует
        if (this->note) delete this->note;
        this->note = base.note ? new std::string(*(base.note)) : nullptr;
        // subscriptionLevel оставл€ем прежним (или присвоим дефолт)
        return *this;
    }
};
