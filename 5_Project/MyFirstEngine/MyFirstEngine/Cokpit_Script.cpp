#include "Cokpit_Script.h"
#include "Cokpit_BackGroundUI.h"

void Cokpit_Script::Initialize()
{

}

void Cokpit_Script::Finalize()
{

}

void Cokpit_Script::Enter()
{
	Cokpit_BackGroundUI* cokpit_BackGroundUI = new Cokpit_BackGroundUI(this);
	AddObject(cokpit_BackGroundUI, game::OBJECT_TYPE::UI);

}


void Cokpit_Script::Exit()
{

}
