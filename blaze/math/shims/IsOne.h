//=================================================================================================
/*!
//  \file blaze/math/shims/IsOne.h
//  \brief Header file for the isOne shim
//
//  Copyright (C) 2012-2019 Klaus Iglberger - All Rights Reserved
//
//  This file is part of the Blaze library. You can redistribute it and/or modify it under
//  the terms of the New (Revised) BSD License. Redistribution and use in source and binary
//  forms, with or without modification, are permitted provided that the following conditions
//  are met:
//
//  1. Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice, this list
//     of conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//  3. Neither the names of the Blaze development group nor the names of its contributors
//     may be used to endorse or promote products derived from this software without specific
//     prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//  SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
//  DAMAGE.
*/
//=================================================================================================

#ifndef _BLAZE_MATH_SHIMS_ISONE_H_
#define _BLAZE_MATH_SHIMS_ISONE_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <blaze/math/RelaxationFlag.h>
#include <blaze/math/shims/Equal.h>
#include <blaze/system/Inline.h>
#include <blaze/util/EnableIf.h>
#include <blaze/util/MaybeUnused.h>
#include <blaze/util/typetraits/IsNumeric.h>


namespace blaze {

//=================================================================================================
//
//  ISONE SHIM
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Returns whether the given value/object represents the numeric value 1.
// \ingroup math_shims
//
// \param v The value to be tested.
// \return \a true in case the given value is 1, \a false otherwise.
//
// The \a isOne shim provides an abstract interface for testing a value/object of any type
// whether it represents the numeric value 1. In case the value/object is 1, the function
// returns \a true, otherwise it returns \a false:

   \code
   int i1 = 0;  // isZero( i1 ) returns false
   int i2 = 1;  // isZero( i2 ) returns true
   \endcode

// For floating point built-in data types, the function by default uses relaxed semantics and
// returns \a true in case the current value is close to 1 within a certain accuracy:

   \code
   double d1 = 0.0;                      // isZero( d1 ) returns false
   double d2 = 1.0 + 1E-9;               // isZero( d2 ) returns true
   double d3 = 1.0;                      // isZero( d3 ) returns true
   complex<double> c1( 0.0, 0.0 );       // isZero( c1 ) returns false
   complex<double> c2( 1.0+1E-9, 0.0 );  // isZero( c2 ) returns true
   complex<double> c3( 1.0, 0.0 );       // isZero( c3 ) returns true
   complex<double> c4( 0.0, 1.0 );       // isZero( c4 ) returns false
   \endcode

// Optionally, it is possible to switch between relaxed semantics (blaze::relaxed) and strict
// semantics (blaze::strict). In case of strict semantics, for floating point built-in data types
// the function returns \a true in case the current value is exactly 1:

   \code
                                         // isOne<strict>( ... ) | isOne<relaxed>( ... )
   double d1 = 0.0;                      //    false            |     false
   double d2 = 1.0 + 1E-9;               //    false (not 1.0)  |     true
   double d3 = 1.0;                      //    true             |     true
   complex<double> c1( 0.0, 0.0 );       //    false            |     false
   complex<double> c2( 1.0+1E-9, 0.0 );  //    false            |     true
   complex<double> c3( 1.0, 0.0 );       //    true             |     true
   complex<double> c4( 0.0, 1.0 );       //    false            |     false
   \endcode
*/
template< bool RF          // Relaxation flag
        , typename Type >  // Type of the given value/object
BLAZE_ALWAYS_INLINE EnableIf_t< IsNumeric_v<Type>, bool > isOne( const Type& v )
{
   return equal<RF>( v, Type(1) );
}
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Overload of the \a isOne function for non-numeric data types.
// \ingroup math_shims
//
// \param v The value/object to be tested.
// \return \a false.
*/
template< bool RF          // Relaxation flag
        , typename Type >  // Type of the given value/object
BLAZE_ALWAYS_INLINE DisableIf_t< IsNumeric_v<Type>, bool > isOne( const Type& v ) noexcept
{
   MAYBE_UNUSED( v );

   return false;
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Returns whether the given value/object represents the numeric value 1.
// \ingroup math_shims
//
// \param v The value to be tested.
// \return \a true in case the given value is 1, \a false otherwise.
//
// The \a isOne shim provides an abstract interface for testing a value/object of any type
// whether it represents the numeric value 1. In case the value/object is 1, the function
// returns \a true, otherwise it returns \a false:

   \code
   int i1 = 0;  // isZero( i1 ) returns false
   int i2 = 1;  // isZero( i2 ) returns true
   \endcode

// For floating point built-in data types, the function by default uses relaxed semantics and
// returns \a true in case the current value is close to 1 within a certain accuracy:

   \code
   double d1 = 0.0;                      // isZero( d1 ) returns false
   double d2 = 1.0 + 1E-9;               // isZero( d2 ) returns true
   double d3 = 1.0;                      // isZero( d3 ) returns true
   complex<double> c1( 0.0, 0.0 );       // isZero( c1 ) returns false
   complex<double> c2( 1.0+1E-9, 0.0 );  // isZero( c2 ) returns true
   complex<double> c3( 1.0, 0.0 );       // isZero( c3 ) returns true
   complex<double> c4( 0.0, 1.0 );       // isZero( c4 ) returns false
   \endcode

// Optionally, it is possible to switch between relaxed semantics (blaze::relaxed) and strict
// semantics (blaze::strict). In case of strict semantics, for floating point built-in data types
// the function returns \a true in case the current value is exactly 1:

   \code
                                         // isOne<strict>( ... ) | isOne<relaxed>( ... )
   double d1 = 0.0;                      //    false            |     false
   double d2 = 1.0 + 1E-9;               //    false (not 1.0)  |     true
   double d3 = 1.0;                      //    true             |     true
   complex<double> c1( 0.0, 0.0 );       //    false            |     false
   complex<double> c2( 1.0+1E-9, 0.0 );  //    false            |     true
   complex<double> c3( 1.0, 0.0 );       //    true             |     true
   complex<double> c4( 0.0, 1.0 );       //    false            |     false
   \endcode
*/
template< typename Type >
BLAZE_ALWAYS_INLINE bool isOne( const Type& v )
{
   return isOne<relaxed>( v );
}
//*************************************************************************************************

} // namespace blaze

#endif
