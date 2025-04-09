#pragma once

class Weapon
{
public:
    Weapon();
    Weapon(const char *name, float damage, float weight, int requiredLevel);

    void print() const;
    bool loadFromFile();
    bool saveToFile() const;

    float getDamage() const;
    float getWeight() const;
    int getRequiredLevel() const;
    const char *getName() const;

private:
    void inputName();
    void inputDamage();
    void inputWeight();
    void inputRequiredLevel();

    bool validName(const char *name) const;
    bool validDamage(float damage) const;
    bool validWeight(float weight) const;
    bool validRequiredLevel(int requiredLevel) const;

private:
    float damage = 0;
    float weight = 0;
    int requiredLevel = 0;
    char name[32] = "";
};