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
#include "../../include/obj/BSWaterShaderProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSWaterShaderProperty::TYPE("BSWaterShaderProperty", &NiProperty::TYPE );

BSWaterShaderProperty::BSWaterShaderProperty() : unknownByte1((byte)0), unknownShort1((unsigned short)0), unknownInt1((unsigned int)0), unknownByte2((byte)0), textureRepeat(1.0, 1.0), waterShaderFlags((SkyrimWaterShaderFlags)0), waterDirection((byte)3), unknownShort3((unsigned short)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSWaterShaderProperty::~BSWaterShaderProperty() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSWaterShaderProperty::GetType() const {
	return TYPE;
}

NiObject * BSWaterShaderProperty::Create() {
	return new BSWaterShaderProperty;
}

void BSWaterShaderProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiProperty::Read( in, link_stack, info );
	NifStream( unknownByte1, in, info );
	NifStream( unknownShort1, in, info );
	NifStream( unknownInt1, in, info );
	NifStream( unknownByte2, in, info );
	NifStream( textureTranslation1, in, info );
	NifStream( textureRepeat, in, info );
	NifStream( waterShaderFlags, in, info );
	NifStream( waterDirection, in, info );
	NifStream( unknownShort3, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSWaterShaderProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiProperty::Write( out, link_map, missing_link_stack, info );
	NifStream( unknownByte1, out, info );
	NifStream( unknownShort1, out, info );
	NifStream( unknownInt1, out, info );
	NifStream( unknownByte2, out, info );
	NifStream( textureTranslation1, out, info );
	NifStream( textureRepeat, out, info );
	NifStream( waterShaderFlags, out, info );
	NifStream( waterDirection, out, info );
	NifStream( unknownShort3, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string BSWaterShaderProperty::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << NiProperty::asString();
	out << "  Unknown Byte 1:  " << unknownByte1 << endl;
	out << "  Unknown Short 1:  " << unknownShort1 << endl;
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Unknown Byte 2:  " << unknownByte2 << endl;
	out << "  Texture Translation 1:  " << textureTranslation1 << endl;
	out << "  Texture Repeat:  " << textureRepeat << endl;
	out << "  Water Shader Flags:  " << waterShaderFlags << endl;
	out << "  Water Direction:  " << waterDirection << endl;
	out << "  Unknown Short 3:  " << unknownShort3 << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSWaterShaderProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiProperty::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSWaterShaderProperty::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

std::list<NiObject *> BSWaterShaderProperty::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiProperty::GetPtrs();
	return ptrs;
}

/***Begin Example Naive Implementation****

TexCoord BSWaterShaderProperty::GetTextureTranslation1() const {
	return textureTranslation1;
}

void BSWaterShaderProperty::SetTextureTranslation1( const TexCoord & value ) {
	textureTranslation1 = value;
}

TexCoord BSWaterShaderProperty::GetTextureRepeat() const {
	return textureRepeat;
}

void BSWaterShaderProperty::SetTextureRepeat( const TexCoord & value ) {
	textureRepeat = value;
}

SkyrimWaterShaderFlags BSWaterShaderProperty::GetWaterShaderFlags() const {
	return waterShaderFlags;
}

void BSWaterShaderProperty::SetWaterShaderFlags( const SkyrimWaterShaderFlags & value ) {
	waterShaderFlags = value;
}

byte BSWaterShaderProperty::GetWaterDirection() const {
	return waterDirection;
}

void BSWaterShaderProperty::SetWaterDirection( byte value ) {
	waterDirection = value;
}

****End Example Naive Implementation***/

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
