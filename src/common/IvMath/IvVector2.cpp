//===============================================================================
// @ IvVector2.cpp
// 
// 3D vector class
// ------------------------------------------------------------------------------
// Copyright (C) 2008-2015 by James M. Van Verth and Lars M. Bishop.
// All rights reserved.
//
//===============================================================================

//-------------------------------------------------------------------------------
//-- Dependencies ---------------------------------------------------------------
//-------------------------------------------------------------------------------

#include "IvVector2.h"
#include "IvMath.h"

//-------------------------------------------------------------------------------
//-- Static Members -------------------------------------------------------------
//-------------------------------------------------------------------------------

IvVector2 IvVector2::xAxis( 1.0f, 0.0f );
IvVector2 IvVector2::yAxis( 0.0f, 1.0f );
IvVector2 IvVector2::origin( 0.0f, 0.0f );
IvVector2 IvVector2::xy( 1.0f, 1.0f );

//-------------------------------------------------------------------------------
//-- Methods --------------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
// @ operator<<()
//-------------------------------------------------------------------------------
// Text output for debugging
//-------------------------------------------------------------------------------
IvWriter& 
operator<<(IvWriter& out, const IvVector2& source)
{
    out << '<' << source.x << ',' << source.y << ',' << '>';

    return out;
    
}   // End of operator<<()
    

//-------------------------------------------------------------------------------
// @ IvVector2::Length()
//-------------------------------------------------------------------------------
// Vector length
//-------------------------------------------------------------------------------
float 
IvVector2::Length() const
{
    return IvSqrt( x*x + y*y );

}   // End of IvVector2::Length()


//-------------------------------------------------------------------------------
// @ IvVector2::LengthSquared()
//-------------------------------------------------------------------------------
// Vector length squared (avoids square root)
//-------------------------------------------------------------------------------
float 
IvVector2::LengthSquared() const
{
    return (x*x + y*y);

}   // End of IvVector2::LengthSquared()


//-------------------------------------------------------------------------------
// @ IvVector2::operator==()
//-------------------------------------------------------------------------------
// Comparison operator
//-------------------------------------------------------------------------------
bool 
IvVector2::operator==( const IvVector2& other ) const
{
    if ( IvAreEqual( other.x, x )
        && IvAreEqual( other.y, y ) )
        return true;

    return false;   
}   // End of IvVector2::operator==()


//-------------------------------------------------------------------------------
// @ IvVector2::operator!=()
//-------------------------------------------------------------------------------
// Comparison operator
//-------------------------------------------------------------------------------
bool 
IvVector2::operator!=( const IvVector2& other ) const
{
    if ( IvAreEqual( other.x, x )
        && IvAreEqual( other.y, y ) )
        return false;

    return true;
}   // End of IvVector2::operator!=()


//-------------------------------------------------------------------------------
// @ IvVector2::IsZero()
//-------------------------------------------------------------------------------
// Check for zero vector
//-------------------------------------------------------------------------------
bool 
IvVector2::IsZero() const
{
    return IvIsZero(x*x + y*y);

}   // End of IvVector2::IsZero()


//-------------------------------------------------------------------------------
// @ IvVector2::Clean()
//-------------------------------------------------------------------------------
// Set elements close to zero equal to zero
//-------------------------------------------------------------------------------
void
IvVector2::Clean()
{
    if ( IvIsZero( x ) )
        x = 0.0f;
    if ( IvIsZero( y ) )
        y = 0.0f;

}   // End of IvVector2::Clean()


//-------------------------------------------------------------------------------
// @ IvVector2::Normalize()
//-------------------------------------------------------------------------------
// Set to unit vector
//-------------------------------------------------------------------------------
void
IvVector2::Normalize()
{
    float lengthsq = x*x + y*y;

    if ( IvIsZero( lengthsq ) )
    {
        Zero();
    }
    else
    {
        float factor = IvRecipSqrt( lengthsq );
        x *= factor;
        y *= factor;
    }

}   // End of IvVector2::Normalize()


//-------------------------------------------------------------------------------
// @ IvVector2::operator+()
//-------------------------------------------------------------------------------
// Add vector to self and return
//-------------------------------------------------------------------------------
IvVector2 
IvVector2::operator+( const IvVector2& other ) const
{
    return IvVector2( x + other.x, y + other.y );

}   // End of IvVector2::operator+()


//-------------------------------------------------------------------------------
// @ IvVector2::operator+=()
//-------------------------------------------------------------------------------
// Add vector to self, store in self
//-------------------------------------------------------------------------------
IvVector2& 
operator+=( IvVector2& self, const IvVector2& other )
{
    self.x += other.x;
    self.y += other.y;

    return self;

}   // End of IvVector2::operator+=()


//-------------------------------------------------------------------------------
// @ IvVector2::operator-()
//-------------------------------------------------------------------------------
// Subtract vector from self and return
//-------------------------------------------------------------------------------
IvVector2 
IvVector2::operator-( const IvVector2& other ) const
{
    return IvVector2( x - other.x, y - other.y );

}   // End of IvVector2::operator-()


//-------------------------------------------------------------------------------
// @ IvVector2::operator-=()
//-------------------------------------------------------------------------------
// Subtract vector from self, store in self
//-------------------------------------------------------------------------------
IvVector2& 
operator-=( IvVector2& self, const IvVector2& other )
{
    self.x -= other.x;
    self.y -= other.y;

    return self;

}   // End of IvVector2::operator-=()

//-------------------------------------------------------------------------------
// @ IvVector2::operator-() (unary)
//-------------------------------------------------------------------------------
// Negate self and return
//-------------------------------------------------------------------------------
IvVector2
IvVector2::operator-() const
{
    return IvVector2(-x, -y);
}    // End of IvVector2::operator-()


//-------------------------------------------------------------------------------
// @ operator*()
//-------------------------------------------------------------------------------
// Scalar multiplication
//-------------------------------------------------------------------------------
IvVector2   
IvVector2::operator*( float scalar )
{
    return IvVector2( scalar*x, scalar*y );

}   // End of operator*()


//-------------------------------------------------------------------------------
// @ operator*()
//-------------------------------------------------------------------------------
// Scalar multiplication
//-------------------------------------------------------------------------------
IvVector2   
operator*( float scalar, const IvVector2& vector )
{
    return IvVector2( scalar*vector.x, scalar*vector.y );

}   // End of operator*()


//-------------------------------------------------------------------------------
// @ IvVector2::operator*()
//-------------------------------------------------------------------------------
// Scalar multiplication by self
//-------------------------------------------------------------------------------
IvVector2&
IvVector2::operator*=( float scalar )
{
    x *= scalar;
    y *= scalar;

    return *this;

}   // End of IvVector2::operator*=()


//-------------------------------------------------------------------------------
// @ operator/()
//-------------------------------------------------------------------------------
// Scalar division
//-------------------------------------------------------------------------------
IvVector2   
IvVector2::operator/( float scalar )
{
    return IvVector2( x/scalar, y/scalar );

}   // End of operator/()


//-------------------------------------------------------------------------------
// @ IvVector2::operator/=()
//-------------------------------------------------------------------------------
// Scalar division by self
//-------------------------------------------------------------------------------
IvVector2&
IvVector2::operator/=( float scalar )
{
    x /= scalar;
    y /= scalar;

    return *this;

}   // End of IvVector2::operator/=()


//-------------------------------------------------------------------------------
// @ IvVector2::Dot()
//-------------------------------------------------------------------------------
// Dot product by self
//-------------------------------------------------------------------------------
float               
IvVector2::Dot( const IvVector2& vector ) const
{
    return (x*vector.x + y*vector.y);

}   // End of IvVector2::Dot()


//-------------------------------------------------------------------------------
// @ Dot()
//-------------------------------------------------------------------------------
// Dot product friend operator
//-------------------------------------------------------------------------------
float               
Dot( const IvVector2& vector1, const IvVector2& vector2 )
{
    return (vector1.x*vector2.x + vector1.y*vector2.y);

}   // End of Dot()


//-------------------------------------------------------------------------------
// @ IvVector2::PerpDot()
//-------------------------------------------------------------------------------
// Perpendicular dot product by self
//-------------------------------------------------------------------------------
float               
IvVector2::PerpDot( const IvVector2& vector ) const
{
    return (x*vector.y - y*vector.x);

}   // End of IvVector2::Dot()


//-------------------------------------------------------------------------------
// @ Dot()
//-------------------------------------------------------------------------------
// Dot product friend operator
//-------------------------------------------------------------------------------
float               
PerpDot( const IvVector2& vector1, const IvVector2& vector2 )
{
    return (vector1.x*vector2.y - vector1.y*vector2.x);

}   // End of Dot()

