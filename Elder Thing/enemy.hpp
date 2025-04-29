#pragma once

class Enemy
{
public:
    Enemy();
    Enemy(char const *name, int hp, int maxHp, int damage);
    Enemy(const Enemy &other);
    Enemy &operator=(const Enemy &other);
    ~Enemy();

    bool validHp(int hp) const;
    bool validMaxHp(int maxHp) const;
    bool validDamage(int damage) const;

private:
    char *name;
    int hp, maxHp;
    int damage;
};