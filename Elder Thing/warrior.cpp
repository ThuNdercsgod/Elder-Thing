#include "warrior.hpp"

const char *Warrior::getType() const
{
    return "Warrior";
}

void Warrior::attack(Combatant *target)
{
    target->defend(this);
}

void Warrior::defend(const Combatant *target)
{
    if (this->getHp() > 0)
    {
        this->setHp(this->getHp() - target->calculateDamage());
        std::cout << "Remaining HP: " << this->getHp() << std::endl;
    }
    else
    {
        std::cout << this->getName() << " is already defeated!" << std::endl;
    }
}

float Warrior::calculateDamage() const
{
    return this->damage;
}

Character *Warrior::clone() const
{
    return new Warrior(*this);
}

void Warrior::useSpecialAbility() const
{
}

void Warrior::print() const
{
    this->printStatus();
    this->printInventory();
    this->printSpell();
}

void Warrior::printStatus() const
{
    std::cout << "\n=== " << this->getName() << " stats ===\n"
              << "HP: " << this->getHp() << "/" << this->getMaxHp()
              << "\nMP: " << this->getMp() << "/" << this->getMaxMp()
              << "\nRunes: " << this->getRunes()
              << "\nLevel: " << this->getLevel()
              << std::endl;
}

float Warrior::getHp() const
{
    return this->hp;
}

void Warrior::setHp(float hp)
{
    this->hp = hp;
}

void Warrior::setDamage(float damage)
{
    this->damage = damage;
}