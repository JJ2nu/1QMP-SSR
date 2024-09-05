#pragma once
#include "GameObject.h"
#include "StartStageUIScript.h"

class Text_Tutorial_ESC : public GameObject
{
public:
	StartStageUIScript* myScript;

public:
	Text_Tutorial_ESC(SceneBase* Scene) :GameObject("Text_Tutorial_ESC", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<StartStageUIScript>("Text_Tutorial_ESC");
		//myScript->DialogReset(9);

		// 다이얼로그 내용 설정
		std::wstring dialogs[1] = { L"ESC" };
		myScript->SetMyColor(255, 255, 255);
		myScript->SetRectSizeAndTransform(1920, 1080, 1750, 50);
		myScript->SetMyDialog(dialogs, 1);
		myScript->SetAllText();
		myScript->SetMyTextureTransform(1600, 100);
		myScript->SetFontSize(80);

	}
	virtual ~Text_Tutorial_ESC() {};

};