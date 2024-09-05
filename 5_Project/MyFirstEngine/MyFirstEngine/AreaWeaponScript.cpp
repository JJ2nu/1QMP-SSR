#include "AreaWeaponScript.h"
#include "SceneBase.h"
#include "ResourceManager.h"
#include <random>

Vector3 AreaWeaponScript::s_vPlayerPos = 0;

AreaWeaponScript::AreaWeaponScript(GameObject* pOwner, std::string ObjName)
	:WeaponScript(pOwner, ObjName)
{
	Start();
}

void AreaWeaponScript::Start()
{

}


