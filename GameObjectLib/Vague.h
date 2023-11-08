#pragma once
#include "Mobs.h"

class Vague {
public:

    Vague(int t1Count, int t2Count, int t3Count, int bossCount);
    const std::vector<Mobs*>& GetMobsList() const;

private:
    int nombre_mob_t1;
    int nombre_mob_t2;
    int nombre_mob_t3;
    int boss;

    MobType1 mobType1;
    MobType2 mobType2;
    MobType3 mobType3;
    Boss bossMob;

    std::vector<Mobs*> mobsList;
};