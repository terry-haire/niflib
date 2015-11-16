/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#ifndef _SUBINDEXRECORDA_H_
#define _SUBINDEXRECORDA_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!  */
struct SubIndexRecordA {
	/*! Default Constructor */
	NIFLIB_API SubIndexRecordA();
	/*! Default Destructor */
	NIFLIB_API ~SubIndexRecordA();
	/*! Copy Constructor */
	NIFLIB_API SubIndexRecordA( const SubIndexRecordA & src );
	/*! Copy Operator */
	NIFLIB_API SubIndexRecordA & operator=( const SubIndexRecordA & src );
	/*! Unknown. */
	unsigned int unknownInt1;
	/*! Unknown. */
	unsigned int unknownInt2;
	/*! Unknown. */
	unsigned int unknownInt3;
	/*! Unknown. */
	unsigned int unknownInt4;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
