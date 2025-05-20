#include <cstring>
#include <iostream>

#include "player.hpp"

Player::Player()
    : Player("Unknown", 100, 100, 100, 0, 0) {}

// Might throw std::invalid_argument or std::bad_alloc
Player::Player(const char *name, float maxHp, float maxMp, float maxStamina, int runes, float level)
    : flaskChargesHp(0), flaskChargesMp(0), currentWeight(0), maxWeight(100), equippedSpell(-1),
      equippedWeapon(-1), strength(0), dexterity(0), intelligence(0), faith(0), endurance(0)
{
    if (!(this->validHp(maxHp) &&
          this->validMp(maxMp) &&
          this->validStamina(maxStamina) &&
          this->validRunes(runes) &&
          this->validLevel(level)))
    {
        throw std::invalid_argument("Invalid Player parameters!");
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
Player::Player(const Player &other)
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

Player::~Player()
{
    delete[] this->name;
    this->name = nullptr;
}

// Might throw std::bad_alloc
Player &Player::operator=(const Player &other)
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

Player &Player::operator++()
{
    int level = this->level;

    this->level = level + 1;

    return *this;
}

Player Player::operator++(int)
{
    Player old = *this;
    int level = this->level;
    this->level = level + 1;

    return old;
}

Player &Player::operator+(const Weapon &weapon)
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
        weaponSlots[i] = weapon;
        weaponsSlotsOccupied[i] = true;
        this->currentWeight += weapon.getWeight();
    }
    else
    {
        std::cout << "Player level is not high enough! "
                  << weapon.getName()
                  << " not equipped!" << std::endl;
    }
    return *this;
}

// Might throw std::ios_base::failure
std::ostream &operator<<(std::ostream &os, const Player &player)
{
    if (os.fail() || os.bad())
    {
        throw std::ios_base::failure("Output stream error!");
    }

    return os << "\n=== " << player.name << " stats ===\n"
              << "HP: " << player.hp << "/" << player.maxHp
              << "\nMP: " << player.mp << "/" << player.maxMp
              << "\nRunes: " << player.runes
              << "\nLevel: " << player.level
              << "\nCurrent weight: " << player.currentWeight;
}

void Player::equipWeapon(Weapon weapon)
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

    if (weapon.getRequiredLevel() <= this->getLevel())
    {
        weaponSlots[i] = weapon;
        weaponsSlotsOccupied[i] = true;
        this->currentWeight += weapon.getWeight();
    }
    else
    {
        std::cout << "Player level is not high enough! "
                  << weapon.getName()
                  << " not equipped!" << std::endl;
    }
}

void Player::equipSpell(Spell spell)
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

    if (spell.getRequiredIntelligence() <= this->intelligence &&
        spell.getRequiredFaith() <= this->faith)
    {
        spellSlots[i] = spell;
        spellSlotsOccupied[i] = true;
    }
    else
    {
        std::cout << "Player intelligence or faith is not high enough! "
                  << spell.getName()
                  << " not learned!" << std::endl;
    }
}

// Might throw std::invalid_argument
void Player::unequipSpell(int index)
{
    if (index < 0 || index >= 8)
    {
        throw std::invalid_argument("Invalid spell slot!");
    }

    if (this->spellSlotsOccupied[index] == true)
    {
        this->spellSlotsOccupied[index] = false;
        this->spellSlots[index] = Spell();
    }
    else
    {
        std::cout << "Spell slot is already empty!" << std::endl;
    }
}

// Might throw std::invalid_argument
void Player::setCurrentWeapon(int index)
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

void Player::setCurrentSpell(int index)
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

int Player::castSpell()
{
    if (this->spellSlots[this->equippedSpell].isOnCooldown() == false)
    {
        this->spellSlots[this->equippedSpell].setRemainingCooldown(this->spellSlots[this->equippedSpell].getCooldown());
        return this->spellSlots[this->equippedSpell].getDamage();
    }
    else
    {
        std::cout << "Spell is on cooldown!" << std::endl;
        return 0;
    }
}

void Player::useHpFlask()
{
    this->flaskChargesHp--;
    this->hp = this->maxHp;
}

void Player::useMpFlask()
{
    this->flaskChargesMp--;
    this->mp = this->maxMp;
}

void Player::takeDamage(const Enemy &enemy)
{
    if (this->hp <= enemy.getDamage())
    {
        this->hp = 0;
        this->isAlive = false;
    }
    else
    {
        this->hp -= enemy.getDamage();
    }
}

int Player::calculateAttackPower() const
{
    return this->weaponSlots[this->equippedWeapon].getDamage();
}

void Player::print() const
{
    std::cout << "\n=== " << this->name << " stats ===\n"
              << "HP: " << this->hp << "/" << this->maxHp
              << "\nMP: " << this->mp << "/" << this->maxMp
              << "\nRunes: " << this->runes
              << "\nLevel: " << this->level
              << "\nCurrent weight: " << this->currentWeight
              << std::endl;

    this->printInventory();
    this->printSpell();
}

void Player::printStatus() const
{
    std::cout << "\n=== " << this->name << " stats ===\n"
              << "HP: " << this->hp << "/" << this->maxHp
              << "\nMP: " << this->mp << "/" << this->maxMp
              << "\nRunes: " << this->runes
              << "\nLevel: " << this->level
              << "\nCurrent weight: " << this->currentWeight
              << std::endl;
}

void Player::printInventory() const
{
    std::cout << "\n=== Inventory ===" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        if (this->weaponsSlotsOccupied[i] == true)
        {
            std::cout << i + 1 << ". " << weaponSlots[i].getName() << std::endl;
        }
        else
        {
            std::cout << i + 1 << ". [Unoccupied]\n";
        }
    }
    std::cout << std::endl;
}

void Player::printSpell() const
{
    std::cout << "\n=== Spells ===" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        if (this->spellSlotsOccupied[i] == true)
        {
            std::cout << i + 1 << ". " << spellSlots[i].getName() << std::endl;
        }
        else
        {
            std::cout << i + 1 << ". [Unoccupied]\n";
        }
    }
    std::cout << std::endl;
}

const char *Player::getName() const
{
    return this->name;
}

float Player::getHp() const
{
    return this->hp;
}

float Player::getMaxHp() const
{
    return this->maxHp;
}

float Player::getMp() const
{
    return this->mp;
}

float Player::getMaxMp() const
{
    return this->maxMp;
}

float Player::getStamina() const
{
    return this->stamina;
}

float Player::getMaxStamina() const
{
    return this->maxStamina;
}

int Player::getRunes() const
{
    return this->runes;
}

float Player::getLevel() const
{
    return this->level;
}

int Player::getStrength() const
{
    return this->strength;
}

int Player::getDexterity() const
{
    return this->dexterity;
}

int Player::getIntelligence() const
{
    return this->intelligence;
}

int Player::getFaith() const
{
    return this->faith;
}

int Player::getEndurance() const
{
    return this->endurance;
}

bool Player::getIsAlive() const
{
    return this->isAlive;
}

// Might throw std::invalid_argument;
void Player::setHp(float newHp)
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
        throw std::invalid_argument("Invalid Player HP!");
    }
}

// Might throw std::invalid_argument;
void Player::setMp(float newMp)
{
    if (this->validMp(newMp))
    {
        this->mp = newMp;
    }
    else
    {
        throw std::invalid_argument("Invalid Player MP!");
    }
}

// Might throw std::invalid_argument;
void Player::setStamina(float newStamina)
{
    if (this->validStamina(newStamina))
    {
        this->stamina = newStamina;
    }
    else
    {
        throw std::invalid_argument("Invalid Player stamina!");
    }
}

// Might throw std::invalid_argument;
void Player::setRunes(int newRunes)
{
    if (this->validRunes(newRunes))
    {
        this->runes = newRunes;
    }
    else
    {
        throw std::invalid_argument("Invalid Player runes!");
    }
}

// Might throw std::invalid_argument;
void Player::setLevel(float newLevel)
{
    if (this->validLevel(newLevel))
    {
        this->level = newLevel;
    }
    else
    {
        throw std::invalid_argument("Invalid Player level!");
    }
}

void Player::setStrength(int amount)
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

void Player::setDexterity(int amount)
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

void Player::setIntelligence(int amount)
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

void Player::setFaith(int amount)
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

void Player::setEndurance(int amount)
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

void Player::setIsAlive(bool alive)
{
    this->isAlive = alive;
}

bool Player::validHp(float hp) const
{
    if (!(hp >= 0))
    {
        std::cout << "Invalid player HP!" << std::endl;
        return false;
    }
    return true;
}

bool Player::validMp(float mp) const
{
    if (!(mp >= 0))
    {
        std::cout << "Invalid player MP!" << std::endl;
        return false;
    }
    return true;
}

bool Player::validStamina(float stamina) const
{
    if (!(stamina >= 0))
    {
        std::cout << "Invalid player stamina!" << std::endl;
        return false;
    }
    return true;
}

bool Player::validRunes(int runes) const
{
    if (!(runes >= 0))
    {
        std::cout << "Invalid player runes!" << std::endl;
        return false;
    }
    return true;
}

bool Player::validLevel(float level) const
{
    if (!(level >= 0))
    {
        std::cout << "Invalid player level!" << std::endl;
        return false;
    }
    return true;
}