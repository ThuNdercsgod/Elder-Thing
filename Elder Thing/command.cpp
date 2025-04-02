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
        Command::printTest();
        std::cout << "Enter the number representing the command:" << std::endl;
        std::cin >> input;

        switch (input)
        {
        case 0:
            valid = true;
            break;
        case 1:
            Command::weaponTest();
            break;
        case 2:
            Command::playerTest();
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
        Command::printWeaponTest();
        std::cout << "Enter the number representing the command:" << std::endl;
        std::cin >> input;

        switch (input)
        {
        case 0:
            valid = true;
            break;
        case 1:
            WeaponTest::basic();
            break;
        case 2:
            WeaponTest::validation();
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

        switch (input)
        {
        case 0:
            valid = true;
            break;
        case 1:
            PlayerTest::equipping();
            break;
        case 2:
            PlayerTest::input();
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