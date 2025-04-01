#include <iostream>

#include "test.hpp"

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
    Player player(20, 20, 70, 5, 1);

    Weapon longsword("Longsword", 80, 5.0f, 12);

    Weapon greatsword("Greatsword", 100, 12.0f, 20);

    Weapon dagger("Dagger", 45, 1.5f, 5);

    player.equipWeapon(longsword);
    player.equipWeapon(greatsword);
    player.equipWeapon(dagger);

    player.print();
}