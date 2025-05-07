#include <cstring>
#include <fstream>
#include <iostream>

#include "weapon.hpp"

Weapon::Weapon()
    : Weapon("Unkown", 0, 0, 0) {}

// Might throw std::invalid_argument;
Weapon::Weapon(const char *name, float damage, float weight, int requiredLevel)
{
    if (this->validName(name) &&
        this->validDamage(damage) &&
        this->validWeight(weight) &&
        this->validRequiredLevel(requiredLevel))
    {
        strcpy(this->name, name);
        this->damage = damage;
        this->weight = weight;
        this->requiredLevel = requiredLevel;
    }
    else
    {
        throw std::invalid_argument("Invalid Weapon parameters!");
    }
}

void Weapon::print() const
{
    std::cout << "Weapon \"" << this->name << "\":" << std::endl;
    std::cout << "Damage: " << this->damage << std::endl;
    std::cout << "Weight: " << this->weight << std::endl;
    std::cout << "Required level: " << this->requiredLevel << std::endl;
    std::cout << std::endl;
}

bool Weapon::loadFromFile()
{
    std::ifstream load("weapons.bin", std::ios::binary);
    if (!load.is_open())
    {
        std::cerr << "File opening error!" << std::endl;
        return false;
    }

    load.seekg(sizeof(int), std::ios::beg);

    load.read(this->name, sizeof(Weapon::name));
    load.read((char *)&this->damage, sizeof(Weapon::damage));
    load.read((char *)&this->weight, sizeof(Weapon::weight));
    load.read((char *)&this->requiredLevel, sizeof(Weapon::requiredLevel));

    load.close();
    return true;
}

bool Weapon::saveToFile() const
{
    int total = 0;

    // Open in both modes, so content does not get truncated
    std::fstream file("weapons.bin", std::ios::in | std::ios::out | std::ios::binary);
    if (!file.is_open())
    {
        // If it does not exist, create it
        file.open("weapons.bin", std::ios::out | std::ios::binary);
        if (!file.is_open())
        {
            std::cerr << "File opening error!" << std::endl;
            return false;
        }

        // Write an initial placeholder value for the count
        file.write((char *)(&total), sizeof(int)); // reinterpret_cast preferred
        file.close();                              // Dont forget to close the OUT mode

        // Reopen again as planned
        file.open("weapons.bin", std::ios::in | std::ios::out | std::ios::binary);
        if (!file.is_open())
        {
            std::cerr << "File reopening error!" << std::endl;
            return false;
        }
    }

    file.seekg(0, std::ios::beg);
    file.read((char *)(&total), sizeof(int));

    total++;

    file.seekp(0, std::ios::beg);
    file.write((char *)(&total), sizeof(int));

    file.seekp(0, std::ios::end);
    file.write(this->name, sizeof(Weapon::name));
    file.write((char *)(&this->damage), sizeof(Weapon::damage));
    file.write((char *)(&this->weight), sizeof(Weapon::weight));
    file.write((char *)(&this->requiredLevel), sizeof(Weapon::requiredLevel));

    file.close();

    return true;
}

float Weapon::getDamage() const
{
    return this->damage;
}

float Weapon::getWeight() const
{
    return this->weight;
}

int Weapon::getRequiredLevel() const
{
    return this->requiredLevel;
}

const char *Weapon::getName() const
{
    return this->name;
}

void Weapon::inputName()
{
    char input[128];
    bool valid;

    do
    {
        std::cout << "Enter the name of the weapon: " << std::endl;
        std::cin.getline(input, 127);
        std::cin.ignore();

        valid = this->validName(input);
    } while (!valid);

    strcpy(this->name, input);
}

void Weapon::inputDamage()
{
    float input;
    bool valid;

    do
    {
        std::cout << "Enter the damage of the weapon: " << std::endl;
        std::cin >> input;

        valid = this->validDamage(input);
    } while (!valid);

    this->damage = input;
}

void Weapon::inputWeight()
{
    float input;
    bool valid;

    do
    {
        std::cout << "Enter the weight of the weapon: " << std::endl;
        std::cin >> input;

        valid = this->validWeight(input);
    } while (!valid);

    this->weight = input;
}

void Weapon::inputRequiredLevel()
{
    int input;
    bool valid;

    do
    {
        std::cout << "Enter the required level of the weapon: " << std::endl;
        std::cin >> input;

        valid = this->validRequiredLevel(input);
    } while (!valid);

    this->requiredLevel = input;
}

bool Weapon::validName(const char *name) const
{
    if (strlen(name) >= 32)
    {
        std::cout << "Invalid weapon name!" << std::endl;
        return false;
    }

    return true;
}

bool Weapon::validDamage(float damage) const
{
    if (!(damage >= 0 && damage <= 100))
    {
        std::cout << "Invalid weapon damage!" << std::endl;
        return false;
    }

    return true;
}

bool Weapon::validWeight(float weight) const
{
    if (!(weight >= 0 && weight <= 20))
    {
        std::cout << "Invalid weapon weight!" << std::endl;
        return false;
    }

    return true;
}

bool Weapon::validRequiredLevel(int requiredLevel) const
{
    if (!(requiredLevel >= 0))
    {
        std::cout << "Invalid weapon required level!" << std::endl;
        return false;
    }

    return true;
}