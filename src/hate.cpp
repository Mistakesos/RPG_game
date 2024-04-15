#include"boss.h"

Hate::Hate(std::string name, int hp, int mp, int attack, int defense, int level, int skill)
{
    this->m_name = name;
    this->m_hp = hp;
    this->m_mp = mp;
    this->m_attack = attack;
    this->m_defense = defense;
    this->m_level = level;
    this->m_skill = skill;
    this->m_isDizzy = false;
}

void Hate::attackTo(Charater& target)
{

}

void Hate::skillTo(Charater& target)
{

}