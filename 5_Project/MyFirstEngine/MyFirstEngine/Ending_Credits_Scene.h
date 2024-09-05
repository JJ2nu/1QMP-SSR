#pragma once
#include "SceneBase.h"

class Ending_Credits_Scene : public SceneBase
{
public:
    void Initialize() override;
    void Finalize() override;

    void Enter() override;
    void Exit() override;


public:
    Ending_Credits_Scene() : SceneBase("Ending_Credits_Scene") {};
    virtual ~Ending_Credits_Scene() {};

};

