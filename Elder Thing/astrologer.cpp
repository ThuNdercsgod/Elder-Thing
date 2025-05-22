#include <cstring>
#include <iostream>

#include "astrologer.hpp"

// Might throw std::invalid_argument or std::bad_alloc
Astrologer::Astrologer(const char *name, float maxHp, float maxMp, float maxStamina, int runes, float level,
                       int staffPower, float intelligenceScalling, float cosmicAffinity)
    : Character(name, maxHp, maxMp, maxStamina, runes, level)
{
    if (staffPower < 0 ||
        intelligenceScalling < 0 ||
        cosmicAffinity < 0)
    {
        throw std::invalid_argument("Invalid parameter for Astrologer!");
    }
    this->staffPower = staffPower;
    this->intelligenceScalling = intelligenceScalling;
    this->cosmicAffinity = cosmicAffinity;
}

void Astrologer::castSorcerySpell(const SorcerySpell &spell) const
{
    std::cout << "Casting Sorcery Spell: " << spell.getName()
              << " with damage: " << spell.getDamage()
              << " and MP cost: " << spell.getMpCost()
              << std::endl;
}

void Astrologer::empowerNextSpell(const SorcerySpell &spell) const
{
    std::cout << "Casting Sorcery Spell: " << spell.getName()
              << " with damage: " << spell.getDamage() * 2
              << " and MP cost: " << spell.getMpCost()
              << std::endl;
}

void Astrologer::predictEnemyAction(const Enemy &enemy) const
{
    std::cout << "Predicting enemy action: " << enemy.getName()
              << " with HP: " << enemy.getHp()
              << " and damage: " << enemy.getDamage()
              << std::endl;
}

Character *Astrologer::clone() const
{
    return new Astrologer(*this);
}

void Astrologer::attack(Enemy *enemy)
{
    enemy->defend(this);
}

void Astrologer::defend(const Enemy *enemy)
{
    if (this->getHp() > 0)
    {
        this->setHp(this->getHp() - enemy->getDamage());
        std::cout << "Remaining HP: " << this->getHp() << std::endl;
    }
    else
    {
        std::cout << this->getName() << " is already defeated!" << std::endl;
    }
}

void Astrologer::useSpecialAbility() const
{
    std::cout << "Using Special Ability: Cosmic Vision!" << std::endl;
}

const char *Astrologer::getClassName() const
{
    return "Astrologer";
}

int Astrologer::calculateDamage() const
{
    return this->getStaffPower() + this->getIntelligenceScalling();
}

bool Astrologer::canLearnSpell(const Spell *spell) const
{
    if (strcmp(spell->getSpellType(), "Sorcery") == 0)
    {
        return true;
    }
    return false;
}

void Astrologer::print() const
{
    this->printStatus();
    this->printInventory();
    this->printSpell();
}

void Astrologer::printStatus() const
{
    std::cout << "\n=== " << this->getName() << " stats ===\n"
              << "HP: " << this->getHp() << "/" << this->getMaxHp()
              << "\nMP: " << this->getMp() << "/" << this->getMaxMp()
              << "\nRunes: " << this->getRunes()
              << "\nLevel: " << this->getLevel()
              << "\nStaff Power: " << this->getStaffPower()
              << "\nIntelligence Scalling: " << this->getIntelligenceScalling()
              << "\nCosmic Affinity: " << this->getCosmicAffinity()
              << std::endl;
}

int Astrologer::getStaffPower() const
{
    return this->staffPower;
}

float Astrologer::getIntelligenceScalling() const
{
    return this->intelligenceScalling;
}

float Astrologer::getCosmicAffinity() const
{
    return this->cosmicAffinity;
}

// Might throw std::invalid_argument
void Astrologer::setStaffPower(int staffPower)
{
    if (staffPower < 0)
    {
        throw std::invalid_argument("Invalid parameter for Astrologer!");
    }
    this->staffPower = staffPower;
}

// Might throw std::invalid_argument
void Astrologer::setIntelligenceScalling(float intelligenceScalling)
{
    if (intelligenceScalling < 0)
    {
        throw std::invalid_argument("Invalid parameter for Astrologer!");
    }
    this->intelligenceScalling = intelligenceScalling;
}

// Might throw std::invalid_argument
void Astrologer::setCosmicAffinity(float cosmicAffinity)
{
    if (cosmicAffinity < 0)
    {
        throw std::invalid_argument("Invalid parameter for Astrologer!");
    }
    this->cosmicAffinity = cosmicAffinity;
}