#pragma once

#include <iostream>

class Character;

class Spell
{
public:
    Spell();
    Spell(const char *name, float damage, int mpCost, int cooldown, int requiredIntelligence, int requiredFaith);
    Spell(const Spell &other);
    virtual ~Spell();

    Spell &operator=(const Spell &other);
    bool operator<(const Spell &other) const;
    bool operator>(const Spell &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Spell &spell);

    void resetCooldown();
    void decrementCooldown(int amount);
    bool isOnCooldown() const;

    void print() const;

    virtual void cast(Character *caster, Character *target) = 0;
    virtual const char *getSpellType() const = 0;
    virtual float calculateDamage() const = 0;

    const char *getName() const;
    float getDamage() const;
    int getMpCost() const;
    int getCooldown() const;
    int getRequiredIntelligence() const;
    int getRequiredFaith() const;
    int getRemainingCooldown() const;

    void setName(const char *name);
    void setDamage(float damage);
    void setMpCost(int mpCost);
    void setCooldown(int cooldown);
    void setRequiredIntelligence(int requiredIntelligence);
    void setRequiredFaith(int requiredFaith);
    void setRemainingCooldown(int remainingCooldown);

protected:
    bool validName(const char *name) const;
    bool validDamage(float damage) const;
    bool validMpCost(int mpCost) const;
    bool validCooldown(int cooldown) const;
    bool validRequiredIntelligence(int requiredIntelligence) const;
    bool validRequiredFaith(int requiredFaith) const;
    bool validRemainingCooldown(int remainingCooldown) const;

private:
    char *name;
    float damage;
    int mpCost;
    int cooldown;
    int requiredIntelligence;
    int requiredFaith;
    int remainingCooldown;
};