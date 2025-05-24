#include <iostream>

#include "demigod.hpp"

void Demigod::attack(Combatant *target)
{
    target->defend(this);
}

void Demigod::defend(const Combatant *target)
{
    if (this->getHp() > 0)
    {
        this->setHp(this->getHp() - target->calculateDamage());
        std::cout << "Remaining HP: " << this->getHp() << std::endl;
    }
    else
    {
        std::cout << "Demigod is already defeated!" << std::endl;
    }
}

float Demigod::calculateDamage() const
{
    return this->damage;
}

const char *Demigod::getType() const
{
    return "Demigod";
}

float Demigod::getHp() const
{
    return this->hp;
}

void Demigod::setHp(float hp)
{
    this->hp = hp;
}

void Demigod::setDamage(float damage)
{
    this->damage = damage;
}