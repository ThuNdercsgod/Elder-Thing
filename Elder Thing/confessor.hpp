#pragma once

#include "character.hpp"
#include "spelltypes.hpp"

class Confessor : public Character
{
public:
    Confessor() = delete;
    Confessor(const char *name, float maxHp, float maxMp, float maxStamina, int runes, float level,
              int holySymbolPower, float faithScalling, int divineBlessing);

    void castIncantationSpell(const IncantationSpell &spell) const;
    void empowerNextSpell(const IncantationSpell &spell) const;
    void predictEnemyAction(const Enemy &enemy) const;

    void attack(Enemy *enemy) override;
    void defend(const Enemy *enemy) override;
    void useSpecialAbility() const override;
    const char *getClassName() const override;
    virtual int calculateDamage() const override;
    bool canLearnSpell(const Spell *spell) const override;

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