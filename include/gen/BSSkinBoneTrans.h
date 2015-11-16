/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#ifndef _BSSKINBONETRANS_H_
#define _BSSKINBONETRANS_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!  */
struct BSSkinBoneTrans {
	/*! Default Constructor */
	NIFLIB_API BSSkinBoneTrans();
	/*! Default Destructor */
	NIFLIB_API ~BSSkinBoneTrans();
	/*! Copy Constructor */
	NIFLIB_API BSSkinBoneTrans( const BSSkinBoneTrans & src );
	/*! Copy Operator */
	NIFLIB_API BSSkinBoneTrans & operator=( const BSSkinBoneTrans & src );
	/*! Unknown. */
	Vector3 boundingSphere_;
	/*! Unknown. */
	float radius_;
	/*! Unknown. */
	Matrix33 rotation;
	/*! Unknown. */
	Vector3 translation;
	/*! Unknown. */
	float scale;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
