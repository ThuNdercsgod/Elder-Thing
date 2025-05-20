#include <cstring>
#include <iostream>

#include "confessor.hpp"

// Might throw std::invalid_argument
Confessor::Confessor(const char *name, float maxHp, float maxMp, float maxStamina, int runes, float level,
                     int holySymbolPower, float faithScalling, int divineBlessing)
    : Player(name, maxHp, maxMp, maxStamina, runes, level)
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

void Confessor::castIncantationSpell(const IncantationSpell &spell) const
{
    std::cout << "Casting Incantation Spell: " << spell.getName()
              << " with damage: " << spell.getDamage()
              << " and MP cost: " << spell.getMpCost()
              << std::endl;
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
              << " and damage: " << enemy.getDamage()
              << std::endl;
}

void Confessor::performSpecialAction() const
{
    std::cout << "Divine Intervention Activated!" << std::endl;
}

bool Confessor::canLearnSpell(const SorcerySpell &spell) const
{
    if (strcmp(spell.getSpellType(), "Incantation") == 0)
    {
        return true;
    }
    return false;
}

bool Confessor::canLearnSpell(const IncantationSpell &spell) const
{
    if (strcmp(spell.getSpellType(), "Incantation") == 0)
    {
        return true;
    }
    return false;
}

const char *Confessor::getClassName() const
{
    return "Confessor";
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