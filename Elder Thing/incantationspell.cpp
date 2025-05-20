#include "incantationspell.hpp"

IncantationSpell::IncantationSpell(const char *name, float damage, int mpCost, int cooldown, int requiredIntelligence, int requiredFaith)
    : Spell(name, damage, mpCost, cooldown, requiredIntelligence, requiredFaith) {}

const char *IncantationSpell::getSpellType() const
{
    return "Incantation";
}