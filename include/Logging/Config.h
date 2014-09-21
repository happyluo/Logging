// **********************************************************************
//
// Copyright (c) 2012-2013 Bernard Luo. All rights reserved.
//
// <Email: luo (dot) xiaowei (at) hotmail (dot) com>
//
// **********************************************************************

#ifndef LOGGING_CONFIG_H
#define LOGGING_CONFIG_H

#include <Build/BuildConfig.h>
//
// NAMESPACE 
//
#if defined(__cplusplus)
#	define LOGGING_BEGIN			namespace Logging {
#	define LOGGING_END				}
#	define USING_LOGGING			using namespace Logging;
#	define LOGGING					::Logging::

#else // __cplusplus

#	define LOGGING_BEGIN			
#	define LOGGING_END				
#	define USING_LOGGING			
#	define LOGGING					

#endif // __cplusplus


#ifndef LOGGING_API
#   ifdef LOGGING_API_EXPORTS
#       define LOGGING_API DECLSPEC_EXPORT
#    else
#       define LOGGING_API DECLSPEC_IMPORT
#    endif
#endif


#endif //LOGGING_CONFIG_H
