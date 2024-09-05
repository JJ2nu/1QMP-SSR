#include "Vector3.h"


Vector3::Vector3(void) : x(0), y(0), z(0) {}
Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
Vector3::Vector3(const Vector3& src)
{
	*this = src;
}

Vector3::~Vector3(void) {}

float Vector3::Dot(const Vector3& lhs, const Vector3& rhs)
{
	return (float)((double)lhs.x * (double)rhs.x
		+ (double)lhs.y * (double)rhs.y
		+ (double)lhs.z * (double)rhs.z);
}

Vector3 Vector3::Cross(const Vector3& lhs, const Vector3& rhs)
{
	return Vector3(
		(float)((double)lhs.y * (double)rhs.z - (double)lhs.z * (double)rhs.y)
		, (float)((double)lhs.z * (double)rhs.x - (double)lhs.x * (double)rhs.z)
		, (float)((double)lhs.x * (double)rhs.y - (double)lhs.y * (double)rhs.x));
}

float Vector3::Angle2D(const Vector3& lhs, const Vector3& rhs)
{
	float dot = Dot(lhs, rhs);
	float magnitude1 = lhs.Magnitude();
	float magnitude2 = rhs.Magnitude();

	if (magnitude1 == 0 || magnitude2 == 0) {
		return 0;
	}

	// 내적을 벡터 길이의 곱으로 나누어 내적의 코사인을 계산합니다.
	float cosine = dot / (magnitude1 * magnitude2);

	// 아크 코사인을 사용하여 라디안 각도를 계산하고, 이를 도 단위로 변환하여 반환합니다.
	return std::acos(cosine) *(180.0f / PI);
}

Vector3 Vector3::Nomalization()
{
	float len = Magnitude();
	float X, Y, Z;
	if (len != 0)
	{
		X = x / len;
		Y = y / len;
		Z = z / len;
		return Vector3(X, Y, Z);
	}
	return Vector3();
}

float Vector3::Magnitude() const
{
	return sqrt(x * x + y * y + z * z);
}

Vector3& Vector3::operator=(const Vector3& rhs)
{
	if (this != &rhs)
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
	}
	return *this;
}

Vector3 Vector3::operator+=(const Vector3& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}
Vector3 Vector3::operator-=(const Vector3& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}
Vector3 Vector3::operator*=(const Vector3& rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	return *this;
}
Vector3 Vector3::operator/=(const Vector3& rhs)
{
	assert(!(rhs.x == 0 || rhs.y == 0 || rhs.z == 0));
	x /= rhs.x;
	y /= rhs.y;
	z /= rhs.z;
	return *this;
}
Vector3 Vector3::operator*=(const int rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}
Vector3 Vector3::operator/=(const int rhs)
{
	assert(rhs != 0);
	x /= rhs;
	y /= rhs;
	z /= rhs;
	return *this;
}
Vector3 Vector3::operator*=(const float rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}
Vector3 Vector3::operator/=(const float rhs)
{
	assert(rhs != 0);
	x /= rhs;
	y /= rhs;
	z /= rhs;
	return *this;
}


Vector3 Vector3::operator+(const Vector3& rhs) const
{
	return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
}
Vector3 Vector3::operator-(const Vector3& rhs) const
{
	return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
}
Vector3 Vector3::operator*(const Vector3& rhs) const
{
	return Vector3(x * rhs.x, y * rhs.y, z * rhs.z);
}
Vector3 Vector3::operator/(const Vector3& rhs) const
{
	assert(!(rhs.x == 0 || rhs.y == 0 || rhs.z == 0));
	return Vector3(x / rhs.x, y / rhs.y, z / rhs.z);
}
Vector3 Vector3::operator*(const int rhs) const
{
	return Vector3(x * rhs, y * rhs, z * rhs);
}
Vector3 Vector3::operator/(const int rhs) const
{
	assert(rhs != 0);
	return Vector3(x * rhs, y * rhs, z * rhs);
}
Vector3 Vector3::operator*(const float rhs) const
{
	return Vector3(x * rhs, y * rhs, z * rhs);
}
Vector3 Vector3::operator/(const float rhs) const
{
	assert(rhs != 0);
	return  Vector3(x * rhs, y * rhs, z * rhs);
}
bool Vector3::operator==(const Vector3& rhs) const
{
	if (x == rhs.x && y == rhs.y && z == rhs.z)
		return true;
	return false;
}
bool Vector3::operator!=(const Vector3& rhs) const
{
	if (x == rhs.x && y == rhs.y && z == rhs.z)
		return false;
	return true;
}