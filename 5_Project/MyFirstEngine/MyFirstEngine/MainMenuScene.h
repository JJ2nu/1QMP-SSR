#pragma once
#include "SceneBase.h"


class MainMenuScene : public SceneBase
{
public:
    void Initialize() override;
    void Finalize() override;

    void Enter() override;
    void Exit() override;

public:
    MainMenuScene() :SceneBase("MainMenuScene"){};
    ~MainMenuScene() {};
};

