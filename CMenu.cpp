/*! \file CMenu.h
    \author Elisa Angelinelli
	\brief Implementation of the fuctions of the menu that will be displayed
    \date 2024-05-23

	Details of the class.
*/

#include "CMenu.h"

/// @brief default constructor 
Menu::Menu() {

	cout << "Menu - constructor - default" << endl;

	Init();

} 

/// @brief copy constructor 
/// @param m reference to the object that should be copied
Menu::Menu(const Menu &m) {
	
	cout << "Menu - copy constructor" << endl;

	Init(m);

}

/// @brief destructor
Menu::~Menu() {

	cout << "Menu - destructor" << endl;
	RemoveAllShapes();

}  

/// @brief overload of operator = 
/// @param m reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
Menu& Menu::operator=(const Menu &o) { 
	
	Init(o);
	return *this;
	
}

/// @brief overload of operator == 
/// @param m reference to the object on the right side of the operator 
/// @return always false 
bool Menu::operator==(const Menu &o) {

	return false;
}

/// @brief default initialization of the object
void Menu::Init() {
	
	for(int i = 0; i < MAX_LENGHT; i++){
		S_Array[i] = NULL;
	}
	
}

/// @brief initialization of the object as a copy of an object 
/// @param m reference to the object that should be copied 
void Menu::Init(const Menu &m) {

	for(int i = 0; i < MAX_LENGHT; i++){
		S_Array[i] = m.S_Array[i];
	}

}

int Menu::Quadrilateral(){
	int q = 0;
	cout << "Which shape do you want to add?" << endl;
	cout << "1 = rectangle" << endl;
	cout << "2 = rhombus" << endl;
	cout << "Insert 0 if you want to see the shapes you have in the array." << endl; 
	scanf("%d", &q);
	if(q != 1 && q != 2 ){
		WarningMessage("Not a valid choice.");
		return 0;
	}
	return q;
}

/// @brief get every object
void Menu::GetAllShapes() {

	for(int i = 0; i < MAX_LENGHT; i++){
		cout << endl;
		cout << "Element " << i << ":" << endl;
		if (S_Array[i] == NULL){
			cout << "No shape" << endl;
			cout << endl;
			return;
		}
		S_Array[i]->Drawing();
	}

}

/// @brief  add a shape to the list
void Menu::AddShape(){

	for(int i = 0; i < MAX_LENGHT; i++){
		if(S_Array[i] == NULL){
			if (Quadrilateral() == 0){
				return;
			}
			else if(Quadrilateral() == 1){
				AddRectangle(i);
			}
			else if(Quadrilateral() == 2){
				AddRhombus(i);
			}
		}
		return;
	}
	WarningMessage("There's no more space in the array.");

}

/// @brief add a rectangle to the list 
void Menu::AddRectangle(int i){

	Rectangle* Rect;
	Rect = new(Rectangle);
	S_Array[i] = Rect;
	float height, width;
	int fill, outline;

	cout << "Insert the width of the rectangle" << endl;
	scanf("%f", &width);
	Rect->SetWidth(width);

	cout << "Insert the height of the rectangle" << endl;
	scanf("%f", &height);
	Rect->SetHeight(height);

	cout << "Colors:" << endl;
	cout << "0 = black" << endl;
	cout << "1 = white" << endl;
	cout << "2 = red" << endl;
	cout << "3 = green" << endl;
	cout << "4 = blue" << endl;

	cout << "Insert the color of the filling" << endl;
	scanf("%i", &fill);
	Rect->SetFill((Color)fill);

	cout << "Insert the color of the outline" << endl;
	scanf("%i", &outline);
	Rect->SetOutline((Color)outline);

}

/// @brief add a rhombus to the list
void Menu::AddRhombus(int i){

	Rhombus* Rhom;
	Rhom = new(Rhombus);
	S_Array[i] = Rhom;
	float dL, dS;
	int fill, outline;

	cout << "Insert the longer diagonal of the rhombus" << endl;
	scanf("%f", &dL);
	Rhom->SetDiagL(dL);

	cout << "Insert the shorter diagonal of the rhombus" << endl;
	scanf("%f", &dS);
	Rhom->SetDiagS(dS);

	cout << "Colors:" << endl;
	cout << "0 = black" << endl;
	cout << "1 = white" << endl;
	cout << "2 = red" << endl;
	cout << "3 = green" << endl;
	cout << "4 = blue" << endl;

	cout << "Insert the color of the filling" << endl;
	scanf("%i", &fill);
	Rhom->SetFill((Color)fill);

	cout << "Insert the color of the outline" << endl;
	scanf("%i", &outline);
	Rhom->SetOutline((Color)outline);

}

/// @brief remove a shape from the list
void Menu::RemoveShape(int i){
	if ( i < 0 || i > MAX_LENGHT){
		WarningMessage("Not a valid index.");
		return;
	}

	if (S_Array[i] == NULL){
		WarningMessage("This shape does not exist");
		return;
	}
	delete(S_Array[i]);
	S_Array[i] = NULL;
}

/// @brief remove all the shapes of the list
void Menu::RemoveAllShapes(){
	for (int i = 0; i < MAX_LENGHT; i++){
		delete(S_Array[i]);
		S_Array[i] = NULL;
	}
}


/// @brief write an error message 
/// @param string message to be printed
void Menu::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Menu --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void Menu::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Menu --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void Menu::Dump() {
	cout << endl;
	cout << "---Menu---" << endl; 
	cout << endl;

	GetAllShapes();
}
