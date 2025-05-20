#include <iostream>

#include "astrologer.hpp"
#include "command.hpp"
#include "sorceryspell.hpp"
// #include "player.hpp"
// #include "test.hpp"
// #include "weapon.hpp"

int main()
{
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
    catch (const std::ios_base::failure &e)
    {
        std::cerr << e.what() << std::endl;
        return 2;
    }

    return 0;
}