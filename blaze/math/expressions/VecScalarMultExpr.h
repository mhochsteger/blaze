//=================================================================================================
/*!
//  \file blaze/math/expressions/VecScalarMultExpr.h
//  \brief Header file for the VecScalarMultExpr base class
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

#ifndef _BLAZE_MATH_EXPRESSIONS_VECSCALARMULTEXPR_H_
#define _BLAZE_MATH_EXPRESSIONS_VECSCALARMULTEXPR_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <blaze/math/expressions/MultExpr.h>


namespace blaze {

//=================================================================================================
//
//  CLASS DEFINITION
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Base class for all vector/scalar multiplication expression templates.
// \ingroup math
//
// The VecScalarMultExpr class serves as a tag for all expression templates that implement a
// vector/scalar multiplication. All classes, that represent a vector/scalar multiplication
// and that are used within the expression template environment of the Blaze library have
// to derive publicly from this class in order to qualify as vector/scalar multiplication
// expression template. Only in case a class is derived publicly from the VecScalarMultExpr
// base class, the IsVecScalarMultExpr type trait recognizes the class as valid vector/scalar
// multiplication expression template.
*/
template< typename VT >  // Vector base type of the expression
struct VecScalarMultExpr
   : public MultExpr<VT>
{};
//*************************************************************************************************




//=================================================================================================
//
//  GLOBAL RESTRUCTURING FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Calculation of the transpose of the given vector-scalar multiplication.
// \ingroup math
//
// \param vector The vector-scalar multiplication expression to be transposed.
// \return The transpose of the expression.
//
// This operator implements the performance optimized treatment of the transpose of a
// vector-scalar multiplication. It restructures the expression \f$ a=trans(b*s1) \f$ to
// the expression \f$ a=trans(b)*s1 \f$.
*/
template< typename VT >  // Vector base type of the expression
inline decltype(auto) trans( const VecScalarMultExpr<VT>& vector )
{
   BLAZE_FUNCTION_TRACE;

   return trans( (~vector).leftOperand() ) * (~vector).rightOperand();
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Calculation of the complex conjugate of the given vector-scalar multiplication.
// \ingroup math
//
// \param vector The vector-scalar multiplication expression to be conjugated.
// \return The complex conjugate of the expression.
//
// This operator implements the performance optimized treatment of the complex conjugate of a
// vector-scalar multiplication. It restructures the expression \f$ a=conj(b*s1) \f$ to the
// expression \f$ a=conj(b)*s1 \f$.
*/
template< typename VT >  // Vector base type of the expression
inline decltype(auto) conj( const VecScalarMultExpr<VT>& vector )
{
   BLAZE_FUNCTION_TRACE;

   return conj( (~vector).leftOperand() ) * (~vector).rightOperand();
}
/*! \endcond */
//*************************************************************************************************

} // namespace blaze

#endif
