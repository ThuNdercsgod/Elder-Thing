#pragma once

#include "character.hpp"

class Battlefield
{
public:
    Battlefield() = default;
    // Battlefield(const Battlefield &other);
    ~Battlefield();

    // Battlefield &operator=(const Battlefield &other);

    void addCharacter(Character *character);
    void removeCharacter(Character *character);
    void addEnemy(Enemy *enemy);
    void removeEnemy(Enemy *enemy);
    void executeRound();
    void displayBattleStatus();

private:
    void freeCharacters(unsigned numOfChar);
    void freeEnemies(unsigned numOfEnemies);

    Character **characters = nullptr;
    unsigned numOfChar = 0;
    Enemy **enemies = nullptr;
    unsigned numOfEnemies = 0;
};