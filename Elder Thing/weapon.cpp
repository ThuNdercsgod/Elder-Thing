#include <cstring>
#include <fstream>
#include <iostream>
#include "weapon.hpp"

void Weapon::print()
{
    std::cout << "Weapon \"" << this->name << "\":" << std::endl;
    std::cout << "Damage: " << this->damage << std::endl;
    std::cout << "Weight: " << this->weight << std::endl;
    std::cout << "Required Strength" << this->requiredStrength << std::endl;
    std::cout << std::endl;
}

bool Weapon::loadFromFile()
{
    return true;
}

bool Weapon::saveToFile()
{
    int total = 0;

    std::ifstream load("weapons.bin", std::ios::binary | std::ios::ate);
    if (!load.is_open())
    {
        std::cerr << "File opening error!" << std::endl;
        return false;
    }
    // TODO figure out wether or not it should have a - before
    load.seekg(sizeof(int), std::ios::end);
    load.read((char *)&total, sizeof(int));
    load.close();

    // TODO save it before the last int or delete the last int and put it at the end
    std::ofstream save("weapons.bin", std::ios::binary | std::ios::app);

    if (!save.is_open())
    {
        std::cerr << "File opening error!" << std::endl;
        return false;
    }

    save.write(this->name, sizeof(Weapon::name));
    save.write(",", 1);
    save.write((char *)&this->damage, sizeof(Weapon::damage));
    save.write(",", 1);
    save.write((char *)&this->weight, sizeof(Weapon::weight));
    save.write(",", 1);
    save.write((char *)&this->requiredStrength, sizeof(Weapon::requiredStrength));
    save.write(";", 1);

    total++;
    save.write((char *)&total, sizeof(total));

    save.close();

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