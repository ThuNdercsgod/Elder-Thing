#pragma once

#include "spell.hpp"

class SorcerySpell : public Spell
{
public:
    SorcerySpell() = delete;
    SorcerySpell(const char *name, float damage, int mpCost, int cooldown, int requiredIntelligence, int requiredFaith);

    const char *getSpellType() const;
};