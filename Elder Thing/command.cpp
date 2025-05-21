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
            this->characterTest();
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
              << "1. Run Character tests\n"
              << "2. Run Weapon tests\n"
              << "3. Run Spell tests\n"
              << "4. Run Enemy tests\n"
              << "0. Exit\n"
              << std::endl;
}

void Command::characterTest()
{
    int input;
    bool valid;

    do
    {
        valid = false;
        Command::printCharacterTest();
        std::cout << "Enter the number representing the command:" << std::endl;
        std::cin >> input;

        switch (input)
        {
        case 0:
            valid = true;
            break;
        case 1:
            this->astrologerTest();
            break;
        case 2:
            this->confessorTest();
            break;
        default:
            std::cout << "Invalid input!" << std::endl;
            break;
        }
    } while (!valid);
}

void Command::printCharacterTest()
{
    std::cout << "\n=== Elder Thing Character Tests ===\n"
              << "1. Run Astrologer tests\n"
              << "2. Run Confessor tests\n"
              << std::endl;
}

void Command::astrologerTest()
{
    int input;
    bool valid;

    do
    {
        valid = false;
        Command::printAstrologerTest();
        std::cout << "Enter the number representing the command:" << std::endl;
        std::cin >> input;

        switch (input)
        {
        case 0:
            valid = true;
            break;
        case 1:
            AstrologerTest::basic();
            break;
        case 2:
            AstrologerTest::weaponEquip();
            break;
        case 3:
            AstrologerTest::spellEquip();
            break;
        case 4:
            AstrologerTest::spellCast();
            break;
        case 5:
            AstrologerTest::operators();
            break;
        default:
            std::cout << "Invalid input!" << std::endl;
            break;
        }
    } while (!valid);
}

void Command::printAstrologerTest()
{
    std::cout << "\n=== Elder Thing Astrologer Tests ===\n"
              << "1. Run basic tests\n"
              << "2. Run weapon equip tests\n"
              << "3. Run spell equip tests\n"
              << "4. Run spell cast tests\n"
              << "5. Run operators tests\n"
              << "0. Go back\n"
              << std::endl;
}

void Command::confessorTest()
{
    int input;
    bool valid;

    do
    {
        valid = false;
        Command::printConfessorTest();
        std::cout << "Enter the number representing the command:" << std::endl;
        std::cin >> input;

        switch (input)
        {
        case 0:
            valid = true;
            break;
        case 1:
            ConfessorTest::basic();
            break;
        case 2:
            ConfessorTest::weaponEquip();
            break;
        case 3:
            ConfessorTest::spellEquip();
            break;
        case 4:
            ConfessorTest::spellCast();
            break;
        case 5:
            ConfessorTest::operators();
            break;
        default:
            std::cout << "Invalid input!" << std::endl;
            break;
        }
    } while (!valid);
}

void Command::printConfessorTest()
{
    std::cout << "\n=== Elder Thing Confessor Tests ===\n"
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
        case 3:
            this->spellTypeTest();
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
              << "3. Run spell type tests\n"
              << "0. Go back\n"
              << std::endl;
}

void Command::printSpellTypeTest()
{
    std::cout << "\n=== Elder Thing Spell Type Tests ===\n"
              << "1. Run Sorcery Spell tests\n"
              << "2. Run Incantation Spell tests\n"
              << "0. Go back\n"
              << std::endl;
}

void Command::spellTypeTest()
{
    int input;
    bool valid;

    do
    {
        valid = false;
        Command::printSpellTypeTest();
        std::cout << "Enter the number representing the command:" << std::endl;
        std::cin >> input;

        switch (input)
        {
        case 0:
            valid = true;
            break;
        case 1:
            SpellTest::SpellTypes::sorcery();
            break;
        case 2:
            SpellTest::SpellTypes::incantation();
            break;
        default:
            std::cout << "Invalid input!" << std::endl;
            break;
        }
    } while (!valid);
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