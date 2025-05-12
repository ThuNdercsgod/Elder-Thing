#pragma once

class Weapon
{
public:
    Weapon();
    Weapon(const char *name, float damage, float weight, int requiredLevel);
    Weapon(const Weapon &other);
    ~Weapon();

    Weapon &operator=(const Weapon &other);
    bool operator==(const Weapon &other);
    bool operator!=(const Weapon &other);
    bool operator>(const Weapon &other);
    bool operator<(const Weapon &other);
    friend std::ostream &operator<<(std::ostream &os, const Weapon &weapon);
    // friend std::istream &operator>>(std::istream &is, const Weapon &weapon);

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
    char *name;
    float damage;
    float weight;
    int requiredLevel;
};