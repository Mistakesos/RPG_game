#include<iostream>
#include<random>
#include<memory>
#include"charater.h"
#include"player.h"
#include"boss.h"
#include"playsound.h"
using std::cout, std::endl;


int main()
{
    // Cowboy cow("牛仔",200, 12, 4, 6, 24);
    // BrokHert boss("邪祟", 300, 15, 3, 10, 28);
    
    //select player
    int select = 0;
    cout << "欢迎来到我的第一个像样的练手项目，请输入你的选择：" << endl;
    cout << "1、牛仔" << endl;
    cout << "2、法海" << endl;
    std::unique_ptr<Charater> player_ptr = nullptr;
    std::cin >> select;
    std::cin.get();
    switch(select)
    {
        case 1:
        {
            player_ptr = std::make_unique<Cowboy>("牛仔", 200, 120, 12, 4, 6, 24);
            cout << "我还没做好呢，真的" << endl;
            cout << "按回车键继续" << endl;
            std::cin.get();
            char select;
            cout << "按y然后回车退出，按n然后回车强制继续" << endl;
            std::cin >> select;
            if(select == 'y')
            {
                exit(0);
            }
            else if(select == 'n')
            {
                cout << "是你决定继续的啊，游戏可能出现不可预知的错误！" << endl;
            }
        }
            break;
        case 2:
            player_ptr = std::make_unique<FaHai>("法海", 300, 300, 200, 200, 18, 3, 100, 32);
            playSound(DIAOCHONG_XJ);
            break;
        default:
            break;
    }

    //generate boss
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 2);
    //int gen_boss = dis(gen);
    int gen_boss = 1;
    std::unique_ptr<Charater> boss_ptr = nullptr;
    switch(gen_boss)
    {
        case 1:
            boss_ptr = std::make_unique<Evil>("邪祟", 5000, 9999, 20, 5, 50, 25);
            break;
        case 2:
            boss_ptr = std::make_unique<Hate>("仇恨之源", 600, 9999, 18, 7, 60, 15);
        default:
            break;
    }
    cout << "你遇到了：" << boss_ptr->getName() << "！" << endl;

    //prime hp data
    int hp_player_prime = player_ptr->getHp();
    int hp_boss_prime = boss_ptr->getHp();
    //prime mp data
    int mp_player_prime = player_ptr->getMp();
    int mp_boss_prime = boss_ptr->getMp();

    //game process
    int select_action = 0;
    bool item = true;
    while(player_ptr->getHp() > 0 && boss_ptr->getHp() > 0)
    {
        // player actions
        if(player_ptr->getStatus() == "dizzy")
        {
            std::cout << "你被击晕了，本回合无法攻击" << std::endl;
            player_ptr->setStatus("unset_dizzy");
        }
        else
        {
            cout << "请输入你的选择：" << endl;
            cout << "1、普通攻击" << endl;
            cout << "2、施放法术" << endl;
            cout << "3、使用道具" << endl;
            cout << "4、闭目养神" << endl;
            std::cin >> select_action;
            std::cin.get();
            switch(select_action) 
            {
            case 1:
                player_ptr->attackTo(*boss_ptr);
                break;
            case 2:
                player_ptr->skillTo(*boss_ptr);
                break;
            case 3:
            {
                if(item == false)
                {
                    cout << "你没有道具了" << std::endl;
                    cout << "将使用一次普通攻击替代此行为" << std::endl;
                    player_ptr->attackTo(*boss_ptr);
                }
                else
                {
                    int hp = player_ptr->getHp();
                    hp += 200;
                    hp = (hp > hp_player_prime) ? hp_player_prime : hp;
                    player_ptr->setHp(hp);
                    std::cout << "你使用了大还丹" << std::endl;
                }
                item = false;
            }
                break;
            default:
            {
                int mp = player_ptr->getMp();
                mp += 20;
                mp = (mp > mp_player_prime) ? mp_player_prime : mp;
                player_ptr->setMp(mp);
            }
                break;
            }
        }

        //boss actions
        std::uniform_int_distribution<int> dis_boss_action(1, 100);
        int select_boss = dis_boss_action(gen);
        if(boss_ptr->getStatus() == "dizzy")
        {
            std::cout << "Boss被击晕了，本回合无法攻击" << std::endl;
            boss_ptr->setStatus("unset_dizzy");
        }
        else
        {
            if(select_boss <= 70)   
            {
                boss_ptr->attackTo(*player_ptr);
            }
            else if(select_boss <= 30)
            {
                boss_ptr->skillTo(*player_ptr);
            }
        }

        //The end, show the end and bar

        //player hp bar
        cout << "你还剩：" << player_ptr->getHp() << "点生命值" << std::endl;
        int block_hp = static_cast<float>(player_ptr->getHp()) / hp_player_prime * 10;
        cout << "[";
        for (int i = 0; i < block_hp; i++)
        {
            cout << "#";
        }
        for (int i = 0; i < 10 - block_hp; i++)
        {
            cout << " ";
        }
        cout << "]" << endl;

        //player mp bar
        cout << "你还剩：" << player_ptr->getMp() << "点法力值" << std::endl;
        int block_mp = static_cast<float>(player_ptr->getMp()) / mp_player_prime * 10;
        cout << "[";
        for (int i = 0; i < block_mp; i++)
        {
            cout << "#";
        }
        for (int i = 0; i < 10 - block_mp; i++)
        {
            cout << " ";
        }
        cout << "]" << endl;

        cout << endl << endl;

        //boss hp bar
        cout << "Boss还剩：" << boss_ptr->getHp() << "点生命值" << std::endl;
        block_hp = static_cast<float>(boss_ptr->getHp()) / hp_boss_prime * 10;
        cout << "[";
        for (int i = 0; i < block_hp; i++)
        {
            cout << "#";
        }
        for (int i = 0; i < 10 - block_hp; i++)
        {
            cout << " ";
        }
        cout << "]" << endl;

        //boss mp bar
        cout << "Boss还剩：" << boss_ptr->getMp() << "点魔力值" << std::endl;
        cout << "[";
        for(int i = 0; i < 10; i++)
        {
            cout << "#";
        }
        cout << "]" << endl;

        //mp recover
        int mp = player_ptr->getMp();
        mp = (mp < mp_player_prime) ? mp += 20 : mp;
        mp = (mp >= mp_player_prime) ? mp_player_prime : mp;
        player_ptr->setMp(mp);

        //lowhp sound effect
        int index = 0;  //Make sure this sound just play once,don't makes player annoying
        if(player_ptr->getHp() <= 200 && index != 0)
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> dis(1, 2);
            int play = dis(gen);
            if(play == 1)
            {
                playSound(LOW_HP1);
            }
            if(play == 2)
            {
                playSound(LOW_HP2);
            }
            index++;    //Index is changed,so these code will not run twice
        }

        //show the end
        if(player_ptr->getHp() == 0)
        {
            cout << "呜呼哀哉！肉体坏灭，你已圆寂,静待转世" << endl;
        }
        else if(boss_ptr->getHp() == 0)
        {
            cout << "区区邪祟，佛法无边，魑魅蟒魉，不足挂齿" << endl;
        }

        #ifdef _WIN32
        system("pause")
        system("cls");
        #elif defined __linux__
        system("read");
        system("clear");
        #endif  //Clear the screen,make sure both linux and windows are all works
    }

    return 0;
}