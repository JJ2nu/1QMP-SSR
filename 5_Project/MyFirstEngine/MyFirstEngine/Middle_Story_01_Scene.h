#pragma once
#include "SceneBase.h"

class Middle_Story_01_Scene : public SceneBase
{
public:
    void Initialize() override;
    void Finalize() override;

    void Enter() override;
    void Exit() override;


public:
    Middle_Story_01_Scene() : SceneBase("Middle_Story_01_Scene") {};
    virtual ~Middle_Story_01_Scene() {};

};

