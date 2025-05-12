class Player;

class Spell
{
public:
    Spell();
    Spell(const char *name, float damage, int mpCost, int cooldown, int requiredIntelligence, int requiredFaith);
    Spell(const Spell &other);
    ~Spell();

    Spell &operator=(const Spell &other);

    void resetCooldown();
    void decrementCooldown(int amount);
    bool isOnCooldown() const;

    friend class Player;

private:
    char *name;
    float damage;
    int mpCost;
    int cooldown;
    int requiredIntelligence;
    int requiredFaith;
    int remainingCooldown;
};