#pragma once

#include "player.hpp"

class Astrologer : public Player
{
public:
    Astrologer() = delete;
    Astrologer(const char *name, float maxHp, float maxMp, float maxStamina, int runes, float level,
               int staffPower, float intelligenceScalling, float cosmicAffinity);

    void performSpecialAction() const;
    bool canLearnSpell(const Spell &spell) const;
    const char *getClassName() const;

    int getStaffPower() const;
    float getIntelligenceScalling() const;
    float getCosmicAffinity() const;

    void setStaffPower(int staffPower);
    void setIntelligenceScalling(float intelligenceScalling);
    void setCosmicAffinity(float cosmicAffinity);

private:
    int staffPower;
    float intelligenceScalling;
    float cosmicAffinity;
};