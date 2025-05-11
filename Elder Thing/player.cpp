#include <cstring>
#include <iostream>

#include "player.hpp"

Player::Player() : Player("Unknown", 100, 100, 100, 0, 0) {}

// Might throw std::invalid_argument or std::bad_alloc
Player::Player(const char *name, float hp, float mp, float stamina, int runes, float level)
{
    if (this->validHp(hp) &&
        this->validMp(mp) &&
        this->validStamina(stamina) &&
        this->validRunes(runes) &&
        this->validLevel(level))
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        this->hp = hp;
        this->mp = mp;
        this->stamina = stamina;
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
    this->mp = other.mp;
    this->stamina = other.stamina;
    this->runes = other.runes;
    this->level = other.level;
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
        this->mp = other.mp;
        this->stamina = other.stamina;
        this->runes = other.runes;
        this->level = other.level;
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
    for (int i = 0; i < 8; i++)
    {
        if (this->weaponsSlotsOccupied)
        {
            this->weaponSlots[i] = weapon;
            return *this;
        }
    }

    std::cout << "Inventory full!" << std::endl;
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

void Player::print()
{
    std::cout << "\n=== " << this->name << " stats ===\n"
              << "HP: " << this->hp << "/" << this->maxHp
              << "\nMP: " << this->mp << "/" << this->maxMp
              << "\nRunes: " << this->runes
              << "\nLevel: " << this->level
              << "\nCurrent weight: " << this->currentWeight
              << std::endl;

    Player::printInventory();
}

void Player::printInventory()
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

void Player::inputHp()
{
    float input;
    bool valid;

    do
    {
        std::cout << "Enter the HP of the player:" << std::endl;
        std::cin >> input;
        valid = this->validHp(input);
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
        valid = this->validMp(input);
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
        valid = this->validStamina(input);
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
    if (!(hp >= 0 && hp <= this->maxHp))
    {
        std::cout << "Invalid player HP!" << std::endl;
        return false;
    }
    return true;
}

bool Player::validMp(float mp) const
{
    if (!(mp >= 0 && mp <= this->maxMp))
    {
        std::cout << "Invalid player MP!" << std::endl;
        return false;
    }
    return true;
}

bool Player::validStamina(float stamina) const
{
    if (!(stamina >= 0 && stamina <= this->maxStamina))
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