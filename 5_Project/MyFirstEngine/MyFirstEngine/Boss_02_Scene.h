#pragma once
#include "SceneBase.h"

class Boss_02_Scene : public SceneBase
{
public:
    void Initialize() override;
    void Finalize() override;

    void Enter() override;
    void Exit() override;

public:
    Boss_02_Scene();
    ~Boss_02_Scene();
};

