//=================================================================================================
/*!
//  \file blaze/math/expressions/VecSerialExpr.h
//  \brief Header file for the VecSerialExpr base class
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

#ifndef _BLAZE_MATH_EXPRESSIONS_VECSERIALEXPR_H_
#define _BLAZE_MATH_EXPRESSIONS_VECSERIALEXPR_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <blaze/math/expressions/SerialExpr.h>


namespace blaze {

//=================================================================================================
//
//  CLASS DEFINITION
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Base class for all vector serial evaluation expression templates.
// \ingroup math
//
// The VecSerialExpr class serves as a tag for all expression templates that enforce a serial
// evaluation of a vector. All classes, that represent a vector serialization operation and
// that are used within the expression template environment of the Blaze library have to
// derive publicly from this class in order to qualify as vector serial evaluation expression
// template. Only in case a class is derived publicly from the VecSerialExpr base class, the
// IsVecSerialExpr type trait recognizes the class as valid vector serial evaluation expression
// template.
*/
template< typename VT >  // Vector base type of the expression
struct VecSerialExpr
   : public SerialExpr<VT>
{};
//*************************************************************************************************




//=================================================================================================
//
//  GLOBAL RESTRUCTURING FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Evaluation of the given vector serial evaluation expression.
// \ingroup math
//
// \param vector The input serial evaluation expression.
// \return The evaluated vector.
//
// This function implements a performance optimized treatment of the serial evaluation of a
// vector serial evaluation expression.
*/
template< typename VT >  // Vector base type of the expression
inline decltype(auto) serial( const VecSerialExpr<VT>& vector )
{
   BLAZE_FUNCTION_TRACE;

   return ~vector;
}
/*! \endcond */
//*************************************************************************************************

} // namespace blaze

#endif
