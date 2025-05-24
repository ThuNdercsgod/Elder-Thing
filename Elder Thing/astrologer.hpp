#pragma once

#include "character.hpp"
#include "spelltypes.hpp"

class Astrologer : virtual public Character, public MagicUser
{
public:
    Astrologer() = delete;
    Astrologer(const char *name, float maxHp, float maxMp, float maxStamina, int runes, float level,
               int staffPower, float intelligenceScalling, float cosmicAffinity);

    void empowerNextSpell(const Spell *spell) const;
    void predictEnemyAction(const Enemy &enemy) const;

    Combatant *clone() const override;
    void attack(Combatant *target) override;
    void defend(const Combatant *target) override;
    void useSpecialAbility() const override;
    float calculateDamage() const override;
    bool canCastSpell(const Spell *spell) const override;
    const char *getType() const override;
    void castSpell(Spell *spell, Combatant *target) override;
    float calculateMagicPower() const override;

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