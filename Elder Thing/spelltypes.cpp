#include "spelltypes.hpp"

SorcerySpell::SorcerySpell(const char *name, float damage, int mpCost, int cooldown, int requiredIntelligence, int requiredFaith)
    : Spell(name, damage, mpCost, cooldown, requiredIntelligence, requiredFaith) {}

const char *SorcerySpell::getSpellType() const
{
    return "Sorcery";
}

IncantationSpell::IncantationSpell(const char *name, float damage, int mpCost, int cooldown, int requiredIntelligence, int requiredFaith)
    : Spell(name, damage, mpCost, cooldown, requiredIntelligence, requiredFaith) {}

const char *IncantationSpell::getSpellType() const
{
    return "Incantation";
}