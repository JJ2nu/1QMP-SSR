#pragma once
#include "SceneBase.h"
class PrototypeScene :
    public SceneBase
{
public:
    void Initialize() override;
    void Finalize() override;

    void Enter() override;
    void Exit() override;

public:
    PrototypeScene();
    ~PrototypeScene();
};

