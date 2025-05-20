#include <iostream>

#include "astrologer.hpp"
#include "confessor.hpp"
#include "player.hpp"

#include "incantationspell.hpp"
#include "sorceryspell.hpp"
#include "spell.hpp"

#include "enemy.hpp"
#include "weapon.hpp"

#include "test.hpp"

void PlayerTest::basic()
{
    Player defConstr;
    defConstr.print();

    Player paramConstr("Parametrized player", 20, 20, 70, 5, 10);
    paramConstr.print();

    Player copyConstr(paramConstr);
    copyConstr.print();

    std::cout << copyConstr << std::endl;
}

// void PlayerTest::input()
// {
//     Player player;
//     Weapon longsword("Longsword", 80, 5.0f, 12);
//     Weapon greatsword("Greatsword", 100, 12.0f, 20);
//     Weapon dagger("Dagger", 45, 1.5f, 5);
//     player.print();
//     player.equipWeapon(longsword);
//     player.equipWeapon(greatsword);
//     player.equipWeapon(dagger);
//     player.print();
// }

void PlayerTest::weaponEquip()
{
    Player player("Default", 20, 20, 70, 5, 10);

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

void PlayerTest::spellEquip()
{
    // Create a new player
    Player player("Default", 20, 20, 70, 5, 10);

    // Print initial status
    std::cout << "Initial player status:" << std::endl;
    player.printStatus();
    player.printSpell();

    // Create some spells
    Spell fireball("Fireball", 30, 15, 2, 12, 0);
    Spell healingLight("Healing Light", 0, 20, 3, 5, 15);
    Spell lightningBolt("Lightning Bolt", 45, 25, 3, 15, 8);

    player.setIntelligence(20);
    player.setFaith(20);

    // Equip spells
    std::cout << "\nLearning spells:" << std::endl;
    player.equipSpell(fireball);
    player.equipSpell(healingLight);
    player.equipSpell(lightningBolt);

    // Print updated spell list
    std::cout << "\nUpdated spell list:" << std::endl;
    player.printSpell();
}

void PlayerTest::spellCast()
{
    std::cout << "\n=== Testing Spell Casting ===\n"
              << std::endl;

    // Create a player with increased intelligence
    Player player("Default", 20, 20, 70, 5, 10);

    // Increase intelligence to meet requirements
    player.setIntelligence(12);

    // Learn a spell
    Spell fireball("Fireball", 30, 15, 2, 12, 0);
    player.equipSpell(fireball);
    player.setCurrentSpell(0);

    std::cout << "Player status before casting:" << std::endl;
    player.printStatus();
    player.printSpell();

    // Cast the spell
    std::cout << "\nCasting spell:" << std::endl;
    int damage = player.castSpell();
    std::cout << "Spell dealt " << damage << " damage" << std::endl;

    std::cout << "\nPlayer status after casting:" << std::endl;
    player.printStatus();

    // Try to cast again (should be on cooldown)
    std::cout << "\nTrying to cast again:" << std::endl;
    damage = player.castSpell();
    std::cout << "Spell dealt " << damage << " damage" << std::endl;

    // Show final status
    std::cout << "\nFinal player status:" << std::endl;
    player.printStatus();
}

void PlayerTest::operators()
{
    std::cout << "\n=== Testing Player Operators ===\n"
              << std::endl;

    std::cout << "Creating Default Player: " << std::endl;
    Player def("Default", 20, 20, 70, 5, 10);
    def.print();

    std::cout << "\nUsing assignment operator: " << std::endl;
    Player equalOp;
    equalOp = def;
    equalOp.print();

    std::cout << "\nIncreasing Player Level by 1: " << std::endl;
    Player plusPlus;
    plusPlus++;
    plusPlus.print();

    std::cout << "\nAdding a weapon to player inventory: " << std::endl;
    Weapon dagger("Dagger", 45, 1.5f, 5);
    Player plus("Default", 20, 20, 70, 5, 10);
    plus + dagger;
    plus.printInventory();
}

void PlayerTest::PlayerClass::astrologer()
{
    std::cout << "\n=== Testing Astrologer Class ===\n"
              << std::endl;

    // Create an Astrologer object
    Astrologer astrologer("Astrologer", 100, 100, 100, 30, 30, 30, 30, 30);

    // Print initial status
    astrologer.print();

    // Test casting spells
    SorcerySpell fireball("Fireball", 30, 15, 2, 12, 0);
    astrologer.castSorcerySpell(fireball);

    SorcerySpell healingLight("Healing Light", 0, 20, 3, 5, 15);
    astrologer.castSorcerySpell(healingLight);

    // Test special action
    astrologer.performSpecialAction();
}

void PlayerTest::PlayerClass::confessor()
{
    std::cout << "\n=== Testing Confessor Class ===\n"
              << std::endl;

    // Create a Confessor object
    Confessor confessor("Confessor", 100, 100, 100, 30, 30, 30, 30, 30);

    // Print initial status
    confessor.print();

    // Test casting spells
    IncantationSpell fireball("Fireball", 30, 15, 2, 12, 0);
    confessor.castIncantationSpell(fireball);

    IncantationSpell healingLight("Healing Light", 0, 20, 3, 5, 15);
    confessor.castIncantationSpell(healingLight);

    // Test special action
    confessor.performSpecialAction();
}

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

    try
    {
        // Testing invalid damage
        Weapon invalidWeapon("Invalid Weapon", -10, -2.0f, -5);
        invalidWeapon.print();
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
    }

    // Test long name
    std::cout << "\nTesting long name truncation:" << std::endl;

    try
    {
        Weapon longNameWeapon("This is an extremely long weapon name that should be truncated", 50, 5.0f, 10);
        longNameWeapon.print();
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void SpellTest::basic()
{
    std::cout << "=== Testing Spell Basic Functionality ===\n"
              << std::endl;

    // Default constructor
    std::cout << "Creating spell with default constructor:" << std::endl;
    Spell defaultSpell;
    defaultSpell.print();

    // Parameterized constructor
    std::cout << "\nCreating spells with parameterized constructor:" << std::endl;
    Spell fireball("Fireball", 30, 15, 2, 12, 0);
    fireball.print();

    std::cout << std::endl;
    Spell healingLight("Healing Light", 0, 20, 3, 5, 15);
    healingLight.print();

    // Copy constructor
    std::cout << "\nUsing copy constructor:" << std::endl;
    Spell copied(fireball);
    std::cout << "Copied spell:" << std::endl;
    copied.print();

    // Test cooldown functionality
    std::cout << "\nTesting cooldown functionality:" << std::endl;
    std::cout << "Initial state:" << std::endl;
    std::cout << "Is Fireball on cooldown? " << (fireball.isOnCooldown() ? "Yes" : "No") << std::endl;

    fireball.resetCooldown();
    std::cout << "After reset cooldown:" << std::endl;
    std::cout << "Is Fireball on cooldown? " << (fireball.isOnCooldown() ? "Yes" : "No") << std::endl;
    std::cout << "Cooldown remaining: " << fireball.getRemainingCooldown() << std::endl;

    fireball.decrementCooldown(1);
    std::cout << "After decrement cooldown:" << std::endl;
    std::cout << "Is Fireball on cooldown? " << (fireball.isOnCooldown() ? "Yes" : "No") << std::endl;
    std::cout << "Cooldown remaining: " << fireball.getRemainingCooldown() << std::endl;

    fireball.decrementCooldown(1);
    std::cout << "After second decrement cooldown:" << std::endl;
    std::cout << "Is Fireball on cooldown? " << (fireball.isOnCooldown() ? "Yes" : "No") << std::endl;
    std::cout << "Cooldown remaining: " << fireball.getRemainingCooldown() << std::endl;
}

void SpellTest::operators()
{
    std::cout << "=== Testing Spell Operators ===\n"
              << std::endl;

    Spell fireball("Fireball", 30, 15, 2, 12, 0);
    Spell lightningBolt("Lightning Bolt", 45, 25, 3, 15, 8);
    Spell healingLight("Healing Light", 0, 20, 3, 5, 15);

    std::cout << "Using copy constructor:" << std::endl;
    Spell copiedSpell(fireball);
    copiedSpell.print();

    std::cout << "\nUsing assignment operator:" << std::endl;
    Spell assignedSpell;
    assignedSpell = fireball;
    assignedSpell.print();

    std::cout << "\nUsing less than operator:" << std::endl;
    if (fireball < lightningBolt)
    {
        std::cout << fireball.getName() << " is less powerful than " << lightningBolt.getName() << std::endl;
    }
    else
    {
        std::cout << fireball.getName() << " is more powerful than " << lightningBolt.getName() << std::endl;
    }

    std::cout << "\nUsing greater than operator:" << std::endl;
    if (fireball > healingLight)
    {
        std::cout << fireball.getName() << " is more powerful than " << healingLight.getName() << std::endl;
    }
    else
    {
        std::cout << fireball.getName() << " is less powerful than " << healingLight.getName() << std::endl;
    }

    std::cout << "\nUsing output operator:" << std::endl;
    std::cout << fireball << std::endl;
}

void SpellTest::SpellTypes::sorcery()
{
    std::cout << "=== Testing Sorcery Spell ===\n"
              << std::endl;

    SorcerySpell fireball("Fireball", 30, 15, 2, 12, 0);
    fireball.print();
}

void SpellTest::SpellTypes::incantation()
{
    std::cout << "=== Testing Incantation Spell ===\n"
              << std::endl;

    IncantationSpell healingLight("Healing Light", 0, 20, 3, 5, 15);
    healingLight.print();
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

    try
    { // Test exception handling
        std::cout << "\nTesting exception handling with invalid parameters:" << std::endl;
        Enemy invalidEnemy("Invalid", -50, 10);
        std::cout << "This should not be printed!" << std::endl;
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

// void EnemyTest::attack()
// {
//     std::cout << "=== Testing Enemy Attack Functionality ===\n"
//               << std::endl;
//     Enemy defaultEnemy;
//     // Testing exception handling
//     defaultEnemy.addAttack("Invalid", -10, 10);
// }