#ifndef PLAYER_H
#define PLAYER_H
#include"charater.h"

class Cowboy : public Charater
{
public:
    Cowboy(std::string name, int hp, int mp, int attack, int defense, int level, int skill);
    void attackTo(Charater& target) override;
    void skillTo(Charater& target) override;
private:
    int m_level;
    int m_skill;
    bool isDizzy;
};

class FaHai : public Charater
{
public:
    FaHai(std::string name, int hp, int hpPrime, int mp, int mpPrime, int attack, int defense, int level, int skill);
    int getHpPrime();
    int getMpPrime();
    void attackTo(Charater& target) override;
    void skillTo(Charater& target) override;
private:
    int m_hpPrime;
    int m_mpPrime;
    int m_level;
    int m_skill;
    bool isDizzy;
};

#endif  //PLAYER_H