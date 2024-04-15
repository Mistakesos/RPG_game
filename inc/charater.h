#ifndef CHARATER_H
#define CHARATER_H
#include<string>

class Charater
{
public:
    std::string getName() const
    {
        return this->m_name;
    }

    int getHp() const
    {
        return this->m_hp;
    }

    int getMp()
    {
        return this->m_mp;
    }

    int getDefense() const
    {
        return this->m_defense;
    }

    std::string getStatus() const
    {
        if(m_isDizzy == true)
        {
            return "dizzy";
        }
        return "normal";
    }

    void setHp(int hp)
    {
        this->m_hp = hp;
    }

    void setMp(int mp)
    {
        this->m_mp = mp;
    }

    void setStatus(std::string status)
    {
        if(status == "dizzy")
        {
            this->m_isDizzy = true;
        }
        else if(status == "unset_dizzy")
        {
            this->m_isDizzy = false;
        }
    }

    virtual void attackTo(Charater& target) = 0;
    virtual void skillTo(Charater& targe) = 0;

    virtual ~Charater()
    {
        
    }
protected:
    std::string m_name;
    int m_hp;
    int m_mp;
    int m_attack;
    int m_defense;
    //status
    bool m_isDizzy;
};

#endif  //CHARATER_H