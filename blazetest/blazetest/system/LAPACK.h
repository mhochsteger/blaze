//=================================================================================================
/*!
//  \file blazetest/system/LAPACK.h
//  \brief System settings for the LAPACK mode
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

#ifndef _BLAZETEST_SYSTEM_LAPACK_H_
#define _BLAZETEST_SYSTEM_LAPACK_H_


//=================================================================================================
//
//  LAPACK MODE CONFIGURATION
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Compilation switch for the LAPACK mode.
// \ingroup system
//
// This compilation switch enables/disables the LAPACK mode for the Blaze math tests. In case
// the LAPACK mode is enabled, all tests that require LAPACK to be available are included, in
// case the LAPACK mode is disabled the tests are ignored. Note that in case the LAPACK mode
// is enabled it is mandatory to link the LAPACK library to the final executables.
//
// Possible settings for the LAPACK switch:
//  - Deactivated: \b 0
//  - Activated  : \b 1
*/
#define BLAZETEST_MATHTEST_LAPACK_MODE 0
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Compilation switch for the LAPACK support of the gesvdx() functions.
// \ingroup system
//
// The LAPACK gesvdx() functions are not supported by all LAPACK libraries. Via this compilation
// switch tests for the gesvdx() function can be explicitly enabled/disabled. In case both the
// LAPACK mode and this switch are enabled, all gesvdx() tests are included, in case either one
// is disabled the gesvdx() tests are ignored.
//
// Possible settings for the LAPACK gesvdx() switch:
//  - Deactivated: \b 0
//  - Activated  : \b 1
*/
#define BLAZETEST_MATHTEST_LAPACK_SUPPORTS_GESVDX 0
//*************************************************************************************************

#endif
