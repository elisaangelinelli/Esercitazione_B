/*! \file CMenu.h
	\brief Declaration of the fuctions of the menu that will be displayed

	Details.
*/


#ifndef MENU_H
#define MENU_H

#include <iostream> 
#include "CQuadrilateral.h"
#include "CRectangle.h"
#include "CRhombus.h"
#define MAX_LENGHT 50

using namespace std;

/// @class Menu
/// @brief an abstract class for menu
class Menu {
protected:

	/// @brief array of shapes
	Quadrilateral* S_Array[MAX_LENGHT];

	int Quadrilateral();


public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Menu();
	Menu(const Menu &m);
	virtual ~Menu();
	/// @}
	
	/// @name OPERATORS
	/// @{
	Menu& operator=(const Menu &m); 
	bool operator==(const Menu &m);
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init();											
	void Init(const Menu &m);											
	/// @}

			
	/// @name GETTERS
	/// @{
	void GetAllShapes();
	/// @}
	
	/// @name FUNCTIONS
	/// @{
	void AddShape();
	void AddRectangle(int i);
	void AddRhombus(int i);
    void RemoveShape(int i);
    void RemoveAllShapes();
	/// @}
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}

};

#endif