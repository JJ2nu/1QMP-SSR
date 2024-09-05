#pragma once
#include "SceneBase.h"

class Sally_Scene : public SceneBase
{

public:
    void Initialize() override;
    void Finalize() override;

    void Enter() override;
    void Exit() override;


public:
    Sally_Scene() : SceneBase("Sally_Scene") {};
    virtual ~Sally_Scene(){};
};

