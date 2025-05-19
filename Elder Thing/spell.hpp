#pragma once

class Player;

class Spell
{
public:
    Spell();
    Spell(const char *name, float damage, int mpCost, int cooldown, int requiredIntelligence, int requiredFaith);
    Spell(const Spell &other);
    ~Spell();

    Spell &operator=(const Spell &other);
    bool operator<(const Spell &other) const;
    bool operator>(const Spell &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Spell &spell);

    void resetCooldown();
    void decrementCooldown(int amount);
    bool isOnCooldown() const;
    // const char *getSpellType() const;

    void print() const;

    friend class Player;

    char *getName() const;
    int getRemainingCooldown() const;

private:
    char *name;
    float damage;
    int mpCost;
    int cooldown;
    int requiredIntelligence;
    int requiredFaith;
    int remainingCooldown;
};