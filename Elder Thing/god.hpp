#pragma once

#include "interfaces.hpp"

class God : public ElderBeing, public MagicUser
{
public:
    void castSpell(Spell *spell, Combatant *target) override;
    bool canCastSpell(const Spell *spell) const override;
    float calculateMagicPower() const override;
    const char *getType() const override;

    float getHp() const;

    void setHp(float hp);
    void setMagicPower(float magicPower);

private:
    float hp;
    float magicPower;
};