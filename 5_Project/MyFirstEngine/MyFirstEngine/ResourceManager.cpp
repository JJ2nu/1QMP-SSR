#include "ResourceManager.h"
#include "AnimationResource.h"
#include "Texture.h"
#include <atlconv.h>

ResourceManager* ResourceManager::instance = nullptr;
ResourceManager::ResourceManager() :
	//Sound
	m_System(), m_Channel{}, m_SoundList{}, m_fVolume(0.5f) {}
ResourceManager::~ResourceManager()
{
	////Texture
	//CTN::LinkedHashMap<std::wstring, Texture*>::Iterator iter(&(m_mTexture.list), m_mTexture.capacity);
	//while (!iter.IsEnd())
	//{
	//	CTN::LinkedHashMap<std::wstring, Texture*>::Data* data = iter.GetCurrent();
	//	if (data != nullptr)
	//	{
	//		if (data->value != nullptr)
	//			delete data->value;
	//		if (data->key != nullptr)
	//			delete[](data->key);
	//	}
	//	iter.Next();
	//}

	////Sound
	//m_System->release();
	//m_System->close();
}

ResourceManager* ResourceManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new ResourceManager();
	}
	return instance;
}

void ResourceManager::DestroyResourceManager()
{
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

void ResourceManager::Initialize()
{
	InitPathManager();
	InitSound();
}

/*

//	ResourcePath

*/
void ResourceManager::InitPathManager()
{
	GetCurrentDirectory(255, m_wResourcePath);

	//int len = wcslen(m_wResourcePath);
	//for (int i = len - 1; i >= 0; i--)
	//{
	//	if (m_wResourcePath[i] == '\\')
	//	{
	//		m_wResourcePath[i] = '\0';
	//		break;
	//	}
	//}
	wcscat_s(m_wResourcePath, 255, L"\\Resource");
}


/*

//	Texture

*/

//안나오면 Resize를 통해 제대로 형식을 맞추어야 한다.(다운 받은 파일은 손상이되어서 로드가 안될가능성이 매우큼)
Texture* ResourceManager::LoadTexture(std::wstring strKey, std::wstring strRelativePath)
{
	Texture* tex = FindTexture(strKey);
	if (tex != nullptr)
		return tex;

	std::wstring strFilePath = m_wResourcePath;
	strFilePath += strRelativePath;

	tex = new Texture;
	tex->Load(strFilePath);
	tex->SetKey(strKey);
	tex->SetPath(strRelativePath);
	m_mTexture.insert({ strKey, tex });
	return tex;
}

Texture* ResourceManager::FindTexture(std::wstring& strKey)
{
	std::unordered_map<std::wstring, Texture*>::iterator iter = m_mTexture.find(strKey);
	if (iter == m_mTexture.end())
	{
		return nullptr;
	}
	return iter->second;
}

/*

//	AnimationResource

*/

AnimationResource* ResourceManager::LoadAnimationImage(std::wstring strKey, std::wstring strRelativePath)
{
	AnimationResource* anim = new AnimationResource;

	std::wstring strFilePath = m_wResourcePath;
	strFilePath += strRelativePath;

	anim->LoadAnimImage(strFilePath.c_str());
	anim->SetKey(strKey);
	anim->SetPath(strRelativePath);
	m_mAnim.insert({ strKey, anim });
	return anim;
}

void ResourceManager::LoadAnimationMotion(AnimationResource* Anim, std::wstring strRelativePath, bool IsLoop)
{
	std::wstring strFilePath = m_wResourcePath;
	strFilePath += strRelativePath;
	
	Anim->LoadAnimMotion(strFilePath.c_str(), IsLoop);
}

AnimationResource* ResourceManager::FindAnimationResource(std::wstring& strKey)
{
	std::unordered_map<std::wstring, AnimationResource*>::iterator iter = m_mAnim.find(strKey);
	if (iter == m_mAnim.end())
	{
		return nullptr;
	}
	return iter->second;
}



/*

//	Sound

*/

void ResourceManager::InitSound()
{
	System_Create(&m_System);
	m_System->init((int)game::eSoundChannel::End, FMOD_INIT_NORMAL, 0);


	//UI사운드
	//
	//버튼
	LoadMusic(game::eSoundList::UI, false, L"Resource\\Sound\\00. UI\\SFX_UI_Button.wav");
	//게임 시작
	LoadMusic(game::eSoundList::UI, false, L"Resource\\Sound\\00. UI\\SFX_UI_GameStart.wav");


	//Battle사운드
	//
	//보스 레이저 취소 0
	LoadMusic(game::eSoundList::Battle, false, L"Resource\\Sound\\00. BATTLE\\SFX_Boss_Laser_Cancel.wav");
	//보스 레이저 클릭 1
	LoadMusic(game::eSoundList::Battle, false, L"Resource\\Sound\\00. BATTLE\\SFX_Boss_Laser_Click.wav");
	//보스 레이저 준비 2
	LoadMusic(game::eSoundList::Battle, false, L"Resource\\Sound\\00. BATTLE\\SFX_Boss_Laser_Ready.wav");
	//보스 레이저 발사 3
	LoadMusic(game::eSoundList::Battle, false, L"Resource\\Sound\\00. BATTLE\\SFX_Boss_Laser_Shot.wav");
	//보스 고속 미사일 4
	LoadMusic(game::eSoundList::Battle, false, L"Resource\\Sound\\00. BATTLE\\SFX_Boss_Missile_Fast.wav");
	//보스 유도 미사일 5
	LoadMusic(game::eSoundList::Battle, false, L"Resource\\Sound\\00. BATTLE\\SFX_Boss_Missile_Guided.wav");
	//보스 저속 미사일 6
	LoadMusic(game::eSoundList::Battle, false, L"Resource\\Sound\\00. BATTLE\\SFX_Boss_Missile_Slow.wav");
	//홀로그램 On 7
	LoadMusic(game::eSoundList::Battle, false, L"Resource\\Sound\\00. BATTLE\\SFX_Hologram_On.wav");
	//플레이어 차지 공격 준비완료 8
	LoadMusic(game::eSoundList::Battle, false, L"Resource\\Sound\\00. BATTLE\\SFX_Player_Attack_ChargeReady.wav");
	//플레이어 차지 공격 발사 9
	LoadMusic(game::eSoundList::Battle, false, L"Resource\\Sound\\00. BATTLE\\SFX_Player_Attack_ChargeShot.wav");
	//플레이어 일반 공격 10
	LoadMusic(game::eSoundList::Battle, false, L"Resource\\Sound\\00. BATTLE\\SFX_Player_Attack_Normal.wav");
	//플레이어 사망 11
	LoadMusic(game::eSoundList::Battle, false, L"Resource\\Sound\\00. BATTLE\\SFX_Player_Dead.wav");
	//플레이어 피격 12
	LoadMusic(game::eSoundList::Battle, false, L"Resource\\Sound\\00. BATTLE\\SFX_Player_Hitted.wav");
	//플레이어 요격(클릭음) 13
	LoadMusic(game::eSoundList::Battle, false, L"Resource\\Sound\\00. BATTLE\\SFX_Player_Intercept.wav");
	//플레이어 포탈 스킬 사용 14
	LoadMusic(game::eSoundList::Battle, false, L"Resource\\Sound\\00. BATTLE\\SFX_Player_Skill_Portal.wav");
	//플레이어 쉴드 피격 15
	LoadMusic(game::eSoundList::Battle, false, L"Resource\\Sound\\00. BATTLE\\SFX_Player_Skill_Shield_Off.wav");
	//플레이어 쉴드 재생 16
	LoadMusic(game::eSoundList::Battle, false, L"Resource\\Sound\\00. BATTLE\\SFX_Player_Skill_Shield_On.wav");
	//보스 장판 공격 경고음 17
	LoadMusic(game::eSoundList::Battle, false, L"Resource\\Sound\\00. BATTLE\\SFX_Warning_Area.wav");
	//보스 강력한 공격 경고음 18
	LoadMusic(game::eSoundList::Battle, false, L"Resource\\Sound\\00. BATTLE\\SFX_Warning_Danger.wav");
	//보스 메테오 경고음 19
	LoadMusic(game::eSoundList::Battle, false, L"Resource\\Sound\\00. BATTLE\\SFX_Warning_Meteo.wav");
	//플레이어 무적 효과음 20
	LoadMusic(game::eSoundList::Battle, false, L"Resource\\Sound\\00. BATTLE\\SFX_Player_Skill_Invincible.wav");
	//플레이어 지원 미사일 효과음 21
	LoadMusic(game::eSoundList::Battle, false, L"Resource\\Sound\\00. BATTLE\\SFX_Support_Missile.wav");
	//폭팔음 22
	LoadMusic(game::eSoundList::Battle, false, L"Resource\\Sound\\00. BATTLE\\SFX_Explosion.ogg");
	

	//BGM 사운드
	//
	//타이틀 브금 0
	LoadMusic(game::eSoundList::BGM, true, L"Resource\\Sound\\00. BGM\\BGM_Title.wav");
	//뉴스 브금 1
	LoadMusic(game::eSoundList::BGM, false, L"Resource\\Sound\\00. BGM\\BGM_News.wav");
	//브리핑 브금 2 
	LoadMusic(game::eSoundList::BGM, true, L"Resource\\Sound\\00. BGM\\BGM_Briefings.wav");
	//우주 브금 3
	LoadMusic(game::eSoundList::BGM, false, L"Resource\\Sound\\00. BGM\\BGM_Space.wav");
	//함선 브금 4
	LoadMusic(game::eSoundList::BGM, false, L"Resource\\Sound\\00. BGM\\BGM_SpaceShip.wav");
	//스테이지01 브금 5
	LoadMusic(game::eSoundList::BGM, true, L"Resource\\Sound\\00. BGM\\BGM_Stage01.wav");
	//스테이지02 브금 6
	LoadMusic(game::eSoundList::BGM, true, L"Resource\\Sound\\00. BGM\\BGM_Stage02.wav");
	//스테이지03 브금 7
	LoadMusic(game::eSoundList::BGM, true, L"Resource\\Sound\\00. BGM\\BGM_Stage03.wav");
	//엔딩 브금 8
	LoadMusic(game::eSoundList::BGM, false, L"Resource\\Sound\\00. BGM\\BGM_Ending.wav");
	
	

	//Story 사운드
	//
	//도입 스토리 뉴스 사운드
	LoadMusic(game::eSoundList::STORY_Story01_News, false, L"Resource\\Sound\\04. INTRODUCTION_STORY_NEWS\\STORY_Story01_News_01.wav");
	LoadMusic(game::eSoundList::STORY_Story01_News, false, L"Resource\\Sound\\04. INTRODUCTION_STORY_NEWS\\STORY_Story01_News_02.wav");
	LoadMusic(game::eSoundList::STORY_Story01_News, false, L"Resource\\Sound\\04. INTRODUCTION_STORY_NEWS\\STORY_Story01_News_03.wav");
	LoadMusic(game::eSoundList::STORY_Story01_News, false, L"Resource\\Sound\\04. INTRODUCTION_STORY_NEWS\\STORY_Story01_News_04.wav");
	LoadMusic(game::eSoundList::STORY_Story01_News, false, L"Resource\\Sound\\04. INTRODUCTION_STORY_NEWS\\STORY_Story01_News_05.wav");
	LoadMusic(game::eSoundList::STORY_Story01_News, false, L"Resource\\Sound\\04. INTRODUCTION_STORY_NEWS\\STORY_Story01_News_06.wav");
	LoadMusic(game::eSoundList::STORY_Story01_News, false, L"Resource\\Sound\\04. INTRODUCTION_STORY_NEWS\\STORY_Story01_News_07.wav");

	//스테이지1 미션브리핑 사운드
	LoadMusic(game::eSoundList::STORY_Story02_Briefing, false, L"Resource\\Sound\\04. INTRODUCTION_STORY_NEWS\\STORY_Story02_Briefing_00.wav");
	LoadMusic(game::eSoundList::STORY_Story02_Briefing, false, L"Resource\\Sound\\04. INTRODUCTION_STORY_NEWS\\STORY_Story02_Briefing_01.wav");
	LoadMusic(game::eSoundList::STORY_Story02_Briefing, false, L"Resource\\Sound\\04. INTRODUCTION_STORY_NEWS\\STORY_Story02_Briefing_02.wav");
	LoadMusic(game::eSoundList::STORY_Story02_Briefing, false, L"Resource\\Sound\\04. INTRODUCTION_STORY_NEWS\\STORY_Story02_Briefing_03.wav");
	LoadMusic(game::eSoundList::STORY_Story02_Briefing, false, L"Resource\\Sound\\04. INTRODUCTION_STORY_NEWS\\STORY_Story02_Briefing_04.wav");
	LoadMusic(game::eSoundList::STORY_Story02_Briefing, false, L"Resource\\Sound\\04. INTRODUCTION_STORY_NEWS\\STORY_Story02_Briefing_05.wav");
	LoadMusic(game::eSoundList::STORY_Story02_Briefing, false, L"Resource\\Sound\\04. INTRODUCTION_STORY_NEWS\\STORY_Story02_Briefing_06.wav");
	LoadMusic(game::eSoundList::STORY_Story02_Briefing, false, L"Resource\\Sound\\04. INTRODUCTION_STORY_NEWS\\STORY_Story02_Briefing_07.wav");
	LoadMusic(game::eSoundList::STORY_Story02_Briefing, false, L"Resource\\Sound\\04. INTRODUCTION_STORY_NEWS\\STORY_Story02_Briefing_08.wav");
	LoadMusic(game::eSoundList::STORY_Story02_Briefing, false, L"Resource\\Sound\\04. INTRODUCTION_STORY_NEWS\\STORY_Story02_Briefing_09.wav");
	LoadMusic(game::eSoundList::STORY_Story02_Briefing, false, L"Resource\\Sound\\04. INTRODUCTION_STORY_NEWS\\STORY_Story02_Briefing_10.wav");

	//출격씬 사운드											   
	LoadMusic(game::eSoundList::STORY_Story03_Takeoff, false, L"Resource\\Sound\\05. SALLY\\STORY_Story03_Takeoff_01.wav");
	LoadMusic(game::eSoundList::STORY_Story03_Takeoff, false, L"Resource\\Sound\\05. SALLY\\STORY_Story03_Takeoff_02.wav");
	LoadMusic(game::eSoundList::STORY_Story03_Takeoff, false, L"Resource\\Sound\\05. SALLY\\STORY_Story03_Takeoff_03.wav");
	LoadMusic(game::eSoundList::STORY_Story03_Takeoff, false, L"Resource\\Sound\\05. SALLY\\STORY_Story03_Takeoff_04.wav");
	LoadMusic(game::eSoundList::STORY_Story03_Takeoff, false, L"Resource\\Sound\\05. SALLY\\STORY_Story03_Takeoff_05.wav");
	LoadMusic(game::eSoundList::STORY_Story03_Takeoff, false, L"Resource\\Sound\\05. SALLY\\STORY_Story03_Takeoff_06.wav");

	//함선 보스1 연출 사운드
	LoadMusic(game::eSoundList::STORY_Story04_Encounters, false, L"Resource\\Sound\\06. SHIP_DIRECTING_BOSS_01\\STORY_Story04_Encounters_01.wav");
	LoadMusic(game::eSoundList::STORY_Story04_Encounters, false, L"Resource\\Sound\\06. SHIP_DIRECTING_BOSS_01\\STORY_Story04_Encounters_02.wav");

	//Stage01 전투 사운드
	LoadMusic(game::eSoundList::STORY_Stage01_Battle, false, L"Resource\\Sound\\07. STAGE_NORMAL_01\\STORY_Stage01_Battle_01.wav");
	LoadMusic(game::eSoundList::STORY_Stage01_Battle, false, L"Resource\\Sound\\07. STAGE_NORMAL_01\\STORY_Stage01_Battle_02.wav");
	LoadMusic(game::eSoundList::STORY_Stage01_Battle, false, L"Resource\\Sound\\07. STAGE_NORMAL_01\\STORY_Stage01_Battle_03.wav");
	LoadMusic(game::eSoundList::STORY_Stage01_Battle, false, L"Resource\\Sound\\07. STAGE_NORMAL_01\\STORY_Stage01_Battle_04.wav");
	LoadMusic(game::eSoundList::STORY_Stage01_Battle, false, L"Resource\\Sound\\07. STAGE_NORMAL_01\\STORY_Stage01_Battle_05.wav");
	LoadMusic(game::eSoundList::STORY_Stage01_Battle, false, L"Resource\\Sound\\07. STAGE_NORMAL_01\\STORY_Stage01_Battle_06.wav");
	LoadMusic(game::eSoundList::STORY_Stage01_Battle, false, L"Resource\\Sound\\07. STAGE_NORMAL_01\\STORY_Stage01_Battle_07.wav");
	LoadMusic(game::eSoundList::STORY_Stage01_Battle, false, L"Resource\\Sound\\07. STAGE_NORMAL_01\\STORY_Stage01_Battle_08.wav");

	//Stage01 클리어 중간 스토리
	LoadMusic(game::eSoundList::STORY_Story05_Briefing, false, L"Resource\\Sound\\09. MIDDLE_STORY_01\\STORY_Story05_Briefing_01.wav");
	LoadMusic(game::eSoundList::STORY_Story05_Briefing, false, L"Resource\\Sound\\09. MIDDLE_STORY_01\\STORY_Story05_Briefing_02.wav");
	LoadMusic(game::eSoundList::STORY_Story05_Briefing, false, L"Resource\\Sound\\09. MIDDLE_STORY_01\\STORY_Story05_Briefing_03.wav");
	LoadMusic(game::eSoundList::STORY_Story05_Briefing, false, L"Resource\\Sound\\09. MIDDLE_STORY_01\\STORY_Story05_Briefing_04.wav");
	LoadMusic(game::eSoundList::STORY_Story05_Briefing, false, L"Resource\\Sound\\09. MIDDLE_STORY_01\\STORY_Story05_Briefing_05.wav");
	LoadMusic(game::eSoundList::STORY_Story05_Briefing, false, L"Resource\\Sound\\09. MIDDLE_STORY_01\\STORY_Story05_Briefing_06.wav");
	LoadMusic(game::eSoundList::STORY_Story05_Briefing, false, L"Resource\\Sound\\09. MIDDLE_STORY_01\\STORY_Story05_Briefing_07.wav");
	LoadMusic(game::eSoundList::STORY_Story05_Briefing, false, L"Resource\\Sound\\09. MIDDLE_STORY_01\\STORY_Story05_Briefing_09.wav");
	LoadMusic(game::eSoundList::STORY_Story05_Briefing, false, L"Resource\\Sound\\09. MIDDLE_STORY_01\\STORY_Story05_Briefing_10.wav");
	LoadMusic(game::eSoundList::STORY_Story05_Briefing, false, L"Resource\\Sound\\09. MIDDLE_STORY_01\\STORY_Story05_Briefing_11.wav");
	LoadMusic(game::eSoundList::STORY_Story05_Briefing, false, L"Resource\\Sound\\09. MIDDLE_STORY_01\\STORY_Story05_Briefing_12.wav");
	LoadMusic(game::eSoundList::STORY_Story05_Briefing, false, L"Resource\\Sound\\09. MIDDLE_STORY_01\\STORY_Story05_Briefing_13.wav");

	//함선 보스2 연출 사운드
	LoadMusic(game::eSoundList::STORY_Story06_Encounters, false, L"Resource\\Sound\\10. SHIP_DIRECTING_BOSS_02\\STORY_Story06_Encounters_01.wav");
	LoadMusic(game::eSoundList::STORY_Story06_Encounters, false, L"Resource\\Sound\\10. SHIP_DIRECTING_BOSS_02\\STORY_Story06_Encounters_02.wav");

	//Stage02 함선 보스2 전투 사운드
	LoadMusic(game::eSoundList::STORY_Stage02_Battle, false, L"Resource\\Sound\\11. STAGE_NORMAL_02\\STORY_Stage02_Battle_01.wav");
	LoadMusic(game::eSoundList::STORY_Stage02_Battle, false, L"Resource\\Sound\\11. STAGE_NORMAL_02\\STORY_Stage02_Battle_02.wav");
	LoadMusic(game::eSoundList::STORY_Stage02_Battle, false, L"Resource\\Sound\\11. STAGE_NORMAL_02\\STORY_Stage02_Battle_03.wav");


	//Stage02 클리어 중간 스토리 사운드
	LoadMusic(game::eSoundList::STORY_Story07_Briefing, false, L"Resource\\Sound\\13. MIDDLE_STORY_02\\STORY_Story07_Briefing_01.wav");
	LoadMusic(game::eSoundList::STORY_Story07_Briefing, false, L"Resource\\Sound\\13. MIDDLE_STORY_02\\STORY_Story07_Briefing_02.wav");
	LoadMusic(game::eSoundList::STORY_Story07_Briefing, false, L"Resource\\Sound\\13. MIDDLE_STORY_02\\STORY_Story07_Briefing_03.wav");
	LoadMusic(game::eSoundList::STORY_Story07_Briefing, false, L"Resource\\Sound\\13. MIDDLE_STORY_02\\STORY_Story07_Briefing_04.wav");
	LoadMusic(game::eSoundList::STORY_Story07_Briefing, false, L"Resource\\Sound\\13. MIDDLE_STORY_02\\STORY_Story07_Briefing_05.wav");
	LoadMusic(game::eSoundList::STORY_Story07_Briefing, false, L"Resource\\Sound\\13. MIDDLE_STORY_02\\STORY_Story07_Briefing_06.wav");
	LoadMusic(game::eSoundList::STORY_Story07_Briefing, false, L"Resource\\Sound\\13. MIDDLE_STORY_02\\STORY_Story07_Briefing_07.wav");
	LoadMusic(game::eSoundList::STORY_Story07_Briefing, false, L"Resource\\Sound\\13. MIDDLE_STORY_02\\STORY_Story07_Briefing_08.wav");

	//Stage03 함선 보스3 연출 사운드
	LoadMusic(game::eSoundList::STORY_Story08_Encounters, false, L"Resource\\Sound\\14. SHIP_DIRECTING_BOSS_03\\STORY_Story08_Encounters_01.wav");
	LoadMusic(game::eSoundList::STORY_Story08_Encounters, false, L"Resource\\Sound\\14. SHIP_DIRECTING_BOSS_03\\STORY_Story08_Encounters_02.wav");


	//Stage03 함선 보스3 전투 사운드
	LoadMusic(game::eSoundList::STORY_Story08_Encounters, false, L"Resource\\Sound\\15. STAGE_NORMAL_03\\STORY_Stage03_Battle_01.wav");
	LoadMusic(game::eSoundList::STORY_Story08_Encounters, false, L"Resource\\Sound\\15. STAGE_NORMAL_03\\STORY_Stage03_Battle_02.wav");

	//엔딩 스토리 사운드
	LoadMusic(game::eSoundList::STORY_Story09_News, false, L"Resource\\Sound\\17. ENDING\\STORY_Story09_News_01.wav");
	LoadMusic(game::eSoundList::STORY_Story09_News, false, L"Resource\\Sound\\17. ENDING\\STORY_Story09_News_02.wav");
	LoadMusic(game::eSoundList::STORY_Story09_News, false, L"Resource\\Sound\\17. ENDING\\STORY_Story09_News_03.wav");

	//엔딩 브리핑 사운드
	LoadMusic(game::eSoundList::STORY_Story10_Briefing, false, L"Resource\\Sound\\17. ENDING\\STORY_Story10_Briefing_01.wav");
	LoadMusic(game::eSoundList::STORY_Story10_Briefing, false, L"Resource\\Sound\\17. ENDING\\STORY_Story10_Briefing_02.wav");
	LoadMusic(game::eSoundList::STORY_Story10_Briefing, false, L"Resource\\Sound\\17. ENDING\\STORY_Story10_Briefing_03.wav");

	//엔딩 폭발 사운드
	LoadMusic(game::eSoundList::STORY_Story11_Bombing, false, L"Resource\\Sound\\17. ENDING\\STORY_Story11_Bombing_02.wav");
	LoadMusic(game::eSoundList::STORY_Story11_Bombing, false, L"Resource\\Sound\\17. ENDING\\STORY_Story11_Bombing_03.wav");

	// 엔딩

	
	/*LoadMusic(game::eSoundList::StartBGM, true, L"Resource\\Sound\\StartBGM.wav");
	LoadMusic(game::eSoundList::MainBGM, true, L"Resource\\Sound\\MainBGM.mp3");
	LoadMusic(game::eSoundList::BossBGM, true, L"Resource\\Sound\\BossBGM.mp3");

	LoadMusic(game::eSoundList::DashEffect, false, L"Resource\\Sound\\DashEffect.mp3");
	LoadMusic(game::eSoundList::ShotEffect, false, L"Resource\\Sound\\ShotEffect.mp3");
	LoadMusic(game::eSoundList::CollisionEffect, false, L"Resource\\Sound\\CollisionEffect.mp3");*/


	SetVolume(0.5f); //크기조정
}

void ResourceManager::LoadMusic(game::eSoundList list, bool loopcheck, std::wstring musicPath)
{
	//std::wstring strFilePath = m_wResourcePath;
	//strFilePath += musicPath;

	std::string tempPath;
	USES_CONVERSION;
	tempPath = std::string(W2A(musicPath.c_str()));

	FMOD::Sound* tempSound;
	if (loopcheck)
		m_System->createSound(tempPath.c_str(), FMOD_LOOP_NORMAL, 0, &tempSound);
	else
		m_System->createSound(tempPath.c_str(), FMOD_LOOP_OFF, 0, &tempSound);
 	m_SoundList[static_cast<int>(list)].push_back(tempSound);
}

void ResourceManager::PlayMusic(game::eSoundList list, int index, game::eSoundChannel channel)
{
	if (m_SoundList[static_cast<int>(list)].size() > index)
	{
		m_Channel[static_cast<int>(channel)]->stop();
		m_System->playSound(m_SoundList[static_cast<int>(list)][index], NULL, 0, &m_Channel[static_cast<int>(channel)]);
		m_Channel[static_cast<int>(channel)]->setVolume(m_fVolume);
	}
}

void ResourceManager::StopMusic(game::eSoundChannel channel)
{
	m_Channel[static_cast<int>(channel)]->stop();
}

void ResourceManager::SetVolume(float volume)
{
	m_fVolume = volume;
	for (unsigned int i = 0; i < static_cast<unsigned int>(game::eSoundChannel::End); ++i)
		m_Channel[i]->setVolume(m_fVolume);
}

bool ResourceManager::IsPlay(game::eSoundChannel channel)
{
	bool isPlay;
	m_Channel[static_cast<int>(channel)]->isPlaying(&isPlay);
	return isPlay;
}

