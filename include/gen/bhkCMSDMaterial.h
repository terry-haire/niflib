/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#ifndef _BHKCMSDMATERIAL_H_
#define _BHKCMSDMATERIAL_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! per-chunk material, used in bhkCompressedMeshShapeData */
struct bhkCMSDMaterial {
	/*! Default Constructor */
	NIFLIB_API bhkCMSDMaterial();
	/*! Default Destructor */
	NIFLIB_API ~bhkCMSDMaterial();
	/*! Copy Constructor */
	NIFLIB_API bhkCMSDMaterial( const bhkCMSDMaterial & src );
	/*! Copy Operator */
	NIFLIB_API bhkCMSDMaterial & operator=( const bhkCMSDMaterial & src );
	/*! Material. */
	SkyrimHavokMaterial skyrimMaterial;
	/*! Copy of Skyrim Layer from bhkRigidBody. The value is stored as 32-bit integer. */
	SkyrimLayer skyrimLayer;
	/*! Skyrim Layer is 32-bit int here.  This is padding. */
	byte unknown1;
	/*! Skyrim Layer is 32-bit int here.  This is padding. */
	unsigned short unknown2;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
