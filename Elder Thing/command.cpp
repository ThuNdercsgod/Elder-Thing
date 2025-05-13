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
            this->playerTest();
            break;
        case 2:
            this->weaponTest();
            break;
        case 3:
            this->spellTest();
            break;
        case 4:
            this->enemyTest();
            break;
        default:
            std::cout << "Invalid input!" << std::endl;
            break;
        }
    } while (!valid);
}

void Command::printTest()
{
    std::cout << "\n=== Elder Thing Tests ===\n"
              << "1. Run Player tests\n"
              << "2. Run Weapon tests\n"
              << "3. Run Spell tests\n"
              << "4. Run Enemy tests\n"
              << "0. Exit\n"
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
            PlayerTest::basic();
            break;
        case 2:
            PlayerTest::weaponEquip();
            break;
        case 3:
            PlayerTest::spellEquip();
            break;
        case 4:
            PlayerTest::spellCast();
            break;
        case 5:
            PlayerTest::operators();
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
              << "1. Run basic tests\n"
              << "2. Run weapon equip tests\n"
              << "3. Run spell equip tests\n"
              << "4. Run spell cast tests\n"
              << "5. Run operators tests\n"
              << "0. Go back\n"
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

void Command::spellTest()
{
    int input;
    bool valid;

    do
    {
        valid = false;
        this->printSpellTest();
        std::cout << "Enter the number representing the command:" << std::endl;
        std::cin >> input;

        switch (input)
        {
        case 0:
            valid = true;
            break;
        case 1:
            SpellTest::basic();
            break;
        case 2:
            SpellTest::operators();
            break;
        default:
            std::cout << "Invalid input!" << std::endl;
            break;
        }
    } while (!valid);
}

void Command::printSpellTest()
{
    std::cout << "\n=== Elder Thing Spell Tests ===\n"
              << "1. Run basic spell tests\n"
              << "2. Run operators spell tests\n"
              << "0. Go back\n"
              << std::endl;
}

void Command::enemyTest()
{
    int input;
    bool valid;

    do
    {
        valid = false;
        Command::printEnemyTest();
        std::cout << "Enter the number representing the command:" << std::endl;
        std::cin >> input;

        switch (input)
        {
        case 0:
            valid = true;
            break;
        case 1:
            EnemyTest::basic();
            break;
        // case 2:
        //     enemyTest.attack();
        //     break;
        default:
            std::cout << "Invalid input!" << std::endl;
            break;
        }
    } while (!valid);
}

void Command::printEnemyTest()
{
    std::cout << "\n=== Elder Thing Enemy Tests ===\n"
              << "1. Run basic tests\n"
              << "0. Go back\n"
              << std::endl;
}