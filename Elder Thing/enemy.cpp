#include <cstring>
#include <iostream>

#include "enemy.hpp"

Enemy::Enemy()
    : Enemy("Unknown", 100, 100, 0) {}

// Might throw std::invalid_argument
Enemy::Enemy(const char *name, int hp, int maxHp, int damage)
{
    if (this->validHp(this->hp) && this->validMaxHp(maxHp) && this->validDamage(damage))
    {
        strcpy(this->name, name);
        this->hp = hp;
        this->maxHp = maxHp;
        this->damage = damage;
    }
    else
    {
        throw std::invalid_argument("Invalid Enemy parameters!");
    }
}

Enemy::Enemy(const Enemy &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->hp = other.hp;
    this->maxHp = other.maxHp;
    this->damage = other.damage;
}

Enemy &Enemy::operator=(const Enemy &other)
{
    if (this != &other)
    {
        delete[] this->name;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);

        this->hp = other.hp;
        this->maxHp = other.maxHp;
        this->damage = other.damage;
    }
    return *this;
}

Enemy::~Enemy()
{
    delete[] this->name;
}

bool Enemy::validHp(int hp) const
{
    if (hp >= 0)
    {
        return true;
    }
    return false;
}

bool Enemy::validMaxHp(int maxHp) const
{
    if (maxHp >= 0)
    {
        return true;
    }
    return false;
}

bool Enemy::validDamage(int damage) const
{
    if (hp >= 0)
    {
        return true;
    }
    return false;
}
