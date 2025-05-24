#include <cstring>
#include <iostream>

#include "confessor.hpp"

// Might throw std::invalid_argument
Confessor::Confessor(const char *name, float maxHp, float maxMp, float maxStamina, int runes, float level,
                     int holySymbolPower, float faithScalling, int divineBlessing)
    : Character(name, maxHp, maxMp, maxStamina, runes, level)
{
    if (holySymbolPower < 0 ||
        faithScalling < 0 ||
        divineBlessing < 0)
    {
        throw std::invalid_argument("Invalid parameter for Confessor!");
    }
    this->holySymbolPower = holySymbolPower;
    this->faithScalling = faithScalling;
    this->divineBlessing = divineBlessing;
}

void Confessor::castSpell(Spell *spell, Combatant *target)
{
    std::cout << "Casting Incantation Spell: " << spell->getName()
              << " with damage: " << spell->getDamage()
              << " and MP cost: " << spell->getMpCost()
              << std::endl;

    spell->setRemainingCooldown(spell->getCooldown());
    //   Target loses hp
}

void Confessor::empowerNextSpell(const IncantationSpell &spell) const
{
    std::cout << "Casting Incantation Spell: " << spell.getName()
              << " with damage: " << spell.getDamage() * 2
              << " and MP cost: " << spell.getMpCost()
              << std::endl;
}

void Confessor::predictEnemyAction(const Enemy &enemy) const
{
    std::cout << "Predicting enemy action: " << enemy.getName()
              << " with HP: " << enemy.getHp()
              << " and damage: " << enemy.calculateDamage()
              << std::endl;
}

Combatant *Confessor::clone() const
{
    return new Confessor(*this);
}

void Confessor::attack(Combatant *target)
{
    target->defend(this);
}

void Confessor::defend(const Combatant *target)
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

void Confessor::useSpecialAbility() const
{
    std::cout << "Using special ability: Divine Intervention!" << std::endl;
}

float Confessor::calculateDamage() const
{
    return this->getHolySymbolPower() + this->getFaithScalling();
}

bool Confessor::canCastSpell(const Spell *spell) const
{
    if (strcmp(spell->getSpellType(), "Incantation") == 0)
    {
        return true;
    }
    return false;
}

const char *Confessor::getType() const
{
    return "Confessor";
}

float Confessor::calculateMagicPower() const
{
    return this->calculateDamage();
}

void Confessor::print() const
{
    this->printStatus();
    this->printInventory();
    this->printSpell();
}

void Confessor::printStatus() const
{
    std::cout << "\n=== " << this->getName() << " stats ===\n"
              << "HP: " << this->getHp() << "/" << this->getMaxHp()
              << "\nMP: " << this->getMp() << "/" << this->getMaxMp()
              << "\nRunes: " << this->getRunes()
              << "\nLevel: " << this->getLevel()
              << "\nHoly Symbol Power: " << this->getHolySymbolPower()
              << "\nFaith Scalling: " << this->getFaithScalling()
              << "\nDivine Blessing: " << this->getDivineBlessing()
              << std::endl;
}

int Confessor::getHolySymbolPower() const
{
    return this->holySymbolPower;
}

float Confessor::getFaithScalling() const
{
    return this->faithScalling;
}

int Confessor::getDivineBlessing() const
{
    return this->divineBlessing;
}

// Might throw std::invalid_argument
void Confessor::setHolySymbolPower(int holySymbolPower)
{
    if (holySymbolPower < 0)
    {
        throw std::invalid_argument("Invalid parameter for Confessor!");
    }
    this->holySymbolPower = holySymbolPower;
}

// Might throw std::invalid_argument
void Confessor::setFaithScalling(float faithScalling)
{
    if (faithScalling < 0)
    {
        throw std::invalid_argument("Invalid parameter for Confessor!");
    }
    this->faithScalling = faithScalling;
}

// Might throw std::invalid_argument
void Confessor::setDivineBlessing(int divineBlessing)
{
    if (divineBlessing < 0)
    {
        throw std::invalid_argument("Invalid parameter for Confessor!");
    }
    this->divineBlessing = divineBlessing;
}