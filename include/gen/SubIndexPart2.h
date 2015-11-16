/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#ifndef _SUBINDEXPART2_H_
#define _SUBINDEXPART2_H_

#include "../NIF_IO.h"

// Include structures
#include "SubIndexRecordB.h"
namespace Niflib {


/*!  */
struct SubIndexPart2 {
	/*! Default Constructor */
	NIFLIB_API SubIndexPart2();
	/*! Default Destructor */
	NIFLIB_API ~SubIndexPart2();
	/*! Copy Constructor */
	NIFLIB_API SubIndexPart2( const SubIndexPart2 & src );
	/*! Copy Operator */
	NIFLIB_API SubIndexPart2 & operator=( const SubIndexPart2 & src );
	/*! Unknown. */
	mutable unsigned int numa2;
	/*! Unknown. */
	mutable unsigned int numb2;
	/*! Unknown. */
	vector<unsigned int > recordA;
	/*! Unknown. */
	vector<SubIndexRecordB > recordB;
	/*! Unknown. */
	mutable unsigned short sspLength;
	/*! Unknown. */
	vector<byte > sspFile;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
