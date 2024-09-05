#include "Transform.h"


Transform::Transform(void) : Position(0, 0, 0), Rotation(0, 0, 0), Scale(1, 1, 1) {}
Transform::Transform(const Transform& src)
{
	*this = src;
}

Transform::~Transform(void) {}
Transform& Transform::operator=(const Transform& rhs)
{
	if (this != &rhs)
	{
		this->Position = rhs.Position;
		this->Rotation = rhs.Rotation;
		/*this->_offsetPosition = rhs._offsetPosition;*/
		this->Scale = rhs.Scale;
	}
	return *this;
}

void Transform::SetPosition(const float x, const float y, const float z)
{
	Position = Vector3(x, y, z);
}

void Transform::SetPosition(const Vector3& v)
{
	Position = v;
}

Vector3 Transform::GetPosition()
{
	return Position;
}

//void Transform::SetOffsetPosition(const float x, const float y, const float z)
//{
//	_offsetPosition = Vector3(x, y, z);
//}
//
//void Transform::SetOffsetPosition(const Vector3& v)
//{
//	_offsetPosition = v;
//}
//
//Vector3 Transform::GetOffsetPosition()
//{
//	return _offsetPosition;
//}

void Transform::SetRotation(const float x, const float y, const float z)
{
	Rotation = Vector3(x, y, z);
}

void Transform::SetRotation(const Vector3& v)
{
	Rotation = v;
}

Vector3 Transform::GetRotation()
{
	return Rotation;
}
Vector3 Transform::GetRotationVector()
{
	float  x = 1;
	float  y = 0;
	float  z = 0;
	//z축 연산
	float x1 = x * cos(Rotation.z * PI / 180) - y * sin(Rotation.z * PI / 180);
	float y1 = x * sin(Rotation.z * PI / 180) - y * sin(Rotation.z * PI / 180);
	//----------------------------------
	//x축 연산
	float y2 = y1 * cos(Rotation.x * PI / 180) - z * sin(Rotation.x * PI / 180);
	float z1 = y1 * sin(Rotation.x * PI / 180) + z * cos(Rotation.x * PI / 180);
	//----------------------------------
	//y축 연산
	float x2 = z1 * sin(Rotation.y * PI / 180) + x1 * cos(Rotation.y * PI / 180);
	float z2 = z1 * cos(Rotation.y * PI / 180) - x1 * sin(Rotation.y * PI / 180);

	return Vector3(x2, y2, z2);
}

Vector3 Transform::GetRotationVector(Vector3 v)
{
	float  x = v.x;
	float  y = v.y;
	float  z = v.z;
	//z축 연산
	float x1 = x * cos(Rotation.z * PI / 180) - y * sin(Rotation.z * PI / 180);
	float y1 = x * sin(Rotation.z * PI / 180) - y * sin(Rotation.z * PI / 180);
	//----------------------------------
	//x축 연산
	float y2 = y1 * cos(Rotation.x * PI / 180) - z * sin(Rotation.x * PI / 180);
	float z1 = y1 * sin(Rotation.x * PI / 180) + z * cos(Rotation.x * PI / 180);
	//----------------------------------
	//y축 연산
	float x2 = z1 * sin(Rotation.y * PI / 180) + x1 * cos(Rotation.y * PI / 180);
	float z2 = z1 * cos(Rotation.y * PI / 180) - x1 * sin(Rotation.y * PI / 180);

	return Vector3(x2, y2, z2);
}


void Transform::SetScale(const float x, const float y, const float z)
{
	Scale = Vector3(x, y, z);
}
void Transform::SetScale(const Vector3& v)
{
	Scale = v;
}
Vector3 Transform::GetScale()
{
	return Scale;
}
