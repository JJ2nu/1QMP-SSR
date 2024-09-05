#pragma once
#include <string>
#include <typeinfo>
#include <Windows.h>
#include <cassert>
#include "Transform.h"

namespace game
{
	enum class Status;
	enum class OBJECT_TYPE;
}

class Object
{
public:
	std::string GetObjClassName();

	void SetObjType(game::OBJECT_TYPE ObjType) { m_sObjType = ObjType; }
	game::OBJECT_TYPE GetObjType() const { return m_sObjType; }

	void SetObjName(std::string ObjName) { m_sObjName = ObjName; }
	std::string GetObjName() const { return m_sObjName; }

	void SetStatus(game::Status Status) { m_eStatus = Status; }
	game::Status GetStatus() const { return m_eStatus; }
	

protected:
	std::string m_sObjName;
	game::OBJECT_TYPE m_sObjType;
	game::Status m_eStatus;
	

protected:
	Object(std::string m_ObjName);
	virtual ~Object();
};

