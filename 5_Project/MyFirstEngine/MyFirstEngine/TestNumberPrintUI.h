#pragma once
#include "GameObject.h"
#include "NumberPrintUIScript.h"

class TestNumberPrintUI : public GameObject
{

	NumberPrintUIScript* myScript;

public:
	TestNumberPrintUI(SceneBase* Scene) : GameObject("TestNumberPrintUI", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<NumberPrintUIScript>("TestNumberPrintUIScript");
		myScript->SetRectSizeAndTransform(1920, 1080, 200, 100);
		myScript->SetMyColor(255, 0, 0);
		
	}

	virtual ~TestNumberPrintUI() {};
	
};

// 여기에 함
