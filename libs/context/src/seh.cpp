
//          Copyright Oliver Kowalke 2009.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_CONTEXT_SOURCE

extern "C" {

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include <excpt.h>
#include <windows.h>
#include <winnt.h>

static char * exception_description(
    _EXCEPTION_RECORD const* record, char * description, size_t len)
{
    const DWORD code = record->ExceptionCode;
    const ULONG_PTR * info = record->ExceptionInformation;

    switch ( code)
    {
    case EXCEPTION_ACCESS_VIOLATION:
    {
        const char * accessType = ( info[0]) ? "writing" : "reading";
        const ULONG_PTR address = info[1];
#if defined (__MINGW32__) || defined (__MINGW64__)
        snprintf( description, len, "Access violation %s 0x%08X", accessType, address);
#else
        _snprintf_s( description, len, _TRUNCATE, "Access violation %s 0x%08X", accessType, address);
#endif
        return description;
    }
    case EXCEPTION_DATATYPE_MISALIGNMENT:    return "Datatype misalignment";
    case EXCEPTION_BREAKPOINT:               return "Breakpoint";
    case EXCEPTION_SINGLE_STEP:              return "Single step";
    case EXCEPTION_ARRAY_BOUNDS_EXCEEDED:    return "Array bounds exceeded";
    case EXCEPTION_FLT_DENORMAL_OPERAND:     return "FPU denormal operand";
    case EXCEPTION_FLT_DIVIDE_BY_ZERO:       return "FPU divide by zero";
    case EXCEPTION_FLT_INEXACT_RESULT:       return "FPU inexact result";
    case EXCEPTION_FLT_INVALID_OPERATION:    return "FPU invalid operation";
    case EXCEPTION_FLT_OVERFLOW:             return "FPU overflow";
    case EXCEPTION_FLT_STACK_CHECK:          return "FPU stack check";
    case EXCEPTION_FLT_UNDERFLOW:            return "FPU underflow";
    case EXCEPTION_INT_DIVIDE_BY_ZERO:       return "Integer divide by zero";
    case EXCEPTION_INT_OVERFLOW:             return "Integer overflow";
    case EXCEPTION_PRIV_INSTRUCTION:         return "Privileged instruction";
    case EXCEPTION_IN_PAGE_ERROR:            return "In page error";
    case EXCEPTION_ILLEGAL_INSTRUCTION:      return "Illegal instruction";
    case EXCEPTION_NONCONTINUABLE_EXCEPTION: return "Noncontinuable exception";
    case EXCEPTION_STACK_OVERFLOW:           return "Stack overflow";
    case EXCEPTION_INVALID_DISPOSITION:      return "Invalid disposition";
    case EXCEPTION_GUARD_PAGE:               return "Guard page";
    case EXCEPTION_INVALID_HANDLE:           return "Invalid handle";
    }

#if defined (__MINGW32__) || defined (__MINGW64__)
    snprintf( description, len, "Unknown (0x%08X)", code);
#else
    _snprintf_s( description, len, _TRUNCATE, "Unknown (0x%08X)", code);
#endif

    return description;
}

EXCEPTION_DISPOSITION boost_fcontext_seh(
     struct _EXCEPTION_RECORD * record,
     void * frame,
     struct _CONTEXT * ctx,
     void * dispatcher)
{
    char description[255];

    fprintf( stderr, "exception: %s (%08X)\n",
        exception_description( record, description, sizeof( description) ),
        record->ExceptionCode);

    ExitProcess( -1);

    return ExceptionContinueSearch; // never reached
}

}
