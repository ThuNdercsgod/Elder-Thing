#include <iostream>

#include "enemy.hpp"
#include "player.hpp"
#include "test.hpp"
#include "weapon.hpp"

void WeaponTest::basic()
{
    // Create and initialize weapons
    Weapon longSword("Longsword", 80, 5.0f, 12);

    Weapon club("Club", 60, 3.5f, 8);

    Weapon dagger("Dagger", 45, 1.5f, 5);

    Weapon greatsword("Greatsword", 100, 12.0f, 20);

    // Print weapon information
    std::cout << "Testing weapon functionality:\n"
              << std::endl;

    longSword.print();
    std::cout << std::endl;

    club.print();
    std::cout << std::endl;

    dagger.print();
    std::cout << std::endl;

    greatsword.print();
}

void WeaponTest::validation()
{
    // Test validation
    std::cout << "\nTesting validation with invalid values:" << std::endl;

    Weapon invalidWeapon("Invalid Weapon", -10, -2.0f, -5);
    invalidWeapon.print();

    // Test long name
    std::cout << "\nTesting long name truncation:" << std::endl;

    Weapon longNameWeapon("This is an extremely long weapon name that should be truncated", 50, 5.0f, 10);
    longNameWeapon.print();
}

void PlayerTest::equipping()
{
    Player player(20, 20, 70, 5, 10);

    Weapon longsword("Longsword", 80, 5.0f, 12);

    Weapon greatsword("Greatsword", 100, 12.0f, 20);

    Weapon dagger("Dagger", 45, 1.5f, 5);

    player.equipWeapon(longsword);
    player.equipWeapon(greatsword);
    player.equipWeapon(dagger);

    player.print();

    player.setLevel(30);

    player.equipWeapon(longsword);
    player.equipWeapon(greatsword);

    player.print();
}

void PlayerTest::input()
{
    Player player;

    Weapon longsword("Longsword", 80, 5.0f, 12);

    Weapon greatsword("Greatsword", 100, 12.0f, 20);

    Weapon dagger("Dagger", 45, 1.5f, 5);

    player.print();

    player.equipWeapon(longsword);
    player.equipWeapon(greatsword);
    player.equipWeapon(dagger);

    player.print();
}

void EnemyTest::basic()
{
    std::cout << "=== Testing Enemy Basic Functionality ===\n"
              << std::endl;

    // Default constructor
    std::cout << "Creating enemy with default constructor:" << std::endl;
    Enemy defaultEnemy;
    defaultEnemy.print();

    // Parameterized constructor
    std::cout << "\nCreating enemy with parameterized constructor:" << std::endl;
    Enemy zombie("Zombie", 100, 15);
    zombie.print();

    // Test exception handling
    std::cout << "\nTesting exception handling with invalid parameters:" << std::endl;
    Enemy invalidEnemy("Invalid", -50, 10);
    std::cout << "This should not be printed!" << std::endl;
}

// void EnemyTest::attack()
// {
//     std::cout << "=== Testing Enemy Attack Functionality ===\n"
//               << std::endl;
//     Enemy defaultEnemy;
//     // Testing exception handling
//     defaultEnemy.addAttack("Invalid", -10, 10);
// }