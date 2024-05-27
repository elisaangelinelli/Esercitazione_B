/*! \file main_test.cpp
	\author Elisa Angelinelli 
	\brief Test of Quadrilateral, Rectangle and Rhombus classes 
	\date 2024-05-21

	Main for Quadrilaterals, Rectangles and Rhombuses
*/
#include<iostream>

#include "CQuadrilateral.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CMenu.h"

const int LISTL=6; 

Quadrilateral* quadList[LISTL];

void Show() {
	
	int i; 
	
	for (i=0; i<LISTL; i++)
		quadList[i]->Drawing();
	
}

int Choice(){
	int c = 0;
	cout << "What do you want to do?" << endl;
	cout << "1 = see all the shapes" << endl;
	cout << "2 = add a shape" << endl;
	cout << "3 = remove a shape" << endl;
	cout << "4 = remove all the shapes" << endl;
	scanf("%d", &c);
	return c;
}


int main() {

	Format f1, f2;
	
	f1.fill = r;
	f1.outline = b; 
	f2.fill = g;
	f2.outline = w;
	
	Rectangle rectA(10,5);
	Rectangle rectB(3,7,f1);
	Rectangle rectC = rectA;

	Rhombus rhoA(6,2,f2);
	Rhombus rhoB = rhoA;
	Rhombus rhoC(4,3);
		
	quadList[0]= &rectA;
	quadList[1]= &rectB;
	quadList[2]= &rectC;
	quadList[3]= &rhoA;
	quadList[4]= &rhoB;
	quadList[5]= &rhoC;

	Show();
	
	rectA.SetFill(g);
	rhoC.SetOutline(r);
	rhoA=rhoC;
	rectB.SetFormat(f2);
	
	Show();

	//part of main to test the implementation of the menu of the display
	Menu Display;
	switch (Choice())
	{
	case 1:
		Display.GetAllShapes();
		Choice();
		break;
	case 2:
		Display.AddShape();
		Choice();
		break;
	case 3:
		int i;
		cout << "Which is the index of the shape you want to remove?" << endl;
		scanf("%i", &i);
		Display.RemoveShape(i);
		Choice();
		break;
	case 4: 
		Display.RemoveAllShapes();
		Choice();
		break;
	default:
		cout << "Not a valid choice" << endl;
		break;
	}


	return 0;

}