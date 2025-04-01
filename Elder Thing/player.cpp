#include <iostream>

#include "player.hpp"

Player::Player()
{
    this->hp = 100;
    this->mp = 100;
    this->stamina = 100;
    this->runes = 0;
    this->level = 0;
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

// TODO make it validate for the players level
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

    weaponSlots[i] = weapon;
    weaponsSlotsOccupied[i] = true;
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