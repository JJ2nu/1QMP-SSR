#pragma once
#include "SceneBase.h"

class SampleScene :
    public SceneBase
{
public:
    // SceneBase을(를) 통해 상속됨
    void Initialize() override;
    void Finalize() override;

    void Enter() override;
    void Exit() override;
public:
    SampleScene();
    ~SampleScene();
};

