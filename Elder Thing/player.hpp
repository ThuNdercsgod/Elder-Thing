#pragma once

class Player
{
public:
    void setHp(float newHp);
    void setMp(float newMp);

private:
    float hp = 100, maxHp = 100;
    float mp = 100, maxMp = 100;
    float stamina = 100, maxStamina = 100;
    int runes = 0;
    float level = 0;
    int flaskChargesHp = 0, flaskChargesMp = 0;
    float currentWeight = 0, maxCarryCapacity = 8;
    int weaponSlots;
    bool weaponSlotFree[8];
};