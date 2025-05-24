#pragma once

#include "interfaces.hpp"

class Demigod : public ElderBeing, public Combatant
{
public:
    void attack(Combatant *target) override;
    void defend(const Combatant *target) override;
    float calculateDamage() const override;
    const char *getType() const override;

    float getHp() const;

    void setHp(float hp);
    void setDamage(float damage);

private:
    float hp;
    float damage;
};