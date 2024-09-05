#pragma once
#include "SceneBase.h"

class Boss_01_Scene : public SceneBase
{
public:
    void Initialize() override;
    void Finalize() override;

    void Enter() override;
    void Exit() override;

public:
    Boss_01_Scene();
    ~Boss_01_Scene();
};

