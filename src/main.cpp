#include <iostream>
#include <locale>
#include <vector>
#include <memory>
#include <map>

class StateHolder
{
public:
    virtual void SetAgility(int) = 0;
    virtual void SetLucky(int) = 0;
    virtual void SetHealth(int) = 0;
    virtual void SetDamage(int) = 0;
    virtual ~StateHolder() = default;
};

class Potion
{
    std::string mName{};
    int mValue{};
    int mTurnCount{};

public:
    explicit Potion(std::string_view name, int value, int turnCount)
        : mName{ name }
        , mValue{ value }
        , mTurnCount{ turnCount }
    {}

    int Turn()
    {
        --mTurnCount;
        return mTurnCount;
    }

    virtual void Apply(StateHolder& cr) const = 0;
    virtual void Cancel(StateHolder& cr) const = 0;

    virtual int Value() const { return mValue; }
    virtual std::string_view Name() const { return mName; }

    virtual ~Potion() = default;
};

class Creature : public StateHolder
{
public:

    void SetAgility(int val) override
    {
        mAgility += val;
    }
    void SetDamage(int val) override
    {
        mDamage += val;
        std::cout << "Increase Damage " << mDamage << '\n';
    }
    void SetHealth(int val) override
    {
        mHealth += val;
        std::cout << "Increase Health " << mHealth << '\n';
    }
    void SetLucky(int val) override
    {
        mLucky += val;
        std::cout << "Increase Lucky: " << mLucky << '\n';
    }

    void addPotion(std::unique_ptr<Potion> potion)
    {
        auto nextKey{ int(mPotionSet.size()) };
        mPotionSet[nextKey] = std::move(potion);
    }

    void applyPotion(int key)
    {
        if (mPotionSet.count(key) == 0) {
            std::cerr << "Potion doesn't exists: " << key << '\n';
            return;
        }
        mPotionSet[key]->Apply(*this);
        mPotionSet.erase(key);
    }

    void printPotions()const
    {
        for (auto&& [key, value] : mPotionSet) {
            std::cerr << "Potion: " << key << '\n';
        }
    }

    friend std::ostream& operator << (std::ostream& out, const Creature& c)
    {
        return std::cout
            << "\tDamage: " << c.mDamage << '\n'
            << "\tHealth: " << c.mHealth;
    }

private:

    int mLucky{};
    int mHealth{};
    int mDamage{};
    int mAgility{};

    std::map<int, std::unique_ptr<Potion>, std::less<>> mPotionSet{};
};


class DamagePotion :
    public Potion
{
public:
    using Potion::Potion;
    void Apply(StateHolder& cr) const override { cr.SetDamage(Value()); }
    void Cancel(StateHolder& cr) const override { cr.SetDamage(-Value()); }
};

class HealthPotion :
    public Potion
{
public:
    using Potion::Potion;
    void Apply(StateHolder& cr) const override { cr.SetHealth(Value()); }
    void Cancel(StateHolder& cr) const override { cr.SetHealth(-Value()); }
};

int main()
{
    Creature cr{};

    auto dmgPot{ std::make_unique<DamagePotion>("Damage +10", 10, 5) };
    auto hltPot{ std::make_unique<HealthPotion>("Health +100", 100, 5) };

    cr.addPotion(std::move(dmgPot));
    cr.addPotion(std::move(hltPot));

    std::cout << "Before:\n" << cr << '\n';

    cr.applyPotion(0);
    cr.applyPotion(1);

    std::cout << "After:\n" << cr << '\n';

    return 0;
}
