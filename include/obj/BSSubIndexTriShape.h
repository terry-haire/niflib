/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#ifndef _BSSUBINDEXTRISHAPE_H_
#define _BSSUBINDEXTRISHAPE_H_

//--BEGIN FILE HEAD CUSTOM CODE--//

//--END CUSTOM CODE--//

#include "BSTriShape.h"

// Include structures
#include "../gen/SubIndexPart1.h"
#include "../gen/SubIndexPart2.h"
namespace Niflib {

class BSSubIndexTriShape;
typedef Ref<BSSubIndexTriShape> BSSubIndexTriShapeRef;

/*! Fallout 4 */
class BSSubIndexTriShape : public BSTriShape {
public:
	/*! Constructor */
	NIFLIB_API BSSubIndexTriShape();

	/*! Destructor */
	NIFLIB_API virtual ~BSSubIndexTriShape();

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
	unsigned int GetNumTriangles2() const;

	// Unknown.
	// \param[in] value The new value.
	void SetNumTriangles2( unsigned int value );

	// Unknown.
	// \return The current value.
	unsigned int GetNumb() const;

	// Unknown.
	// \param[in] value The new value.
	void SetNumb( unsigned int value );

	// Unknown.
	// \return The current value.
	vector<SubIndexPart1 > GetSubIndexPart1() const;

	// Unknown.
	// \param[in] value The new value.
	void SetSubIndexPart1( const vector<SubIndexPart1 >& value );

	// Unknown.
	// \return The current value.
	SubIndexPart2 GetSubIndexPart2() const;

	// Unknown.
	// \param[in] value The new value.
	void SetSubIndexPart2( const SubIndexPart2 & value );

	****End Example Naive Implementation***/

	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
protected:
	/*! Unknown. */
	unsigned int numTriangles2;
	/*! Unknown. */
	mutable unsigned int numa;
	/*! Unknown. */
	unsigned int numb;
	/*! Unknown. */
	vector<SubIndexPart1 > subIndexPart1;
	/*! Unknown. */
	SubIndexPart2 subIndexPart2;
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
