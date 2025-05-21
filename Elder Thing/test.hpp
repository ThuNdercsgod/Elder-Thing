#pragma once

namespace AstrologerTest
{
    void basic();
    // void input();
    void weaponEquip();
    void spellEquip();
    void spellCast();
    void operators();
};

namespace ConfessorTest
{
    void basic();
    void weaponEquip();
    void spellEquip();
    void spellCast();
    void operators();
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