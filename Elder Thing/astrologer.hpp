#pragma once

#include "character.hpp"
#include "spelltypes.hpp"

class Astrologer : public Character
{
public:
    Astrologer() = delete;
    Astrologer(const char *name, float maxHp, float maxMp, float maxStamina, int runes, float level,
               int staffPower, float intelligenceScalling, float cosmicAffinity);

    void castSorcerySpell(const SorcerySpell &spell) const;
    void empowerNextSpell(const SorcerySpell &spell) const;
    void predictEnemyAction(const Enemy &enemy) const;

    Character *clone() const override;
    void attack(Enemy *enemy) override;
    void defend(const Enemy *enemy) override;
    void useSpecialAbility() const override;
    const char *getClassName() const override;
    int calculateDamage() const override;
    bool canLearnSpell(const Spell *spell) const override;

    void print() const override;
    void printStatus() const override;

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