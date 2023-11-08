#include "Vague.h"
#include "Mobs.h" 
#include <iostream>

Vague::Vague(int t1Count, int t2Count, int t3Count, int bossCount) {
    for (int i = 0; i < t1Count; i++) {
        mobsList.push_back(new Mobs("Mob de type 1", 100.0f, 10, 100, 0.0f, 0.0f, "../Assets/img/Mob1.png"));
    }
    for (int i = 0; i < t2Count; i++) {
        mobsList.push_back(new Mobs("Mob de type 2", 150.0f, 15, 100, 0.0f, 100.0f, "../Assets/img/Mob2.png"));
    }
    for (int i = 0; i < t3Count; i++) {
        mobsList.push_back(new Mobs("Mob de type 3", 60.0f, 8, 200, 0.0f, 200.0f, "../Assets/img/Mob3.png"));
    }
    for (int i = 0; i < bossCount; i++) {
        mobsList.push_back(new Mobs("Boss", 500.0f, 50, 50, 0.0f, 300.0f, "../Assets/img/Boss.png"));
    }
}

const std::vector<Mobs*>& Vague::GetMobsList() const {
    return mobsList;
}