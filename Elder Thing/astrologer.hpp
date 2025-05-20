#pragma once

#include "player.hpp"
#include "sorceryspell.hpp"
#include "incantationspell.hpp"

class Astrologer : public Player
{
public:
    Astrologer() = delete;
    Astrologer(const char *name, float maxHp, float maxMp, float maxStamina, int runes, float level,
               int staffPower, float intelligenceScalling, float cosmicAffinity);

    void castSorcerySpell(const SorcerySpell &spell) const;
    void empowerNextSpell(const SorcerySpell &spell) const;
    void predictEnemyAction(const Enemy &enemy) const;

    void performSpecialAction() const;
    bool canLearnSpell(const SorcerySpell &spell) const;
    bool canLearnSpell(const IncantationSpell &spell) const;
    const char *getClassName() const;

    void print() const;
    void printStatus() const;

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