#pragma once

#include "spell.hpp"

class IncantationSpell : public Spell 
{
public:
    IncantationSpell() = delete;
    IncantationSpell(const char *name, float damage, int mpCost, int cooldown, int requiredIntelligence, int requiredFaith);

    const char *getSpellType() const;
};