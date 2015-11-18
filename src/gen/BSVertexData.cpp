/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#include "../../include/gen/BSVertexData.h"
#include "../../include/gen/HalfVector3.h"
#include "../../include/gen/HalfTexCoord.h"
#include "../../include/gen/ByteVector3.h"
#include "../../include/gen/ByteVector3.h"
#include "../../include/gen/ByteColor4.h"
using namespace Niflib;

//Constructor
BSVertexData::BSVertexData() : unknownDot((hfloat)0), unknownInt1((unsigned int)0), unknownByte1((byte)0), unknownByte2((byte)0), unknownInt2((unsigned int)0) {};

//Copy Constructor
BSVertexData::BSVertexData( const BSVertexData & src ) {
	*this = src;
};

//Copy Operator
BSVertexData & BSVertexData::operator=( const BSVertexData & src ) {
	this->vertex = src.vertex;
	this->unknownDot = src.unknownDot;
	this->unknownInt1 = src.unknownInt1;
	this->uv = src.uv;
	this->normal = src.normal;
	this->unknownByte1 = src.unknownByte1;
	this->tangent = src.tangent;
	this->unknownByte2 = src.unknownByte2;
	this->vertexColors = src.vertexColors;
	this->boneWeights = src.boneWeights;
	this->boneIndices = src.boneIndices;
	this->unknownInt2 = src.unknownInt2;
	return *this;
};

//Destructor
BSVertexData::~BSVertexData() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
