#pragma once
#include "SceneBase.h"


class Scene_1 : public SceneBase
{
public:
    void Initialize() override;
    void Finalize() override;

    void Enter() override;
    void Exit() override;

public:
    Scene_1() :SceneBase("Scene_1") {};
    ~Scene_1() {};
};

