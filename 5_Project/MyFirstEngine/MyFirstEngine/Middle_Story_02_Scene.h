#pragma once
#include "SceneBase.h"

class Middle_Story_02_Scene : public SceneBase
{
public:
    void Initialize() override;
    void Finalize() override;

    void Enter() override;
    void Exit() override;
       
public:
    Middle_Story_02_Scene() : SceneBase("Middle_Story_02_Scene") {};
    virtual ~Middle_Story_02_Scene() {};

};

