/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#ifndef _BSLIGHTINGSHADERPROPERTY_H_
#define _BSLIGHTINGSHADERPROPERTY_H_

//--BEGIN FILE HEAD CUSTOM CODE--//

//--END CUSTOM CODE--//

#include "NiProperty.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class BSShaderTextureSet;
class BSLightingShaderProperty;
typedef Ref<BSLightingShaderProperty> BSLightingShaderPropertyRef;

/*!
 * Bethesda-specific node, used in Skyrim to configure material/shader/texture
 * properties.
 */
class BSLightingShaderProperty : public NiProperty {
public:
	/*! Constructor */
	NIFLIB_API BSLightingShaderProperty();

	/*! Destructor */
	NIFLIB_API virtual ~BSLightingShaderProperty();

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

	// Skyrim Shader Flag field 1 (will use SkyrimLightingShaderFlags1)
	// \return The current value.
	unsigned int GetShaderFlags1() const;

	// Skyrim Shader Flag field 1 (will use SkyrimLightingShaderFlags1)
	// \param[in] value The new value.
	void SetShaderFlags1( unsigned int value );

	// Skyrim Shader Flag field 2 (will use SkyrimLightingShaderFlags2)
	// \return The current value.
	unsigned int GetShaderFlags2() const;

	// Skyrim Shader Flag field 2 (will use SkyrimLightingShaderFlags2)
	// \param[in] value The new value.
	void SetShaderFlags2( unsigned int value );

	// Offset UVs
	// \return The current value.
	TexCoord GetTextureTranslation1() const;

	// Offset UVs
	// \param[in] value The new value.
	void SetTextureTranslation1( const TexCoord & value );

	// Offset UVs
	// \return The current value.
	TexCoord GetTextureRepeat() const;

	// Offset UVs
	// \param[in] value The new value.
	void SetTextureRepeat( const TexCoord & value );

	// Texture Set
	// \return The current value.
	Ref<BSShaderTextureSet > GetTextureSet() const;

	// Texture Set
	// \param[in] value The new value.
	void SetTextureSet( Ref<BSShaderTextureSet > value );

	// Glow color and alpha
	// \return The current value.
	Color3 GetEmissiveColor() const;

	// Glow color and alpha
	// \param[in] value The new value.
	void SetEmissiveColor( const Color3 & value );

	// Unknown
	// \return The current value.
	float GetEmissiveSaturation() const;

	// Unknown
	// \param[in] value The new value.
	void SetEmissiveSaturation( float value );

	// The material transparency (1=non-transparent).
	// \return The current value.
	float GetAlpha() const;

	// The material transparency (1=non-transparent).
	// \param[in] value The new value.
	void SetAlpha( float value );

	// The material's glossiness. (0-999)
	// \return The current value.
	float GetGlossiness() const;

	// The material's glossiness. (0-999)
	// \param[in] value The new value.
	void SetGlossiness( float value );

	// Adds a colored highlight.
	// \return The current value.
	Color3 GetSpecularColor() const;

	// Adds a colored highlight.
	// \param[in] value The new value.
	void SetSpecularColor( const Color3 & value );

	// Brightness of specular highlight. (0=not visible) (0-999)
	// \return The current value.
	float GetSpecularStrength() const;

	// Brightness of specular highlight. (0=not visible) (0-999)
	// \param[in] value The new value.
	void SetSpecularStrength( float value );

	// Unknown, related to backlight/rim/softlight effect
	// \return The current value.
	float GetLightingEffect1() const;

	// Unknown, related to backlight/rim/softlight effect
	// \param[in] value The new value.
	void SetLightingEffect1( float value );

	// Unknown, related to backlight/rim/softlight effect
	// \return The current value.
	float GetLightingEffect2() const;

	// Unknown, related to backlight/rim/softlight effect
	// \param[in] value The new value.
	void SetLightingEffect2( float value );

	// How strong the environment/cube map is. (0-??)
	// \return The current value.
	float GetEnvironmentMapStrength() const;

	// How strong the environment/cube map is. (0-??)
	// \param[in] value The new value.
	void SetEnvironmentMapStrength( float value );

	// Eye(Skyrim)
	// \return The current value.
	float GetEyeCubemapScale() const;

	// Eye(Skyrim)
	// \param[in] value The new value.
	void SetEyeCubemapScale( float value );

	// Eye(Skyrim)Left Unknown
	// \return The current value.
	Vector3 GetLeftEyeReflectionCenter() const;

	// Eye(Skyrim)Left Unknown
	// \param[in] value The new value.
	void SetLeftEyeReflectionCenter( const Vector3 & value );

	// Eye(Skyrim)Right Unknown
	// \return The current value.
	Vector3 GetRightEyeReflectionCenter() const;

	// Eye(Skyrim)Right Unknown
	// \param[in] value The new value.
	void SetRightEyeReflectionCenter( const Vector3 & value );

	****End Example Naive Implementation***/

	//--BEGIN MISC CUSTOM CODE--//

	// Skyrim's shaders: 0=default 1=EnvMap, 2=Glow, 5=Skin, 6=Hair, 7=Unknown,
	// 11=Ice/Parallax, 15=Eye.
	// \return The current value.
	int GetSkyrimShaderType() const;

	// Skyrim's shaders: 0=default 1=EnvMap, 2=Glow, 5=Skin, 6=Hair, 7=Unknown,
	// 11=Ice/Parallax, 15=Eye.
	// \param[in] value The new value.
	void SetSkyrimShaderType( int value );


	// Skyrim Shader Flag field 1 (will use SkyrimLightingShaderFlags1)
	// \return The current value.
	unsigned int GetShaderFlags1() const;

	// Skyrim Shader Flag field 1 (will use SkyrimLightingShaderFlags1)
	// \param[in] value The new value.
	void SetShaderFlags1( unsigned int value );

	// Skyrim Shader Flag field 2 (will use SkyrimLightingShaderFlags2)
	// \return The current value.
	unsigned int GetShaderFlags2() const;

	// Skyrim Shader Flag field 2 (will use SkyrimLightingShaderFlags2)
	// \param[in] value The new value.
	void SetShaderFlags2( unsigned int value );

	// Offset UVs
	// \return The current value.
	TexCoord GetTextureTranslation1() const;

	// Offset UVs
	// \param[in] value The new value.
	void SetTextureTranslation1( const TexCoord & value );

	// Offset UVs
	// \return The current value.
	TexCoord GetTextureRepeat() const;

	// Offset UVs
	// \param[in] value The new value.
	void SetTextureRepeat( const TexCoord & value );

	// Texture Set
	// \return The current value.
	Ref<BSShaderTextureSet > GetTextureSet() const;

	// Texture Set
	// \param[in] value The new value.
	void SetTextureSet( Ref<BSShaderTextureSet > value );

	// Glow color and alpha
	// \return The current value.
	Color3 GetEmissiveColor() const;

	// Glow color and alpha
	// \param[in] value The new value.
	void SetEmissiveColor( const Color3 & value );

	// Unknown
	// \return The current value.
	float GetEmissiveSaturation() const;

	// Unknown
	// \param[in] value The new value.
	void SetEmissiveSaturation( float value );

	// The material transparency (1=non-transparent).
	// \return The current value.
	float GetAlpha() const;

	// The material transparency (1=non-transparent).
	// \param[in] value The new value.
	void SetAlpha( float value );

	// The material's glossiness. (0-999)
	// \return The current value.
	float GetGlossiness() const;

	// The material's glossiness. (0-999)
	// \param[in] value The new value.
	void SetGlossiness( float value );

	// Adds a colored highlight.
	// \return The current value.
	Color3 GetSpecularColor() const;

	// Adds a colored highlight.
	// \param[in] value The new value.
	void SetSpecularColor( const Color3 & value );

	// Brightness of specular highlight. (0=not visible) (0-999)
	// \return The current value.
	float GetSpecularStrength() const;

	// Brightness of specular highlight. (0=not visible) (0-999)
	// \param[in] value The new value.
	void SetSpecularStrength( float value );

	// Unknown, related to backlight/rim/softlight effect
	// \return The current value.
	float GetLightingEffect1() const;

	// Unknown, related to backlight/rim/softlight effect
	// \param[in] value The new value.
	void SetLightingEffect1( float value );

	// Unknown, related to backlight/rim/softlight effect
	// \return The current value.
	float GetLightingEffect2() const;

	// Unknown, related to backlight/rim/softlight effect
	// \param[in] value The new value.
	void SetLightingEffect2( float value );

	// How strong the environment/cube map is. (0-??)
	// \return The current value.
	float GetEnvironmentMapStrength() const;

	// How strong the environment/cube map is. (0-??)
	// \param[in] value The new value.
	void SetEnvironmentMapStrength( float value );

	// Eye(Skyrim)
	// \return The current value.
	float GetEyeCubemapScale() const;

	// Eye(Skyrim)
	// \param[in] value The new value.
	void SetEyeCubemapScale( float value );

	// Eye(Skyrim)Left Unknown
	// \return The current value.
	Vector3 GetLeftEyeReflectionCenter() const;

	// Eye(Skyrim)Left Unknown
	// \param[in] value The new value.
	void SetLeftEyeReflectionCenter( const Vector3 & value );

	// Eye(Skyrim)Right Unknown
	// \return The current value.
	Vector3 GetRightEyeReflectionCenter() const;

	// Eye(Skyrim)Right Unknown
	// \param[in] value The new value.
	void SetRightEyeReflectionCenter( const Vector3 & value );

	//--END CUSTOM CODE--//
protected:
	/*! Skyrim Shader Flag field 1 (will use SkyrimLightingShaderFlags1) */
	unsigned int shaderFlags1;
	/*! Skyrim Shader Flag field 2 (will use SkyrimLightingShaderFlags2) */
	unsigned int shaderFlags2;
	/*! Offset UVs */
	TexCoord textureTranslation1;
	/*! Offset UVs */
	TexCoord textureRepeat;
	/*! Texture Set */
	Ref<BSShaderTextureSet > textureSet;
	/*! Glow color and alpha */
	Color3 emissiveColor;
	/*! Unknown */
	float emissiveSaturation;
	/*! Unknown, always 3? */
	unsigned int unknownInt7;
	/*! The material transparency (1=non-transparent). */
	float alpha;
	/*! Unknown */
	float unknownFloat2;
	/*! The material's glossiness. (0-999) */
	float glossiness;
	/*! Adds a colored highlight. */
	Color3 specularColor;
	/*! Brightness of specular highlight. (0=not visible) (0-999) */
	float specularStrength;
	/*! Unknown, related to backlight/rim/softlight effect */
	float lightingEffect1;
	/*! Unknown, related to backlight/rim/softlight effect */
	float lightingEffect2;
	/*! How strong the environment/cube map is. (0-??) */
	float environmentMapStrength;
	/*! Unknown, related to skin */
	Vector3 unknownFloatSet1;
	/*! Unknown, related to hair */
	Color3 unknownColor1;
	/*! Unknown */
	array<2,float > unknownFloatSet3;
	/*! Unknown, related to ice or parallax */
	float unknownFloat9;
	/*! Unknown, related to ice parallax */
	Color4 unknownColor2;
	/*! Unknown, also related to ice? */
	Vector4 unknownFloatSet5;
	/*! Eye(Skyrim) */
	float eyeCubemapScale;
	/*! Eye(Skyrim)Left Unknown */
	Vector3 leftEyeReflectionCenter;
	/*! Eye(Skyrim)Right Unknown */
	Vector3 rightEyeReflectionCenter;
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
