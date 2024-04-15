#include<iostream>
#include<SFML/Audio.hpp>
#include"playsound.h"

std::vector<const char*> vFileName;
void formatvFileName()
{
    vFileName.push_back(BORUO_BM);
    vFileName.push_back(BORUO_ZF);
    vFileName.push_back(BORUO_RE);
    vFileName.push_back(DALUO_FZ);
    vFileName.push_back(DAWEI_TL);
    vFileName.push_back(DIAOCHONG_XJ);
    vFileName.push_back(JIA_SHA);
    vFileName.push_back(JIA_SHA_PS);
    vFileName.push_back(LOW_HP1);
    vFileName.push_back(LOW_HP2);
    vFileName.push_back(MASTER_STK);
    vFileName.push_back(SHOUT_SD1);
    vFileName.push_back(SHOUT_SD2);
    vFileName.push_back(SHAN_KAI);
    vFileName.push_back(SHAN_YI);
}

void playSound(const char* filename)
{
    sf::SoundBuffer buffer;
    if(!buffer.loadFromFile(filename))
    {
        std::cerr << "error code -1, loadfile faild" << std::endl;
        return;
    }
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    while(sound.getStatus() == sf::Sound::Playing)
    {
        std::cout << "跳过";
        if(std::cin.get())
        {
            break;
        }
    }

}