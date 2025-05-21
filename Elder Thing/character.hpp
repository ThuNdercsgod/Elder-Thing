#pragma once

#include "enemy.hpp"
#include "spell.hpp"
#include "weapon.hpp"

class Character
{
public:
    Character();
    Character(const char *name, float maxHp, float maxMp, float maxStamina, int runes, float level);
    Character(const Character &other);
    ~Character();

    Character &operator=(const Character &other);
    Character &operator++();
    Character operator++(int);
    Character &operator+(const Weapon &weapon);

    friend std::ostream &operator<<(std::ostream &os, const Character &Character);

    void equipWeapon(Weapon weapon);
    void equipSpell(Spell spell);
    void unequipSpell(int index);
    void setCurrentWeapon(int index);
    void setCurrentSpell(int index);
    int castSpell();
    void useHpFlask();
    void useMpFlask();
    void takeDamage(const Enemy &enemy);
    int calculateAttackPower() const;

    void print() const;
    void printStatus() const;
    void printInventory() const;
    void printSpell() const;

    const char *getName() const;
    float getHp() const;
    float getMaxHp() const;
    float getMp() const;
    float getMaxMp() const;
    float getStamina() const;
    float getMaxStamina() const;
    int getRunes() const;
    float getLevel() const;
    int getStrength() const;
    int getDexterity() const;
    int getIntelligence() const;
    int getFaith() const;
    int getEndurance() const;
    bool getIsAlive() const;

    void setHp(float newHp);
    void setMp(float newMp);
    void setStamina(float newStamina);
    void setRunes(int newRunes);
    void setLevel(float newLevel);
    void setStrength(int amount);
    void setDexterity(int amount);
    void setIntelligence(int amount);
    void setFaith(int amount);
    void setEndurance(int amount);
    void setIsAlive(bool alive);

protected:
    // void performSpecialPower() const;
    // bool canLearnSpell(const Spell &spell) const;
    // const char *getClassName() const;

    bool validHp(float hp) const;
    bool validMp(float mp) const;
    bool validRunes(int runes) const;
    bool validStamina(float stamina) const;
    bool validLevel(float level) const;

private:
    char *name;
    float hp, maxHp;
    float mp, maxMp;
    float stamina, maxStamina;

    int runes;
    float level;

    int strength, dexterity, intelligence, faith, endurance;

    int flaskChargesHp = 2, flaskChargesMp = 2;

    bool isAlive = true;

    float currentWeight, maxWeight;
    Weapon weaponSlots[8] = {};
    bool weaponsSlotsOccupied[8] = {false, false, false, false, false, false, false, false};
    int equippedWeapon;

    Spell spellSlots[8] = {};
    bool spellSlotsOccupied[8] = {false, false, false, false, false, false, false, false};
    int equippedSpell;
};