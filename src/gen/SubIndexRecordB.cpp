/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#include "../../include/gen/SubIndexRecordB.h"
using namespace Niflib;

//Constructor
SubIndexRecordB::SubIndexRecordB() : unknownInt1((unsigned int)0), unknownHfloat1((hfloat)0), unknownHfloat2((hfloat)0), numData((unsigned int)0) {};

//Copy Constructor
SubIndexRecordB::SubIndexRecordB( const SubIndexRecordB & src ) {
	*this = src;
};

//Copy Operator
SubIndexRecordB & SubIndexRecordB::operator=( const SubIndexRecordB & src ) {
	this->unknownInt1 = src.unknownInt1;
	this->unknownHfloat1 = src.unknownHfloat1;
	this->unknownHfloat2 = src.unknownHfloat2;
	this->numData = src.numData;
	this->extraData = src.extraData;
	return *this;
};

//Destructor
SubIndexRecordB::~SubIndexRecordB() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
