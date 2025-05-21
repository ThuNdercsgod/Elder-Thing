#include <iostream>

#include "astrologer.hpp"
#include "confessor.hpp"
#include "character.hpp"

#include "spell.hpp"
#include "spelltypes.hpp"

#include "enemy.hpp"
#include "weapon.hpp"

#include "test.hpp"

void AstrologerTest::basic()
{
    std::cout << "\n=== Testing Character Class ===\n"
              << std::endl;

    Astrologer paramConstr("Parametrized Astrologer", 20, 20, 70, 5, 10, 30, 30, 30);
    paramConstr.print();

    Astrologer copyConstr(paramConstr);
    copyConstr.print();

    std::cout << copyConstr << std::endl;
}

void AstrologerTest::weaponEquip()
{
    std::cout << "\n=== Testing Weapon Equipping ===\n"
              << std::endl;

    Astrologer astrologer("Default", 20, 20, 70, 5, 10, 30, 30, 30);
    std::cout << "Initial Astrologer status:" << std::endl;
    astrologer.printStatus();

    Weapon longsword("Longsword", 80, 5.0f, 12);

    Weapon greatsword("Greatsword", 100, 12.0f, 20);

    Weapon dagger("Dagger", 45, 1.5f, 5);

    astrologer.equipWeapon(&longsword);
    astrologer.equipWeapon(&greatsword);
    astrologer.equipWeapon(&dagger);

    astrologer.print();

    astrologer.setLevel(30);

    astrologer.equipWeapon(&longsword);
    astrologer.equipWeapon(&greatsword);

    astrologer.print();
}

void AstrologerTest::spellEquip()
{
    // Create a new Astrologer
    Astrologer astrologer("Default", 20, 20, 70, 5, 10, 30, 30, 30);

    // Print initial status
    std::cout << "Initial Astrologer status:" << std::endl;
    astrologer.printStatus();
    astrologer.printSpell();

    // Create some spells
    SorcerySpell fireball("Fireball", 30, 15, 2, 12, 0);
    IncantationSpell healingLight("Healing Light", 0, 20, 3, 5, 15);
    SorcerySpell lightningBolt("Lightning Bolt", 45, 25, 3, 15, 8);

    astrologer.setIntelligence(20);
    astrologer.setFaith(20);

    // Equip spells
    std::cout << "\nLearning spells:" << std::endl;
    astrologer.equipSpell(&fireball);
    astrologer.equipSpell(&healingLight);
    astrologer.equipSpell(&lightningBolt);

    // Print updated spell list
    std::cout << "\nUpdated spell list:" << std::endl;
    astrologer.printSpell();
}

void AstrologerTest::spellCast()
{
    std::cout << "\n=== Testing Spell Casting ===\n"
              << std::endl;

    // Create a Astrologer with increased intelligence
    Astrologer astrologer("Default", 20, 20, 70, 5, 10, 30, 30, 30);

    // Increase intelligence to meet requirements
    astrologer.setIntelligence(12);

    // Learn a spell
    SorcerySpell fireball("Fireball", 30, 15, 2, 12, 0);
    astrologer.equipSpell(&fireball);
    astrologer.setCurrentSpell(0);

    std::cout << "Astrologer status before casting:" << std::endl;
    astrologer.printStatus();
    astrologer.printSpell();

    // Cast the spell
    std::cout << "\nCasting spell:" << std::endl;
    int damage = astrologer.castSpell();
    std::cout << "Spell dealt " << damage << " damage" << std::endl;

    std::cout << "\nAstrologer status after casting:" << std::endl;
    astrologer.printStatus();

    // Try to cast again (should be on cooldown)
    std::cout << "\nTrying to cast again:" << std::endl;
    damage = astrologer.castSpell();
    std::cout << "Spell dealt " << damage << " damage" << std::endl;

    // Show final status
    std::cout << "\nFinal Astrologer status:" << std::endl;
    astrologer.printStatus();
}

void AstrologerTest::operators()
{
    std::cout << "\n=== Testing Astrologer Operators ===\n"
              << std::endl;

    std::cout << "Creating Default Astrologer: " << std::endl;
    Astrologer def("Default", 20, 20, 70, 5, 10, 30, 30, 30);
    def.print();

    std::cout << "\nUsing assignment operator: " << std::endl;
    Astrologer equalOp("Equal", 20, 20, 70, 5, 10, 30, 30, 30);
    equalOp = def;
    equalOp.print();

    std::cout << "\nIncreasing Astrologer Level by 1: " << std::endl;
    Astrologer plusPlus("PlusPlus", 20, 20, 70, 5, 10, 30, 30, 30);
    plusPlus++;
    plusPlus.print();

    std::cout << "\nAdding a weapon to Astrologer inventory: " << std::endl;
    Weapon dagger("Dagger", 45, 1.5f, 5);
    Astrologer plus("Default", 20, 20, 70, 5, 10, 30, 30, 30);
    plus + dagger;
    plus.printInventory();
}

void ConfessorTest::basic()
{
    std::cout << "\n=== Testing Confessor Class ===\n"
              << std::endl;

    Confessor paramConstr("Parametrized Confessor", 20, 20, 70, 5, 10, 30, 30, 30);
    paramConstr.print();

    Confessor copyConstr(paramConstr);
    copyConstr.print();

    std::cout << copyConstr << std::endl;
}

void ConfessorTest::weaponEquip()
{
    std::cout << "\n=== Testing Weapon Equipping ===\n"
              << std::endl;

    Confessor confessor("Default", 20, 20, 70, 5, 10, 30, 30, 30);
    std::cout << "Initial Confessor status:" << std::endl;
    confessor.printStatus();

    Weapon longsword("Longsword", 80, 5.0f, 12);

    Weapon greatsword("Greatsword", 100, 12.0f, 20);

    Weapon dagger("Dagger", 45, 1.5f, 5);

    confessor.equipWeapon(&longsword);
    confessor.equipWeapon(&greatsword);
    confessor.equipWeapon(&dagger);

    confessor.print();

    confessor.setLevel(30);

    confessor.equipWeapon(&longsword);
    confessor.equipWeapon(&greatsword);

    confessor.print();
}

void ConfessorTest::spellEquip()
{
    // Create a new Confessor
    Confessor confessor("Default", 20, 20, 70, 5, 10, 30, 30, 30);

    // Print initial status
    std::cout << "Initial Confessor status:" << std::endl;
    confessor.printStatus();
    confessor.printSpell();

    // Create some spells
    SorcerySpell fireball("Fireball", 30, 15, 2, 12, 0);
    IncantationSpell healingLight("Healing Light", 0, 20, 3, 5, 15);
    SorcerySpell lightningBolt("Lightning Bolt", 45, 25, 3, 15, 8);

    confessor.setIntelligence(20);
    confessor.setFaith(20);

    // Equip spells
    std::cout << "\nLearning spells:" << std::endl;
    confessor.equipSpell(&fireball);
    confessor.equipSpell(&healingLight);
    confessor.equipSpell(&lightningBolt);

    // Print updated spell list
    std::cout << "\nUpdated spell list:" << std::endl;
    confessor.printSpell();
}

void ConfessorTest::spellCast()
{
    std::cout << "\n=== Testing Spell Casting ===\n"
              << std::endl;

    // Create a Confessor with increased intelligence
    Confessor confessor("Default", 20, 20, 70, 5, 10, 30, 30, 30);

    // Increase intelligence to meet requirements
    confessor.setIntelligence(12);

    // Learn a spell
    SorcerySpell fireball("Fireball", 30, 15, 2, 12, 0);
    confessor.equipSpell(&fireball);
    confessor.setCurrentSpell(0);

    std::cout << "Confessor status before casting:" << std::endl;
    confessor.printStatus();
    confessor.printSpell();

    // Cast the spell
    std::cout << "\nCasting spell:" << std::endl;
    int damage = confessor.castSpell();
    std::cout << "Spell dealt " << damage << " damage" << std::endl;

    std::cout << "\nConfessor status after casting:" << std::endl;
    confessor.printStatus();

    // Try to cast again (should be on cooldown)
    std::cout << "\nTrying to cast again:" << std::endl;
    damage = confessor.castSpell();
    std::cout << "Spell dealt " << damage << " damage" << std::endl;

    // Show final status
    std::cout << "\nFinal Confessor status:" << std::endl;
    confessor.printStatus();
}

void ConfessorTest::operators()
{
    std::cout << "\n=== Testing Confessor Operators ===\n"
              << std::endl;

    std::cout << "Creating Default Confessor: " << std::endl;
    Confessor def("Default", 20, 20, 70, 5, 10, 30, 30, 30);
    def.print();

    std::cout << "\nUsing assignment operator: " << std::endl;
    Confessor equalOp("Equal", 20, 20, 70, 5, 10, 30, 30, 30);
    equalOp = def;
    equalOp.print();

    std::cout << "\nIncreasing Confessor Level by 1: " << std::endl;
    Confessor plusPlus("PlusPlus", 20, 20, 70, 5, 10, 30, 30, 30);
    plusPlus++;
    plusPlus.print();

    std::cout << "\nAdding a weapon to Confessor inventory: " << std::endl;
    Weapon dagger("Dagger", 45, 1.5f, 5);
    Confessor plus("Default", 20, 20, 70, 5, 10, 30, 30, 30);
    plus + dagger;
    plus.printInventory();
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

void SorcerySpellTest::basic()
{
    std::cout << "=== Testing Sorcery Spell Basic Functionality ===\n"
              << std::endl;

    // Parameterized constructor
    std::cout << "\nCreating spells with parameterized constructor:" << std::endl;
    SorcerySpell fireball("Fireball", 30, 15, 2, 12, 0);
    fireball.print();

    std::cout << std::endl;
    SorcerySpell healingLight("Healing Light", 0, 20, 3, 5, 15);
    healingLight.print();

    // Copy constructor
    std::cout << "\nUsing copy constructor:" << std::endl;
    SorcerySpell copied(fireball);
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

void SorcerySpellTest::operators()
{
    std::cout << "=== Testing Sorcery Spell Operators ===\n"
              << std::endl;

    SorcerySpell fireball("Fireball", 30, 15, 2, 12, 0);
    SorcerySpell lightningBolt("Lightning Bolt", 45, 25, 3, 15, 8);
    SorcerySpell healingLight("Healing Light", 0, 20, 3, 5, 15);

    std::cout << "Using copy constructor:" << std::endl;
    SorcerySpell copiedSpell(fireball);
    copiedSpell.print();

    std::cout << "\nUsing assignment operator:" << std::endl;
    SorcerySpell assignedSpell("Assigned Spell", 0, 0, 0, 0, 0);
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

void IncantationSpellTest::basic()
{
    std::cout << "=== Testing Incantation Spell Basic Functionality ===\n"
              << std::endl;

    // Parameterized constructor
    std::cout << "\nCreating spells with parameterized constructor:" << std::endl;
    IncantationSpell fireball("Fireball", 30, 15, 2, 12, 0);
    fireball.print();

    std::cout << std::endl;
    IncantationSpell healingLight("Healing Light", 0, 20, 3, 5, 15);
    healingLight.print();

    // Copy constructor
    std::cout << "\nUsing copy constructor:" << std::endl;
    IncantationSpell copied(fireball);
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

void IncantationSpellTest::operators()
{
    std::cout << "=== Testing Incantation Spell Operators ===\n"
              << std::endl;

    IncantationSpell fireball("Fireball", 30, 15, 2, 12, 0);
    IncantationSpell lightningBolt("Lightning Bolt", 45, 25, 3, 15, 8);
    IncantationSpell healingLight("Healing Light", 0, 20, 3, 5, 15);

    std::cout << "Using copy constructor:" << std::endl;
    IncantationSpell copiedSpell(fireball);
    copiedSpell.print();

    std::cout << "\nUsing assignment operator:" << std::endl;
    IncantationSpell assignedSpell("Assigned Spell", 0, 0, 0, 0, 0);
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