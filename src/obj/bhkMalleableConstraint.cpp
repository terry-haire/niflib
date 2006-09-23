/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkMalleableConstraint.h"
#include "../../include/gen/RagDollDescriptor.h"
#include "../../include/gen/LimitedHingeDescriptor.h"
#include "../../include/obj/NiObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkMalleableConstraint::TYPE("bhkMalleableConstraint", &BHK_MALLEABLE_CONSTRAINT_PARENT::TypeConst() );

bhkMalleableConstraint::bhkMalleableConstraint() BHK_MALLEABLE_CONSTRAINT_CONSTRUCT {}

bhkMalleableConstraint::~bhkMalleableConstraint() {}

void bhkMalleableConstraint::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkMalleableConstraint::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkMalleableConstraint::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkMalleableConstraint::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkMalleableConstraint::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkMalleableConstraint::GetType() const {
	return TYPE;
};

