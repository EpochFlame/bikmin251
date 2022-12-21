#ifndef _VECTOR3_H
#define _VECTOR3_H

#include "JSystem/JGeometry.h"
#include "stream.h"
#include "Dolphin/math.h"
#include "sysMath.h"
#include "Vector2.h"
#include "sqrt.h"

template <typename T>
struct Vector3 {
	T x, y, z;
	inline Vector3() {};
	/**
	 * @fabricated
	 */
	inline Vector3(T value)
	    : x(value)
	    , y(value)
	    , z(value)
	{
	}
	inline Vector3(T x, T y, T z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	inline Vector3(JGeometry::TVec3<T> vec) { __memcpy(this, &vec, sizeof(Vector3)); }

	inline Vector3(Vec& vec)
	{
		x = vec.x;
		y = vec.y;
		z = vec.z;
	}

	inline Vector3& operator=(const Vector3& other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}

	inline void operator=(Vector3<T>& other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
	}

	// /**
	//  * @fabricated
	//  */
	// inline Vector3<T> operator-(const Vector3<T>& other) const {
	// 	return Vector3<T>(x - other.x, y - other.y, z - other.z);
	// }

	/**
	 * @fabricated
	 */
	inline Vector3<T> operator*(const Vector3<T>& other) const { return Vector3<T>(x * other.x, y * other.y, z * other.z); }

	/**
	 * @fabricated
	 */
	inline float magnitude() { return x + y + z; }

	/**
	 * @fabricated
	 */
	// inline JGeometry::TVec3<T> toTVec() const
	// {
	// 	JGeometry::TVec3<T> vec;
	// 	vec.x = x;
	// 	vec.y = y;
	// 	vec.z = z;
	// 	return vec;
	// }

	/**
	 * @fabricated
	 */
	inline void setTVec(JGeometry::TVec3<T>& vec)
	{
		vec.x = x;
		vec.y = y;
		vec.z = z;
	}

	inline void negate()
	{
		x *= -1.0f;
		y *= -1.0f;
		z *= -1.0f;
	}

	// 	inline Vector3& operator+(const Vector3 other) {
	//     Vector3 newVector = *this;
	//     x += other.x;
	//     y += other.y;
	//     z += other.z;
	//     return newVector;
	// }
	// inline Vector3& operator*(const float other) {
	//     Vector3 newVector = *this;
	//     newVector.x *= other;
	//     newVector.y *= other;
	//     newVector.z *= other;
	//     return newVector;
	// }
	inline void operator*=(const float other) { *this = Vector3(x * other, y * other, z * other); }
	inline void operator+=(const Vector3& other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
	}
	inline void operator-=(const Vector3& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
	}

	float length() const;
	float distance(Vector3&);
	float normalise();

	void read(Stream&);
	void write(Stream&);

	static Vector3<T> zero;
};

// template <> struct Vector3<float> {
// 	static Vector3<float> zero;
// };

// Use instead of Vector3<float> or Vector3<f32>
typedef Vector3<float> Vector3f;
typedef Vector3<int> Vector3i;

/**
 * @reifiedAddress{80207BA0}
 * @reifiedFile{plugProjectKandoU/itemUjamushi.cpp}
 */
inline Vector3f operator+(const Vector3f& a, const Vector3f& b) { return Vector3f(a.x + b.x, a.y + b.y, a.z + b.z); }

/**
 * @reifiedAddress{80207E70}
 * @reifiedFile{plugProjectKandoU/itemUjamushi.cpp}
 */
inline Vector3f operator-(const Vector3f& a, const Vector3f& b) { return Vector3f(a.x - b.x, a.y - b.y, a.z - b.z); }

inline Vector3f operator*(const Vector3f& a, const float b) { return Vector3f(a.x * b, a.y * b, a.z * b); }

inline Vector3f operator*=(const Vector3f& a, const float b) { return Vector3f(a.x * b, a.y * b, a.z * b); }

inline float dot(const Vector3f& a, const Vector3f& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

inline void weightVecXZ(Vector3f& vec, f32 weight)
{
	Vector3f temp = vec;
	temp.x *= weight;
	temp.z *= weight;
	vec = temp;
}

template <>
inline f32 Vector3f::length() const
{
	Vector3f vec(x, y, z);
	f32 x2 = x * x;
	f32 y2 = y * y;
	f32 z2 = z * z;

	if (x2 + y2 + z2 > 0.0f) {
		f32 sqrLen = vec.x * vec.x + y * y + z * z;
		return sqrtf(sqrLen);
	} else {
		return 0.0f;
	}
}

template <>
inline f32 Vector3f::normalise()
{
	f32 len = length();

	if (len > 0.0f) {
		f32 norm = 1.0f / len;
		x *= norm;
		y *= norm;
		z *= norm;
		return len;
	}
	return 0.0f;
}

inline f32 _lenVec(Vector3f& vec)
{
	Vector2f sqr(vec.z * vec.z, vec.x * vec.x + vec.y * vec.y);
	return _sqrtf(sqr.x + sqr.y);
}

inline f32 stickMagnitude(Vector3f& vec)
{
	Vector3f a = vec;
	a.z *= a.z;
	return _sqrtf(a.x * a.x + a.y * a.y + a.z);
}

inline f32 _length(Vector3f& vec)
{
	Vector3f a = vec;
	a.y *= a.y;
	a.z *= a.z;
	return _sqrtf(a.y + a.x * a.x + a.z);
}

inline f32 _length2(Vector3f& vec)
{
	Vector3f a = vec;
	a.x *= a.x;
	a.y *= a.y;
	return _sqrtf(a.x + a.z * a.z + a.y);
}

inline f32 _distanceBetween(Vector3f& me, Vector3f& them)
{
	Vector3f sep = me - them;
	return _length(sep);
}

inline f32 _distanceBetween2(Vector3f& me, Vector3f& them)
{
	Vector3f sep = Vector3f(me.y - them.y, me.z - them.z, me.x - them.x);
	return _length2(sep);
}

inline f32 _distanceBetweenCheck(Vector3f& me, Vector3f& them)
{
	Vector3f sep = me - them;
	f32 length   = _length(sep);
	if (length > 0.0f) {
		return length;
	} else {
		return 0.0f;
	}
}

inline f32 _distanceBetweenCheckDouble(Vector3f& me, Vector3f& them)
{
	Vector3f sep  = me - them;
	Vector3f sep2 = them - me;
	f32 length2   = _length(sep2);
	f32 length    = _length(sep);
	if (length > 0.0f) {
		return length;
	} else {
		return 0.0f;
	}
}

inline void _normalise(Vector3f& vec)
{
	Vector2f sqr(vec.z * vec.z, vec.x * vec.x + vec.y * vec.y);
	f32 length = sqr.x + sqr.y;
	__sqrtf(length, &length);

	if (length > 0.0f) {
		f32 norm = 1.0f / length;
		vec.x *= norm;
		vec.y *= norm;
		vec.z *= norm;
	}
}

inline void _normaliseXZ(Vector3f& vec)
{
	Vector2f sqr(vec.z * vec.z, vec.x * vec.x + vec.y * vec.y);
	f32 length = sqr.x + sqr.y;
	__sqrtf(length, &length);

	if (length > 0.0f) {
		f32 norm = 1.0f / length;
		vec.x *= norm;
		vec.z *= norm;
	}
}

inline f32 _normaliseVec(Vector3f& vec)
{
	Vector2f sqr(vec.z * vec.z, vec.x * vec.x + vec.y * vec.y);
	f32 length = sqr.x + sqr.y;
	__sqrtf(length, &length);

	if (length > 0.0f) {
		f32 norm = 1.0f / length;
		vec      = vec * norm;
		return length;
	}
	return 0.0f;
}

inline f32 sqrDistanceXZ(Vector3f& vec1, Vector3f& vec2)
{
	f32 x = vec1.x - vec2.x;
	f32 z = vec1.z - vec2.z;
	return x * x + z * z;
}

inline f32 _distanceXZ(Vector3f& vec1, Vector3f& vec2)
{
	Vector2f vec;
	vec.x = vec1.x - vec2.x;
	vec.y = vec1.z - vec2.z;
	return _sqrtf(vec.x * vec.x + vec.y * vec.y);
}

inline void sumXY(Vector3f vec, float* sum) { *sum = (vec.x *= vec.x) + (vec.y *= vec.y); }

inline void sumZ(Vector3f vec, float* sum)
{
	f32 z = vec.z * vec.z;
	*sum  = z + *sum;
}

template <>
inline f32 Vector3f::distance(Vector3f& them)
{
	Vector3f diff = *this - them;

	f32 sum;
	sumXY(diff, &sum);
	sumZ(diff, &sum);

	return _sqrtf(sum);
}

inline void setAccel(Vector3f& outputVec, const Vector3f& inputVec, f32 massRatio, f32 fps, f32 groundFactor, f32 airFactor)
{
	outputVec.x = inputVec.x * (groundFactor * fps * massRatio);
	outputVec.z = inputVec.z * (groundFactor * fps * massRatio);
	outputVec.y = inputVec.y * (airFactor * fps * massRatio);
}

inline void setOpAccel(Vector3f& outputVec, const Vector3f& inputVec, f32 massRatio, f32 fps, f32 groundFactor, f32 airFactor)
{
	outputVec.x = -inputVec.x * (groundFactor * fps * massRatio);
	outputVec.z = -inputVec.z * (groundFactor * fps * massRatio);
	outputVec.y = -inputVec.y * (airFactor * fps * massRatio);
}

inline void addAccel(Vector3f& outputVec, const Vector3f& inputVec, f32 massRatio, f32 fps, f32 groundFactor, f32 airFactor)
{
	outputVec.x += inputVec.x * (groundFactor * fps * massRatio);
	outputVec.z += inputVec.z * (groundFactor * fps * massRatio);
	outputVec.y += inputVec.y * (airFactor * fps * massRatio);
}
#endif
