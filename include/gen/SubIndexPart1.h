/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#ifndef _SUBINDEXPART1_H_
#define _SUBINDEXPART1_H_

#include "../NIF_IO.h"

// Include structures
#include "SubIndexRecordA.h"
namespace Niflib {


/*!  */
struct SubIndexPart1 {
	/*! Default Constructor */
	NIFLIB_API SubIndexPart1();
	/*! Default Destructor */
	NIFLIB_API ~SubIndexPart1();
	/*! Copy Constructor */
	NIFLIB_API SubIndexPart1( const SubIndexPart1 & src );
	/*! Copy Operator */
	NIFLIB_API SubIndexPart1 & operator=( const SubIndexPart1 & src );
	/*! Unknown. */
	unsigned int unknownInt1;
	/*! Unknown. */
	unsigned int unknownInt2;
	/*! Unknown. */
	unsigned int unknownInt3;
	/*! Unknown. */
	mutable unsigned int numRecords;
	/*! Unknown. */
	vector<SubIndexRecordA > subIndexRecord;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
