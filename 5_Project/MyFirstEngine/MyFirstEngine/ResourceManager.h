#pragma once

#ifndef _WIN64
#include "fmod.hpp"
#pragma comment (lib, "fmod_vc.lib")
using namespace FMOD;
#endif
#ifdef _WIN64
#include "fmod.hpp"
#pragma comment (lib, "fmod_vc.lib")
using namespace FMOD;
#endif

#include <unordered_map>
#include <string>
#include "Define.h"

class Resource;
class Texture;
class AnimationResource;
//class Sound;

class ResourceManager
{
public:
	static ResourceManager* GetInstance();
	static void DestroyResourceManager();

	void Initialize();


	//ResourcePath
	void InitPathManager();
	wchar_t* GetPath() {return m_wResourcePath;}

	//Texture
	Texture* LoadTexture(std::wstring strKey, std::wstring strRelativePath);
	Texture* FindTexture(std::wstring& strKey);

	//Animation
	AnimationResource* LoadAnimationImage(std::wstring strKey, std::wstring strRelativePath);
	void LoadAnimationMotion(AnimationResource* Anim, std::wstring strRelativePath, bool IsLoop = true);
	AnimationResource* FindAnimationResource(std::wstring& strKey);

	//Sound
	void InitSound();
	void LoadMusic(game::eSoundList list, bool loopcheck, std::wstring musicPath);
	void PlayMusic(game::eSoundList list, int index,  game::eSoundChannel channel);
	void StopMusic(game::eSoundChannel channel);
	void SetVolume(float volume);
	bool IsPlay(game::eSoundChannel channel);

private:
	static ResourceManager* instance;

	//ResourcePath
	wchar_t m_wResourcePath[255];

	//Texture
	std::unordered_map<std::wstring, Texture*> m_mTexture;

	//AnimationResource
	std::unordered_map<std::wstring, AnimationResource*> m_mAnim;

	//Sound
	FMOD::System* m_System;
	FMOD::Channel* m_Channel[static_cast<int>(game::eSoundChannel::End)];
	
	std::vector<FMOD::Sound*>m_SoundList[static_cast<int>(game::eSoundList::End)];
	float m_fVolume;

private:
	ResourceManager();
	~ResourceManager();
};


