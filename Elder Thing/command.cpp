#include <iostream>

#include "command.hpp"
#include "test.hpp"

void Command::test()
{
    int input;
    bool valid;

    do
    {
        valid = false;
        this->printTest();
        std::cout << "Enter the number representing the command:" << std::endl;
        std::cin >> input;

        switch (input)
        {
        case 0:
            valid = true;
            break;
        case 1:
            this->weaponTest();
            break;
        case 2:
            this->playerTest();
            break;
        // case 4:
        //     break;
        default:
            std::cout << "Invalid input!" << std::endl;
            break;
        }
    } while (!valid);
}

void Command::printTest()
{
    std::cout << "\n=== Elder Thing Tests ===\n"
              //   << "1. Run all tests\n"
              << "1. Run Weapon tests\n"
              << "2. Run Player tests\n"
              //   << "4. Run Player flask tests\n"
              << "0. Exit\n"
              << std::endl;
}

void Command::weaponTest()
{
    int input;
    bool valid;

    do
    {
        valid = false;
        this->printWeaponTest();
        std::cout << "Enter the number representing the command:" << std::endl;
        std::cin >> input;
        WeaponTest weaponTest;

        switch (input)
        {
        case 0:
            valid = true;
            break;
        case 1:
            weaponTest.basic();
            break;
        case 2:
            weaponTest.validation();
            break;
        default:
            std::cout << "Invalid input!" << std::endl;
            break;
        }
    } while (!valid);
}

void Command::printWeaponTest()
{
    std::cout << "\n=== Elder Thing Weapon Tests ===\n"
              << "1. Run basic weapon tests\n"
              << "2. Run validation weapon tests\n"
              << "0. Go back\n"
              << std::endl;
}

void Command::playerTest()
{
    int input;
    bool valid;

    do
    {
        valid = false;
        Command::printPlayerTest();
        std::cout << "Enter the number representing the command:" << std::endl;
        std::cin >> input;
        PlayerTest playerTest;

        switch (input)
        {
        case 0:
            valid = true;
            break;
        case 1:
            playerTest.equipping();
            break;
        case 2:
            playerTest.input();
            break;
        default:
            std::cout << "Invalid input!" << std::endl;
            break;
        }
    } while (!valid);
}

void Command::printPlayerTest()
{
    std::cout << "\n=== Elder Thing Player Tests ===\n"
              << "1. Run equipping tests\n"
              << "2. Run input tests\n"
              << "0. Go back\n"
              << std::endl;
}