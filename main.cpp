#include <iostream>

#include "CommunityProfile.hpp"
#include "Achievement.hpp"
#include "Challenge.hpp"
#include "Leaderboard.hpp"
#include "SleepTracker.hpp"
#include "HydrationTracker.hpp"
#include "RecoverySession.hpp"

int main() {

    std::cout << "=== Enhanced Fitness Community Demo ===\n\n";

    // --- STATIC and STACK objects ---
    std::cout << "[ COMMUNITY PROFILE — STATIC ]\n";
    CommunityProfile alice = CommunityProfile::createProfile("u1", "Alice", "2025-01-01");
    Achievement firstRun = Achievement::createAchievement("a1", "First Run", "Complete 1 run", 10);

    alice.awardBadge(firstRun);
    alice.addFriend("u2");
    alice.showProfileInfo();
    std::cout << "\n";


    // --- SMART POINTERS ---
    std::cout << "[ SMART POINTERS ]\n";

    std::unique_ptr<CommunityProfile> bob =
        std::make_unique<CommunityProfile>("u2", "Bob", "2025-02-10");

    std::shared_ptr<CommunityProfile> carol =
        std::make_shared<CommunityProfile>("u3", "Carol", "2025-03-03");

    bob->addFriend("u1");
    carol->addFriend("u1");

    bob->showProfileInfo();
    carol->showProfileInfo();

    std::shared_ptr<CommunityProfile> carolCopy = carol;

    std::cout << "carol use_count = " << carol.use_count() << "\n\n";


    // --- operator overloading examples ---
    std::cout << "[ OPERATOR OVERLOADING ]\n";

    Achievement a2 =
        Achievement::createAchievement("a2", "First Run", "Complete 1 run", 10);
    std::cout << "a2 == firstRun? " << (a2 == firstRun) << "\n";

    CommunityProfile combined = alice + *carol;
    std::cout << "Combined profile: " << combined << "\n\n";


    // --- Leaderboard (operator+=, operator[]) ---
    std::cout << "[ LEADERBOARD ]\n";

    Leaderboard lb = Leaderboard::createLeaderboard("lb1", "week");

    lb += { "u1", 100 };
    lb += { "u2", 120 };
    lb += { "u1", 50 };

    lb.showLeaderboard();

    try {
        auto pair = lb[0];
        std::cout << "Top entry: " << pair.first << " - " << pair.second << "\n";
    }
    catch (const std::exception& ex) {
        std::cout << "Leaderboard access error: " << ex.what() << "\n";
    }

    std::cout << "Total leaderboards: "
        << Leaderboard::GetTotalLeaderboards() << "\n\n";


    // --- Challenge merging (operator+=) ---
    std::cout << "[ CHALLENGES ]\n";

    Challenge c1 = Challenge::createChallenge("c1", "30-day plank",
        "Daily plank challenge", 30);
    c1.join("u1");

    Challenge c2 = Challenge::createChallenge("c2", "pushups week",
        "Do pushups", 7);
    c2.join("u2");

    c1 += c2;
    c1.showChallengeInfo();
    std::cout << "\n";


    // --- SLEEP TRACKING ---
    std::cout << "[ SLEEP TRACKING ]\n";

    SleepTracker sleepArray[2];
    sleepArray[0] = SleepTracker::createSleepTracker("u1");
    sleepArray[1] = SleepTracker::createSleepTracker("u2");

    sleepArray[0].logSleep(7);
    sleepArray[0].logSleep(8);

    sleepArray[1].logSleep(6);
    sleepArray[1].logSleep(7);

    std::cout << "User1 avg sleep: " << sleepArray[0].averageSleep(2) << "\n";

    std::unique_ptr<SleepTracker> dynSleep0 =
        std::make_unique<SleepTracker>(SleepTracker::createSleepTracker("u4"));
    dynSleep0->logSleep(9);
    dynSleep0->logSleep(7);

    std::cout << "Dyn user avg: " << dynSleep0->averageSleep(2) << "\n\n";


    // --- vector of shared_ptr profiles ---
    std::cout << "[ SHARED_PTR VECTOR ]\n";

    std::vector<std::shared_ptr<CommunityProfile>> members;
    members.push_back(carol);
    members.push_back(carolCopy);

    std::cout << "members[0] == members[1]? "
        << (members[0] == members[1]) << "\n\n";


    // --- Hydration with exception handling ---
    std::cout << "[ HYDRATION TRACKER ]\n";

    HydrationTracker ht =
        HydrationTracker::createHydrationTracker("u1", 2000);

    try {
        ht.addDrink(500);
        ht.addDrink(-100);
    }
    catch (const std::invalid_argument& ex) {
        std::cout << "Caught invalid_argument: " << ex.what() << "\n";
    }

    ht.addDrink(300);
    ht.showHydrationInfo();
    std::cout << "\n";


    // --- RecoverySession operator< demonstration ---
    std::cout << "[ RECOVERY SESSION ]\n";

    RecoverySession rs1 =
        RecoverySession::createSession("s1", "2025-10-01", "yoga", 30, "evening");

    RecoverySession rs2 =
        RecoverySession::createSession("s2", "2025-10-02", "sleep", 60, "nap");

    std::cout << "Shorter session is s1? " << (rs1 < rs2) << "\n\n";


    // --- demonstrate 'this' ---
    std::cout << "[ THIS DEMONSTRATION ]\n";

    alice.awardBadge(Achievement::createAchievement("a3", "Consistency",
        "7 days", 50));
    alice.showProfileInfo();
    std::cout << "\n";


    // --- more exceptions ---
    std::cout << "[ EXCEPTION TEST ]\n";
    try {
        auto bad = lb[100];
        (void)bad;
    }
    catch (const std::exception& ex) {
        std::cout << "Handled exception: " << ex.what() << "\n";
    }


    std::cout << "\n=== End demo ===\n";
    return 0;
}
