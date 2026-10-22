/// compiler directive
#ifndef VECTOR3_4620    /// ifndef: if not defined
#define VECTOR3_4620

#include<iostream>
#include<cmath>

/// class representing 3D vector with x, y, z coordinates
struct Vector3
{
  float x,y,z;

  /// add another vector to current vector
  Vector3 &operator+=(const Vector3 &rhs)
  {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;  
  }

  /// subtract another vector from current vector
  Vector3 &operator-=(const Vector3 &rhs)
  {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;  
  }

  /// multiply each element of vector by scalar
  Vector3 &operator*=(const float rhs)
  {
    x *= rhs;
    y *= rhs;
    z *= rhs;
    return *this;  
  }

  /// calculate dot product of two vectors
  float dot(const Vector3 &rhs)
  {
    return x * rhs.x + y * rhs.y + z * rhs.z;
  }

  /// calculate cross product, returning perpendicular vector
  Vector3 cross(const Vector3 &rhs)
  {
    return Vector3{
      y * rhs.z - z * rhs.y,
      z * rhs.x - x * rhs.z,
      x * rhs.y - y * rhs.x };
  }

  /// calculate magnitude/length of vector
  float length()
  {
    return sqrt( x * x + y * y + z * z );
  }

  /// return unit vector pointing in same direction
  Vector3 normalize()
  {
    float l = length();
    if(l == 0) return Vector3{0,0,0};
    return Vector3{x/l, y/l, z/l};
  }

}; /// end Vector3 class

/// overload + operator to add two vectors
inline Vector3 operator+( Vector3 lhs, const Vector3 &rhs){
  return lhs += rhs;
}
/// overload - operator to subtract two vectors
inline Vector3 operator-( Vector3 lhs, const Vector3 &rhs){
  return lhs -= rhs;
}
/// overload * operator to multiply vector by scalar
inline Vector3 operator*( Vector3 lhs, const float rhs){
  return lhs *= rhs;
}

/// Uncomment these lines if add a Vector3 and want to debug :)
inline std::ostream &operator<<(std::ostream &os, const Vector3 &v) 
{
    return os << '(' << v.x << ", " << v.y << ", " << v.z << ')';
}

#endif
