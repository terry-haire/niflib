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
#include "../../include/obj/bhkCompressedMeshShapeData.h"
#include "../../include/gen/bhkCMSDMaterial.h"
#include "../../include/gen/bhkCMSDData.h"
#include "../../include/gen/bhkCMSDData.h"
#include "../../include/gen/bhkCMSDBigTris.h"
#include "../../include/gen/bhkCMSDChunk.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkCompressedMeshShapeData::TYPE("bhkCompressedMeshShapeData", &NiObject::TYPE );

bhkCompressedMeshShapeData::bhkCompressedMeshShapeData() : unknownInt1((unsigned int)0), unknownInt2((unsigned int)0), unknownShort1((unsigned short)0), unknownShort2((unsigned short)0), unknownShort3((unsigned short)0), unknownShort4((unsigned short)0), unknownFloat1(0.0f), unknownByte1((byte)0), unknownInt3((unsigned int)0), unknownInt4((unsigned int)0), unknownInt5((unsigned int)0), unknownByte2((byte)0), numMaterials((unsigned int)0), unknownInt6((unsigned int)0), numDataSet((unsigned int)0), unknownInt7((unsigned int)0), unknownInt8((unsigned int)0), unknownInt9((unsigned int)0), unknownFloat2(0.0f), numBigVerts((unsigned int)0), numBigTris((unsigned int)0), numChunks((unsigned int)0), unknownInt12((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

bhkCompressedMeshShapeData::~bhkCompressedMeshShapeData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & bhkCompressedMeshShapeData::GetType() const {
	return TYPE;
}

NiObject * bhkCompressedMeshShapeData::Create() {
	return new bhkCompressedMeshShapeData;
}

void bhkCompressedMeshShapeData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Read( in, link_stack, info );
	NifStream( unknownInt1, in, info );
	NifStream( unknownInt2, in, info );
	NifStream( unknownShort1, in, info );
	NifStream( unknownShort2, in, info );
	NifStream( unknownShort3, in, info );
	NifStream( unknownShort4, in, info );
	NifStream( unknownFloat1, in, info );
	NifStream( unknownFloats1, in, info );
	NifStream( unknownFloats2, in, info );
	NifStream( unknownByte1, in, info );
	NifStream( unknownInt3, in, info );
	NifStream( unknownInt4, in, info );
	NifStream( unknownInt5, in, info );
	NifStream( unknownByte2, in, info );
	NifStream( numMaterials, in, info );
	chunkMaterials.resize(numMaterials);
	for (unsigned int i1 = 0; i1 < chunkMaterials.size(); i1++) {
		NifStream( chunkMaterials[i1].materialId, in, info );
		NifStream( chunkMaterials[i1].unknownInteger, in, info );
	};
	NifStream( unknownInt6, in, info );
	NifStream( numDataSet, in, info );
	NifStream( unknownInt7, in, info );
	NifStream( unknownInt8, in, info );
	NifStream( unknownInt9, in, info );
	if ( (numDataSet >= 1) ) {
		dataSet1.resize(numDataSet);
		for (unsigned int i2 = 0; i2 < dataSet1.size(); i2++) {
			NifStream( dataSet1[i2].unknownFloats1, in, info );
			NifStream( dataSet1[i2].unknownInt1, in, info );
		};
	};
	if ( (numDataSet >= 2) ) {
		dataSet2.resize((numDataSet - 1));
		for (unsigned int i2 = 0; i2 < dataSet2.size(); i2++) {
			NifStream( dataSet2[i2].unknownFloats1, in, info );
			NifStream( dataSet2[i2].unknownInt1, in, info );
		};
	};
	NifStream( unknownFloat2, in, info );
	NifStream( numBigVerts, in, info );
	if ( (numBigVerts >= 1) ) {
		bigVerts.resize(numBigVerts);
		for (unsigned int i2 = 0; i2 < bigVerts.size(); i2++) {
			NifStream( bigVerts[i2], in, info );
		};
	};
	NifStream( numBigTris, in, info );
	if ( (numBigTris >= 1) ) {
		bigTris.resize(numBigTris);
		for (unsigned int i2 = 0; i2 < bigTris.size(); i2++) {
			NifStream( bigTris[i2].triangle1, in, info );
			NifStream( bigTris[i2].triangle2, in, info );
			NifStream( bigTris[i2].triangle3, in, info );
			NifStream( bigTris[i2].unknownInt1, in, info );
			NifStream( bigTris[i2].unknownShort1, in, info );
		};
	};
	NifStream( numChunks, in, info );
	if ( (numChunks >= 1) ) {
		chunks.resize(numChunks);
		for (unsigned int i2 = 0; i2 < chunks.size(); i2++) {
			NifStream( chunks[i2].unknownFloats1, in, info );
			NifStream( chunks[i2].unknownFloats2, in, info );
			NifStream( chunks[i2].numVertices, in, info );
			chunks[i2].vertices.resize(chunks[i2].numVertices);
			for (unsigned int i3 = 0; i3 < chunks[i2].vertices.size(); i3++) {
				NifStream( chunks[i2].vertices[i3], in, info );
			};
			NifStream( chunks[i2].numIndices, in, info );
			chunks[i2].indices.resize(chunks[i2].numIndices);
			for (unsigned int i3 = 0; i3 < chunks[i2].indices.size(); i3++) {
				NifStream( chunks[i2].indices[i3], in, info );
			};
			NifStream( chunks[i2].numStrips, in, info );
			chunks[i2].strips.resize(chunks[i2].numStrips);
			for (unsigned int i3 = 0; i3 < chunks[i2].strips.size(); i3++) {
				NifStream( chunks[i2].strips[i3], in, info );
			};
			NifStream( chunks[i2].numIndices2, in, info );
			chunks[i2].indices2.resize(chunks[i2].numIndices2);
			for (unsigned int i3 = 0; i3 < chunks[i2].indices2.size(); i3++) {
				NifStream( chunks[i2].indices2[i3], in, info );
			};
		};
	};
	NifStream( unknownInt12, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void bhkCompressedMeshShapeData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, missing_link_stack, info );
	numChunks = (unsigned int)(chunks.size());
	numBigTris = (unsigned int)(bigTris.size());
	numBigVerts = (unsigned int)(bigVerts.size());
	numDataSet = (unsigned int)(dataSet1.size());
	numMaterials = (unsigned int)(chunkMaterials.size());
	NifStream( unknownInt1, out, info );
	NifStream( unknownInt2, out, info );
	NifStream( unknownShort1, out, info );
	NifStream( unknownShort2, out, info );
	NifStream( unknownShort3, out, info );
	NifStream( unknownShort4, out, info );
	NifStream( unknownFloat1, out, info );
	NifStream( unknownFloats1, out, info );
	NifStream( unknownFloats2, out, info );
	NifStream( unknownByte1, out, info );
	NifStream( unknownInt3, out, info );
	NifStream( unknownInt4, out, info );
	NifStream( unknownInt5, out, info );
	NifStream( unknownByte2, out, info );
	NifStream( numMaterials, out, info );
	for (unsigned int i1 = 0; i1 < chunkMaterials.size(); i1++) {
		NifStream( chunkMaterials[i1].materialId, out, info );
		NifStream( chunkMaterials[i1].unknownInteger, out, info );
	};
	NifStream( unknownInt6, out, info );
	NifStream( numDataSet, out, info );
	NifStream( unknownInt7, out, info );
	NifStream( unknownInt8, out, info );
	NifStream( unknownInt9, out, info );
	if ( (numDataSet >= 1) ) {
		for (unsigned int i2 = 0; i2 < dataSet1.size(); i2++) {
			NifStream( dataSet1[i2].unknownFloats1, out, info );
			NifStream( dataSet1[i2].unknownInt1, out, info );
		};
	};
	if ( (numDataSet >= 2) ) {
		for (unsigned int i2 = 0; i2 < dataSet2.size(); i2++) {
			NifStream( dataSet2[i2].unknownFloats1, out, info );
			NifStream( dataSet2[i2].unknownInt1, out, info );
		};
	};
	NifStream( unknownFloat2, out, info );
	NifStream( numBigVerts, out, info );
	if ( (numBigVerts >= 1) ) {
		for (unsigned int i2 = 0; i2 < bigVerts.size(); i2++) {
			NifStream( bigVerts[i2], out, info );
		};
	};
	NifStream( numBigTris, out, info );
	if ( (numBigTris >= 1) ) {
		for (unsigned int i2 = 0; i2 < bigTris.size(); i2++) {
			NifStream( bigTris[i2].triangle1, out, info );
			NifStream( bigTris[i2].triangle2, out, info );
			NifStream( bigTris[i2].triangle3, out, info );
			NifStream( bigTris[i2].unknownInt1, out, info );
			NifStream( bigTris[i2].unknownShort1, out, info );
		};
	};
	NifStream( numChunks, out, info );
	if ( (numChunks >= 1) ) {
		for (unsigned int i2 = 0; i2 < chunks.size(); i2++) {
			chunks[i2].numIndices2 = (unsigned int)(chunks[i2].indices2.size());
			chunks[i2].numStrips = (unsigned int)(chunks[i2].strips.size());
			chunks[i2].numIndices = (unsigned int)(chunks[i2].indices.size());
			chunks[i2].numVertices = (unsigned int)(chunks[i2].vertices.size());
			NifStream( chunks[i2].unknownFloats1, out, info );
			NifStream( chunks[i2].unknownFloats2, out, info );
			NifStream( chunks[i2].numVertices, out, info );
			for (unsigned int i3 = 0; i3 < chunks[i2].vertices.size(); i3++) {
				NifStream( chunks[i2].vertices[i3], out, info );
			};
			NifStream( chunks[i2].numIndices, out, info );
			for (unsigned int i3 = 0; i3 < chunks[i2].indices.size(); i3++) {
				NifStream( chunks[i2].indices[i3], out, info );
			};
			NifStream( chunks[i2].numStrips, out, info );
			for (unsigned int i3 = 0; i3 < chunks[i2].strips.size(); i3++) {
				NifStream( chunks[i2].strips[i3], out, info );
			};
			NifStream( chunks[i2].numIndices2, out, info );
			for (unsigned int i3 = 0; i3 < chunks[i2].indices2.size(); i3++) {
				NifStream( chunks[i2].indices2[i3], out, info );
			};
		};
	};
	NifStream( unknownInt12, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string bhkCompressedMeshShapeData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numChunks = (unsigned int)(chunks.size());
	numBigTris = (unsigned int)(bigTris.size());
	numBigVerts = (unsigned int)(bigVerts.size());
	numDataSet = (unsigned int)(dataSet1.size());
	numMaterials = (unsigned int)(chunkMaterials.size());
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Unknown Short 1:  " << unknownShort1 << endl;
	out << "  Unknown Short 2:  " << unknownShort2 << endl;
	out << "  Unknown Short 3:  " << unknownShort3 << endl;
	out << "  Unknown Short 4:  " << unknownShort4 << endl;
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Floats 1:  " << unknownFloats1 << endl;
	out << "  Unknown Floats 2:  " << unknownFloats2 << endl;
	out << "  Unknown Byte 1:  " << unknownByte1 << endl;
	out << "  Unknown Int 3:  " << unknownInt3 << endl;
	out << "  Unknown Int 4:  " << unknownInt4 << endl;
	out << "  Unknown Int 5:  " << unknownInt5 << endl;
	out << "  Unknown Byte 2:  " << unknownByte2 << endl;
	out << "  Num Materials:  " << numMaterials << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < chunkMaterials.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Material ID:  " << chunkMaterials[i1].materialId << endl;
		out << "    Unknown Integer:  " << chunkMaterials[i1].unknownInteger << endl;
	};
	out << "  Unknown Int 6:  " << unknownInt6 << endl;
	out << "  Num Data Set:  " << numDataSet << endl;
	out << "  Unknown Int 7:  " << unknownInt7 << endl;
	out << "  Unknown Int 8:  " << unknownInt8 << endl;
	out << "  Unknown Int 9:  " << unknownInt9 << endl;
	if ( (numDataSet >= 1) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < dataSet1.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Unknown Floats 1:  " << dataSet1[i2].unknownFloats1 << endl;
			out << "      Unknown Int 1:  " << dataSet1[i2].unknownInt1 << endl;
		};
	};
	if ( (numDataSet >= 2) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < dataSet2.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Unknown Floats 1:  " << dataSet2[i2].unknownFloats1 << endl;
			out << "      Unknown Int 1:  " << dataSet2[i2].unknownInt1 << endl;
		};
	};
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Num Big Verts:  " << numBigVerts << endl;
	if ( (numBigVerts >= 1) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < bigVerts.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Big Verts[" << i2 << "]:  " << bigVerts[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Num Big Tris:  " << numBigTris << endl;
	if ( (numBigTris >= 1) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < bigTris.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Triangle 1:  " << bigTris[i2].triangle1 << endl;
			out << "      Triangle 2:  " << bigTris[i2].triangle2 << endl;
			out << "      Triangle 3:  " << bigTris[i2].triangle3 << endl;
			out << "      Unknown Int 1:  " << bigTris[i2].unknownInt1 << endl;
			out << "      Unknown Short 1:  " << bigTris[i2].unknownShort1 << endl;
		};
	};
	out << "  Num Chunks:  " << numChunks << endl;
	if ( (numChunks >= 1) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < chunks.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			chunks[i2].numIndices2 = (unsigned int)(chunks[i2].indices2.size());
			chunks[i2].numStrips = (unsigned int)(chunks[i2].strips.size());
			chunks[i2].numIndices = (unsigned int)(chunks[i2].indices.size());
			chunks[i2].numVertices = (unsigned int)(chunks[i2].vertices.size());
			out << "      Unknown Floats 1:  " << chunks[i2].unknownFloats1 << endl;
			out << "      Unknown Floats 2:  " << chunks[i2].unknownFloats2 << endl;
			out << "      Num Vertices:  " << chunks[i2].numVertices << endl;
			array_output_count = 0;
			for (unsigned int i3 = 0; i3 < chunks[i2].vertices.size(); i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Vertices[" << i3 << "]:  " << chunks[i2].vertices[i3] << endl;
				array_output_count++;
			};
			out << "      Num Indices:  " << chunks[i2].numIndices << endl;
			array_output_count = 0;
			for (unsigned int i3 = 0; i3 < chunks[i2].indices.size(); i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Indices[" << i3 << "]:  " << chunks[i2].indices[i3] << endl;
				array_output_count++;
			};
			out << "      Num Strips:  " << chunks[i2].numStrips << endl;
			array_output_count = 0;
			for (unsigned int i3 = 0; i3 < chunks[i2].strips.size(); i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Strips[" << i3 << "]:  " << chunks[i2].strips[i3] << endl;
				array_output_count++;
			};
			out << "      Num Indices 2:  " << chunks[i2].numIndices2 << endl;
			array_output_count = 0;
			for (unsigned int i3 = 0; i3 < chunks[i2].indices2.size(); i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Indices 2[" << i3 << "]:  " << chunks[i2].indices2[i3] << endl;
				array_output_count++;
			};
		};
	};
	out << "  Unknown Int 12:  " << unknownInt12 << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void bhkCompressedMeshShapeData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkCompressedMeshShapeData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

std::list<NiObject *> bhkCompressedMeshShapeData::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiObject::GetPtrs();
	return ptrs;
}

/***Begin Example Naive Implementation****

vector<bhkCMSDData > bhkCompressedMeshShapeData::GetDataSet1() const {
	return dataSet1;
}

void bhkCompressedMeshShapeData::SetDataSet1( const vector<bhkCMSDData >& value ) {
	dataSet1 = value;
}

vector<bhkCMSDData > bhkCompressedMeshShapeData::GetDataSet2() const {
	return dataSet2;
}

void bhkCompressedMeshShapeData::SetDataSet2( const vector<bhkCMSDData >& value ) {
	dataSet2 = value;
}

vector<Vector4 > bhkCompressedMeshShapeData::GetBigVerts() const {
	return bigVerts;
}

void bhkCompressedMeshShapeData::SetBigVerts( const vector<Vector4 >& value ) {
	bigVerts = value;
}

vector<bhkCMSDBigTris > bhkCompressedMeshShapeData::GetBigTris() const {
	return bigTris;
}

void bhkCompressedMeshShapeData::SetBigTris( const vector<bhkCMSDBigTris >& value ) {
	bigTris = value;
}

****End Example Naive Implementation***/

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
