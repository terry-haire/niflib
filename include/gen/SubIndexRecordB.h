/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#ifndef _SUBINDEXRECORDB_H_
#define _SUBINDEXRECORDB_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!  */
struct SubIndexRecordB {
	/*! Default Constructor */
	NIFLIB_API SubIndexRecordB();
	/*! Default Destructor */
	NIFLIB_API ~SubIndexRecordB();
	/*! Copy Constructor */
	NIFLIB_API SubIndexRecordB( const SubIndexRecordB & src );
	/*! Copy Operator */
	NIFLIB_API SubIndexRecordB & operator=( const SubIndexRecordB & src );
	/*! Unknown. */
	unsigned int unknownInt1;
	/*! Unknown. */
	hfloat unknownHfloat1;
	/*! Unknown. */
	hfloat unknownHfloat2;
	/*! Unknown. */
	mutable unsigned int numData;
	/*! Unknown. */
	vector<float > extraData;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
