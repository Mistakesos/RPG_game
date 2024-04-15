#ifndef BOSS_H
#define BOSS_H
#include"charater.h"

class Evil : public Charater
{
public:
    Evil(std::string name, int hp, int mp, int attack, int defense, int level, int skill);
    void attackTo(Charater& target) override;
    void skillTo(Charater& target) override;

private:
    int m_level;
    int m_skill;
    bool isDizzy;
};

class Hate : public Charater
{
public:
    Hate(std::string name, int hp, int mp, int attack, int defense, int level, int skill);
    void attackTo(Charater& target);
    void skillTo(Charater& target);
private:
    int m_level;
    int m_skill;
    bool isDizzy;
};

#endif  //BOSS_H