#include<random>
#include"player.h"
#include"playsound.h"

Cowboy::Cowboy(std::string name, int hp, int mp, int attack, int defense, int level, int skill)
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
void Cowboy::attackTo(Charater& target)
{
    int hp = target.getHp();
    hp -= this->m_attack - target.getDefense() < 0 ? 1 : this->m_attack - target.getDefense();
    hp = (hp < 0) ? 0 : hp;
    target.setHp(hp);
}

void Cowboy::skillTo(Charater& target)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 100);
    int rate = 70;
    if(dis(gen) <= rate)
    {
        target.setStatus("dizzy");
    }
    this->attackTo(target);    
}