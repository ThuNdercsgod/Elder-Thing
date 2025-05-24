#pragma once

#include <iostream>

#include "interfaces.hpp"

class Character;

// class Attack
// {
//     Attack();
//     Attack(const char *name, int damage, int range);
//     ~Attack();

//     friend class Enemy;

//     char *name;
//     int damage;
//     int range;
// };

class Enemy : public Combatant
{
public:
    Enemy();
    Enemy(const char *name, int maxHp, int damage);
    Enemy(const Enemy &other);
    ~Enemy();

    Enemy &operator=(const Enemy &other);
    bool operator!() const;
    friend std::ostream &operator<<(std::ostream &os, const Enemy &enemy);

    // void addAttack(const char *name, int damage, int range);
    void print() const;

    void attack(Combatant *target) override;
    void defend(const Combatant *target) override;
    float calculateDamage() const override;
    const char *getType() const override;

    Combatant *clone() const override;

    const char *getName() const;
    int getHp() const;
    int getMaxHp() const;

    void setHp(int hp);
    void setMaxHp(int maxHp);
    void setDamage(int damage);

private:
    bool validName(const char *name) const;
    bool validHp(int hp) const;
    bool validDamage(int damage) const;

    char *name;
    float hp, maxHp;
    float damage;
    // int numberOfAttacks;
    // Attack *attacks;
};
