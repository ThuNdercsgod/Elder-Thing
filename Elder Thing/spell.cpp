#include <cstring>
#include <iostream>

#include "spell.hpp"

// Might throw std::bad_alloc
Spell::Spell()
    : Spell("Unknown", 0, 0, 0, 0, 0) {}

// Might throw std::bad_alloc
Spell::Spell(const char *name, float damage, int mpCost, int cooldown, int requiredIntelligence, int requiredFaith)
    : remainingCooldown(0)
{
    if (!(validName(name) &&
          validDamage(damage) &&
          validMpCost(mpCost) &&
          validCooldown(cooldown) &&
          validRequiredIntelligence(requiredIntelligence) &&
          validRequiredFaith(requiredFaith)))
    {
        throw std::invalid_argument("Invalid parameter for Spell!");
    }
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

// Might throw std::ios_bas::failure
std::ostream &operator<<(std::ostream &os, const Spell &spell)
{
    if (os.fail() || os.bad())
    {
        throw std::ios_base::failure("Output stream error!");
    }

    return os << "Spell \"" << spell.name << "\":\n"
              << "Damage: " << spell.damage << "\n"
              << "MP cost: " << spell.mpCost << "\n"
              << "Cooldown: " << spell.cooldown << "\n"
              << "Required intelligence: " << spell.requiredIntelligence << "\n"
              << "Required faith: " << spell.requiredFaith
              << std::endl;
}

bool Spell::operator<(const Spell &other) const
{
    if (this->damage < other.damage)
    {
        return true;
    }
    return false;
}

bool Spell::operator>(const Spell &other) const
{
    return this > &other;
}

void Spell::resetCooldown()
{
    this->remainingCooldown = this->cooldown;
}

void Spell::decrementCooldown(int amount)
{
    if (this->remainingCooldown >= amount)
    {
        this->remainingCooldown -= amount;
    }
    else
    {
        this->remainingCooldown = 0;
    }
}

bool Spell::isOnCooldown() const
{
    if (this->remainingCooldown > 0)
    {
        return true;
    }
    return false;
}

void Spell::print() const
{
    std::cout << "Spell \"" << this->name << "\":\n"
              << "Damage: " << this->damage << "\n"
              << "MP cost: " << this->mpCost << "\n"
              << "Cooldown: " << this->cooldown << "\n"
              << "Required intelligence: " << this->requiredIntelligence << "\n"
              << "Required faith: " << this->requiredFaith
              << std::endl;
}

const char *Spell::getName() const
{
    return this->name;
}

float Spell::getDamage() const
{
    return this->damage;
}

int Spell::getMpCost() const
{
    return this->mpCost;
}

int Spell::getCooldown() const
{
    return this->cooldown;
}

int Spell::getRequiredIntelligence() const
{
    return this->requiredIntelligence;
}

int Spell::getRequiredFaith() const
{
    return this->requiredFaith;
}

int Spell::getRemainingCooldown() const
{
    return this->remainingCooldown;
}

// Might throw std::invalid_argument
void Spell::setName(const char *name)
{
    if (!validName(name))
    {
        delete[] this->name;
        throw std::invalid_argument("Invalid parameter for Spell!");
    }

    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

// Might throw std::invalid_argument
void Spell::setDamage(float damage)
{
    if (!validDamage(damage))
    {
        throw std::invalid_argument("Invalid parameter for Spell!");
    }
    this->damage = damage;
}

// Might throw std::invalid_argument
void Spell::setMpCost(int mpCost)
{
    if (!validMpCost(mpCost))
    {
        throw std::invalid_argument("Invalid parameter for Spell!");
    }
    this->mpCost = mpCost;
}

// Might throw std::invalid_argument
void Spell::setCooldown(int cooldown)
{
    if (!validCooldown(cooldown))
    {
        throw std::invalid_argument("Invalid parameter for Spell!");
    }
    this->cooldown = cooldown;
}

// Might throw std::invalid_argument
void Spell::setRequiredIntelligence(int requiredIntelligence)
{
    if (!validRequiredIntelligence(requiredIntelligence))
    {
        throw std::invalid_argument("Invalid parameter for Spell!");
    }
    this->requiredIntelligence = requiredIntelligence;
}

// Might throw std::invalid_argument
void Spell::setRequiredFaith(int requiredFaith)
{
    if (!validRequiredFaith(requiredFaith))
    {
        throw std::invalid_argument("Invalid parameter for Spell!");
    }
    this->requiredFaith = requiredFaith;
}

// Might throw std::invalid_argument
void Spell::setRemainingCooldown(int remainingCooldown)
{
    if (!validRemainingCooldown(remainingCooldown))
    {
        throw std::invalid_argument("Invalid parameter for Spell!");
    }
    this->remainingCooldown = remainingCooldown;
}

bool Spell::validName(const char *name) const
{
    if (name == nullptr || strcmp(name, "") == 0)
    {
        return false;
    }
    return true;
}

bool Spell::validDamage(float damage) const
{
    if (damage < 0)
    {
        return false;
    }
    return true;
}

bool Spell::validMpCost(int mpCost) const
{
    if (mpCost < 0)
    {
        return false;
    }
    return true;
}

bool Spell::validCooldown(int cooldown) const
{
    if (cooldown < 0)
    {
        return false;
    }
    return true;
}

bool Spell::validRequiredIntelligence(int requiredIntelligence) const
{
    if (requiredIntelligence < 0)
    {
        return false;
    }
    return true;
}

bool Spell::validRequiredFaith(int requiredFaith) const
{
    if (requiredFaith < 0)
    {
        return false;
    }
    return true;
}

bool Spell::validRemainingCooldown(int remainingCooldown) const
{
    if (remainingCooldown < 0)
    {
        return false;
    }
    return true;
}