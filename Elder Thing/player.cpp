#include <iostream>

#include "player.hpp"

// Default constructor. Gets input from user.
Player::Player()
{
    Player::inputHp();
    Player::inputMp();
    Player::inputStamina();
    Player::inputRunes();
    Player::inputLevel();
}

Player::Player(float hp, float mp, float stamina, int runes, float level)
{
    if (Player::validHp(hp) &&
        Player::validMp(mp) &&
        Player::validStamina(stamina) &&
        Player::validRunes(runes) &&
        Player::validLevel(level))
    {
        this->hp = hp;
        this->mp = mp;
        this->stamina = stamina;
        this->runes = runes;
        this->level = level;
    }
    else
    {
        std::cout << "Invalid parameters for player creation! Using default parameters!"
                  << std::endl;
    }
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

Player::~Player() {}

void Player::print()
{
    std::cout << "\n=== Player stats ===\n"
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

void Player::setHp(float newHp)
{
    if (Player::validHp(newHp))
    {
        this->hp = newHp;
    }
}

void Player::setMp(float newMp)
{
    if (Player::validMp(newMp))
    {
        this->mp = newMp;
    }
}

void Player::setStamina(float newStamina)
{
    if (Player::validStamina(newStamina))
    {
        this->stamina = newStamina;
    }
}

void Player::setRunes(int newRunes)
{
    if (Player::validRunes(newRunes))
    {
        this->runes = newRunes;
    }
}

void Player::setLevel(float newLevel)
{
    if (Player::validLevel(newLevel))
    {
        this->level = newLevel;
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
        valid = Player::validHp(input);
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
        valid = Player::validMp(input);
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
        valid = Player::validStamina(input);
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
        valid = Player::validRunes(input);
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
        valid = Player::validLevel(input);
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