/*
 * Copyright 1998,1999 The OpenLDAP Foundation, Redwood City, California, USA
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted only
 * as authorized by the OpenLDAP Public License.  A copy of this
 * license is available at http://www.OpenLDAP.org/license.html or
 * in file LICENSE in the top-level directory of the distribution.
 */
/* LDAP C Defines */

#ifndef _LDAP_CDEFS_H
#define _LDAP_CDEFS_H

#if defined(__cplusplus)
#	define LDAP_BEGIN_DECL	extern "C" {
#	define LDAP_END_DECL	}
#else
#	define LDAP_BEGIN_DECL	/* begin declarations */
#	define LDAP_END_DECL	/* end declarations */
#endif

#if !defined(__NO_PROTOTYPES) && ( \
	defined(__STDC__) || defined(__cplusplus) || \
	defined(__NEED_PROTOTYPES) )

	/* ANSI C or C++ */
#	define LDAP_P(protos)	protos
#	define LDAP_CONCAT1(x,y)	x ## y
#	define LDAP_CONCAT(x,y)	LDAP_CONCAT1(x,y)
#	define LDAP_STRING(x)	#x /* stringify without expanding x */
#	define LDAP_XSTRING(x)	LDAP_STRING(x) /* expand x, then stringify */

#ifndef LDAP_CONST
#	define LDAP_CONST	const
#endif

#else /* no prototypes */

	/* traditional C */
#	define LDAP_P(protos)	()
#	define LDAP_CONCAT(x,y)	x/**/y
#	define LDAP_STRING(x)	"x"

#ifndef LDAP_CONST
#	define LDAP_CONST	/* no const */
#endif

#endif /* no prototypes */


#ifndef LDAP_F_PRE
#	ifdef _WIN32
#		define LDAP_F_PRE	extern __declspec( dllexport )
#	else /* ! _WIN32 */
#		define LDAP_F_PRE	extern
#	endif /* _WIN32 */
#endif /* LDAP_FDECL */
#ifndef LDAP_F_POST
#	ifdef _WIN32
#		define LDAP_F_POST
#	else /* ! _WIN32 */
#		define LDAP_F_POST	
#	endif /* _WIN32 */
#endif /* LDAP_FDECL */
#ifndef LDAP_F
#define LDAP_F(type)	LDAP_F_PRE type LDAP_F_POST
#endif

#endif /* _LDAP_CDEFS_H */
