// CommunityProfile.hpp
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Achievement.hpp"
#include "ProfileBase.hpp"

class CommunityProfile : public ProfileBase {
protected:
    // ƒемонстраци€ protected: производные классы могут обращатьс€ к этим пол€м
    std::vector<std::string> friends;
    std::vector<Achievement> badges;

public:
    std::string id;
    std::string nickname;
    std::string joinedDate;

    // ѕоле-указатель дл€ демонстрации поверхностного vs глубокого копировани€
    std::string* note;

    CommunityProfile();
    CommunityProfile(const std::string& id_, const std::string& nick_, const std::string& joined);
    // ѕо условию: реализован конструктор копировани€
    CommunityProfile(const CommunityProfile& other);
    // ћожно запретить оператор копировани€ при необходимости, но тут демонстрируем копирование
    CommunityProfile& operator=(const CommunityProfile& other);

    virtual ~CommunityProfile(); // нужен дл€ правильного удалени€ note

    static CommunityProfile createProfile(const std::string& id_, const std::string& nick_, const std::string& joined);

    void addFriend(const std::string& friendId);
    void awardBadge(const Achievement& badge);

    // ѕереопределение виртуальной функции из ProfileBase
    void showProfileInfo() const override;

    // ƒемонстраци€ operator+ (оставлено как пример)
    CommunityProfile operator+(const CommunityProfile& rhs) const;

    //  лонирование (шаблоны: shallow vs deep)
    ProfileBase* cloneShallow() const override; // поверхностное клонирование
    ProfileBase* cloneDeep() const override;    // глубокое клонирование

    friend std::ostream& operator<<(std::ostream& os, const CommunityProfile& p);
};
