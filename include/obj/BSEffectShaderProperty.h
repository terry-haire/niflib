/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#ifndef _BSEFFECTSHADERPROPERTY_H_
#define _BSEFFECTSHADERPROPERTY_H_

//--BEGIN FILE HEAD CUSTOM CODE--//

//--END CUSTOM CODE--//

#include "NiProperty.h"
namespace Niflib {

class BSEffectShaderProperty;
typedef Ref<BSEffectShaderProperty> BSEffectShaderPropertyRef;

/*! Skyrim non-PP shader model, used primarily for transparency effects. */
class BSEffectShaderProperty : public NiProperty {
public:
	/*! Constructor */
	NIFLIB_API BSEffectShaderProperty();

	/*! Destructor */
	NIFLIB_API virtual ~BSEffectShaderProperty();

	/*!
	 * A constant value which uniquly identifies objects of this type.
	 */
	NIFLIB_API static const Type TYPE;

	/*!
	 * A factory function used during file reading to create an instance of this type of object.
	 * \return A pointer to a newly allocated instance of this type of object.
	 */
	NIFLIB_API static NiObject * Create();

	/*!
	 * Summarizes the information contained in this object in English.
	 * \param[in] verbose Determines whether or not detailed information about large areas of data will be printed out.
	 * \return A string containing a summary of the information within the object in English.  This is the function that Niflyze calls to generate its analysis, so the output is the same.
	 */
	NIFLIB_API virtual string asString( bool verbose = false ) const;

	/*!
	 * Used to determine the type of a particular instance of this object.
	 * \return The type constant for the actual type of the object.
	 */
	NIFLIB_API virtual const Type & GetType() const;

	/***Begin Example Naive Implementation****

	// Unknown.
	// \return The current value.
	SkyrimShaderPropertyFlags1 GetShaderFlags1() const;

	// Unknown.
	// \param[in] value The new value.
	void SetShaderFlags1( const SkyrimShaderPropertyFlags1 & value );

	// Unknown.
	// \return The current value.
	SkyrimShaderPropertyFlags2 GetShaderFlags2() const;

	// Unknown.
	// \param[in] value The new value.
	void SetShaderFlags2( const SkyrimShaderPropertyFlags2 & value );

	// UV OffSet
	// \return The current value.
	TexCoord GetUvOffset() const;

	// UV OffSet
	// \param[in] value The new value.
	void SetUvOffset( const TexCoord & value );

	// UV Scale
	// \return The current value.
	TexCoord GetUvScale() const;

	// UV Scale
	// \param[in] value The new value.
	void SetUvScale( const TexCoord & value );

	// points to an external texture.
	// \return The current value.
	string GetSourceTexture() const;

	// points to an external texture.
	// \param[in] value The new value.
	void SetSourceTexture( const string & value );

	// How to handle texture borders.
	// \return The current value.
	unsigned int GetTextureClampMode() const;

	// How to handle texture borders.
	// \param[in] value The new value.
	void SetTextureClampMode( unsigned int value );

	// Unknown.
	// \return The current value.
	float GetFalloffStartAngle() const;

	// Unknown.
	// \param[in] value The new value.
	void SetFalloffStartAngle( float value );

	// Unknown.
	// \return The current value.
	float GetFalloffStopAngle() const;

	// Unknown.
	// \param[in] value The new value.
	void SetFalloffStopAngle( float value );

	// Texture will fade in within this proximity.
	// \return The current value.
	float GetFalloffStartOpacity() const;

	// Texture will fade in within this proximity.
	// \param[in] value The new value.
	void SetFalloffStartOpacity( float value );

	// Unknown.
	// \return The current value.
	float GetFalloffStopOpacity() const;

	// Unknown.
	// \param[in] value The new value.
	void SetFalloffStopOpacity( float value );

	// Emissive color
	// \return The current value.
	Color4 GetEmissiveColor() const;

	// Emissive color
	// \param[in] value The new value.
	void SetEmissiveColor( const Color4 & value );

	// Multipled Emissive Colors
	// \return The current value.
	float GetEmissiveMultiple() const;

	// Multipled Emissive Colors
	// \param[in] value The new value.
	void SetEmissiveMultiple( float value );

	// Unknown.
	// \return The current value.
	float GetSoftFalloffDepth() const;

	// Unknown.
	// \param[in] value The new value.
	void SetSoftFalloffDepth( float value );

	// points to an external texture.
	// \return The current value.
	string GetGreyscaleTexture() const;

	// points to an external texture.
	// \param[in] value The new value.
	void SetGreyscaleTexture( const string & value );

	****End Example Naive Implementation***/

	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
protected:
	/*! Unknown. */
	SkyrimShaderPropertyFlags1 shaderFlags1;
	/*! Unknown. */
	SkyrimShaderPropertyFlags2 shaderFlags2;
	/*! UV OffSet */
	TexCoord uvOffset;
	/*! UV Scale */
	TexCoord uvScale;
	/*! points to an external texture. */
	string sourceTexture;
	/*! How to handle texture borders. */
	unsigned int textureClampMode;
	/*! Unknown. */
	float falloffStartAngle;
	/*! Unknown. */
	float falloffStopAngle;
	/*! Texture will fade in within this proximity. */
	float falloffStartOpacity;
	/*! Unknown. */
	float falloffStopOpacity;
	/*! Emissive color */
	Color4 emissiveColor;
	/*! Multipled Emissive Colors */
	float emissiveMultiple;
	/*! Unknown. */
	float softFalloffDepth;
	/*! points to an external texture. */
	string greyscaleTexture;
public:
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObject *> GetPtrs() const;
};

//--BEGIN FILE FOOT CUSTOM CODE--//

//--END CUSTOM CODE--//

} //End Niflib namespace
#endif
