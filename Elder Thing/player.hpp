#pragma once

#include "weapon.hpp"

class Player
{
public:
    Player();
    Player(const char *name, float hp, float mp, float stamina, int runes, float level);
    Player(const Player &other);
    ~Player();

    Player &operator=(const Player &other);
    Player &operator++();
    Player operator++(int);
    Player &operator+(const Weapon &weapon);

    friend std::ostream &operator<<(std::ostream &os, const Player &player);

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

private:
    char *name;
    float hp, maxHp = 100;
    float mp, maxMp = 100;
    float stamina, maxStamina = 100;

    int runes;
    float level;

    int flaskChargesHp = 0, flaskChargesMp = 0;

    float currentWeight = 0, maxWeight = 100;
    Weapon weaponSlots[8] = {};
    bool weaponsSlotsOccupied[8] = {};
};