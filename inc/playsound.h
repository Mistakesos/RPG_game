#ifndef PLAYSOUND_H
#define PLAYSOUND_H
#include<iostream>
#include<vector>

constexpr const char* BORUO_BM = "../resources/sound_effects/boRuoBaMaKong.wav";
constexpr const char* BORUO_ZF = "../resources/sound_effects/boRuoZhuFo.wav";
constexpr const char* BORUO_RE = "../resources/sound_effects/re_boRuo.wav";
constexpr const char* DALUO_FZ = "../resources/sound_effects/daLuoFaZhou.wav";
constexpr const char* DAWEI_TL = "../resources/sound_effects/daWeiTianLong.wav";
constexpr const char* DIAOCHONG_XJ = "../resources/sound_effects/diaoChongxiaoji.wav";
constexpr const char* JIA_SHA = "../resources/sound_effects/jiaSha.wav";
constexpr const char* JIA_SHA_PS = "../resources/sound_effects/ps_jiaSha.wav";
constexpr const char* LOW_HP1 = "../resources/sound_effects/lowHpSound1.wav";
constexpr const char* LOW_HP2 = "../resources/sound_effects/lowHpSound2.wav";
constexpr const char* MASTER_STK = "../resources/sound_effects/masterStroke.wav";
constexpr const char* SHOUT_SD1 = "../resources/sound_effects/shoutVoice1.wav";
constexpr const char* SHOUT_SD2 = "../resources/sound_effects/shoutVoice2.wav";
constexpr const char* SHAN_KAI = "../resources/sound_effects/kaiShan.wav";
constexpr const char* SHAN_YI = "../resources/sound_effects/yiShan.wav";

void playSound(const char* filename);

extern std::vector<const char*> vFileName;
void formatvFileName();

#endif  //PLAYSOUND_H