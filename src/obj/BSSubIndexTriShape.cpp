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
#include "../../include/obj/BSSubIndexTriShape.h"
#include "../../include/gen/SubIndexPart1.h"
#include "../../include/gen/SubIndexRecordA.h"
#include "../../include/gen/SubIndexPart2.h"
#include "../../include/gen/SubIndexRecordB.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSSubIndexTriShape::TYPE("BSSubIndexTriShape", &BSTriShape::TYPE );

BSSubIndexTriShape::BSSubIndexTriShape() : numTriangles2((unsigned int)0), numa((unsigned int)0), numb((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSSubIndexTriShape::~BSSubIndexTriShape() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSSubIndexTriShape::GetType() const {
	return TYPE;
}

NiObject * BSSubIndexTriShape::Create() {
	return new BSSubIndexTriShape;
}

void BSSubIndexTriShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	BSTriShape::Read( in, link_stack, info );
	if ( (dataSize > 0) ) {
		NifStream( numTriangles2, in, info );
		NifStream( numa, in, info );
		NifStream( numb, in, info );
		subIndexPart1.resize(numa);
		for (unsigned int i2 = 0; i2 < subIndexPart1.size(); i2++) {
			NifStream( subIndexPart1[i2].unknownInt1, in, info );
			NifStream( subIndexPart1[i2].unknownInt2, in, info );
			NifStream( subIndexPart1[i2].unknownInt3, in, info );
			NifStream( subIndexPart1[i2].numRecords, in, info );
			subIndexPart1[i2].subIndexRecord.resize(subIndexPart1[i2].numRecords);
			for (unsigned int i3 = 0; i3 < subIndexPart1[i2].subIndexRecord.size(); i3++) {
				NifStream( subIndexPart1[i2].subIndexRecord[i3].unknownInt1, in, info );
				NifStream( subIndexPart1[i2].subIndexRecord[i3].unknownInt2, in, info );
				NifStream( subIndexPart1[i2].subIndexRecord[i3].unknownInt3, in, info );
				NifStream( subIndexPart1[i2].subIndexRecord[i3].unknownInt4, in, info );
			};
		};
	};
	if ( ((numa < numb) && (dataSize > 0)) ) {
		NifStream( subIndexPart2.numa2, in, info );
		NifStream( subIndexPart2.numb2, in, info );
		subIndexPart2.recordA.resize(subIndexPart2.numa2);
		for (unsigned int i2 = 0; i2 < subIndexPart2.recordA.size(); i2++) {
			NifStream( subIndexPart2.recordA[i2], in, info );
		};
		subIndexPart2.recordB.resize(subIndexPart2.numb2);
		for (unsigned int i2 = 0; i2 < subIndexPart2.recordB.size(); i2++) {
			NifStream( subIndexPart2.recordB[i2].unknownInt1, in, info );
			NifStream( subIndexPart2.recordB[i2].unknownHfloat1, in, info );
			NifStream( subIndexPart2.recordB[i2].unknownHfloat2, in, info );
			NifStream( subIndexPart2.recordB[i2].numData, in, info );
			subIndexPart2.recordB[i2].extraData.resize(subIndexPart2.recordB[i2].numData);
			for (unsigned int i3 = 0; i3 < subIndexPart2.recordB[i2].extraData.size(); i3++) {
				NifStream( subIndexPart2.recordB[i2].extraData[i3], in, info );
			};
		};
		NifStream( subIndexPart2.sspLength, in, info );
		subIndexPart2.sspFile.resize(subIndexPart2.sspLength);
		for (unsigned int i2 = 0; i2 < subIndexPart2.sspFile.size(); i2++) {
			NifStream( subIndexPart2.sspFile[i2], in, info );
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSSubIndexTriShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	BSTriShape::Write( out, link_map, missing_link_stack, info );
	numa = (unsigned int)(subIndexPart1.size());
	if ( (dataSize > 0) ) {
		NifStream( numTriangles2, out, info );
		NifStream( numa, out, info );
		NifStream( numb, out, info );
		for (unsigned int i2 = 0; i2 < subIndexPart1.size(); i2++) {
			subIndexPart1[i2].numRecords = (unsigned int)(subIndexPart1[i2].subIndexRecord.size());
			NifStream( subIndexPart1[i2].unknownInt1, out, info );
			NifStream( subIndexPart1[i2].unknownInt2, out, info );
			NifStream( subIndexPart1[i2].unknownInt3, out, info );
			NifStream( subIndexPart1[i2].numRecords, out, info );
			for (unsigned int i3 = 0; i3 < subIndexPart1[i2].subIndexRecord.size(); i3++) {
				NifStream( subIndexPart1[i2].subIndexRecord[i3].unknownInt1, out, info );
				NifStream( subIndexPart1[i2].subIndexRecord[i3].unknownInt2, out, info );
				NifStream( subIndexPart1[i2].subIndexRecord[i3].unknownInt3, out, info );
				NifStream( subIndexPart1[i2].subIndexRecord[i3].unknownInt4, out, info );
			};
		};
	};
	if ( ((numa < numb) && (dataSize > 0)) ) {
		subIndexPart2.sspLength = (unsigned short)(subIndexPart2.sspFile.size());
		subIndexPart2.numb2 = (unsigned int)(subIndexPart2.recordB.size());
		subIndexPart2.numa2 = (unsigned int)(subIndexPart2.recordA.size());
		NifStream( subIndexPart2.numa2, out, info );
		NifStream( subIndexPart2.numb2, out, info );
		for (unsigned int i2 = 0; i2 < subIndexPart2.recordA.size(); i2++) {
			NifStream( subIndexPart2.recordA[i2], out, info );
		};
		for (unsigned int i2 = 0; i2 < subIndexPart2.recordB.size(); i2++) {
			subIndexPart2.recordB[i2].numData = (unsigned int)(subIndexPart2.recordB[i2].extraData.size());
			NifStream( subIndexPart2.recordB[i2].unknownInt1, out, info );
			NifStream( subIndexPart2.recordB[i2].unknownHfloat1, out, info );
			NifStream( subIndexPart2.recordB[i2].unknownHfloat2, out, info );
			NifStream( subIndexPart2.recordB[i2].numData, out, info );
			for (unsigned int i3 = 0; i3 < subIndexPart2.recordB[i2].extraData.size(); i3++) {
				NifStream( subIndexPart2.recordB[i2].extraData[i3], out, info );
			};
		};
		NifStream( subIndexPart2.sspLength, out, info );
		for (unsigned int i2 = 0; i2 < subIndexPart2.sspFile.size(); i2++) {
			NifStream( subIndexPart2.sspFile[i2], out, info );
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string BSSubIndexTriShape::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << BSTriShape::asString();
	numa = (unsigned int)(subIndexPart1.size());
	if ( (dataSize > 0) ) {
		out << "    Num Triangles 2:  " << numTriangles2 << endl;
		out << "    NumA:  " << numa << endl;
		out << "    NumB:  " << numb << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < subIndexPart1.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			subIndexPart1[i2].numRecords = (unsigned int)(subIndexPart1[i2].subIndexRecord.size());
			out << "      Unknown Int 1:  " << subIndexPart1[i2].unknownInt1 << endl;
			out << "      Unknown Int 2:  " << subIndexPart1[i2].unknownInt2 << endl;
			out << "      Unknown Int 3:  " << subIndexPart1[i2].unknownInt3 << endl;
			out << "      Num Records:  " << subIndexPart1[i2].numRecords << endl;
			array_output_count = 0;
			for (unsigned int i3 = 0; i3 < subIndexPart1[i2].subIndexRecord.size(); i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				out << "        Unknown Int 1:  " << subIndexPart1[i2].subIndexRecord[i3].unknownInt1 << endl;
				out << "        Unknown Int 2:  " << subIndexPart1[i2].subIndexRecord[i3].unknownInt2 << endl;
				out << "        Unknown Int 3:  " << subIndexPart1[i2].subIndexRecord[i3].unknownInt3 << endl;
				out << "        Unknown Int 4:  " << subIndexPart1[i2].subIndexRecord[i3].unknownInt4 << endl;
			};
		};
	};
	if ( ((numa < numb) && (dataSize > 0)) ) {
		subIndexPart2.sspLength = (unsigned short)(subIndexPart2.sspFile.size());
		subIndexPart2.numb2 = (unsigned int)(subIndexPart2.recordB.size());
		subIndexPart2.numa2 = (unsigned int)(subIndexPart2.recordA.size());
		out << "    NumA2:  " << subIndexPart2.numa2 << endl;
		out << "    NumB2:  " << subIndexPart2.numb2 << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < subIndexPart2.recordA.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Record A[" << i2 << "]:  " << subIndexPart2.recordA[i2] << endl;
			array_output_count++;
		};
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < subIndexPart2.recordB.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			subIndexPart2.recordB[i2].numData = (unsigned int)(subIndexPart2.recordB[i2].extraData.size());
			out << "      Unknown Int 1:  " << subIndexPart2.recordB[i2].unknownInt1 << endl;
			out << "      Unknown HFloat 1:  " << subIndexPart2.recordB[i2].unknownHfloat1 << endl;
			out << "      Unknown HFloat 2:  " << subIndexPart2.recordB[i2].unknownHfloat2 << endl;
			out << "      Num Data:  " << subIndexPart2.recordB[i2].numData << endl;
			array_output_count = 0;
			for (unsigned int i3 = 0; i3 < subIndexPart2.recordB[i2].extraData.size(); i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Extra Data[" << i3 << "]:  " << subIndexPart2.recordB[i2].extraData[i3] << endl;
				array_output_count++;
			};
		};
		out << "    SSP Length:  " << subIndexPart2.sspLength << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < subIndexPart2.sspFile.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      SSP File[" << i2 << "]:  " << subIndexPart2.sspFile[i2] << endl;
			array_output_count++;
		};
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSSubIndexTriShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	BSTriShape::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSSubIndexTriShape::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = BSTriShape::GetRefs();
	return refs;
}

std::list<NiObject *> BSSubIndexTriShape::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = BSTriShape::GetPtrs();
	return ptrs;
}

/***Begin Example Naive Implementation****

unsigned int BSSubIndexTriShape::GetNumTriangles2() const {
	return numTriangles2;
}

void BSSubIndexTriShape::SetNumTriangles2( unsigned int value ) {
	numTriangles2 = value;
}

unsigned int BSSubIndexTriShape::GetNumb() const {
	return numb;
}

void BSSubIndexTriShape::SetNumb( unsigned int value ) {
	numb = value;
}

vector<SubIndexPart1 > BSSubIndexTriShape::GetSubIndexPart1() const {
	return subIndexPart1;
}

void BSSubIndexTriShape::SetSubIndexPart1( const vector<SubIndexPart1 >& value ) {
	subIndexPart1 = value;
}

SubIndexPart2 BSSubIndexTriShape::GetSubIndexPart2() const {
	return subIndexPart2;
}

void BSSubIndexTriShape::SetSubIndexPart2( const SubIndexPart2 & value ) {
	subIndexPart2 = value;
}

****End Example Naive Implementation***/

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
