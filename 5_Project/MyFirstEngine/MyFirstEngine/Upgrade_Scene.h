#pragma once
#include "SceneBase.h"
#include "Observer.h"
class Upgrade_Scene : public SceneBase
{
public:
    void Initialize() override;
    void Finalize() override;

    void Enter() override;
    void Exit() override;

    struct UpgradeInfo
    {
        int type;
        std::wstring strKey;
        std::wstring relPath;
        std::wstring options;
    }upgradeinfo;
    int firstSkill = -1;




public:
    Upgrade_Scene() :SceneBase("Upgrade_Scene") {};
    ~Upgrade_Scene() {};
};

