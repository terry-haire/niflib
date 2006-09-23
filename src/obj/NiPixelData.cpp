/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPixelData.h"
#include "../../include/gen/MipMap.h"
#include "../../include/gen/ByteArray.h"
#include "../../include/obj/NiPalette.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPixelData::TYPE("NiPixelData", &NI_PIXEL_DATA_PARENT::TypeConst() );

NiPixelData::NiPixelData() NI_PIXEL_DATA_CONSTRUCT {}

NiPixelData::~NiPixelData() {}

void NiPixelData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPixelData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPixelData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPixelData::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPixelData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPixelData::GetType() const {
	return TYPE;
};

int NiPixelData::GetHeight() const {
	if ( mipmaps.size() == 0 ) {
		return 0;
	} else {
		return mipmaps[0].height;
	}
}

int NiPixelData::GetWidth() const {
	if (mipmaps.size() == 0 ) {
		return 0;
	} else {
		return mipmaps[0].width;
	}
}

PixelFormat NiPixelData::GetPixelFormat() const {
	return pixelFormat;
}

void NiPixelData::Reset( int new_width, int new_height, PixelFormat px_fmt ) {
	//Ensure that texture dimentions are powers of two
	if ( (new_height & (new_height-1)) != 0 ) {
		throw runtime_error("Texture height must be a power of two.  1, 2, 4, 8, 16, 32, 64, 256, 512, etc.");
	}

	if ( (new_width & (new_width-1)) != 0 ) {
		throw runtime_error("Texture width must be a power of two.  1, 2, 4, 8, 16, 32, 64, 256, 512, etc.");
	}
	
	//Delete any data that was previously held
	pixelData.data.clear();
	//if ( pixelData.data != NULL ) {
	//	delete [] pixelData.data;
	//	pixelData.data = NULL;
	//	pixelData.dataSize = 0;
	//}

	//pixelData.dataSize = 0;
	mipmaps.resize(1);


	//Set up first mipmap
	mipmaps[0].width = new_width;
	mipmaps[0].height = new_height;
	mipmaps[0].offset = 0;

	//Set up pixel format fields
	pixelFormat = px_fmt;
	switch(pixelFormat) {
		case PX_FMT_RGB8:
			redMask    = 0x000000FF;
			greenMask  = 0x0000FF00;
			blueMask   = 0x00FF0000;
			alphaMask  = 0x00000000;
			bitsPerPixel = 24;
			unknown8Bytes[0] = 96;
			unknown8Bytes[1] = 8;
			unknown8Bytes[2] = 130;
			unknown8Bytes[3] = 0;
			unknown8Bytes[4] = 0;
			unknown8Bytes[5] = 65;
			unknown8Bytes[6] = 0;
			unknown8Bytes[7] = 0;
			break;
		case PX_FMT_RGBA8 :
			redMask    = 0x000000FF;
			greenMask  = 0x0000FF00;
			blueMask   = 0x00FF0000;
			alphaMask  = 0xFF000000;
			bitsPerPixel = 32;
			unknown8Bytes[0] = 129;
			unknown8Bytes[1] = 8;
			unknown8Bytes[2] = 130;
			unknown8Bytes[3] = 32;
			unknown8Bytes[4] = 0;
			unknown8Bytes[5] = 65;
			unknown8Bytes[6] = 12;
			unknown8Bytes[7] = 0;
			break;	
		case PX_FMT_PAL8 :
			redMask   = 0x00000000;
			blueMask  = 0x00000000;
			greenMask = 0x00000000;
			alphaMask = 0x00000000;
			bitsPerPixel = 8;
			unknown8Bytes[0] = 34;
			unknown8Bytes[1] = 0;
			unknown8Bytes[2] = 0;
			unknown8Bytes[3] = 32;
			unknown8Bytes[4] = 0;
			unknown8Bytes[5] = 65;
			unknown8Bytes[6] = 12;
			unknown8Bytes[7] = 0;
			break;	
		//[4,0,0,0,0,0,0,0] if 0 (?) bits per pixel
		default:
			throw runtime_error("The pixel type you have requested is not currently supported.");
	}
}

vector<Color4> NiPixelData::GetColors() const {
	vector<Color4> pixels;

	if ( mipmaps.size() == 0 ) {
		//Return empty vector
		return pixels;
	}

	//Pack the pixel data from the first mipmap into a vector of
	//Color4 based on the pixel format.
	pixels.resize( mipmaps[0].width * mipmaps[0].height );
	switch(pixelFormat) {
		case PX_FMT_RGB8:
			for ( uint i = 0; i < pixels.size(); ++i ) {
				pixels[i].r = float(pixelData.data[i * 3]) / 255.0f;
				pixels[i].g = float(pixelData.data[i * 3 + 1]) / 255.0f;
				pixels[i].b = float(pixelData.data[i * 3 + 2]) / 255.0f;
				pixels[i].a = 1.0f;
			}
			break;
		case PX_FMT_RGBA8:
			for ( uint i = 0; i < pixels.size(); ++i ) {
				pixels[i].r = float(pixelData.data[i * 4]) / 255.0f;
				pixels[i].g = float(pixelData.data[i * 4 + 1]) / 255.0f;
				pixels[i].b = float(pixelData.data[i * 4 + 2]) / 255.0f;
				pixels[i].a = float(pixelData.data[i * 4 + 3]) / 255.0f;
			}
			break;
		default:
			throw runtime_error("The GetColors function only supports the PX_FMT_RGB8 and PX_FMT_RGBA8 pixel formats.");
	}

#ifdef IM_DEBUG

	imdebug("rgba b=32f rs=2 w=%d h=%d %p", mipmaps[0].width, mipmaps[0].height, &pixels[0] );
	//delete [] img;
	cout << "Showing image returned by GetColors function." << endl;
	cin.get();
#endif

	return pixels;
}

void NiPixelData::SetColors( const vector<Color4> & new_pixels, bool generate_mipmaps ) {
	//Ensure that compatible pixel format is being used
	if ( pixelFormat != PX_FMT_RGB8 && pixelFormat != PX_FMT_RGBA8 ) {
		throw runtime_error("The SetColors function only supports the PX_FMT_RGB8 and PX_FMT_RGBA8 pixel formats.");
	}

	//Ensure that there is size information in the mipmaps
	if ( mipmaps.size() == 0 ) {
		throw runtime_error("The size informatoin has not been set.  Call the IPixelData::Reset() function first.");
	}

	//Ensure that the right number of pixels for the dimentions set have been passed
	if ( new_pixels.size() != mipmaps[0].height * mipmaps[0].width ) {
		throw runtime_error("You must pass one color for every pixel in the image.  There should be height * width colors.");
	}

	uint size = 0;
	mipmaps.resize(1);
	size = (mipmaps[0].height * mipmaps[0].width * bitsPerPixel) / 8;

	//Deal with multiple mipmaps
	if ( generate_mipmaps == true ) {
		MipMap m;
		m.height = mipmaps[0].height;
		m.width = mipmaps[0].width;

		size = (mipmaps[0].height * mipmaps[0].width * bitsPerPixel) / 8;

		while ( m.width != 1 && m.height != 1 ) {
			////cout << "Width:  " << m.width << "  Height:  " << m.height << "  Offset:  " << m.offset << endl;
			m.width /= 2;
			m.height /= 2;
			m.offset = size;

			size += (m.height * m.width * bitsPerPixel) / 8;

			mipmaps.push_back(m);
		}
	}

	//Allocate space to store mipmaps
	//if ( pixelData.data != NULL ) {
	//	delete [] pixelData.data;
	//}

	//pixelData.dataSize = size * bitsPerPixel / 8;
	//pixelData.data = new byte[pixelData.dataSize];

	pixelData.data.resize( size * bitsPerPixel / 8 );

	//Copy pixels to Color4 C array
	Color4 * tmp_image = new Color4[new_pixels.size()];

	for (uint i = 0; i < new_pixels.size(); ++i ) {
		tmp_image[i] = new_pixels[i];
	}

	//Pack pixel data
	for (uint i = 0; i < mipmaps.size(); ++i ) {
		cout << "Width:  " << mipmaps[i].width << "  Height:  " << mipmaps[i].height << "  Offset:  " << mipmaps[i].offset << endl;

		if ( i > 0 ) {
			//Allocate space to store re-sized image.
			Color4 * resized = new Color4[ mipmaps[i].width * mipmaps[i].height ];

			//Visit every other pixel in each row and column of the previous image
			for ( uint w = 0; w < mipmaps[i-1].width; w+=2 ) {
				for ( uint h = 0; h < mipmaps[i-1].height; h+=2 ) {
					//cout << "w:  " << w << "  h:  " << h << endl;
					Color4 & av = resized[(h/2) * mipmaps[i].width + (w/2)];

					//Start with the value of the current pixel
					av = tmp_image[h * mipmaps[i-1].width + w];
					float num_colors = 1.0f;

					//Only process the pixel above if height is > 1
					if ( h > 1 ) {
						Color4 & px = tmp_image[(h+1) * mipmaps[i-1].width + w];
						av.r += px.r;
						av.g += px.g;
						av.b += px.b;
						av.a += px.a;
						num_colors += 1.0f;
					}

					//Only process the pixel to the right if width > 1
					if (w > 1 ) {
						Color4 & px = tmp_image[h * mipmaps[i-1].width + (w+1)];
						av.r += px.r;
						av.g += px.g;
						av.b += px.b;
						av.a += px.a;
						num_colors += 1.0f;
					}

					//Only process the pixel to the upper right if both width and height are > 1
					if ( w > 1 && h >> 1 ) {
						Color4 & px = tmp_image[(h+1) * mipmaps[i-1].width + (w+1)];
						av.r += px.r;
						av.g += px.g;
						av.b += px.b;
						av.a += px.a;
						num_colors += 1.0f;
					}

					//Calculate average
					av.r /= num_colors;
					av.g /= num_colors;
					av.b /= num_colors;
					av.a /= num_colors;
				}
			}
			//Resize is complete, set result to tmp_image

			//delete old tmp_image data
			delete [] tmp_image;

			//Adjust pointer values
			tmp_image = resized;
			resized = NULL;
		}

		//Data is ready to be packed into the byes of this mipmap

		#ifdef IM_DEBUG
			cout << "Showing mipmap size " << mipmaps[i].width << " x " << mipmaps[i].height << "." << endl;
			imdebug("rgba b=32f w=%d h=%d %p", mipmaps[i].width, mipmaps[i].height, &tmp_image[0] );
			cin.get();
		#endif

		//Start at offset
		byte * map = &pixelData.data[mipmaps[i].offset];

		switch(pixelFormat) {
		case PX_FMT_RGB8:
			for ( uint j = 0; j < mipmaps[i].width * mipmaps[i].height; ++j ) {
				map[j * 3] = int( tmp_image[j].r * 255.0f );
				map[j * 3 + 1] = int( tmp_image[j].g * 255.0f );
				map[j * 3 + 2] = int( tmp_image[j].b * 255.0f );
			}

			//#ifdef IM_DEBUG
			//	cout << "Showing mipmap after being packed  - size " << mipmaps[i].width << " x " << mipmaps[i].height << "." << endl;
			//	imdebug("rgb w=%d h=%d %p", mipmaps[i].width, mipmaps[i].height, &map[0] );
			//	cin.get();
			//#endif
			break;
		case PX_FMT_RGBA8:
			for ( uint j = 0; j < mipmaps[i].width * mipmaps[i].height; ++j ) {
				map[j * 4] = int( tmp_image[j].r * 255.0f );
				map[j * 4 + 1] = int( tmp_image[j].g * 255.0f );
				map[j * 4 + 2] = int( tmp_image[j].b * 255.0f );
				map[j * 4 + 3] = int( tmp_image[j].a * 255.0f );
			}

			//#ifdef IM_DEBUG
			//	cout << "Showing mipmap after being packed  - size " << mipmaps[i].width << " x " << mipmaps[i].height << "." << endl;
			//	imdebug("rgba w=%d h=%d %p", mipmaps[i].width, mipmaps[i].height, &map[0] );
			//	cin.get();
			//#endif
			break;
		case PX_FMT_PAL8:
			throw runtime_error("The SetColors function only supports the PX_FMT_RGB8 and PX_FMT_RGBA8 pixel formats.");
			break;
		}
	}
}