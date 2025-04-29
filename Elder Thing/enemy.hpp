#pragma once

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

class Enemy
{
public:
    Enemy();
    Enemy(const char *name, int maxHp, int damage);
    Enemy(const Enemy &other);
    Enemy &operator=(const Enemy &other);
    ~Enemy();

    // void addAttack(const char *name, int damage, int range);
    void print() const;

private:
    bool validName(const char *name) const;
    bool validHp(int hp) const;
    bool validMaxHp(int maxHp) const;
    bool validDamage(int damage) const;

    char *name;
    int hp, maxHp;
    int damage;
    // int numberOfAttacks;
    // Attack *attacks;
};
