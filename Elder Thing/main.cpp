#include <iostream>

#include "command.hpp"
#include "player.hpp"
#include "test.hpp"
#include "weapon.hpp"

int main()
{
    // TODO add class "Enemy"
    // TODO add class "Spell"
    // TODO add Spell test
    // TODO expand player
    // TODO add copy constructors and operators
    // TODO add static methods

    try
    {
        Command command;
        command.test();
    }
    catch (std::bad_alloc &e)
    {
        std::cerr << "Memory allocation error!";
        return 1;
    }
    catch (int &e)
    {
        std::cerr << "Invalid parameters!" << std::endl;
        return 2;
    }

    return 0;
}