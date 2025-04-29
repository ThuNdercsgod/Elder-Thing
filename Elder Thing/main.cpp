#include <iostream>

#include "command.hpp"
// #include "player.hpp"
// #include "test.hpp"
// #include "weapon.hpp"

int main()
{
    // TODO expand class "Enemy"
    // TODO add class "Spell"
    // TODO add Spell test
    // TODO expand class "Player"
    // TODO add copy constructors and operators
    // TODO add static methods

    try
    {
        Command command;
        command.test();
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "Memory allocation error!" << std::endl;
        return 1;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Memory allocation error!" << std::endl;
        return 1;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
        return 2;
    }

    return 0;
}