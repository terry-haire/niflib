/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#include "../../include/gen/SubIndexPart1.h"
#include "../../include/gen/SubIndexRecordA.h"
using namespace Niflib;

//Constructor
SubIndexPart1::SubIndexPart1() : unknownInt1((unsigned int)0), unknownInt2((unsigned int)0), unknownInt3((unsigned int)0), numRecords((unsigned int)0) {};

//Copy Constructor
SubIndexPart1::SubIndexPart1( const SubIndexPart1 & src ) {
	*this = src;
};

//Copy Operator
SubIndexPart1 & SubIndexPart1::operator=( const SubIndexPart1 & src ) {
	this->unknownInt1 = src.unknownInt1;
	this->unknownInt2 = src.unknownInt2;
	this->unknownInt3 = src.unknownInt3;
	this->numRecords = src.numRecords;
	this->subIndexRecord = src.subIndexRecord;
	return *this;
};

//Destructor
SubIndexPart1::~SubIndexPart1() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
