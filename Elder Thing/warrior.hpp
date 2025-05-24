#pragma once

#include "character.hpp"

class Warrior : virtual public Character
{
public:
    const char *getType() const override;
    void attack(Combatant *target) override;
    void defend(const Combatant *target) override;
    float calculateDamage() const override;
    Character *clone() const override;
    void useSpecialAbility() const override;

    void print() const override;
    void printStatus() const override;

    float getHp() const;

    void setHp(float hp);
    void setDamage(float damage);

private:
    float hp;
    float damage;
};