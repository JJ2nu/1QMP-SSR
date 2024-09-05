#pragma once
#include "GameObject.h"
#include "StartStageUIScript.h"


class StartStageUI : public GameObject
{
public:
	StartStageUIScript* myScript;

public :
	StartStageUI(SceneBase* Scene) :GameObject("PlayUI", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<StartStageUIScript>("StartStageUIScript");
		//myScript->DialogReset(9);

		// 다이얼로그 내용 설정
		std::wstring dialogs[1] = {L"\tGAME\nSTART"};
		myScript->SetMyColor(255, 0, 0);
		myScript->SetRectSizeAndTransform(1920,1080,800,500);
		myScript->SetMyDialog(dialogs, 1);
		myScript->SetAllText();
		myScript->SetMyTextureTransform(800, 500);
		myScript->SetFontSize(100);

	}
	virtual ~StartStageUI() {};
	
};
// 샘플용..