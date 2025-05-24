#pragma once

#include "astrologer.hpp"
#include "warrior.hpp"

class Recluse : public Astrologer, public Warrior
{
public:
    const char *getType() const override;
    Character *clone() const override;
    void attack(Combatant *target) override;
    void defend(const Combatant *target) override;
    float calculateDamage() const override;
    void useSpecialAbility() const override;

    void print() const override;
    void printStatus() const override;
};