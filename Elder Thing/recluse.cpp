#include "recluse.hpp"

const char *Recluse::getType() const
{
    return "Recluse";
}

Character *Recluse::clone() const
{
    return new Recluse(*this);
}

void Recluse::attack(Combatant *target)
{
    std::cout << "No damage applied!" << std::endl;
}

void Recluse::defend(const Combatant *target)
{
    this->setHp(0);
    this->setIsAlive(false);

    std::cout << this->getName() << " is defeated!" << std::endl;
}

float Recluse::calculateDamage() const
{
    return 0;
}

void Recluse::useSpecialAbility() const
{
    std::cout << "No special ability available!" << std::endl;
}

void Recluse::print() const
{
    this->printStatus();
    this->printInventory();
    this->printSpell();
}

void Recluse::printStatus() const
{
    std::cout << "\n=== " << this->getName() << " stats ===\n"
              << "HP: " << this->getHp() << "/" << this->getMaxHp()
              << "\nMP: " << this->getMp() << "/" << this->getMaxMp()
              << "\nRunes: " << this->getRunes()
              << "\nLevel: " << this->getLevel()
              << std::endl;
}