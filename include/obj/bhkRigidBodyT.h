/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#ifndef _BHKRIGIDBODYT_H_
#define _BHKRIGIDBODYT_H_

//--BEGIN FILE HEAD CUSTOM CODE--//
//--END CUSTOM CODE--//

#include "bhkRigidBody.h"
namespace Niflib {

class bhkRigidBodyT;
typedef Ref<bhkRigidBodyT> bhkRigidBodyTRef;

/*! Unknown. */
class bhkRigidBodyT : public bhkRigidBody {
public:
	/*! Constructor */
	NIFLIB_API bhkRigidBodyT();

	/*! Destructor */
	NIFLIB_API virtual ~bhkRigidBodyT();

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

	//--This object has no eligable attributes.  No example implementation generated--//

	//--BEGIN MISC CUSTOM CODE--//
	/*
		// A vector that moves the body by the specified amount. Only enabled in
		// bhkRigidBodyT objects.
		// \return The current value.
		Vector4 GetTranslation() const;

		// A vector that moves the body by the specified amount. Only enabled in
		// bhkRigidBodyT objects.
		// \param[in] value The new value.
		void SetTranslation(const Vector4 & value);

		// The rotation Yaw/Pitch/Roll to apply to the body. Only enabled in bhkRigidBodyT
		// objects.
		// \return The current value.
		QuaternionXYZW GetRotation() const;

		// The rotation Yaw/Pitch/Roll to apply to the body. Only enabled in bhkRigidBodyT
		// objects.
		// \param[in] value The new value.
		void SetRotation(const QuaternionXYZW & value);
	*/

	/*!
	* Gets the current translation of this rigid body.
	* \return The translation of this rigid body.
	*/
	NIFLIB_API Vector4 GetTranslation() const;

	/*!
	* Sets a new translation for this rigid body.
	* \param[in] value  The new translation for this rigid body.
	*/
	NIFLIB_API void SetTranslation(const Vector4 & value);

	/*!
	* Gets the current rotation of this rigid body.
	* \return The rotation of this rigid body.
	*/
	NIFLIB_API QuaternionXYZW GetRotation() const;

	/*!
	* Sets a new rotation for this rigid body.
	* \param[in] value The new rotation for this rigid body.
	*/
	NIFLIB_API void SetRotation(const QuaternionXYZW & value);

	//--END CUSTOM CODE--//
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
