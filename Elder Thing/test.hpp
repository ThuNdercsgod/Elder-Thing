#pragma once

namespace PlayerTest
{
    void basic();
    // void input();
    void weaponEquip();
    void spellEquip();
    void spellCast();
    void operators();
    namespace PlayerClass
    {
        void astrologer();
        void confessor();
    }
};

namespace WeaponTest
{
    void basic();
    void validation();
};

namespace SpellTest
{
    void basic();
    void operators();
    namespace SpellTypes
    {
        void sorcery();
        void incantation();
    }
};

namespace EnemyTest
{
    void basic();
    // void attack();
};