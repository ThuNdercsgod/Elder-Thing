#pragma once

#include "weapon.hpp"

class Player
{
public:
    Player();
    Player(float hp, float mp, float stamina, int runes, float level);
    ~Player();

    void equipWeapon(Weapon weapon);

    void print();
    void printInventory();

    void setHp(float newHp);
    void setMp(float newMp);
    void setStamina(float newStamina);
    void setRunes(int newRunes);
    void setLevel(float newLevel);

    float getHp() const;
    float getMaxHp() const;
    float getMaxMp() const;
    float getMp() const;
    float getStamina() const;
    float getMaxStamina() const;
    int getRunes() const;
    float getLevel() const;

private:
    bool validHp(float hp) const;
    bool validMp(float mp) const;
    bool validRunes(int runes) const;
    bool validStamina(float stamina) const;
    bool validLevel(float level) const;

private:
    float hp, maxHp = 100;
    float mp, maxMp = 100;
    float stamina, maxStamina = 100;

    int runes;
    float level;

    int flaskChargesHp = 0, flaskChargesMp = 0;

    float currentWeight = 0, maxWeight = 20;
    Weapon weaponSlots[8] = {};
    bool weaponsSlotsOccupied[8] = {};
};