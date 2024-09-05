#pragma once
#include "SceneBase.h"

class Cokpit_Script : public SceneBase
{
public:
    void Initialize() override;
    void Finalize() override;

    void Enter() override;
    void Exit() override;

public:
    Cokpit_Script() :SceneBase("Cokpit_Script") {};
    virtual ~Cokpit_Script() {};
};

