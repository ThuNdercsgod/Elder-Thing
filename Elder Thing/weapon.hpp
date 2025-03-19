#pragma once

class Weapon
{
public:
    void print();
    bool loadFromFile();
    bool saveToFile();
    void initialize();

private:
    bool validName();
    bool validDamage();
    bool validWeight();
    bool validRequieredStrength();

private:
    float damage = 0;
    float weight = 0;
    int requiredStrength = 0;
    char name[32] = "\0";
};