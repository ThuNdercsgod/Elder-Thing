#include <iostream>
#include "player.hpp"
#include "weapon.hpp"

int main()
{
    Weapon weapon;

    weapon.initialize();

    weapon.print();

    // TODO Weapon::saveToFile()
    weapon.saveToFile();

    return 0;
}