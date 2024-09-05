#pragma once
#include "SceneBase.h"

class Story_Briefing_Scene : public SceneBase
{
public:
    void Initialize() override;
    void Finalize() override;

    void Enter() override;
    void Exit() override;


public:
    Story_Briefing_Scene() : SceneBase("Story_Briefing_Scene") {};
    virtual ~Story_Briefing_Scene() {};

};

