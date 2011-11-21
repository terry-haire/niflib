/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//

//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/BSBoneLODExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSBoneLODExtraData::TYPE("BSBoneLODExtraData", &NiExtraData::TYPE );

BSBoneLODExtraData::BSBoneLODExtraData() : unknownInt1((unsigned int)0), unknownInt2((unsigned int)0), unknownInt3((unsigned int)0), unknownInt4((unsigned int)0), unknownInt5((unsigned int)0), unknownInt6((unsigned int)0), unknownInt7((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSBoneLODExtraData::~BSBoneLODExtraData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSBoneLODExtraData::GetType() const {
	return TYPE;
}

NiObject * BSBoneLODExtraData::Create() {
	return new BSBoneLODExtraData;
}

void BSBoneLODExtraData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiExtraData::Read( in, link_stack, info );
	NifStream( unknownInt1, in, info );
	NifStream( unknownInt2, in, info );
	NifStream( unknownInt3, in, info );
	if ( (info.userVersion >= 12) ) {
		if ( (unknownInt1 >= 2) ) {
			NifStream( unknownInt4, in, info );
			NifStream( unknownInt5, in, info );
		};
		if ( (unknownInt1 == 3) ) {
			NifStream( unknownInt6, in, info );
			NifStream( unknownInt7, in, info );
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSBoneLODExtraData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiExtraData::Write( out, link_map, missing_link_stack, info );
	NifStream( unknownInt1, out, info );
	NifStream( unknownInt2, out, info );
	NifStream( unknownInt3, out, info );
	if ( (info.userVersion >= 12) ) {
		if ( (unknownInt1 >= 2) ) {
			NifStream( unknownInt4, out, info );
			NifStream( unknownInt5, out, info );
		};
		if ( (unknownInt1 == 3) ) {
			NifStream( unknownInt6, out, info );
			NifStream( unknownInt7, out, info );
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string BSBoneLODExtraData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << NiExtraData::asString();
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Unknown Int 3:  " << unknownInt3 << endl;
	if ( (unknownInt1 >= 2) ) {
		out << "    Unknown Int 4:  " << unknownInt4 << endl;
		out << "    Unknown Int 5:  " << unknownInt5 << endl;
	};
	if ( (unknownInt1 == 3) ) {
		out << "    Unknown Int 6:  " << unknownInt6 << endl;
		out << "    Unknown Int 7:  " << unknownInt7 << endl;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSBoneLODExtraData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiExtraData::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSBoneLODExtraData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

std::list<NiObject *> BSBoneLODExtraData::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiExtraData::GetPtrs();
	return ptrs;
}

//--This object has no eligable attributes.  No example implementation generated--//

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
