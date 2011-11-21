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
#include "../../include/obj/BSLightingShaderProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSLightingShaderProperty::TYPE("BSLightingShaderProperty", &BSShaderPPLightingProperty::TYPE );

BSLightingShaderProperty::BSLightingShaderProperty() : unknownInt1((unsigned int)0), unknownFloatSet1(0.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSLightingShaderProperty::~BSLightingShaderProperty() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSLightingShaderProperty::GetType() const {
	return TYPE;
}

NiObject * BSLightingShaderProperty::Create() {
	return new BSLightingShaderProperty;
}

void BSLightingShaderProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	BSShaderPPLightingProperty::Read( in, link_stack, info );
	if ( (info.userVersion == 12) ) {
		NifStream( unknownInt1, in, info );
		for (unsigned int i2 = 0; i2 < 9; i2++) {
			NifStream( unknownFloats[i2], in, info );
		};
	};
	if ( (info.userVersion >= 12) ) {
		if ( (unknownFlag == 1) ) {
			NifStream( unknownFloatSet1, in, info );
		};
		if ( (unknownFlag == 5) ) {
			NifStream( unknownVector3Set1, in, info );
		};
		if ( (unknownFlag == 16) ) {
			for (unsigned int i3 = 0; i3 < 7; i3++) {
				NifStream( unknownFloatSet2[i3], in, info );
			};
		};
		if ( (unknownFlag == 6) ) {
			NifStream( unknownVector3Set2, in, info );
		};
		if ( (unknownFlag == 11) ) {
			for (unsigned int i3 = 0; i3 < 5; i3++) {
				NifStream( unknownFloatSet3[i3], in, info );
			};
		};
		if ( (unknownFlag == 14) ) {
			NifStream( unknownVector4Set3, in, info );
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSLightingShaderProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	BSShaderPPLightingProperty::Write( out, link_map, missing_link_stack, info );
	if ( (info.userVersion == 12) ) {
		NifStream( unknownInt1, out, info );
		for (unsigned int i2 = 0; i2 < 9; i2++) {
			NifStream( unknownFloats[i2], out, info );
		};
	};
	if ( (info.userVersion >= 12) ) {
		if ( (unknownFlag == 1) ) {
			NifStream( unknownFloatSet1, out, info );
		};
		if ( (unknownFlag == 5) ) {
			NifStream( unknownVector3Set1, out, info );
		};
		if ( (unknownFlag == 16) ) {
			for (unsigned int i3 = 0; i3 < 7; i3++) {
				NifStream( unknownFloatSet2[i3], out, info );
			};
		};
		if ( (unknownFlag == 6) ) {
			NifStream( unknownVector3Set2, out, info );
		};
		if ( (unknownFlag == 11) ) {
			for (unsigned int i3 = 0; i3 < 5; i3++) {
				NifStream( unknownFloatSet3[i3], out, info );
			};
		};
		if ( (unknownFlag == 14) ) {
			NifStream( unknownVector4Set3, out, info );
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string BSLightingShaderProperty::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << BSShaderPPLightingProperty::asString();
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 9; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Floats[" << i1 << "]:  " << unknownFloats[i1] << endl;
		array_output_count++;
	};
	if ( (unknownFlag == 1) ) {
		out << "    Unknown Float Set 1:  " << unknownFloatSet1 << endl;
	};
	if ( (unknownFlag == 5) ) {
		out << "    Unknown Vector3 Set 1:  " << unknownVector3Set1 << endl;
	};
	if ( (unknownFlag == 16) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < 7; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Float Set 2[" << i2 << "]:  " << unknownFloatSet2[i2] << endl;
			array_output_count++;
		};
	};
	if ( (unknownFlag == 6) ) {
		out << "    Unknown Vector3 Set 2:  " << unknownVector3Set2 << endl;
	};
	if ( (unknownFlag == 11) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < 5; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Float Set 3[" << i2 << "]:  " << unknownFloatSet3[i2] << endl;
			array_output_count++;
		};
	};
	if ( (unknownFlag == 14) ) {
		out << "    Unknown Vector4 Set 3:  " << unknownVector4Set3 << endl;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSLightingShaderProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	BSShaderPPLightingProperty::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSLightingShaderProperty::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = BSShaderPPLightingProperty::GetRefs();
	return refs;
}

std::list<NiObject *> BSLightingShaderProperty::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = BSShaderPPLightingProperty::GetPtrs();
	return ptrs;
}

//--This object has no eligable attributes.  No example implementation generated--//

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
