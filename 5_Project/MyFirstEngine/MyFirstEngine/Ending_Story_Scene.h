#pragma once
#include "SceneBase.h"

class Ending_Story_Scene : public SceneBase
{
public:
    void Initialize() override;
    void Finalize() override;

    void Enter() override;
    void Exit() override;

public:
    Ending_Story_Scene() :SceneBase("Ending_Story_Scene") {};
    ~Ending_Story_Scene() {};
};

