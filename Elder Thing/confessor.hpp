#pragma once

#include "character.hpp"
#include "spelltypes.hpp"

class Confessor : virtual public Character, public MagicUser
{
public:
    Confessor() = delete;
    Confessor(const char *name, float maxHp, float maxMp, float maxStamina, int runes, float level,
              int holySymbolPower, float faithScalling, int divineBlessing);

    void empowerNextSpell(const IncantationSpell &spell) const;
    void predictEnemyAction(const Enemy &enemy) const;

    Combatant *clone() const override;
    void attack(Combatant *target) override;
    void defend(const Combatant *target) override;
    void useSpecialAbility() const override;
    virtual float calculateDamage() const override;
    bool canCastSpell(const Spell *spell) const override;
    const char *getType() const override;
    float calculateMagicPower() const override;
    void castSpell(Spell *spell, Combatant *target) override;

    void print() const override;
    void printStatus() const override;

    int getHolySymbolPower() const;
    float getFaithScalling() const;
    int getDivineBlessing() const;

    void setHolySymbolPower(int holySymbolPower);
    void setFaithScalling(float faithScalling);
    void setDivineBlessing(int divineBlessing);

private:
    int holySymbolPower;
    float faithScalling;
    int divineBlessing;
};