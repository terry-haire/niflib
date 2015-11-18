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
#include "../../include/obj/BSTriShape.h"
#include "../../include/gen/BSVertexData.h"
#include "../../include/gen/HalfVector3.h"
#include "../../include/gen/HalfTexCoord.h"
#include "../../include/gen/ByteVector3.h"
#include "../../include/gen/ByteVector3.h"
#include "../../include/gen/ByteColor4.h"
#include "../../include/obj/NiObject.h"
#include "../../include/obj/NiProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSTriShape::TYPE("BSTriShape", &BSShape::TYPE );

BSTriShape::BSTriShape() : skin(NULL), vertexflag1((byte)0), vertexflag2((byte)0), vertexflag3((byte)0), vertexflag4((byte)0), vertexflag5((byte)0), vertexflag6((byte)0), vertexflag7((byte)0), vertexflag8((byte)0), numTriangles((unsigned int)0), numVertices((unsigned short)0), dataSize((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

BSTriShape::~BSTriShape() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & BSTriShape::GetType() const {
	return TYPE;
}

NiObject * BSTriShape::Create() {
	return new BSTriShape;
}

void BSTriShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	BSShape::Read( in, link_stack, info );
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		NifStream( unknown4Floats[i1], in, info );
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	for (unsigned int i1 = 0; i1 < 2; i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( vertexflag1, in, info );
	NifStream( vertexflag2, in, info );
	NifStream( vertexflag3, in, info );
	NifStream( vertexflag4, in, info );
	NifStream( vertexflag5, in, info );
	NifStream( vertexflag6, in, info );
	NifStream( vertexflag7, in, info );
	NifStream( vertexflag8, in, info );
	NifStream( numTriangles, in, info );
	NifStream( numVertices, in, info );
	NifStream( dataSize, in, info );
	if ( (dataSize > 0) ) {
		vertexData.resize(numVertices);
		for (unsigned int i2 = 0; i2 < vertexData.size(); i2++) {
			NifStream( vertexData[i2].vertex.x, in, info );
			NifStream( vertexData[i2].vertex.y, in, info );
			NifStream( vertexData[i2].vertex.z, in, info );
			NifStream( vertexData[i2].unknownDot, in, info );
			if ( (vertexflag1 == 3) ) {
				NifStream( vertexData[i2].unknownInt1, in, info );
			};
			if ( (vertexflag1 > 4) ) {
				NifStream( vertexData[i2].uv.u, in, info );
				NifStream( vertexData[i2].uv.v, in, info );
			};
			if ( ((vertexflag1 > 3) && (vertexflag1 != 7)) ) {
				NifStream( vertexData[i2].normal.x, in, info );
				NifStream( vertexData[i2].normal.y, in, info );
				NifStream( vertexData[i2].normal.z, in, info );
				NifStream( vertexData[i2].unknownByte1, in, info );
				NifStream( vertexData[i2].tangent.x, in, info );
				NifStream( vertexData[i2].tangent.y, in, info );
				NifStream( vertexData[i2].tangent.z, in, info );
				NifStream( vertexData[i2].unknownByte2, in, info );
			};
			if ( ((vertexflag1 == 6) || ((vertexflag1 == 7) || ((vertexflag1 == 9) || (vertexflag1 == 10)))) ) {
				NifStream( vertexData[i2].vertexColors.r, in, info );
				NifStream( vertexData[i2].vertexColors.g, in, info );
				NifStream( vertexData[i2].vertexColors.b, in, info );
				NifStream( vertexData[i2].vertexColors.a, in, info );
			};
			if ( (vertexflag1 > 6) ) {
				for (unsigned int i4 = 0; i4 < 4; i4++) {
					NifStream( vertexData[i2].boneWeights[i4], in, info );
				};
				for (unsigned int i4 = 0; i4 < 4; i4++) {
					NifStream( vertexData[i2].boneIndices[i4], in, info );
				};
			};
			if ( (vertexflag1 == 10) ) {
				NifStream( vertexData[i2].unknownInt2, in, info );
			};
		};
		triangles.resize(numTriangles);
		for (unsigned int i2 = 0; i2 < triangles.size(); i2++) {
			NifStream( triangles[i2], in, info );
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void BSTriShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	BSShape::Write( out, link_map, missing_link_stack, info );
	numVertices = (unsigned short)(vertexData.size());
	numTriangles = (unsigned int)(triangles.size());
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		NifStream( unknown4Floats[i1], out, info );
	};
	if ( info.version < VER_3_3_0_13 ) {
		WritePtr32( &(*skin), out );
	} else {
		if ( skin != NULL ) {
			map<NiObjectRef,unsigned int>::const_iterator it = link_map.find( StaticCast<NiObject>(skin) );
			if (it != link_map.end()) {
				NifStream( it->second, out, info );
				missing_link_stack.push_back( NULL );
			} else {
				NifStream( 0xFFFFFFFF, out, info );
				missing_link_stack.push_back( skin );
			}
		} else {
			NifStream( 0xFFFFFFFF, out, info );
			missing_link_stack.push_back( NULL );
		}
	}
	for (unsigned int i1 = 0; i1 < 2; i1++) {
		if ( info.version < VER_3_3_0_13 ) {
			WritePtr32( &(*bsProperties[i1]), out );
		} else {
			if ( bsProperties[i1] != NULL ) {
				map<NiObjectRef,unsigned int>::const_iterator it = link_map.find( StaticCast<NiObject>(bsProperties[i1]) );
				if (it != link_map.end()) {
					NifStream( it->second, out, info );
					missing_link_stack.push_back( NULL );
				} else {
					NifStream( 0xFFFFFFFF, out, info );
					missing_link_stack.push_back( bsProperties[i1] );
				}
			} else {
				NifStream( 0xFFFFFFFF, out, info );
				missing_link_stack.push_back( NULL );
			}
		}
	};
	NifStream( vertexflag1, out, info );
	NifStream( vertexflag2, out, info );
	NifStream( vertexflag3, out, info );
	NifStream( vertexflag4, out, info );
	NifStream( vertexflag5, out, info );
	NifStream( vertexflag6, out, info );
	NifStream( vertexflag7, out, info );
	NifStream( vertexflag8, out, info );
	NifStream( numTriangles, out, info );
	NifStream( numVertices, out, info );
	NifStream( dataSize, out, info );
	if ( (dataSize > 0) ) {
		for (unsigned int i2 = 0; i2 < vertexData.size(); i2++) {
			NifStream( vertexData[i2].vertex.x, out, info );
			NifStream( vertexData[i2].vertex.y, out, info );
			NifStream( vertexData[i2].vertex.z, out, info );
			NifStream( vertexData[i2].unknownDot, out, info );
			if ( (vertexflag1 == 3) ) {
				NifStream( vertexData[i2].unknownInt1, out, info );
			};
			if ( (vertexflag1 > 4) ) {
				NifStream( vertexData[i2].uv.u, out, info );
				NifStream( vertexData[i2].uv.v, out, info );
			};
			if ( ((vertexflag1 > 3) && (vertexflag1 != 7)) ) {
				NifStream( vertexData[i2].normal.x, out, info );
				NifStream( vertexData[i2].normal.y, out, info );
				NifStream( vertexData[i2].normal.z, out, info );
				NifStream( vertexData[i2].unknownByte1, out, info );
				NifStream( vertexData[i2].tangent.x, out, info );
				NifStream( vertexData[i2].tangent.y, out, info );
				NifStream( vertexData[i2].tangent.z, out, info );
				NifStream( vertexData[i2].unknownByte2, out, info );
			};
			if ( ((vertexflag1 == 6) || ((vertexflag1 == 7) || ((vertexflag1 == 9) || (vertexflag1 == 10)))) ) {
				NifStream( vertexData[i2].vertexColors.r, out, info );
				NifStream( vertexData[i2].vertexColors.g, out, info );
				NifStream( vertexData[i2].vertexColors.b, out, info );
				NifStream( vertexData[i2].vertexColors.a, out, info );
			};
			if ( (vertexflag1 > 6) ) {
				for (unsigned int i4 = 0; i4 < 4; i4++) {
					NifStream( vertexData[i2].boneWeights[i4], out, info );
				};
				for (unsigned int i4 = 0; i4 < 4; i4++) {
					NifStream( vertexData[i2].boneIndices[i4], out, info );
				};
			};
			if ( (vertexflag1 == 10) ) {
				NifStream( vertexData[i2].unknownInt2, out, info );
			};
		};
		for (unsigned int i2 = 0; i2 < triangles.size(); i2++) {
			NifStream( triangles[i2], out, info );
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string BSTriShape::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << BSShape::asString();
	numVertices = (unsigned short)(vertexData.size());
	numTriangles = (unsigned int)(triangles.size());
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown 4 Floats[" << i1 << "]:  " << unknown4Floats[i1] << endl;
		array_output_count++;
	};
	out << "  Skin:  " << skin << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 2; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    BS Properties[" << i1 << "]:  " << bsProperties[i1] << endl;
		array_output_count++;
	};
	out << "  VertexFlag1:  " << vertexflag1 << endl;
	out << "  VertexFlag2:  " << vertexflag2 << endl;
	out << "  VertexFlag3:  " << vertexflag3 << endl;
	out << "  VertexFlag4:  " << vertexflag4 << endl;
	out << "  VertexFlag5:  " << vertexflag5 << endl;
	out << "  VertexFlag6:  " << vertexflag6 << endl;
	out << "  VertexFlag7:  " << vertexflag7 << endl;
	out << "  VertexFlag8:  " << vertexflag8 << endl;
	out << "  Num Triangles:  " << numTriangles << endl;
	out << "  Num Vertices:  " << numVertices << endl;
	out << "  Data Size:  " << dataSize << endl;
	if ( (dataSize > 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < vertexData.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      x:  " << vertexData[i2].vertex.x << endl;
			out << "      y:  " << vertexData[i2].vertex.y << endl;
			out << "      z:  " << vertexData[i2].vertex.z << endl;
			out << "      Unknown Dot:  " << vertexData[i2].unknownDot << endl;
			if ( (vertexflag1 == 3) ) {
				out << "        Unknown Int 1:  " << vertexData[i2].unknownInt1 << endl;
			};
			if ( (vertexflag1 > 4) ) {
				out << "        u:  " << vertexData[i2].uv.u << endl;
				out << "        v:  " << vertexData[i2].uv.v << endl;
			};
			if ( ((vertexflag1 > 3) && (vertexflag1 != 7)) ) {
				out << "        x:  " << vertexData[i2].normal.x << endl;
				out << "        y:  " << vertexData[i2].normal.y << endl;
				out << "        z:  " << vertexData[i2].normal.z << endl;
				out << "        Unknown Byte 1:  " << vertexData[i2].unknownByte1 << endl;
				out << "        x:  " << vertexData[i2].tangent.x << endl;
				out << "        y:  " << vertexData[i2].tangent.y << endl;
				out << "        z:  " << vertexData[i2].tangent.z << endl;
				out << "        Unknown Byte 2:  " << vertexData[i2].unknownByte2 << endl;
			};
			if ( ((vertexflag1 == 6) || ((vertexflag1 == 7) || ((vertexflag1 == 9) || (vertexflag1 == 10)))) ) {
				out << "        r:  " << vertexData[i2].vertexColors.r << endl;
				out << "        g:  " << vertexData[i2].vertexColors.g << endl;
				out << "        b:  " << vertexData[i2].vertexColors.b << endl;
				out << "        a:  " << vertexData[i2].vertexColors.a << endl;
			};
			if ( (vertexflag1 > 6) ) {
				array_output_count = 0;
				for (unsigned int i4 = 0; i4 < 4; i4++) {
					if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
						out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
						break;
					};
					if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
						break;
					};
					out << "          Bone Weights[" << i4 << "]:  " << vertexData[i2].boneWeights[i4] << endl;
					array_output_count++;
				};
				array_output_count = 0;
				for (unsigned int i4 = 0; i4 < 4; i4++) {
					if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
						out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
						break;
					};
					if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
						break;
					};
					out << "          Bone Indices[" << i4 << "]:  " << vertexData[i2].boneIndices[i4] << endl;
					array_output_count++;
				};
			};
			if ( (vertexflag1 == 10) ) {
				out << "        Unknown Int 2:  " << vertexData[i2].unknownInt2 << endl;
			};
		};
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < triangles.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Triangles[" << i2 << "]:  " << triangles[i2] << endl;
			array_output_count++;
		};
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void BSTriShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	BSShape::FixLinks( objects, link_stack, missing_link_stack, info );
	skin = FixLink<NiObject>( objects, link_stack, missing_link_stack, info );
	for (unsigned int i1 = 0; i1 < 2; i1++) {
		bsProperties[i1] = FixLink<NiProperty>( objects, link_stack, missing_link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	// add propertylink1 and propertylink2 to properties so GetProperties continues to function
	if (bsProperties[0] != NULL)
		properties.push_back(bsProperties[0]);
	if (bsProperties[1] != NULL)
		properties.push_back(bsProperties[1]);

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSTriShape::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = BSShape::GetRefs();
	if ( skin != NULL )
		refs.push_back(StaticCast<NiObject>(skin));
	for (unsigned int i1 = 0; i1 < 2; i1++) {
		if ( bsProperties[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(bsProperties[i1]));
	};
	return refs;
}

std::list<NiObject *> BSTriShape::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = BSShape::GetPtrs();
	for (unsigned int i1 = 0; i1 < 2; i1++) {
	};
	return ptrs;
}

/***Begin Example Naive Implementation****

Ref<NiObject > BSTriShape::GetSkin() const {
	return skin;
}

void BSTriShape::SetSkin( Ref<NiObject > value ) {
	skin = value;
}

array<2,Ref<NiProperty > >  BSTriShape::GetBsProperties() const {
	return bsProperties;
}

void BSTriShape::SetBsProperties( const array<2,Ref<NiProperty > >&  value ) {
	bsProperties = value;
}

byte BSTriShape::GetVertexflag1() const {
	return vertexflag1;
}

void BSTriShape::SetVertexflag1( byte value ) {
	vertexflag1 = value;
}

byte BSTriShape::GetVertexflag2() const {
	return vertexflag2;
}

void BSTriShape::SetVertexflag2( byte value ) {
	vertexflag2 = value;
}

byte BSTriShape::GetVertexflag3() const {
	return vertexflag3;
}

void BSTriShape::SetVertexflag3( byte value ) {
	vertexflag3 = value;
}

byte BSTriShape::GetVertexflag4() const {
	return vertexflag4;
}

void BSTriShape::SetVertexflag4( byte value ) {
	vertexflag4 = value;
}

byte BSTriShape::GetVertexflag5() const {
	return vertexflag5;
}

void BSTriShape::SetVertexflag5( byte value ) {
	vertexflag5 = value;
}

byte BSTriShape::GetVertexflag6() const {
	return vertexflag6;
}

void BSTriShape::SetVertexflag6( byte value ) {
	vertexflag6 = value;
}

byte BSTriShape::GetVertexflag7() const {
	return vertexflag7;
}

void BSTriShape::SetVertexflag7( byte value ) {
	vertexflag7 = value;
}

byte BSTriShape::GetVertexflag8() const {
	return vertexflag8;
}

void BSTriShape::SetVertexflag8( byte value ) {
	vertexflag8 = value;
}

unsigned int BSTriShape::GetDataSize() const {
	return dataSize;
}

void BSTriShape::SetDataSize( unsigned int value ) {
	dataSize = value;
}

vector<BSVertexData > BSTriShape::GetVertexData() const {
	return vertexData;
}

void BSTriShape::SetVertexData( const vector<BSVertexData >& value ) {
	vertexData = value;
}

vector<Triangle > BSTriShape::GetTriangles() const {
	return triangles;
}

void BSTriShape::SetTriangles( const vector<Triangle >& value ) {
	triangles = value;
}

****End Example Naive Implementation***/

//--BEGIN MISC CUSTOM CODE--//


int BSTriShape::GetVertexCount() const {
	return int(vertexData.size());
}

Vector3 BSTriShape::GetCenter() const
{
	return Vector3();
}

float BSTriShape::GetRadius() const
{
	return 1.0f;
}

vector<Vector3> BSTriShape::GetVertices() const {
	vector<Vector3> vertices;
	vertices.reserve(vertexData.size());
	for (vector<BSVertexData>::const_iterator itr = vertexData.begin(); itr != vertexData.end(); ++itr)	{
		vertices.push_back(Vector3(ConvertHFloatToFloat(itr->vertex.x),
			ConvertHFloatToFloat(itr->vertex.y), ConvertHFloatToFloat(itr->vertex.z)));
	}
	return vertices;
}

vector<Vector3> BSTriShape::GetNormals() const {
	vector<Vector3> normals;
	return normals;
}

bool BSTriShape::HasColors() const {
	return (((vertexflag1 == 7) || ((vertexflag1 == 9) || (vertexflag1 == 10))));
}

static inline float ConvertByteToFloat(byte value) {
	//return float(value) * 2.0f / 255.0f - 1.0f;
	return float(value)  * 255.0f / 128.0f - 1.0f;
}

vector<Color4> BSTriShape::GetColors() const {
	vector<Color4> vertexColors;
	vertexColors.reserve(vertexData.size());
	for (vector<BSVertexData>::const_iterator itr = vertexData.begin(); itr != vertexData.end(); ++itr) {
		vertexColors.push_back(Color4(ConvertByteToFloat(itr->vertexColors.r), ConvertByteToFloat(itr->vertexColors.b),
			ConvertByteToFloat(itr->vertexColors.g), ConvertByteToFloat(itr->vertexColors.a)));
	}
	return vertexColors;
}

vector<TexCoord> BSTriShape::GetUVSet() const {
	vector<TexCoord> tcs;
	tcs.reserve(vertexData.size());
	for (vector<BSVertexData>::const_iterator itr = vertexData.begin(); itr != vertexData.end(); ++itr) {
		tcs.push_back(TexCoord(ConvertHFloatToFloat(itr->uv.u),ConvertHFloatToFloat(itr->uv.v)));
	}
	return tcs;
}

bool BSTriShape::HasNormals() const
{
	return (((vertexflag1 > 3) && ((vertexflag1 != 6) && (vertexflag1 != 7))));
}

vector<Vector3> BSTriShape::GetBitangents() const
{
	vector<Vector3> bt;
	return bt;
}

vector<Vector3> BSTriShape::GetTangents() const
{
	vector<Vector3> tangents;
	tangents.reserve(vertexData.size());
	for (vector<BSVertexData>::const_iterator itr = vertexData.begin(); itr != vertexData.end(); ++itr) {
		tangents.push_back(Vector3(ConvertByteToFloat(itr->tangent.x), ConvertByteToFloat(itr->tangent.y),
			ConvertByteToFloat(itr->tangent.z)));
	}
	return tangents;
}

// Do we have bone weights?
// \return Whether skinning data is present
bool BSTriShape::HasSkin() const {
	return (vertexflag1 >= 6);
}

Ref<NiObject > BSTriShape::GetSkin() const {
	return skin;
}

void BSTriShape::SetSkin(Ref<NiObject > value) {
	skin = value;
}

int BSTriShape::GetBoneWeights(unsigned int vertexIdx, float weights[4], int bones[4]) const {
	if (vertexIdx < 0 || vertexIdx >= vertexData.size()) return 0;
	const auto& vert = vertexData[vertexIdx];
	for (int i = 0; i < 4; ++i )
	{
		if (vert.boneIndices[i] == 0 && vert.boneWeights[i] == 0) return i;
		bones[i] = vert.boneIndices[i];
		weights[i] = ConvertHFloatToFloat(vert.boneWeights[i]);
	}
	return 4;
}

// Unknown.
// \return The current value.
const vector<BSVertexData>& BSTriShape::GetVertexData() const {
	return vertexData;
}

// Unknown.
// \param[in] value The new value.
void BSTriShape::SetVertexData(const vector<BSVertexData >& value) {
	vertexData = value;
}

// Unknown.
// \return The current value.
const vector<Triangle>& BSTriShape::GetTriangles() const {
	return triangles;
}

// Unknown.
// \param[in] value The new value.
void BSTriShape::SetTriangles(const vector<Triangle >& value) {
	triangles = value;
}




//--END CUSTOM CODE--//
