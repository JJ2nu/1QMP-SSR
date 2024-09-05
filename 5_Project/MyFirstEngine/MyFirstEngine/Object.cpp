#include "Object.h"
#include "Define.h"

Object::Object(std::string ObjName)
	: m_sObjName(ObjName)
{
	m_eStatus = game::Status::Active;
}

Object::~Object(){}

std::string Object::GetObjClassName()
{
	const std::type_info& self = typeid(*this);
	std::string className = self.name();
	size_t classPos = className.find("class ");
	if (classPos != std::string::npos) {
		className.erase(classPos, 6); // 6 is the length of "class "
	}
	return className;
}