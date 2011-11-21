/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#ifndef _BSPROCEDURALLIGHTNINGCONTROLLER_H_
#define _BSPROCEDURALLIGHTNINGCONTROLLER_H_

//--BEGIN FILE HEAD CUSTOM CODE--//

//--END CUSTOM CODE--//

#include "NiFloatInterpController.h"
namespace Niflib {

class BSProceduralLightningController;
typedef Ref<BSProceduralLightningController> BSProceduralLightningControllerRef;

/*!  */
class BSProceduralLightningController : public NiFloatInterpController {
public:
	/*! Constructor */
	NIFLIB_API BSProceduralLightningController();

	/*! Destructor */
	NIFLIB_API virtual ~BSProceduralLightningController();

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

	// Unknown
	// \return The current value.
	unsigned int GetTarget___() const;

	// Unknown
	// \param[in] value The new value.
	void SetTarget___( unsigned int value );

	// Unknown
	// \return The current value.
	unsigned int GetTarget___1() const;

	// Unknown
	// \param[in] value The new value.
	void SetTarget___1( unsigned int value );

	// Unknown
	// \return The current value.
	unsigned int GetTarget___2() const;

	// Unknown
	// \param[in] value The new value.
	void SetTarget___2( unsigned int value );

	// Unknown
	// \return The current value.
	unsigned int GetTarget___3() const;

	// Unknown
	// \param[in] value The new value.
	void SetTarget___3( unsigned int value );

	// Unknown
	// \return The current value.
	unsigned int GetTarget___4() const;

	// Unknown
	// \param[in] value The new value.
	void SetTarget___4( unsigned int value );

	// Unknown
	// \return The current value.
	unsigned int GetTarget___5() const;

	// Unknown
	// \param[in] value The new value.
	void SetTarget___5( unsigned int value );

	// Unknown
	// \return The current value.
	unsigned int GetTarget___6() const;

	// Unknown
	// \param[in] value The new value.
	void SetTarget___6( unsigned int value );

	// Unknown
	// \return The current value.
	unsigned int GetTarget___7() const;

	// Unknown
	// \param[in] value The new value.
	void SetTarget___7( unsigned int value );

	// Unknown
	// \return The current value.
	float GetFloat1() const;

	// Unknown
	// \param[in] value The new value.
	void SetFloat1( float value );

	// Unknown
	// \return The current value.
	float GetFloat2() const;

	// Unknown
	// \param[in] value The new value.
	void SetFloat2( float value );

	// Unknown
	// \return The current value.
	float GetFloat3() const;

	// Unknown
	// \param[in] value The new value.
	void SetFloat3( float value );

	// Unknown
	// \return The current value.
	float GetFloat4() const;

	// Unknown
	// \param[in] value The new value.
	void SetFloat4( float value );

	// Unknown
	// \return The current value.
	float GetFloat5() const;

	// Unknown
	// \param[in] value The new value.
	void SetFloat5( float value );

	// Unknown
	// \return The current value.
	byte GetByte1() const;

	// Unknown
	// \param[in] value The new value.
	void SetByte1( byte value );

	// Unknown
	// \return The current value.
	byte GetByte2() const;

	// Unknown
	// \param[in] value The new value.
	void SetByte2( byte value );

	// Unknown
	// \return The current value.
	byte GetByte3() const;

	// Unknown
	// \param[in] value The new value.
	void SetByte3( byte value );

	// Unknown
	// \return The current value.
	unsigned int GetTarget___8() const;

	// Unknown
	// \param[in] value The new value.
	void SetTarget___8( unsigned int value );

	****End Example Naive Implementation***/

	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
protected:
	/*! Unknown */
	unsigned int target___;
	/*! Unknown */
	unsigned int target___1;
	/*! Unknown */
	unsigned int target___2;
	/*! Unknown */
	unsigned int target___3;
	/*! Unknown */
	unsigned int target___4;
	/*! Unknown */
	unsigned int target___5;
	/*! Unknown */
	unsigned int target___6;
	/*! Unknown */
	unsigned int target___7;
	/*! Unknown */
	unsigned short unknownShort1;
	/*! Unknown */
	unsigned short unknownShort2;
	/*! Unknown */
	unsigned short unknownShort3;
	/*! Unknown */
	float float1;
	/*! Unknown */
	float float2;
	/*! Unknown */
	float float3;
	/*! Unknown */
	float float4;
	/*! Unknown */
	float float5;
	/*! Unknown */
	byte byte1;
	/*! Unknown */
	byte byte2;
	/*! Unknown */
	byte byte3;
	/*! Unknown */
	unsigned int target___8;
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
