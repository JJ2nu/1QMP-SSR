#pragma once
#include "SceneBase.h"


class Story_News_Scene : public SceneBase
{
public:
    void Initialize() override;
    void Finalize() override;

    void Enter() override;
    void Exit() override;

public:
    Story_News_Scene() :SceneBase("Story_News_Scene") {};
    ~Story_News_Scene() {};
};

