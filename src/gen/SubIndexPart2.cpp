/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#include "../../include/gen/SubIndexPart2.h"
#include "../../include/gen/SubIndexRecordB.h"
using namespace Niflib;

//Constructor
SubIndexPart2::SubIndexPart2() : numa2((unsigned int)0), numb2((unsigned int)0), sspLength((unsigned short)0) {};

//Copy Constructor
SubIndexPart2::SubIndexPart2( const SubIndexPart2 & src ) {
	*this = src;
};

//Copy Operator
SubIndexPart2 & SubIndexPart2::operator=( const SubIndexPart2 & src ) {
	this->numa2 = src.numa2;
	this->numb2 = src.numb2;
	this->recordA = src.recordA;
	this->recordB = src.recordB;
	this->sspLength = src.sspLength;
	this->sspFile = src.sspFile;
	return *this;
};

//Destructor
SubIndexPart2::~SubIndexPart2() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
