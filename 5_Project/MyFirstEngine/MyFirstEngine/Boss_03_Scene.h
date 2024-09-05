#pragma once
#include "SceneBase.h"

class Boss_03_Scene : public SceneBase
{
public:
    void Initialize() override;
    void Finalize() override;

    void Enter() override;
    void Exit() override;

public:
    Boss_03_Scene();
    ~Boss_03_Scene();
};

