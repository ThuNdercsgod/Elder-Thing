#pragma once

class Weapon
{
public:
    void print() const;
    bool loadFromFile();
    bool saveToFile() const;
    void input();
    void initialize(const char *name, float damage, float weight, int requiredStrength);

    float getDamage() const;
    float getWeight() const;
    int getRequiredStrength() const;
    const char *getName() const;

private:
    void inputName();
    void inputDamage();
    void inputWeight();
    void inputRequiredStrength();

    bool validName(const char *name) const;
    bool validDamage(float damage) const;
    bool validWeight(int weight) const;
    bool validRequiredStrength(int requiredStrength) const;

private:
    float damage = 0;
    float weight = 0;
    int requiredStrength = 0;
    char name[32] = "";
};