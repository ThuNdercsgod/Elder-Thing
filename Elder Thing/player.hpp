#pragma once

#include "spell.hpp"
#include "weapon.hpp"

class Player
{
public:
    Player();
    Player(const char *name, float maxHp, float maxMp, float maxStamina, int runes, float level);
    Player(const Player &other);
    ~Player();

    Player &operator=(const Player &other);
    Player &operator++();
    Player operator++(int);
    Player &operator+(const Weapon &weapon);

    friend std::ostream &operator<<(std::ostream &os, const Player &player);

    void equipWeapon(Weapon weapon);
    void equipSpell(Spell spell);
    void unequipSpell(int index);
    void setCurrentSpell(int index);
    int castSpell();

    void print() const;
    void printStatus() const;
    void printInventory() const;
    void printSpell() const;

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

    void setHp(float newHp);
    void setMp(float newMp);
    void setStamina(float newStamina);
    void setRunes(int newRunes);
    void setLevel(float newLevel);
    void increaseStrength(int amount);
    void increaseDexterity(int amount);
    void increaseIntelligence(int amount);
    void increaseFaith(int amount);
    void increaseEndurance(int amount);

private:
    void inputHp();
    void inputMp();
    void inputStamina();
    void inputRunes();
    void inputLevel();

    bool validHp(float hp) const;
    bool validMp(float mp) const;
    bool validRunes(int runes) const;
    bool validStamina(float stamina) const;
    bool validLevel(float level) const;
    // TODO valid() for strength, dexterity, intelligence, faith, endurance;

private:
    char *name;
    float hp, maxHp;
    float mp, maxMp;
    float stamina, maxStamina;

    int strength, dexterity, intelligence, faith, endurance;

    int runes;
    float level;

    int flaskChargesHp = 0, flaskChargesMp = 0;

    float currentWeight, maxWeight;
    Weapon weaponSlots[8] = {};
    bool weaponsSlotsOccupied[8] = {false, false, false, false, false, false, false, false};

    Spell spellSlots[8] = {};
    bool spellSlotsOccupied[8] = {false, false, false, false, false, false, false, false};
    int equippedSpell;
};