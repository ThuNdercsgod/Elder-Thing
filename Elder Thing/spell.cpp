#include <cstring>

#include "spell.hpp"

// Might throw std::bad_alloc
Spell::Spell()
    : Spell("Unknown", 0, 0, 0, 0, 0) {}

// Might throw std::bad_alloc
Spell::Spell(const char *name, float damage, int mpCost, int cooldown, int requiredIntelligence, int requiredFaith)
    : remainingCooldown(0)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->damage = damage;
    this->mpCost = mpCost;
    this->cooldown = cooldown;
    this->requiredIntelligence = requiredIntelligence;
    this->requiredFaith = requiredFaith;
}

// Might throw std::bad_alloc
Spell::Spell(const Spell &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->damage = other.damage;
    this->mpCost = other.mpCost;
    this->cooldown = other.cooldown;
    this->requiredIntelligence = other.requiredIntelligence;
    this->requiredFaith = other.requiredFaith;
    this->remainingCooldown = other.remainingCooldown;
}

Spell::~Spell()
{
    delete[] this->name;
    this->name = nullptr;
}

Spell &Spell::operator=(const Spell &other)
{
    if (this != &other)
    {
        delete[] this->name;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);

        this->damage = other.damage;
        this->mpCost = other.mpCost;
        this->cooldown = other.cooldown;
        this->requiredIntelligence = other.requiredIntelligence;
        this->requiredFaith = other.requiredFaith;
        this->remainingCooldown = other.remainingCooldown;
    }
    return *this;
}

void Spell::resetCooldown()
{
    this->cooldown = 0;
}

void Spell::decrementCooldown(int amount)
{
    if (this->cooldown >= amount)
    {
        this->cooldown -= amount;
    }
    else
    {
        this->cooldown = 0;
    }
}

bool Spell::isOnCooldown() const
{
    if (this->cooldown > 0)
    {
        return true;
    }
    return false;
}