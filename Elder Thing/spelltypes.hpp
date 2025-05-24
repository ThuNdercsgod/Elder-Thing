#pragma once

#include "spell.hpp"

class SorcerySpell : public Spell
{
public:
    SorcerySpell() = delete;
    SorcerySpell(const char *name, float damage, int mpCost, int cooldown, int requiredIntelligence, int requiredFaith);

    void cast(Character *caster, Character *target) override;
    const char *getSpellType() const override;
    float calculateDamage() const override;
    Spell *clone() const override;
};

class IncantationSpell : public Spell
{
public:
    IncantationSpell() = delete;
    IncantationSpell(const char *name, float damage, int mpCost, int cooldown, int requiredIntelligence, int requiredFaith);

    void cast(Character *caster, Character *target) override;
    const char *getSpellType() const override;
    float calculateDamage() const override;
    Spell *clone() const override;
};