//=================================================================================================
/*!
//  \file blaze/math/lapack/clapack/sytrs.h
//  \brief Header file for the CLAPACK sytrs wrapper functions
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

#ifndef _BLAZE_MATH_LAPACK_CLAPACK_SYTRS_H_
#define _BLAZE_MATH_LAPACK_CLAPACK_SYTRS_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <blaze/util/Complex.h>
#include <blaze/util/StaticAssert.h>
#include <blaze/util/Types.h>


//=================================================================================================
//
//  LAPACK FORWARD DECLARATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
#if !defined(INTEL_MKL_VERSION)
extern "C" {

void ssytrs_( char* uplo, int* n, int* nrhs, float* A, int* lda, int* ipiv,
              float* B, int* ldb, int* info, blaze::fortran_charlen_t nuplo );
void dsytrs_( char* uplo, int* n, int* nrhs, double* A, int* lda, int* ipiv,
              double* B, int* ldb, int* info, blaze::fortran_charlen_t nuplo );
void csytrs_( char* uplo, int* n, int* nrhs, float* A, int* lda, int* ipiv,
              float* B, int* ldb, int* info, blaze::fortran_charlen_t nuplo );
void zsytrs_( char* uplo, int* n, int* nrhs, double* A, int* lda, int* ipiv,
              double* B, int* ldb, int* info, blaze::fortran_charlen_t nuplo );

}
#endif
/*! \endcond */
//*************************************************************************************************




namespace blaze {

//=================================================================================================
//
//  LAPACK LDLT-BASED SUBSTITUTION FUNCTIONS (SYTRS)
//
//=================================================================================================

//*************************************************************************************************
/*!\name LAPACK LDLT-based substitution functions (sytrs) */
//@{
void sytrs( char uplo, int n, int nrhs, const float* A, int lda, const int* ipiv,
            float* B, int ldb, int* info );

void sytrs( char uplo, int n, int nrhs, const double* A, int lda, const int* ipiv,
            double* B, int ldb, int* info );

void sytrs( char uplo, int n, int nrhs, const complex<float>* A, int lda, const int* ipiv,
            complex<float>* B, int ldb, int* info );

void sytrs( char uplo, int n, int nrhs, const complex<double>* A, int lda, const int* ipiv,
            complex<double>* B, int ldb, int* info );
//@}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief LAPACK kernel for the substitution step of solving a symmetric indefinite single
//        precision linear system of equations (\f$ A*X=B \f$).
// \ingroup lapack_substitution
//
// \param uplo \c 'L' to use the lower part of the matrix, \c 'U' to use the upper part.
// \param n The number of rows/columns of the column-major matrix \f$[0..\infty)\f$.
// \param nrhs The number of right-hand side vectors \f$[0..\infty)\f$.
// \param A Pointer to the first element of the single precision column-major square matrix.
// \param lda The total number of elements between two columns of matrix \a A \f$[0..\infty)\f$.
// \param ipiv Auxiliary array of size \a n for the pivot indices.
// \param B Pointer to the first element of the single precision column-major matrix.
// \param ldb The total number of elements between two columns of matrix \a B \f$[0..\infty)\f$.
// \param info Return code of the function call.
// \return void
//
// This function uses the LAPACK ssytrs() function to perform the substitution step to compute
// the solution to the symmetric indefinite system of linear equations \f$ A*X=B \f$, where \a A
// is a \a n-by-\a n matrix that has already been factorized by the ssytrf() function and \a X
// and \a B are column-major \a n-by-\a nrhs matrices.
//
// The \a info argument provides feedback on the success of the function call:
//
//   - = 0: The function finished successfully.
//   - < 0: If info = -i, the i-th argument had an illegal value.
//
// For more information on the ssytrs() function, see the LAPACK online documentation browser:
//
//        http://www.netlib.org/lapack/explore-html/
//
// \note This function can only be used if a fitting LAPACK library, which supports this function,
// is available and linked to the executable. Otherwise a call to this function will result in a
// linker error.
*/
inline void sytrs( char uplo, int n, int nrhs, const float* A, int lda, const int* ipiv,
                   float* B, int ldb, int* info )
{
#if defined(INTEL_MKL_VERSION)
   BLAZE_STATIC_ASSERT( sizeof( MKL_INT ) == sizeof( int ) );
#endif

   ssytrs_( &uplo, &n, &nrhs, const_cast<float*>( A ), &lda,
            const_cast<int*>( ipiv ), B, &ldb, info
#if !defined(INTEL_MKL_VERSION)
          , blaze::fortran_charlen_t(1)
#endif
          );
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief LAPACK kernel for the substitution step of solving a symmetric indefinite double
//        precision linear system of equations (\f$ A*X=B \f$).
// \ingroup lapack_substitution
//
// \param uplo \c 'L' to use the lower part of the matrix, \c 'U' to use the upper part.
// \param n The number of rows/columns of the column-major matrix \f$[0..\infty)\f$.
// \param nrhs The number of right-hand side vectors \f$[0..\infty)\f$.
// \param A Pointer to the first element of the double precision column-major square matrix.
// \param lda The total number of elements between two columns of matrix \a A \f$[0..\infty)\f$.
// \param ipiv Auxiliary array of size \a n for the pivot indices.
// \param B Pointer to the first element of the double precision column-major matrix.
// \param ldb The total number of elements between two columns of matrix \a B \f$[0..\infty)\f$.
// \param info Return code of the function call.
// \return void
//
// This function uses the LAPACK dsytrs() function to perform the substitution step to compute
// the solution to the symmetric indefinite system of linear equations \f$ A*X=B \f$, where \a A
// is a \a n-by-\a n matrix that has already been factorized by the dsytrf() function and \a X
// and \a B are column-major \a n-by-\a nrhs matrices.
//
// The \a info argument provides feedback on the success of the function call:
//
//   - = 0: The function finished successfully.
//   - < 0: If info = -i, the i-th argument had an illegal value.
//
// For more information on the dsytrs() function, see the LAPACK online documentation browser:
//
//        http://www.netlib.org/lapack/explore-html/
//
// \note This function can only be used if a fitting LAPACK library, which supports this function,
// is available and linked to the executable. Otherwise a call to this function will result in a
// linker error.
*/
inline void sytrs( char uplo, int n, int nrhs, const double* A, int lda, const int* ipiv,
                   double* B, int ldb, int* info )
{
#if defined(INTEL_MKL_VERSION)
   BLAZE_STATIC_ASSERT( sizeof( MKL_INT ) == sizeof( int ) );
#endif

   dsytrs_( &uplo, &n, &nrhs, const_cast<double*>( A ), &lda,
            const_cast<int*>( ipiv ), B, &ldb, info
#if !defined(INTEL_MKL_VERSION)
          , blaze::fortran_charlen_t(1)
#endif
          );
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief LAPACK kernel for the substitution step of solving a symmetric indefinite single
//        precision complex linear system of equations (\f$ A*X=B \f$).
// \ingroup lapack_substitution
//
// \param uplo \c 'L' to use the lower part of the matrix, \c 'U' to use the upper part.
// \param n The number of rows/columns of the column-major matrix \f$[0..\infty)\f$.
// \param nrhs The number of right-hand side vectors \f$[0..\infty)\f$.
// \param A Pointer to the first element of the single precision complex column-major square matrix.
// \param lda The total number of elements between two columns of matrix \a A \f$[0..\infty)\f$.
// \param ipiv Auxiliary array of size \a n for the pivot indices.
// \param B Pointer to the first element of the single precision complex column-major matrix.
// \param ldb The total number of elements between two columns of matrix \a B \f$[0..\infty)\f$.
// \param info Return code of the function call.
// \return void
//
// This function uses the LAPACK csytrs() function to perform the substitution step to compute
// the solution to the symmetric indefinite system of linear equations \f$ A*X=B \f$, where \a A
// is a \a n-by-\a n matrix that has already been factorized by the csytrf() function and \a X
// and \a B are column-major \a n-by-\a nrhs matrices.
//
// The \a info argument provides feedback on the success of the function call:
//
//   - = 0: The function finished successfully.
//   - < 0: If info = -i, the i-th argument had an illegal value.
//
// For more information on the csytrs() function, see the LAPACK online documentation browser:
//
//        http://www.netlib.org/lapack/explore-html/
//
// \note This function can only be used if a fitting LAPACK library, which supports this function,
// is available and linked to the executable. Otherwise a call to this function will result in a
// linker error.
*/
inline void sytrs( char uplo, int n, int nrhs, const complex<float>* A, int lda,
                   const int* ipiv, complex<float>* B, int ldb, int* info )
{
   BLAZE_STATIC_ASSERT( sizeof( complex<float> ) == 2UL*sizeof( float ) );

#if defined(INTEL_MKL_VERSION)
   BLAZE_STATIC_ASSERT( sizeof( MKL_INT ) == sizeof( int ) );
   using ET = MKL_Complex8;
#else
   using ET = float;
#endif

   csytrs_( &uplo, &n, &nrhs, const_cast<ET*>( reinterpret_cast<const ET*>( A ) ),
            &lda, const_cast<int*>( ipiv ), reinterpret_cast<ET*>( B ), &ldb, info
#if !defined(INTEL_MKL_VERSION)
          , blaze::fortran_charlen_t(1)
#endif
          );
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief LAPACK kernel for the substitution step of solving a symmetric indefinite double
//        precision complex linear system of equations (\f$ A*X=B \f$).
// \ingroup lapack_substitution
//
// \param uplo \c 'L' to use the lower part of the matrix, \c 'U' to use the upper part.
// \param n The number of rows/columns of the column-major matrix \f$[0..\infty)\f$.
// \param nrhs The number of right-hand side vectors \f$[0..\infty)\f$.
// \param A Pointer to the first element of the double precision complex column-major square matrix.
// \param lda The total number of elements between two columns of matrix \a A \f$[0..\infty)\f$.
// \param ipiv Auxiliary array of size \a n for the pivot indices.
// \param B Pointer to the first element of the double precision complex column-major matrix.
// \param ldb The total number of elements between two columns of matrix \a B \f$[0..\infty)\f$.
// \param info Return code of the function call.
// \return void
//
// This function uses the LAPACK zsytrs() function to perform the substitution step to compute
// the solution to the symmetric indefinite system of linear equations \f$ A*X=B \f$, where \a A
// is a \a n-by-\a n matrix that has already been factorized by the zsytrf() function and \a X
// and \a B are column-major \a n-by-\a nrhs matrices.
//
// The \a info argument provides feedback on the success of the function call:
//
//   - = 0: The function finished successfully.
//   - < 0: If info = -i, the i-th argument had an illegal value.
//
// For more information on the zsytrs() function, see the LAPACK online documentation browser:
//
//        http://www.netlib.org/lapack/explore-html/
//
// \note This function can only be used if a fitting LAPACK library, which supports this function,
// is available and linked to the executable. Otherwise a call to this function will result in a
// linker error.
*/
inline void sytrs( char uplo, int n, int nrhs, const complex<double>* A, int lda,
                   const int* ipiv, complex<double>* B, int ldb, int* info )
{
   BLAZE_STATIC_ASSERT( sizeof( complex<double> ) == 2UL*sizeof( double ) );

#if defined(INTEL_MKL_VERSION)
   BLAZE_STATIC_ASSERT( sizeof( MKL_INT ) == sizeof( int ) );
   using ET = MKL_Complex16;
#else
   using ET = double;
#endif

   zsytrs_( &uplo, &n, &nrhs, const_cast<ET*>( reinterpret_cast<const ET*>( A ) ),
            &lda, const_cast<int*>( ipiv ), reinterpret_cast<ET*>( B ), &ldb, info
#if !defined(INTEL_MKL_VERSION)
          , blaze::fortran_charlen_t(1)
#endif
          );
}
//*************************************************************************************************

} // namespace blaze

#endif
