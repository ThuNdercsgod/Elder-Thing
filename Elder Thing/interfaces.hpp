#pragma once

class Character;
class Spell;

class Entity
{
public:
    // virtual void updateState() = 0;
    virtual const char *getType() const = 0;
    // virtual Entity *clone() const = 0;
    // virtual void acceptVisitor(Entity *visitor) = 0;
    virtual ~Entity() = default;
};

class ElderBeing : virtual public Entity
{
public:
    virtual ~ElderBeing() = default;
};

class Combatant : virtual public Entity
{
public:
    virtual void attack(Combatant *target) = 0;
    virtual void defend(const Combatant *target) = 0;
    virtual float calculateDamage() const = 0;
    virtual Combatant *clone() const = 0;
    virtual ~Combatant() = default;
};

class MagicUser : virtual public Entity
{
public:
    virtual void castSpell(Spell *spell, Combatant *target) = 0;
    virtual bool canCastSpell(const Spell *spell) const = 0;
    virtual float calculateMagicPower() const = 0;
    virtual ~MagicUser() = default;
};
