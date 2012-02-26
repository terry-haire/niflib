/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#ifndef _BHKCMSDCHUNK_H_
#define _BHKCMSDCHUNK_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! Defines subshape chunks in bhkCompressedMeshShapeData */
struct bhkCMSDChunk {
	/*! Default Constructor */
	NIFLIB_API bhkCMSDChunk();
	/*! Default Destructor */
	NIFLIB_API ~bhkCMSDChunk();
	/*! Copy Constructor */
	NIFLIB_API bhkCMSDChunk( const bhkCMSDChunk & src );
	/*! Copy Operator */
	NIFLIB_API bhkCMSDChunk & operator=( const bhkCMSDChunk & src );
	/*! Origin? */
	Vector3 unknownFloats1;
	/*! Rotation? */
	Vector3 unknownFloats2;
	/*! Number of compressed vertices */
	mutable unsigned int numVertices;
	/*! Compressed vertices */
	vector<unsigned short > vertices;
	/*! Unknown. */
	mutable unsigned int numIndices;
	/*! Unknown. */
	vector<unsigned short > indices;
	/*! Number of compressed strips */
	mutable unsigned int numStrips;
	/*! Compressed strips */
	vector<unsigned short > strips;
	/*! Number of */
	mutable unsigned int numIndices2;
	/*! Compressed */
	vector<unsigned short > indices2;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
