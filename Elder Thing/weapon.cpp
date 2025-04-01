#include <cstring>
#include <fstream>
#include <iostream>

#include "weapon.hpp"

void Weapon::print() const
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
bool Weapon::saveToFile() const
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

void Weapon::input()
{
    Weapon::inputName();
    Weapon::inputDamage();
    Weapon::inputWeight();
    Weapon::inputRequiredStrength();
}

void Weapon::initialize(const char *name, float damage, float weight, int requiredStrength)
{
    if (!(Weapon::validName(name) &&
          Weapon::validDamage(damage) &&
          Weapon::validWeight(weight) &&
          Weapon::validRequiredStrength(requiredStrength)))
    {
        std::cout << "Invalid weapon!" << std::endl;
    }
    else
    {
        strcpy(this->name, name);
        this->damage = damage;
        this->weight = weight;
        this->requiredStrength = requiredStrength;
    }
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

void Weapon::inputName()
{
    char input[128];
    bool valid;

    do
    {
        std::cout << "Enter the name of the weapon: ";
        std::cin.getline(input, 127);
        std::cout << std::endl;

        valid = Weapon::validName(input);
    } while (!valid);

    strcpy(this->name, input);
}

void Weapon::inputDamage()
{
    float input;
    bool valid;

    do
    {
        std::cout << "Enter the damage of the weapon: ";
        std::cin >> input;
        std::cout << std::endl;

        valid = Weapon::validDamage(input);
    } while (!valid);

    this->damage = input;
}

void Weapon::inputWeight()
{
    int input;
    bool valid;

    do
    {
        std::cout << "Enter the weight of the weapon: ";
        std::cin >> input;
        std::cout << std::endl;

        valid = Weapon::validWeight(input);
    } while (!valid);

    this->weight = input;
}

void Weapon::inputRequiredStrength()
{
    int input;
    bool valid;

    do
    {
        std::cout << "Enter the required strength of the weapon: ";
        std::cin >> input;
        std::cout << std::endl;

        valid = Weapon::validRequiredStrength(input);
    } while (!valid);

    this->requiredStrength = input;
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

bool Weapon::validWeight(int weight) const
{
    if (!(weight >= 0 && weight <= 8))
    {
        std::cout << "Invalid weapon weight!" << std::endl;
        return false;
    }

    return true;
}

bool Weapon::validRequiredStrength(int requiredStrength) const
{
    if (!(requiredStrength >= 0))
    {
        std::cout << "Invalid weapon required strength!" << std::endl;
        return false;
    }

    return true;
}