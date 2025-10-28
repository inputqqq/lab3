#include <iostream>
#include <vector>
#include "CommunityProfile.hpp"
#include "Challenge.hpp"
#include "Achievement.hpp"
#include "SleepTracker.hpp"
#include "HydrationTracker.hpp"
#include "Leaderboard.hpp"
#include "RecoverySession.hpp"
#include <windows.h>
#include <locale>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    std::locale::global(std::locale(""));
    std::cout << "=== Демонстрация работы классов ===\n\n";

    // 1. Статическая инициализация
    CommunityProfile profile1("u1", "FitGuru", "2024-06-15");
    profile1.addFriend("u2");
    profile1.awardBadge("Новичок");
    profile1.showProfileInfo();

    Challenge chall1("c1", "30 дней планки", "Ежедневно", 30);
    chall1.join("u1");
    chall1.showChallengeInfo();

    Achievement ach1("a1", "Марафонец", "10 тренировок", 100);
    ach1.showAchievementInfo();

    SleepTracker sleep1("u1");
    sleep1.logSleep(7.2);
    sleep1.showSleepStats();

    HydrationTracker water1("u1", 2000);
    water1.addDrink(500);
    water1.addDrink(800);
    water1.showHydrationInfo();

    Leaderboard lb1("lb1", "неделя");
    lb1.addScore("u1", 850);
    lb1.addScore("u2", 920);
    lb1.showLeaderboard();

    RecoverySession sess1("s1", "2025-10-28", "йога", 25, "Отлично!");
    sess1.showSessionInfo();
    sess1.getBenefits();
    sess1.logCompletion();

    // 2. Динамическая инициализация
    std::cout << "--- Динамические объекты ---\n";
    CommunityProfile* p2 = new CommunityProfile("u3", "Runner", "2024-08-01");
    p2->showProfileInfo();
    delete p2;

    Challenge* c2 = new Challenge("c2", "Бег 5 км", "За 30 мин", 7);
    c2->join("u3");
    c2->showChallengeInfo();
    delete c2;

    // 3. Работа с ссылками и указателями
    std::cout << "--- Ссылки и указатели ---\n";
    CommunityProfile p3("u4", "GymRat", "2024-09-01");
    CommunityProfile& ref = p3;
    CommunityProfile* ptr = &p3;
    ref.addFriend("u1");
    ptr->awardBadge("Железный");
    ptr->showProfileInfo();

    // 4. Динамический массив объектов
    std::cout << "--- Динамический массив объектов ---\n";
    const int N = 2;
    CommunityProfile* arr = new CommunityProfile[N]{
        CommunityProfile("u5", "Swimmer", "2024-10-01"),
        CommunityProfile("u6", "Cyclist", "2024-10-05")
    };
    for (int i = 0; i < N; ++i) {
        arr[i].showProfileInfo();
    }
    delete[] arr;

    // 5. Массив динамических объектов
    std::cout << "--- Массив динамических объектов ---\n";
    const int M = 2;
    Challenge** challs = new Challenge * [M];
    challs[0] = new Challenge("c3", "Планка 2 мин", "Удержать", 1);
    challs[1] = new Challenge("c4", "100 приседаний", "За день", 1);
    for (int i = 0; i < M; ++i) {
        challs[i]->showChallengeInfo();
        delete challs[i];
    }
    delete[] challs;
    return 0;
}