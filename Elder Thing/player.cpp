#include <cstring>
#include <iostream>

#include "player.hpp"

Player::Player() : Player("Unknown", 100, 100, 100, 0, 0) {}

// Might throw std::invalid_argument or std::bad_alloc
Player::Player(const char *name, float maxHp, float maxMp, float maxStamina, int runes, float level)
    : flaskChargesHp(0), flaskChargesMp(0), currentWeight(0), maxWeight(100), equippedSpell(-1),
      strength(0), dexterity(0), intelligence(0), faith(0), endurance(0)
{
    if (this->validHp(maxHp) &&
        this->validMp(maxMp) &&
        this->validStamina(maxStamina) &&
        this->validRunes(runes) &&
        this->validLevel(level))
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        this->hp = maxHp;
        this->maxHp = maxHp;
        this->mp = maxMp;
        this->maxMp = maxMp;
        this->stamina = maxStamina;
        this->maxStamina = maxStamina;

        this->runes = runes;
        this->level = level;
    }
    else
    {
        throw std::invalid_argument("Invalid Player parameters!");
    }
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

    this->strength = other.strength;
    this->dexterity = other.dexterity;
    this->intelligence = other.intelligence;
    this->faith = other.faith;
    this->endurance = other.endurance;

    this->runes = other.runes;
    this->level = other.level;

    this->flaskChargesHp = other.flaskChargesHp;
    this->flaskChargesMp = other.flaskChargesMp;

    this->currentWeight = other.currentWeight;
    this->maxWeight = other.maxWeight;
    for (int i = 0; i < 8; i++)
    {
        this->weaponsSlotsOccupied[i] = other.weaponsSlotsOccupied[i];
        this->weaponSlots[i] = other.weaponSlots[i];
        this->spellSlots[i] = other.spellSlots[i];
        this->spellSlotsOccupied[i] = other.spellSlotsOccupied[i];
    }
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

        this->strength = other.strength;
        this->dexterity = other.dexterity;
        this->intelligence = other.intelligence;
        this->faith = other.faith;
        this->endurance = other.endurance;

        this->runes = other.runes;
        this->level = other.level;

        this->flaskChargesHp = other.flaskChargesHp;
        this->flaskChargesMp = other.flaskChargesMp;

        this->currentWeight = other.currentWeight;
        this->maxWeight = other.maxWeight;
        for (int i = 0; i < 8; i++)
        {
            this->weaponsSlotsOccupied[i] = other.weaponsSlotsOccupied[i];
            this->weaponSlots[i] = other.weaponSlots[i];
            this->spellSlots[i] = other.spellSlots[i];
            this->spellSlotsOccupied[i] = other.spellSlotsOccupied[i];
        }
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

    if (spell.requiredIntelligence <= this->intelligence &&
        spell.requiredFaith <= this->faith)
    {
        spellSlots[i] = spell;
        spellSlotsOccupied[i] = true;
    }
    else
    {
        std::cout << "Player intelligence or faith is not high enough! "
                  << spell.name
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
        std::cout << "Spell slot is empty!" << std::endl;
    }
}

int Player::castSpell()
{
    if (this->spellSlots[this->equippedSpell].isOnCooldown() == false)
    {
        this->spellSlots[this->equippedSpell].remainingCooldown = this->spellSlots[this->equippedSpell].cooldown;
        return this->spellSlots[this->equippedSpell].damage;
    }
    else
    {
        std::cout << "Spell is on cooldown!" << std::endl;
        return 0;
    }
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
            std::cout << i + 1 << ". " << spellSlots[i].name << std::endl;
        }
        else
        {
            std::cout << i + 1 << ". [Unoccupied]\n";
        }
    }
    std::cout << std::endl;
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

// Might throw std::invalid_argument;
void Player::setHp(float newHp)
{
    if (this->validHp(newHp))
    {
        this->hp = newHp;
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

void Player::increaseStrength(int amount)
{
    this->strength += amount;
}

void Player::increaseDexterity(int amount)
{
    this->dexterity += amount;
}

void Player::increaseIntelligence(int amount)
{
    this->intelligence += amount;
}

void Player::increaseFaith(int amount)
{
    this->faith += amount;
}

void Player::increaseEndurance(int amount)
{
    this->endurance += amount;
}

void Player::inputHp()
{
    float input;
    bool valid;

    do
    {
        std::cout << "Enter the HP of the player:" << std::endl;
        std::cin >> input;
        valid = this->validHp(input) && input <= this->maxHp;
    } while (!valid);

    this->hp = input;
}

void Player::inputMp()
{
    float input;
    bool valid;

    do
    {
        std::cout << "Enter the MP of the player:" << std::endl;
        std::cin >> input;
        valid = this->validMp(input) && input <= this->maxMp;
    } while (!valid);

    this->mp = input;
}

void Player::inputStamina()
{
    float input;
    bool valid;

    do
    {
        std::cout << "Enter the stamina of the player:" << std::endl;
        std::cin >> input;
        valid = this->validStamina(input) && input <= this->maxStamina;
    } while (!valid);

    this->stamina = input;
}

void Player::inputRunes()
{
    float input;
    bool valid;

    do
    {
        std::cout << "Enter the runes of the player:" << std::endl;
        std::cin >> input;
        valid = this->validRunes(input);
    } while (!valid);

    this->runes = input;
}

void Player::inputLevel()
{
    float input;
    bool valid;

    do
    {
        std::cout << "Enter the level of the player:" << std::endl;
        std::cin >> input;
        valid = this->validLevel(input);
    } while (!valid);

    this->level = input;
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