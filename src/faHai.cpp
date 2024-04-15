#include<iostream>
#include<random>
#include"player.h"
#include"playsound.h"

FaHai::FaHai(std::string name, int hp, int hpPrime, int mp, int mpPrime, int attack, int defense, int level, int skill)
{
    this->m_name = name;
    this->m_hp = hp;
    this->m_hpPrime = hpPrime;
    this->m_mp = mp;
    this->m_mpPrime = mpPrime;
    this->m_attack = attack;
    this->m_defense = defense;
    this->m_level = level;
    this->m_skill = skill;
    this->m_isDizzy = false;
}

int FaHai::getHpPrime()
{
    return this->m_hpPrime;
}

int FaHai::getMpPrime()
{
    return this->m_mpPrime;
}
void FaHai::attackTo(Charater& target)
{
    //attack
    int hp = target.getHp();
    int damage = this->m_attack * 3 - target.getDefense() < 0 ? 1 : this->m_attack * 3 - target.getDefense();
    hp -= damage;
    std::cout << "你造成了：" << damage << "点伤害" << std::endl;
    hp = (hp < 0) ? 0 : hp;
    target.setHp(hp);

    //playsound
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 2);
    int play = dis(gen);
    switch (play)
    {
        case 1:
            playSound(SHOUT_SD1);
            break;
        case 2:
            playSound(SHOUT_SD2);
            break;
    }
}


void FaHai::skillTo(Charater& target)
{
    int select_skill = 0;
    std::cout << "你要释放哪一个技能？" << std::endl;
    std::cout << "1、百裂连击" << std::endl;
    std::cout << "2、大唐佛法" << std::endl;
    std::cout << "3、袈裟加身" << std::endl;
    std::cout << "4、移山之术" << std::endl;
    std::cout << "5、开山之法" << std::endl;
    std::cout << "6、飞龙在天" << std::endl;
    std::cin >> select_skill;
    std::cin.get();

    //select skill
    switch (select_skill)
    {
        case 1:
        {
            if(this->getMp() < 20)
            {
                std::cout << "你的法力值不够，不再能发动技能" << std::endl;
                std::cout << "将使用一次普通攻击代替" << std::endl;
                this->attackTo(target);
                break;
            }
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> dis(1, 100);
            int rate = 70;
            if(dis(gen) <= rate)
            {
                target.setStatus("dizzy");
            }
            int mp = this->getMp();
            mp -= 20;
            mp = (mp < 0) ? 0 : mp;
            this->setMp(mp);

            //play sound
            playSound(BORUO_RE);
            for(int i = 0; i < 3; i++)
            {
                this->attackTo(target);
            }
        }
            break;
        case 2:
        {
            if(this->getMp() < 40)
            {
                std::cout << "你的法力值不够，不再能发动技能" << std::endl;
                std::cout << "将使用一次普通攻击代替" << std::endl;
                this->attackTo(target);
                break;
            }
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> dis(1, 100);
            int critRate = dis(gen);
            int hp = target.getHp();
            if(critRate <= 50)
            {
                int damage = (this->m_skill + this->m_skill * 0.5) * 4;
                hp -= damage;
                std::cout << "你造成了：" << damage << "点伤害" << std::endl;
            }
            else
            {
                int damage = (this->m_skill + this->m_skill * 0.5) * 2;
                hp -= damage;
                std::cout << "你造成了：" << damage << "点伤害" << std::endl;
            }
            hp = (hp < 0) ? 0 : hp;
            target.setHp(hp);

            int mp = this->getMp();
            mp -= 40;
            mp = (mp < 0) ? 0 : mp;
            this->setMp(mp);

            //play sound
            std::uniform_int_distribution<int> dis_sound(1, 4);
            int sound = dis_sound(gen);
            switch (sound)
            {
                case 1:
                    playSound(BORUO_BM);  
                    break;
                case 2:
                    playSound(BORUO_ZF);
                    break;
                case 3:
                    playSound(DALUO_FZ);
                    break;
                case 4:
                    playSound(DAWEI_TL);
                    break;
            }
        }
            break;
        case 3:
        {
            if(this->getMp() < 40)
            {
                std::cout << "你的法力值不够，不再能发动技能" << std::endl;
                std::cout << "将使用一次普通攻击代替" << std::endl;
                this->attackTo(target);
                break;
            }
            if(this->getHp() <= 200)
            {
                playSound(JIA_SHA_PS);
            } 
            int hp = this->getHp();
            hp = (hp < this->getHpPrime()) ? hp += 60 : hp;
            hp = (hp >= this->getHpPrime()) ? this->getHpPrime() : hp;
            this->setHp(hp);
            std::cout << "你恢复了：" << "60" << "点血量" << std::endl;

            int mp = this->getMp();
            mp -= 40;
            mp = (mp < 0) ? 0 : mp;
            this->setMp(mp);

            //play sound
            playSound(JIA_SHA);
        }
            break;
        case 4:
        {
            if(this->getMp() < 30)
            {
                std::cout << "你的法力值不够，不再能发动技能" << std::endl;
                std::cout << "将使用一次普通攻击代替" << std::endl;
                this->attackTo(target);
                break;
            }
            int hp = this->getHp();
            hp = (hp <= this->getMpPrime()) ? hp : this->getMpPrime();
            this->setMp(hp);
            std::cout << "你将生命值赋给了法力值" << std::endl;
            int mp = this->getMp();
            mp -= 30;
            mp = (mp < 0) ? 0 : mp;
            this->setMp(mp);

            //play sound
            playSound(SHAN_YI);
        }
            break;
        case 5:
        {
            if(this->getMp() < 30)
            {
                std::cout << "你的法力值不够，不再能发动技能" << std::endl;
                std::cout << "将使用一次普通攻击代替" << std::endl;
                this->attackTo(target);
                break;
            }
            int mp = this->getMp();
            mp = (mp <= this->getHpPrime()) ? mp : this->getHpPrime();
            this->setHp(mp);
            std::cout << "你将法力值赋给了生命值" << std::endl;

            mp = this->getMp();
            mp -= 30;
            mp = (mp < 0) ? 0 : mp;
            this->setMp(mp);

            //play sound
            playSound(SHAN_KAI);
        }
            break;
        case 6:
        {
            if(this->getMp() < 100)
            {
                std::cout << "你的法力值不够，不再能发动技能" << std::endl;
                std::cout << "将使用一次普通攻击代替" << std::endl;
                this->attackTo(target);
                break;
            }

            std::random_device rd;
            std::mt19937 gen;
            std::uniform_int_distribution<int> dis(1, 100);
            int critRate = dis(gen);
            int hp = target.getHp();
            if(critRate <= 80)
            {
                int damage = this->m_attack * 18 * 2;
                std::cout << "你造成了：" << damage << "点伤害！！！" << std::endl;
                hp -= damage;
                target.setStatus("dizzy");
            }
            else
            {
                int damage = this->m_attack * 18 * 6;
                std::cout << "你造成了：" << damage << "点伤害！！！" << std::endl;
                hp -= damage;
                target.setStatus("dizzy");
            }
            hp = (hp < 0) ? 0 : hp;
            target.setHp(hp);

            int mp = this->getMp();
            mp -= 100;
            mp = (mp < 0) ? 0 : mp;
            this->setMp(mp);

            //play sound
            playSound(MASTER_STK);
        }
            break;
        default:
            break;
    }
}


