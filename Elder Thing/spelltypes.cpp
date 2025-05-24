#include "character.hpp"
#include "spelltypes.hpp"

SorcerySpell::SorcerySpell(const char *name, float damage, int mpCost, int cooldown, int requiredIntelligence, int requiredFaith)
    : Spell(name, damage, mpCost, cooldown, requiredIntelligence, requiredFaith) {}

void SorcerySpell::cast(Character *caster, Character *target)
{
    if (caster->getMp() < this->getMpCost())
    {
        std::cout << "Not enough MP to cast " << this->getName() << "!" << std::endl;
        return;
    }

    if (this->isOnCooldown())
    {
        std::cout << this->getName() << " is on cooldown for " << this->getRemainingCooldown() << " turns!" << std::endl;
        return;
    }

    if (caster->getIntelligence() < this->getRequiredIntelligence())
    {
        std::cout << caster->getName() << " does not have enough intelligence to cast " << this->getName() << "!" << std::endl;
        return;
    }

    if (caster->getFaith() < this->getRequiredFaith())
    {
        std::cout << caster->getName() << " does not have enough faith to cast " << this->getName() << "!" << std::endl;
        return;
    }

    target->setHp(target->getHp() - this->getDamage());
    caster->setMp(caster->getMp() - this->getMpCost());
    this->resetCooldown();
}

const char *SorcerySpell::getSpellType() const
{
    return "Sorcery";
}

float SorcerySpell::calculateDamage() const
{
    return this->getDamage();
}

Spell *SorcerySpell::clone() const
{
    return new SorcerySpell(*this);
}

IncantationSpell::IncantationSpell(const char *name, float damage, int mpCost, int cooldown, int requiredIntelligence, int requiredFaith)
    : Spell(name, damage, mpCost, cooldown, requiredIntelligence, requiredFaith) {}

void IncantationSpell::cast(Character *caster, Character *target)
{
    if (caster->getMp() < this->getMpCost())
    {
        std::cout << "Not enough MP to cast " << this->getName() << "!" << std::endl;
        return;
    }

    if (this->isOnCooldown())
    {
        std::cout << this->getName() << " is on cooldown for " << this->getRemainingCooldown() << " turns!" << std::endl;
        return;
    }

    if (caster->getIntelligence() < this->getRequiredIntelligence())
    {
        std::cout << caster->getName() << " does not have enough intelligence to cast " << this->getName() << "!" << std::endl;
        return;
    }

    if (caster->getFaith() < this->getRequiredFaith())
    {
        std::cout << caster->getName() << " does not have enough faith to cast " << this->getName() << "!" << std::endl;
        return;
    }

    target->setHp(target->getHp() - this->getDamage());
    caster->setMp(caster->getMp() - this->getMpCost());
    this->resetCooldown();
}

const char *IncantationSpell::getSpellType() const
{
    return "Incantation";
}

float IncantationSpell::calculateDamage() const
{
    return this->getDamage();
}

Spell *IncantationSpell::clone() const
{
    return new IncantationSpell(*this);
}
