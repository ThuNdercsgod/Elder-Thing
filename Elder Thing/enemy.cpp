#include <cstring>
#include <iostream>

#include "character.hpp"
#include "enemy.hpp"

Enemy::Enemy()
    : Enemy("Unknown", 100, 0) {}

// Might throw std::invalid_argument or std::bad_alloc
Enemy::Enemy(const char *name, int maxHp, int damage)
{
    if (this->validName(name) && this->validHp(maxHp) && this->validDamage(damage))
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        this->hp = maxHp;
        this->maxHp = maxHp;
        this->damage = damage;
        // this->numberOfAttacks = 0;
    }
    else
    {
        throw std::invalid_argument("Invalid Enemy parameters!");
    }
}

// Might throw std::bad_alloc
Enemy::Enemy(const Enemy &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->hp = other.hp;
    this->maxHp = other.maxHp;
    this->damage = other.damage;
    // this->numberOfAttacks = 0;
}

Enemy::~Enemy()
{
    delete[] this->name;
    this->name = nullptr;
}

// Might throw std::bad_alloc
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
        // this->numberOfAttacks = numberOfAttacks
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Enemy &enemy)
{
    return os << "\n=== Enemy " << enemy.name << " ===\n"
              << "\nHP: " << enemy.hp << "/" << enemy.maxHp
              << "\nDamage: " << enemy.damage
              << std::endl;
}

bool Enemy::operator!() const
{
    if (this->hp == 0)
    {
        return true;
    }
    return false;
}

// void Enemy::addAttack(const char *name, int damage, int range)
// {
//     try
//     {
//         Attack attack(name, damage, range);
//     }
//     catch (std::invalid_argument &e)
//     {
//         delete[] this->name;
//         this->name = nullptr;
//         throw;
//     }
//     catch (std::bad_alloc &e)
//     {
//         delete[] this->name;
//         this->name = nullptr;
//         throw;
//     }
// }

void Enemy::print() const
{
    std::cout << "\n=== Enemy " << this->name << " ==="
              << "\nHP: " << this->hp << "/" << this->maxHp
              << "\nDamage: " << this->damage
              << std::endl;
}

void Enemy::attack(Character *target) const
{
    target->defend(this);
}

void Enemy::defend(Character *attacker)
{
    if (this->hp > 0)
    {
        this->hp -= attacker->calculateDamage();
        std::cout << "Remaining HP: " << this->hp << std::endl;
    }
    else if (this->hp <= attacker->calculateDamage())
    {
        this->hp = 0;
        std::cout << this->name << " is defeated!" << std::endl;
    }

    else
    {
        std::cout << this->name << " is already defeated!" << std::endl;
    }
}

const char *Enemy::getName() const
{
    return this->name;
}

int Enemy::getHp() const
{
    return this->hp;
}

int Enemy::getMaxHp() const
{
    return this->maxHp;
}

int Enemy::getDamage() const
{
    return this->damage;
}

// Might throw std::invalid_argument
void Enemy::setHp(int hp)
{
    if (!this->validHp(hp))
    {
        throw std::invalid_argument("Invalid parameters for Enemy!");
    }
    this->hp = hp;
}

// Might throw std::invalid_argument
void Enemy::setMaxHp(int maxHp)
{
    if (!this->validHp(maxHp))
    {
        throw std::invalid_argument("Invalid parameters for Enemy!");
    }
    this->maxHp = maxHp;
}

// Might throw std::invalid_argument
void Enemy::setDamage(int damage)
{
    if (!this->validDamage(damage))
    {
        throw std::invalid_argument("Invalid Parameters for Enemy!");
    }
    this->damage = damage;
}

bool Enemy::validName(const char *name) const
{
    if (strcmp(name, "") != 0)
    {
        return true;
    }
    return false;
}

bool Enemy::validHp(int hp) const
{
    if (hp > 0)
    {
        return true;
    }
    return false;
}

bool Enemy::validDamage(int damage) const
{
    if (damage >= 0)
    {
        return true;
    }
    return false;
}

// Attack::Attack()
//     : Attack("Unknown", 100, 1) {}

// Might throw std::invalid_argument or std::bad_alloc
// Attack::Attack(const char *name, int damage, int range)
// {
//     if (strcmp(name, "") != 0 && damage > 0 && range > 0)
//     {
//         this->name = new char[strlen(name) + 1];
//         strcpy(this->name, name);
//         this->damage = damage;
//         this->range = range;
//     }
//     else
//     {
//         throw std::invalid_argument("Invalid Attack parameters!");
//     }
// }

// Attack::~Attack()
// {
//     delete[] this->name;
//     this->name = nullptr;
// }