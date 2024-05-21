/*! \file CQuadrilateral.h
	\brief Declaration of the general class Quadrilateral

	Details.
*/


#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include <iostream> 
#include "StructFormat.h"

using namespace std;

/// @class Quadrilateral
/// @brief an abstract base class for quadrilateral
class Quadrilateral {
protected:

	float sides[4];
	
	Format* shapef;
	
	void SetSides(float s1, float s2, float s3, float s4); 
	
	/// @name PURE VIRTUAL FUNCTIONS
	/// @{
	virtual float Area()=0;
	/// @}

public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Quadrilateral();
	Quadrilateral(Format sf);
	Quadrilateral(const Quadrilateral &o, const Format sf);
	virtual ~Quadrilateral();
	/// @}
	
	/// @name OPERATORS
	/// @{
	Quadrilateral& operator=(const Quadrilateral &o); 
	bool operator==(const Quadrilateral &o);
	Format& operator=(const Format &sf);
	bool operator==(const Format &sf);
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init();
	void InitFormat();
	void InitFormat(Format sf);												
	void Init(const Quadrilateral &o);							
	void Reset();
	void ResetFormat();												
	/// @}

			
	/// @name GETTERS
	/// @{
	float GetArea();
	float GetPerimeter();
	void GetSides(float &s0, float &s1, float &s2, float &s3);
	void GetFormat(Format sf); 
	Color GetFill(Color fill);
	Color GetOutline(Color outline);
	/// @}
	
	/// @name SETTERS
	/// @{
	void SetFormat(Format sf);
	void SetFill(Color fill);
	void SetOutline(Color outline);
	/// @}
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}
	
	/// @name PURE VIRTUAL FUNCTIONS 
	/// @{
	virtual void Drawing()=0;
	/// @}

};

#endif