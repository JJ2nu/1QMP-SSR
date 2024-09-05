#pragma once
#include "GameObject.h"
#include "StartStageUIScript.h"
#include "ResourceManager.h"


class Sally_Dialog : public GameObject
{

public:
	StartStageUIScript* myScript;
	Sally_Dialog(SceneBase* Scene) : GameObject("SALLY_Dialog", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<StartStageUIScript>("SALLY_DialogUIScript");

		std::wstring dialogs[5] = 
		{
			L" ",
			L" ",
			L" ",
			L" ",
			L" ",	
		};

		//myScript->m_eSoundChannel = game::eSoundChannel::Voice;
		//myScript->m_eSoundList = game::eSoundList::STORY_Story03_Takeoff;

		//ResourceManager::GetInstance()->PlayMusic(game::eSoundList::STORY_Story03_Takeoff, 0, game::eSoundChannel::Voice);

		myScript->SetMyColor(255, 255, 255);
		myScript->SetMyDialog(dialogs, 5);
		myScript->SetAllText();
		myScript->SetRectSizeAndTransform(1900, 1080, 620, 900);
		myScript->SetFontSize(50);
		myScript->MaxdelayTime = 1.f;
	};
	virtual ~Sally_Dialog() {};

private:

};