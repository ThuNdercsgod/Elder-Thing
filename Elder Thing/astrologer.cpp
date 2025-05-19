#include <cstring>
#include <iostream>

#include "astrologer.hpp"

// Might throw std::invalid_argument or std::bad_alloc
Astrologer::Astrologer(const char *name, float maxHp, float maxMp, float maxStamina, int runes, float level,
                       int staffPower, float intelligenceScalling, float cosmicAffinity)
    : Player(name, maxHp, maxMp, maxStamina, runes, level)
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

void Astrologer::performSpecialAction() const
{
    std::cout << "Cosmic Vision Activated!" << std::endl;
}

bool Astrologer::canLearnSpell(const Spell &spell) const
{
    if (strcmp(spell.getType(), "Sorcery") == 0)
    {
        return true;
    }
    return false;
}

const char *Astrologer::getClassName() const
{
    return "Astrologer";
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