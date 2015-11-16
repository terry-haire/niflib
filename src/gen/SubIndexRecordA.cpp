/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#include "../../include/gen/SubIndexRecordA.h"
using namespace Niflib;

//Constructor
SubIndexRecordA::SubIndexRecordA() : unknownInt1((unsigned int)0), unknownInt2((unsigned int)0), unknownInt3((unsigned int)0), unknownInt4((unsigned int)0) {};

//Copy Constructor
SubIndexRecordA::SubIndexRecordA( const SubIndexRecordA & src ) {
	*this = src;
};

//Copy Operator
SubIndexRecordA & SubIndexRecordA::operator=( const SubIndexRecordA & src ) {
	this->unknownInt1 = src.unknownInt1;
	this->unknownInt2 = src.unknownInt2;
	this->unknownInt3 = src.unknownInt3;
	this->unknownInt4 = src.unknownInt4;
	return *this;
};

//Destructor
SubIndexRecordA::~SubIndexRecordA() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
