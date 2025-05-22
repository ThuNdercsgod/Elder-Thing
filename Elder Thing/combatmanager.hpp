#pragma once

#include "character.hpp"

class CombatManager
{
public:
    CombatManager() = default;
    // CombatManager(const CombatManager &other);
    ~CombatManager();

    // CombatManager &operator=(const CombatManager &other);

    void addCharacter(Character *character);
    void removeCharacter(Character *character);
    void addEnemy(Enemy *enemy);
    void removeEnemy(Enemy *enemy);
    void executeRound();
    void displayBattleStatus();

    const Character *getCharacter(const char *type);

private:
    void freeCharacters(unsigned numOfChar);
    void freeEnemies(unsigned numOfEnemies);

    Character **characters = nullptr;
    unsigned numOfChar = 0;
    Enemy **enemies = nullptr;
    unsigned numOfEnemies = 0;
};