#include <cstring>

#include "combatmanager.hpp"

// CombatManager &CombatManager::operator=(const CombatManager &other)
// {
//     if (this != &other)
//     {
//         this->freeCharacters(this->numOfChar);

//         this->characters = new Character *[other.numOfChar];
//         for (int i = 0; i < other.numOfChar; i++)
//         {
//             this->characters[i] = other.characters[i]->clone();
//         }

//         this->numOfChar = other.numOfChar;
//     }
//     return *this;
// }

CombatManager::~CombatManager()
{
    delete[] this->characters;
    this->characters = nullptr;
    delete[] this->enemies;
    this->enemies = nullptr;
}

void CombatManager::addCharacter(Character *character)
{
    Character **newChar = new Character *[this->numOfChar + 1];
    for (int i = 0; i < this->numOfChar; i++)
    {
        newChar[i] = this->characters[i];
    }
    newChar[this->numOfChar] = character;

    delete[] this->characters;
    this->characters = newChar;
    this->numOfChar++;
}

void CombatManager::removeCharacter(Character *character)
{
    int index = -1;
    for (int i = 0; i < this->numOfChar; i++)
    {
        if (strcmp(this->characters[i]->getName(), character->getName()) == 0)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        throw std::invalid_argument("Character is not in the Combat Manager!");
    }

    if (this->numOfChar - 1 > 0)
    {
        Character **newChar = new Character *[this->numOfChar - 1];
        for (int i = 0; i < index; i++)
        {
            newChar[i] = this->characters[i];
        }
        for (int i = index + 1; i < this->numOfChar; i++)
        {
            newChar[i - 1] = this->characters[i];
        }

        delete this->characters[index];
        delete[] this->characters;
        this->characters = newChar;
        this->numOfChar--;
    }
    else
    {
        delete this->characters[0];
        delete[] this->characters;
        this->characters = nullptr;
    }
}

void CombatManager::addEnemy(Enemy *enemy)
{
    Enemy **newEnemies = new Enemy *[this->numOfEnemies + 1];
    for (int i = 0; i < this->numOfEnemies; i++)
    {
        newEnemies[i] = this->enemies[i];
    }
    newEnemies[this->numOfEnemies] = enemy;

    delete[] this->enemies;
    this->enemies = newEnemies;
    this->numOfEnemies++;
}

void CombatManager::removeEnemy(Enemy *enemy)
{
    int index = -1;
    for (int i = 0; i < this->numOfEnemies; i++)
    {
        if (strcmp(this->enemies[i]->getName(), enemy->getName()) == 0)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        throw std::invalid_argument("Enemy is not in the Combat Manager!");
    }

    if (this->numOfEnemies - 1 > 0)
    {
        Enemy **newEnemies = new Enemy *[this->numOfEnemies - 1];
        for (int i = 0; i < index; i++)
        {
            newEnemies[i] = this->enemies[i];
        }
        for (int i = index + 1; i < this->numOfEnemies; i++)
        {
            newEnemies[i - 1] = this->enemies[i];
        }

        delete this->enemies[index];
        delete[] this->enemies;
        this->enemies = newEnemies;
        this->numOfEnemies--;
    }
    else
    {
        delete this->enemies[0];
        delete[] this->enemies;
        this->enemies = nullptr;
    }
}

void CombatManager::executeRound()
{
    for (int i = 0; i < this->numOfChar; i++)
    {
        if (this->characters[i]->getIsAlive() == true)
        {
            this->characters[i]->defend(this->enemies[0]);
            if (this->characters[i]->getHp() <= 0)
            {
                std::cout << this->characters[i]->getName() << " is defeated!" << std::endl;
                this->removeCharacter(this->characters[i]);
            }
        }
        else
        {
            std::cout << this->characters[i]->getName() << " is already defeated!" << std::endl;
        }
    }
}

void CombatManager::displayBattleStatus()
{
    std::cout << "\n=== Battle Status ===" << std::endl;
    for (int i = 0; i < this->numOfChar; i++)
    {
        this->characters[i]->printStatus();
    }
    for (int i = 0; i < this->numOfEnemies; i++)
    {
        this->enemies[i]->print();
    }
}

const Character *getCharacter(const char *type);

void CombatManager::freeCharacters(unsigned numOfChar)
{
    if (numOfChar != 0)
    {
        for (int i = 0; i < numOfChar; i++)
        {
            delete this->characters[i];
            this->characters[i] = nullptr;
        }
        delete[] this->characters;
        this->characters = nullptr;
    }
}

void CombatManager::freeEnemies(unsigned numOfEnemies)
{
    if (numOfEnemies != 0)
    {
        for (int i = 0; i < numOfEnemies; i++)
        {
            delete this->enemies[i];
            this->enemies[i] = nullptr;
        }
        delete[] this->enemies;
        this->enemies = nullptr;
    }
}