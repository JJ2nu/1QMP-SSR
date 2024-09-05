#pragma once
#include "SceneBase.h"


class Start_Menu : public SceneBase
{
public:
    void Initialize() override;
    void Finalize() override;

    void Enter() override;
    void Exit() override;

public:
    Start_Menu() :SceneBase("Start_Menu") {};
    ~Start_Menu() {};
};

