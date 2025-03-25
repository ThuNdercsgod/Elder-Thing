#pragma once

class Player
{
public:
    float setHp();
    float setMp();

private:
    float hp = 100;
    float maxHp = 100;

    float mp = 100;
    float maxMp = 100;

    float stamina = 100;
    float maxStamina = 100;

    int runes = 0;
    float level = 0;

    int flaskChargesHp = 0;
    int flaskChargesMp = 0;

    float currentWeight = 0;
    float maxCarryCapacity = 3;

    int weaponSlots;
    bool weaponSlotFree[8];
};