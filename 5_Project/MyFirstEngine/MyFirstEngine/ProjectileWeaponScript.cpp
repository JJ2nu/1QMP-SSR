#include "ProjectileWeaponScript.h"
#include "ResourceManager.h"


// 생성자: ProjectileWeaponScript를 소유 GameObject와 객체 이름으로 초기화
ProjectileWeaponScript::ProjectileWeaponScript(GameObject* pOwner, std::string ObjName)
    : WeaponScript(pOwner, std::move(ObjName)), m_ActivationTime(0.0f), m_IsWarningActive(false), m_cRender(nullptr),
    missileX(2000.0f), missileY(300.0f), missileWidth(50.0f), missileHeight(10.0f)
{
    
}
void ProjectileWeaponScript::Start()
{
    
}
void ProjectileWeaponScript::MoveMissile(float fixedDeltaTime, Vector3 moveDirection)
{
}


void ProjectileWeaponScript::FixedUpdate(float fixedDeltaTime)
{

}
void ProjectileWeaponScript::Activate(Vector3 pos)
{

}
