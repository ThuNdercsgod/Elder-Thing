#include <cstring>
#include <iostream>

#include "god.hpp"
#include "spell.hpp"

void God::castSpell(Spell *spell, Combatant *target)
{
    std::cout << "Casting Sorcery Spell: " << spell->getName()
              << " with damage: " << spell->getDamage()
              << " and MP cost: " << spell->getMpCost()
              << std::endl;

    spell->setRemainingCooldown(spell->getCooldown());
}

bool God::canCastSpell(const Spell *spell) const
{
    if (strcmp(spell->getSpellType(), "Sorcery") == 0 ||
        strcmp(spell->getSpellType(), "Incantation") == 0)
    {
        return true;
    }
    return false;
}

float God::calculateMagicPower() const
{
    return this->magicPower;
}

const char *God::getType() const
{
    return "God";
}

float God::getHp() const
{
    return this->hp;
}

void God::setHp(float hp)
{
    this->hp = hp;
}

void God::setMagicPower(float magicPower)
{
    this->magicPower = magicPower;
}