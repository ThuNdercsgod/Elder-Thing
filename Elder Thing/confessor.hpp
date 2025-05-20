#pragma once

#include "player.hpp"
#include "sorceryspell.hpp"
#include "incantationspell.hpp"

class Confessor : public Player
{
public:
    Confessor() = delete;
    Confessor(const char *name, float maxHp, float maxMp, float maxStamina, int runes, float level,
              int holySymbolPower, float faithScalling, int divineBlessing);

    void castIncantationSpell(const IncantationSpell &spell) const;
    void empowerNextSpell(const IncantationSpell &spell) const;
    void predictEnemyAction(const Enemy &enemy) const;

    void performSpecialAction() const;
    bool canLearnSpell(const SorcerySpell &spell) const;
    bool canLearnSpell(const IncantationSpell &spell) const;
    const char *getClassName() const;

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