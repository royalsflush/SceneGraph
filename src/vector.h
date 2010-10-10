// vector.h
// Visualização 3D
// W. Celes - celes@inf.puc-rio.br
// PUC-Rio, Jan 2008

#ifndef V_VECTOR_H
#define V_VECTOR_H

#include <stdio.h>
#include <math.h>

struct VVector
{
  float x, y, z;
  
  VVector ()
  {
  }
  
  VVector (float vx, float vy, float vz)
  : x(vx), y(vy), z(vz)
  {
  }
  void Set (float vx, float vy, float vz)
  {
    x = vx; y = vy; z = vz;
  }
  
  float SqrLength () const
  {
    return (x*x+y*y+z*z);
  }
  
  float Length () const
  {
    return (float)sqrt(x*x+y*y+z*z);
  }

  float Normalize ()
  {
    float l = Length();
    if (l != 0.0f)
    {
      float d = 1.0f/l;
      x *= d; y *= d; z *= d;
    }
    return l;
  }
  
  VVector& operator+= (const VVector& other)
  {
    x += other.x; y += other.y; z += other.z;
    return *this;
  }

  VVector& operator+= (float scalar)
  {
    x += scalar; y += scalar; z += scalar;
    return *this;
  }

  VVector& operator-= (const VVector& other)
  {
    x -= other.x; y -= other.y; z -= other.z;
    return *this;
  }

  VVector& operator-= (float scalar)
  {
    x -= scalar; y -= scalar; z -= scalar;
    return *this;
  }

  VVector operator- ()
  {
    VVector v(-x,-y,-z);
    return v;
  }

  VVector& operator*= (const VVector& other)
  {
    x *= other.x; y *= other.y; z *= other.z;
    return *this;
  }

  VVector& operator*= (float scalar)
  {
    x *= scalar; y *= scalar; z *= scalar;
    return *this;
  }

  VVector& operator/= (float scalar)
  {
    x /= scalar; y /= scalar; z /= scalar;
    return *this;
  }
  
  friend float Dot (const VVector& a, const VVector& b)
  {
    return a.x*b.x + a.y*b.y + a.z*b.z;
  }
  
  friend VVector Cross (const VVector& a, const VVector& b)
  {
    return VVector(a.y*b.z-b.y*a.z,b.x*a.z-a.x*b.z,a.x*b.y-b.x*a.y);
  }

  void Print (const char* label=0) const
  {
    printf("%s: %g  %g  %g\n", label ? label : "", x, y, z);
  }
  
};

#endif
