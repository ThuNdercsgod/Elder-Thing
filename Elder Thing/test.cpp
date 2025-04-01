#include <iostream>

#include "test.hpp"

void WeaponTest::basic()
{
    // Create and initialize weapons
    Weapon longSword;
    longSword.initialize("Longsword", 80, 5, 12);

    Weapon club;
    club.initialize("Club", 60, 3, 8);

    Weapon dagger;
    dagger.initialize("Dagger", 45, 1, 5);

    Weapon greatsword;
    greatsword.initialize("Greatsword", 100, 8, 20);

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

    Weapon invalidWeapon;
    invalidWeapon.initialize("Invalid Weapon", -10, -2, -5);
    invalidWeapon.print();

    // Test long name
    std::cout << "\nTesting long name truncation:" << std::endl;

    Weapon longNameWeapon;
    longNameWeapon.initialize("This is an extremely long weapon name that should be truncated", 50, 5, 10);
    longNameWeapon.print();
}