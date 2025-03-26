#include <cstring>
#include <fstream>
#include <iostream>
#include "weapon.hpp"

void Weapon::print()
{
    std::cout << "Weapon \"" << this->name << "\":" << std::endl;
    std::cout << "Damage: " << this->damage << std::endl;
    std::cout << "Weight: " << this->weight << std::endl;
    std::cout << "Required Strength: " << this->requiredStrength << std::endl;
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

    load.seekg(5, std::ios::beg);

    load.read(this->name, sizeof(Weapon::name));
    load.seekg(1, std::ios::cur);
    load.read((char *)&this->damage, sizeof(Weapon::damage));
    load.seekg(1, std::ios::cur);
    load.read((char *)&this->weight, sizeof(Weapon::weight));
    load.seekg(1, std::ios::cur);
    load.read((char *)&this->requiredStrength, sizeof(Weapon::requiredStrength));

    load.seekg(1, std::ios::cur);

    return true;
}

// TODO stop it from deleting the file when editing the total size
bool Weapon::saveToFile()
{
    int total = 0;

    std::fstream load("weapons.bin", std::ios::binary | std::ios::in);
    if (!load.is_open())
    {
        std::cerr << "File opening error!" << std::endl;
        return false;
    }

    load.seekg(0, std::ios::beg);
    load.read((char *)&total, sizeof(int));

    std::cout << total << std::endl;

    load.close();

    // TODO save it before the last int or delete the last int and put it at the end
    std::ofstream edit("weapons.bin", std::ios::binary);

    if (!edit.is_open())
    {
        std::cerr << "File opening error!" << std::endl;
        return false;
    }

    edit.seekp(0, std::ios::beg);
    total++;
    edit.write((char *)&total, sizeof(total));

    edit.seekp(0, std::ios::end);

    edit.write(this->name, sizeof(Weapon::name));
    edit.write((char *)&this->damage, sizeof(Weapon::damage));
    edit.write((char *)&this->weight, sizeof(Weapon::weight));
    edit.write((char *)&this->requiredStrength, sizeof(Weapon::requiredStrength));

    edit.close();

    return true;
}

void Weapon::initialize()
{
    bool valid;
    do
    {
        valid = true;

        if (!Weapon::validName() || !Weapon::validDamage() ||
            !Weapon::validWeight() || !Weapon::validRequieredStrength())
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            valid = false;
        }

    } while (valid == false);
}

float Weapon::getDamage() const
{
    return this->damage;
}

float Weapon::getWeight() const
{
    return this->weight;
}

int Weapon::getRequiredStrength() const
{
    return this->requiredStrength;
}

const char *Weapon::getName() const
{
    return this->name;
}

bool Weapon::validName()
{
    char input[128];

    std::cout << "Enter the name of the weapon: ";
    std::cin.getline(input, 127);
    std::cout << std::endl;

    if (strlen(input) >= 32)
    {
        return false;
    }

    strcpy(this->name, input);
    return true;
}

bool Weapon::validDamage()
{
    float input;
    std::cout << "Enter the damage of the weapon: ";
    std::cin >> input;
    std::cout << std::endl;

    if (!(input >= 0 && input <= 100))
    {
        return false;
    }

    this->damage = input;
    return true;
}

bool Weapon::validWeight()
{
    float input;
    std::cout << "Enter the weigth of the weapon: ";
    std::cin >> input;
    std::cout << std::endl;

    if (!(input >= 0 && input <= 100))
    {
        return false;
    }

    this->weight = input;
    return true;
}

bool Weapon::validRequieredStrength()
{
    float input;
    std::cout << "Enter the required strength of the weapon: ";
    std::cin >> input;
    std::cout << std::endl;

    if (!(input >= 0 && input <= 100))
    {
        return false;
    }

    this->requiredStrength = input;
    return true;
}