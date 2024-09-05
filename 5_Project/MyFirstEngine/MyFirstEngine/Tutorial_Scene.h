#pragma once
#include "SceneBase.h"

class Tutorial_Scene : public SceneBase
{

public:
    void Initialize() override;
    void Finalize() override;

    void Enter() override;
    void Exit() override;


public:
    Tutorial_Scene() : SceneBase("Tutorial_Scene") {};
    virtual ~Tutorial_Scene() {};

};

