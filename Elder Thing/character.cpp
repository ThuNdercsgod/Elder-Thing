#include <cstring>
#include <iostream>

#include "character.hpp"

Character::Character()
    : Character("Unknown", 100, 100, 100, 0, 0) {}

// Might throw std::invalid_argument or std::bad_alloc
Character::Character(const char *name, float maxHp, float maxMp, float maxStamina, int runes, float level)
    : flaskChargesHp(0), flaskChargesMp(0), currentWeight(0), maxWeight(100), equippedSpell(-1),
      equippedWeapon(-1), strength(0), dexterity(0), intelligence(0), faith(0), endurance(0)
{
    if (!(this->validHp(maxHp) &&
          this->validMp(maxMp) &&
          this->validStamina(maxStamina) &&
          this->validRunes(runes) &&
          this->validLevel(level)))
    {
        throw std::invalid_argument("Invalid Character parameters!");
    }
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->hp = maxHp;
    if (this->hp == 0)
    {
        this->isAlive = false;
    }
    this->maxHp = maxHp;
    this->mp = maxMp;
    this->maxMp = maxMp;
    this->stamina = maxStamina;
    this->maxStamina = maxStamina;

    this->runes = runes;
    this->level = level;
}

// Might throws std::bad_alloc
Character::Character(const Character &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->hp = other.hp;
    this->maxHp = other.maxHp;
    this->mp = other.mp;
    this->maxMp = other.maxMp;
    this->stamina = other.stamina;
    this->maxStamina = other.maxStamina;

    this->runes = other.runes;
    this->level = other.level;

    this->strength = other.strength;
    this->dexterity = other.dexterity;
    this->intelligence = other.intelligence;
    this->faith = other.faith;
    this->endurance = other.endurance;

    this->flaskChargesHp = other.flaskChargesHp;
    this->flaskChargesMp = other.flaskChargesMp;

    this->isAlive = other.isAlive;

    this->currentWeight = other.currentWeight;
    this->maxWeight = other.maxWeight;
    for (int i = 0; i < 8; i++)
    {
        this->weaponsSlotsOccupied[i] = other.weaponsSlotsOccupied[i];
        this->weaponSlots[i] = other.weaponSlots[i];
        this->spellSlots[i] = other.spellSlots[i];
        this->spellSlotsOccupied[i] = other.spellSlotsOccupied[i];
    }
    this->equippedWeapon = other.equippedWeapon;
    this->equippedSpell = other.equippedSpell;
}

Character::~Character()
{
    delete[] this->name;
    this->name = nullptr;
}

// Might throw std::bad_alloc
Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        delete[] this->name;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);

        this->hp = other.hp;
        this->maxHp = other.maxHp;
        this->mp = other.mp;
        this->maxMp = other.maxMp;
        this->stamina = other.stamina;
        this->maxStamina = other.maxStamina;

        this->runes = other.runes;
        this->level = other.level;

        this->strength = other.strength;
        this->dexterity = other.dexterity;
        this->intelligence = other.intelligence;
        this->faith = other.faith;
        this->endurance = other.endurance;

        this->flaskChargesHp = other.flaskChargesHp;
        this->flaskChargesMp = other.flaskChargesMp;

        this->isAlive = other.isAlive;

        this->currentWeight = other.currentWeight;
        this->maxWeight = other.maxWeight;
        for (int i = 0; i < 8; i++)
        {
            this->weaponsSlotsOccupied[i] = other.weaponsSlotsOccupied[i];
            this->weaponSlots[i] = other.weaponSlots[i];
            this->spellSlots[i] = other.spellSlots[i];
            this->spellSlotsOccupied[i] = other.spellSlotsOccupied[i];
        }
        this->equippedWeapon = other.equippedWeapon;
        this->equippedSpell = other.equippedSpell;
    }
    return *this;
}

Character &Character::operator++()
{
    int level = this->level;

    this->level = level + 1;

    return *this;
}

Character &Character::operator++(int)
{
    int level = this->level;
    this->level = level + 1;

    return *this;
}

Character &Character::operator+(const Weapon &weapon)
{
    int i = 0;
    while (this->weaponsSlotsOccupied[i] == true)
    {
        i++;

        if (i == 8)
        {
            std::cout << "Inventory full! Weapon is not equipped!" << std::endl;
            return *this;
        }
    }

    if (weapon.getRequiredLevel() <= this->getLevel())
    {
        weaponSlots[i] = (Weapon *)&weapon;
        weaponsSlotsOccupied[i] = true;
        this->currentWeight += weapon.getWeight();
    }
    else
    {
        std::cout << "Character level is not high enough! "
                  << weapon.getName()
                  << " not equipped!" << std::endl;
    }
    return *this;
}

// Might throw std::ios_base::failure
std::ostream &operator<<(std::ostream &os, const Character &Character)
{
    if (os.fail() || os.bad())
    {
        throw std::ios_base::failure("Output stream error!");
    }

    return os << "\n=== " << Character.name << " stats ===\n"
              << "HP: " << Character.hp << "/" << Character.maxHp
              << "\nMP: " << Character.mp << "/" << Character.maxMp
              << "\nRunes: " << Character.runes
              << "\nLevel: " << Character.level
              << "\nCurrent weight: " << Character.currentWeight;
}

void Character::equipWeapon(Weapon *weapon)
{
    int i = 0;
    while (this->weaponsSlotsOccupied[i] == true)
    {
        i++;

        if (i == 8)
        {
            std::cout << "Inventory full! Weapon is not equipped!" << std::endl;
            return;
        }
    }

    if (weapon->getRequiredLevel() <= this->getLevel())
    {
        weaponSlots[i] = weapon;
        weaponsSlotsOccupied[i] = true;
        this->currentWeight += weapon->getWeight();
    }
    else
    {
        std::cout << "Character level is not high enough! "
                  << weapon->getName()
                  << " not equipped!" << std::endl;
    }
}

void Character::equipSpell(Spell *spell)
{
    int i = 0;
    while (this->spellSlotsOccupied[i] == true)
    {
        i++;

        if (i == 8)
        {
            std::cout << "Inventory full! Spell is not learned!" << std::endl;
            return;
        }
    }

    if (spell->getRequiredIntelligence() <= this->intelligence &&
        spell->getRequiredFaith() <= this->faith)
    {
        spellSlots[i] = spell;
        spellSlotsOccupied[i] = true;
    }
    else
    {
        std::cout << "Character intelligence or faith is not high enough! "
                  << spell->getName()
                  << " not learned!" << std::endl;
    }
}

// Might throw std::invalid_argument
void Character::unequipSpell(int index)
{
    if (index < 0 || index >= 8)
    {
        throw std::invalid_argument("Invalid spell slot!");
    }

    if (this->spellSlotsOccupied[index] == true)
    {
        this->spellSlotsOccupied[index] = false;
        this->spellSlots[index] = nullptr;
    }
    else
    {
        std::cout << "Spell slot is already empty!" << std::endl;
    }
}

// Might throw std::invalid_argument
void Character::setCurrentWeapon(int index)
{
    if (index < 0 || index >= 8)
    {
        throw std::invalid_argument("Invalid weapon slot!");
    }

    if (this->weaponsSlotsOccupied[index] == true)
    {
        this->equippedWeapon = index;
    }
    else
    {
        throw std::invalid_argument("Invalid weapon slot!");
    }
}

void Character::setCurrentSpell(int index)
{
    if (index < 0 || index >= 8)
    {
        throw std::invalid_argument("Invalid spell slot!");
    }

    if (this->spellSlotsOccupied[index] == true)
    {
        this->equippedSpell = index;
    }
    else
    {
        throw std::invalid_argument("Invalid spell slot!");
    }
}

int Character::castSpell()
{
    if (this->spellSlots[this->equippedSpell]->isOnCooldown() == false)
    {
        this->spellSlots[this->equippedSpell]->setRemainingCooldown(this->spellSlots[this->equippedSpell]->getCooldown());
        return this->spellSlots[this->equippedSpell]->getDamage();
    }
    else
    {
        std::cout << "Spell is on cooldown!" << std::endl;
        return 0;
    }
}

void Character::useHpFlask()
{
    this->flaskChargesHp--;
    this->hp = this->maxHp;
}

void Character::useMpFlask()
{
    this->flaskChargesMp--;
    this->mp = this->maxMp;
}

// void Character::print() const
// {
//     std::cout << "\n=== " << this->name << " stats ===\n"
//               << "HP: " << this->hp << "/" << this->maxHp
//               << "\nMP: " << this->mp << "/" << this->maxMp
//               << "\nRunes: " << this->runes
//               << "\nLevel: " << this->level
//               << "\nCurrent weight: " << this->currentWeight
//               << std::endl;

//     this->printInventory();
//     this->printSpell();
// }

// void Character::printStatus() const
// {
//     std::cout << "\n=== " << this->name << " stats ===\n"
//               << "HP: " << this->hp << "/" << this->maxHp
//               << "\nMP: " << this->mp << "/" << this->maxMp
//               << "\nRunes: " << this->runes
//               << "\nLevel: " << this->level
//               << "\nCurrent weight: " << this->currentWeight
//               << std::endl;
// }

void Character::printInventory() const
{
    std::cout << "\n=== Inventory ===" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        if (this->weaponsSlotsOccupied[i] == true)
        {
            std::cout << i + 1 << ". " << weaponSlots[i]->getName() << std::endl;
        }
        else
        {
            std::cout << i + 1 << ". [Unoccupied]\n";
        }
    }
    std::cout << std::endl;
}

void Character::printSpell() const
{
    std::cout << "\n=== Spells ===" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        if (this->spellSlotsOccupied[i] == true)
        {
            std::cout << i + 1 << ". " << spellSlots[i]->getName() << std::endl;
        }
        else
        {
            std::cout << i + 1 << ". [Unoccupied]\n";
        }
    }
    std::cout << std::endl;
}

const char *Character::getName() const
{
    return this->name;
}

float Character::getHp() const
{
    return this->hp;
}

float Character::getMaxHp() const
{
    return this->maxHp;
}

float Character::getMp() const
{
    return this->mp;
}

float Character::getMaxMp() const
{
    return this->maxMp;
}

float Character::getStamina() const
{
    return this->stamina;
}

float Character::getMaxStamina() const
{
    return this->maxStamina;
}

int Character::getRunes() const
{
    return this->runes;
}

float Character::getLevel() const
{
    return this->level;
}

int Character::getStrength() const
{
    return this->strength;
}

int Character::getDexterity() const
{
    return this->dexterity;
}

int Character::getIntelligence() const
{
    return this->intelligence;
}

int Character::getFaith() const
{
    return this->faith;
}

int Character::getEndurance() const
{
    return this->endurance;
}

bool Character::getIsAlive() const
{
    return this->isAlive;
}

int Character::getEquippedWeapon() const
{
    return this->equippedWeapon;
}

int Character::getEquippedSpell() const
{
    return this->equippedSpell;
}

Weapon *Character::getWeapon(int index) const
{
    if (index < 0 || index >= 8)
    {
        throw std::invalid_argument("Invalid weapon slot!");
    }

    if (this->weaponsSlotsOccupied[index] == true)
    {
        return this->weaponSlots[index];
    }
    else
    {
        throw std::invalid_argument("Invalid weapon slot!");
    }
}

Spell *Character::getSpell(int index) const
{
    if (index < 0 || index >= 8)
    {
        throw std::invalid_argument("Invalid spell slot!");
    }

    if (this->spellSlotsOccupied[index] == true)
    {
        return this->spellSlots[index];
    }
    else
    {
        throw std::invalid_argument("Invalid spell slot!");
    }
}

// Might throw std::invalid_argument;
void Character::setHp(float newHp)
{
    if (this->validHp(newHp))
    {
        this->hp = newHp;
        if (this->hp == 0)
        {
            this->isAlive = false;
        }
    }
    else
    {
        throw std::invalid_argument("Invalid Character HP!");
    }
}

// Might throw std::invalid_argument;
void Character::setMp(float newMp)
{
    if (this->validMp(newMp))
    {
        this->mp = newMp;
    }
    else
    {
        throw std::invalid_argument("Invalid Character MP!");
    }
}

// Might throw std::invalid_argument;
void Character::setStamina(float newStamina)
{
    if (this->validStamina(newStamina))
    {
        this->stamina = newStamina;
    }
    else
    {
        throw std::invalid_argument("Invalid Character stamina!");
    }
}

// Might throw std::invalid_argument;
void Character::setRunes(int newRunes)
{
    if (this->validRunes(newRunes))
    {
        this->runes = newRunes;
    }
    else
    {
        throw std::invalid_argument("Invalid Character runes!");
    }
}

// Might throw std::invalid_argument;
void Character::setLevel(float newLevel)
{
    if (this->validLevel(newLevel))
    {
        this->level = newLevel;
    }
    else
    {
        throw std::invalid_argument("Invalid Character level!");
    }
}

void Character::setStrength(int amount)
{
    if (amount > 0)
    {
        this->strength += amount;
    }
    else
    {
        std::cout << "Invalid amount for stat increase!" << std::endl;
    }
}

void Character::setDexterity(int amount)
{
    if (amount > 0)
    {
        this->dexterity += amount;
    }
    else
    {
        std::cout << "Invalid amount for stat increase!" << std::endl;
    }
}

void Character::setIntelligence(int amount)
{
    if (amount > 0)
    {
        this->intelligence += amount;
    }
    else
    {
        std::cout << "Invalid amount for stat increase!" << std::endl;
    }
}

void Character::setFaith(int amount)
{
    if (amount > 0)
    {
        this->faith += amount;
    }
    else
    {
        std::cout << "Invalid amount for stat increase!" << std::endl;
    }
}

void Character::setEndurance(int amount)
{
    if (amount > 0)
    {
        this->endurance += amount;
    }
    else
    {
        std::cout << "Invalid amount for stat increase!" << std::endl;
    }
}

void Character::setIsAlive(bool alive)
{
    this->isAlive = alive;
}

bool Character::validHp(float hp) const
{
    if (!(hp >= 0))
    {
        std::cout << "Invalid Character HP!" << std::endl;
        return false;
    }
    return true;
}

bool Character::validMp(float mp) const
{
    if (!(mp >= 0))
    {
        std::cout << "Invalid Character MP!" << std::endl;
        return false;
    }
    return true;
}

bool Character::validStamina(float stamina) const
{
    if (!(stamina >= 0))
    {
        std::cout << "Invalid Character stamina!" << std::endl;
        return false;
    }
    return true;
}

bool Character::validRunes(int runes) const
{
    if (!(runes >= 0))
    {
        std::cout << "Invalid Character runes!" << std::endl;
        return false;
    }
    return true;
}

bool Character::validLevel(float level) const
{
    if (!(level >= 0))
    {
        std::cout << "Invalid Character level!" << std::endl;
        return false;
    }
    return true;
}