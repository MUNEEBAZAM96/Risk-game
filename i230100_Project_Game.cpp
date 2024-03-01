//============================================================================
// Name        : Muneeb Ur Rehman
// Roll Number : 23i0100
// Class       : SE(B)
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
//#include "Board.h"
#include "util.h"
#include <iostream>
#include<cstring>
#include<string.h>
#include"i230100_Project.h"
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<time.h>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */
//Boacccrd *b;
void MenueDisplay() {
	// In your animation loop

	// Set a gradient background
	glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue background
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < 300; i++) {
		DrawString(rand() % 1200, rand() % 1000, "*", colors[GREEN]);

	}

	cout << setw(100) << "WELCOME TO RISK BOARD GAME  !\n";
	DrawLine(0, 800, 1200,800, 50, colors[RED]);

	DrawRoundRect(230, 450,500, 500,colors[BLUE]
		,40);

	DrawString(250, 870, "  WELCOME TO RISK BOARD GAME  !", colors[RED]);

	DrawString(320, 800, "   xxxxxxx  Select  xxxxxx  ! ", colors[YELLOW]);

	DrawString(380, 730, " 1) NEW GAME  !", colors[RED]);
	DrawString(380, 670, "  2) HIGH SCORE   ! ", colors[BLACK]);

	DrawString(360, 610, "  3) INSTRUCTIONS! ", colors[GREEN]);

	DrawString(360, 550, "  4) CREDITS ", colors[BLACK]);

	DrawCircle(1086, 7, 400, colors[YELLOW_GREEN]);
	glutSwapBuffers();
}	

 /////////////////   Leader Board Function which Take Two Arrays and Display on the Leader Board 
void LEADERBOARD(string arr[10] , int sc[10]) {
	// Set a gradient background
	glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue background
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < 300; i++) {
		DrawString(rand() % 1200, rand() % 1000, "*", colors[RED]);

	}

	int l = 900 ;
	
	/*for (int i = 0; i < 800; i+50) {
	DrawString(i, l, "_||____ ! ", colors[GOLD]);
	l - 50;
	}*/
	DrawString(220, 900, "xxxxxxxxxxxxx LEADER BOARD xxxxxxxxxxxxxx  ! ", colors[ORANGE]);

	DrawRoundRect(180, 230, 500, 600, colors[YELLOW_GREEN]
		, 40);
	int u = 770;
	for (int i = 0; i < 10; i++) {
		DrawString(250, u,arr[i], colors[RED]);
		u = u - 50 ;
	  }
	int v = 770;
	for (int k = 0; k < 10; k++) {
		int const r = 350;
		string st = Num2Str(sc[k]);
		DrawString(450, v, st, colors[BLUE]);
		v = v - 50;
	}
	DrawString(400, v-150, "Press here  Exit", colors[BLUE]);
	   glutSwapBuffers();
}
		/////////// File Handling Read Data From File ;
/////////////  Read Data Into File //////////////////////////
void readDataFromFile(int array[10] , string arr[10]) {
	 ifstream inputFile("LeaderBoard.txt");
	if (inputFile.is_open()) {
		for (int i = 0; i < 10; ++i) {
			inputFile >> array[i];
			cout << endl;
			inputFile >> arr[i];
			cout << endl;
		}
		inputFile.close();
	}
	else {
		cerr << "Unable to open file for reading." <<endl;
	}
}
   //////////////////////////// File Handling Write data To File //////////////////////////
////////////////////////////////  Write Data into File //////////////////////////////////////////////////////////////
void writeDataToFile(int array[10] , string Player[10]) {
	   ofstream outputFile("LeaderBoard.txt");

	if (outputFile.is_open()) {
		for (int i = 0; i < 10; ++i) {
			outputFile << array[i] << " " << endl;
			outputFile << Player[i] << " " << endl;
		}
		outputFile.close();
	}
	else {
	     cerr << "Unable to open file for writing." <<endl;
	}
}
 // territory drawn Funtion single territory drawn 
void territoryDraw1(int x1,int y1 , int color1 , int territory1 , int territory2) {

	DrawRoundRect(x1-25, y1-30,60,60, colors[color1]
		, 10);

	DrawRoundRect(x1, y1, 10, 10, colors[territory1]
		, 10);

	DrawRoundRect(x1-10, y1-10, 10, 10, colors[territory2]
		, 5);
   }

// Territory Draw shape two ;
void territoryDraw2(int x1, int y1, int colour, int territory1, int territory2) {
	DrawLine(x1, y1, x1, y1 + 80, 2, colors[RED]);
	DrawLine(x1, y1+80, x1+80, y1 + 80, 2, colors[RED]);
	DrawLine(x1, y1 , x1 + 80, y1 + 80, 2, colors[RED]);



	DrawRoundRect(x1+20, y1+40, 10, 10, colors[territory1]
		, 10);

	DrawRoundRect(x1+10, y1 +30, 10, 10, colors[territory2]
		, 5);
	 }
// shape number 3 
void territoryDraw3(int x1, int y1, int colour, int territory1, int territory2) {

	DrawLine( x1,  y1,  x1+50,  y1+50, 2, colors[23]);
	DrawLine(x1+50, y1+50, x1 +100 , y1, 4, colors[23]);
	DrawLine(x1 , y1, x1 + 50, y1-50, 4, colors[23]);
	DrawLine(x1+100, y1, x1 + 50, y1 - 50, 4, colors[23]);
	

	DrawRoundRect(x1+40, y1-7, 10, 10, colors[territory1]
		, 10);

	DrawRoundRect(x1 + 60, y1 - 15, 10, 10, colors[territory2]
		, 5);
}
  // shape Number 4 | | /\*
void territoryDraw4(int x1, int y1, int colour, int territory1, int territory2) {
	DrawLine(x1, y1, x1 + 50, y1 + 50, 2, colors[15]);
	DrawLine(x1 + 50, y1 + 50, x1 + 100, y1, 4, colors[15]);
	DrawLine(x1, y1, x1 + 50, y1 - 50, 4, colors[15]);
	DrawLine(x1 + 100, y1, x1 + 50, y1 - 50, 4, colors[15]);


	DrawRoundRect(x1 + 40, y1 - 7, 10, 10, colors[territory1]
		, 10);

	DrawRoundRect(x1 + 60, y1 - 15, 10, 10, colors[territory2]
		, 5);
	
}
	// shape 5 
void territoryDraw5(int x1, int y1, int colour, int territory1, int territory2) {

	DrawLine(x1, y1, x1 + 50, y1 + 50, 2, colors[2]);
	DrawLine(x1 + 50, y1 + 50, x1 + 100, y1, 4, colors[2]);
	DrawLine(x1, y1, x1 + 50, y1 - 50, 4, colors[2]);
	DrawLine(x1 + 100, y1, x1 + 50, y1 - 50, 4, colors[2]);


	DrawRoundRect(x1 + 40, y1 - 7, 10, 10, colors[territory1]
		, 10);

	DrawRoundRect(x1 + 60, y1 - 15, 10, 10, colors[territory2]
		, 5);
}

/////////////////// Shape Number Six //////////////////////////////////////////////////////////////////////////
// 
// /////////////////////////////////////////////////////////////////////////////////////////////////////////// 
void territoryDraw6(int x1, int y1, int colour, int territory1, int territory2) {

	DrawLine(x1, y1, x1 + 50, y1 + 50, 2, colors[68]);
	DrawLine(x1 + 50, y1 + 50, x1 + 100, y1, 4, colors[68]);
	DrawLine(x1, y1, x1 + 50, y1 - 50, 4, colors[68]);
	DrawLine(x1 + 100, y1, x1 + 50, y1 - 50, 4, colors[68]);


	DrawRoundRect(x1 + 40, y1 - 7, 10, 10, colors[territory1]
		, 10);

	DrawRoundRect(x1 + 60, y1 - 15, 10, 10, colors[territory2]
		, 5);
}
   
void GameDisplay(int ter[56])/**/ {
	
	glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue background
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < 90; i++) {
		if (Count%2==0) {
			DrawString(rand() % 1200, rand() % 1000, "*", colors[SNOW]);
		}
		else {
			DrawString(rand() % 1200, rand() % 1000, "*", colors[CHOCOLATE]);
		}
	}
	///// TURN IDENTIFIER 
	if (Troops1 <= 0 || Troops2 <= 0) {
		Troops1 = 0;
		Troops2 = 0;
		T1 = 20;
		T2 = 20;
	}
	
	
	DrawString(220, 950, "xxxxxxxxxxxxx WORLD MAP xxxxxxxxxxxxxx  ! ", colors[ORANGE]);
	DrawCircle(1086, 25, 400, colors[BLACK]);
	DrawCircle(1106, 1100, 350, colors[WHITE]);
	DrawString(1000,900, Player_1, colors[color1]);
	DrawString(1000,200,Player_2, colors[color2]);
	DrawString(930, 850,"Territories OWNED : ", colors[GOLD]);
	DrawString(880, 150,"Territories OWNED : ", colors[BROWN]);
	DrawCircle(1180, 860, 30, colors[BLUE]);
	DrawCircle(1130, 160, 30, colors[GREEN]);
	///// TROOPS SEEN 
	DrawString(930, 950, "TROOPS:", colors[GOLD]);
	DrawString(880, 300, "TROOPS:", colors[BROWN]);
	DrawCircle(1070, 960, 30, colors[BLUE]);
	DrawCircle(1020, 310, 30, colors[GREEN]);
	///////// TROOPS 
	string TOOPS1 = Num2Str(Troops1);
	string TOOPS2 = Num2Str(Troops2);
	///////// Puttin Values  /////////////////
	DrawString(1060, 950, TOOPS1, colors[RED]);
	DrawString(1010, 300, TOOPS2, colors[RED]);
	// Using Function to Convert integer to string //////////////////////////////////////////////////////
	string Teritory1 = Num2Str(T1);
	string Teritory2 = Num2Str(T2);
	/////////// Putting Value into Function ////////////////////////
	DrawString(1170, 850, Teritory1, colors[RED]);
	DrawString(1120, 150, Teritory2, colors[RED]);
	if (Count%2!=0) {
		DrawString(1000, 800, "Your Turn ", colors[RED]);
	}
	if (Count%2==0) {
		DrawString(1000, 100, "Your Turn ", colors[BLUE]);
	}
	if (Dec1 > Dec2) {
		DrawString(400, 900, Player_1 + "  Got More Dice !", colors[DARK_ORANGE]);
	}
	else {
		DrawString(400, 900, Player_2 + "  Got More Dice !", colors[RED]);
	}
	// For Dice roll 

	DrawRoundRect(1030, 500, 200,200, colors[YELLOW]
		, 10);
	/*dice = Num2Str(Dice());*/
	DrawString(1080, 660,"xx Dice xx", colors[BROWN]);
	DrawCircle(1090, 590, 50, colors[WHITE]);
	DrawString(1080, 570,dice, colors[BROWN]);
	current_page = 4 ;
	/////////////// WORLD DOMINANCE ///////////////////////////////////////
	// MAP DRAW 
/////////////////////// teriitories Drawn //////////////////////////////
	territoryDraw3(50,850, 23, ter[0],ter[0]);
	territoryDraw3(50, 750, 23, ter[1], ter[1]);
	territoryDraw3(150, 850, 23, ter[2], ter[2]);
	territoryDraw3(150, 750, 23, ter[3],ter[3]);
	territoryDraw3(200, 700, 23, ter[4],ter[4]);
	territoryDraw3(100, 700, 23, ter[5], ter[5]);
	territoryDraw3(50, 650, 23, ter[6],ter[6]);
	territoryDraw3(200, 600, 23, ter[7],ter[7]);
	territoryDraw3(100, 600, 23, ter[8], ter[8]);
	territoryDraw3(50, 550, 23, ter[9], ter[9]);
	territoryDraw3(50, 450, 23, ter[10], ter[10]);

	DrawString(250, 800, "XX NORTH AMERCIA XX", colors[GOLD]);
	// NORTH AMERICA 
	territoryDraw2(80, 315, 23, ter[11],ter[11]);
	territoryDraw2(80, 240, 23, ter[12], ter[12]);
	territoryDraw2(160, 315, 23,ter[13],ter[13]);
	territoryDraw2(160, 240, 23, ter[14],ter[14]);
	territoryDraw2(240, 315, 23, BLACK,BLACK);
	territoryDraw2(240, 240, 23, ter[16],ter[16]);
	territoryDraw2(320, 315, 23, ter[17], ter[17]);
	territoryDraw2(320, 240, 23, ter[18],ter[18]);
	// Africa 
	DrawString(170, 450, "XX AFRICA XX", colors[BROWN]);
	territoryDraw5(300, 600, 37, ter[19], ter[19]);
	territoryDraw5(350, 650, 37,ter[20], ter[20]);
	territoryDraw5(400, 700, 37, ter[21], ter[21]);
	territoryDraw5(450, 750, 37, ter[22], ter[22]);
	territoryDraw5(300, 500, 37, ter[23], ter[23]);
	territoryDraw5(350, 550, 37, ter[24], ter[24]);
	territoryDraw5(400, 600, 37, ter[25], ter[25]);
	territoryDraw5(450, 650, 37, ter[26], ter[26]);
	territoryDraw5(350, 450, 37, ter[27], ter[27]);
	territoryDraw5(400, 500, 37, ter[28], ter[28]);
	territoryDraw5(450, 550, 37, ter[29], ter[29]);
	territoryDraw5(500, 600, 37, ter[30], ter[30]);
	// ASIA 
	DrawString(600, 850, "XX ASIA XX ", colors[YELLOW]);
	territoryDraw4(550, 750, 37, ter[31], ter[31]);
	territoryDraw4(650, 750, 37, ter[32], ter[32]);
	territoryDraw4(550, 650, 37, ter[33], ter[33]);
	territoryDraw4(650, 650, 37, ter[34], ter[34]);
	territoryDraw4(750, 650, 37, ter[35], ter[35]);
	territoryDraw4(850, 650, 37, ter[36], ter[36]);
	territoryDraw4(600, 700, 37, ter[37], ter[37]);
	territoryDraw4(700, 700, 37, ter[38], ter[38]);
	territoryDraw4(800, 700, 37, ter[39], ter[39]);
	territoryDraw4(600, 600, 37, ter[40], ter[40]);
	territoryDraw4(700, 600, 37, ter[41], ter[41]);
	territoryDraw4(800, 600, 37, ter[42], ter[42]);
	territoryDraw4(650, 550, 37, ter[43], ter[43]);
	territoryDraw4(750, 550, 37, ter[44], ter[44]);
	territoryDraw4(850, 550, 37, ter[45], ter[45]);

	//////////South America region 

	DrawString(510, 470, "XX SOUTH AMERICA REGION XX", colors[BLUE]);
	territoryDraw6(620, 410, 37, ter[46], ter[46]);
	territoryDraw6(520,410, 37, ter[47], ter[47]);
	territoryDraw6(420,410, 37, ter[48], ter[48]);
	territoryDraw6(570, 360, 37, ter[49], ter[49]);
	territoryDraw6(470, 360, 37, ter[50], ter[50]);
	territoryDraw6(370, 360, 37, BLACK, BLACK);
	//////////////Button ///////////////////////////////////
	if (Troops1 <= 0 && Troops2 <= 0) {
		Troops1 = 0;
		wood = -40; 
		//////// Attack Button ////////////////////////
	
		DrawRoundRect(50,100 ,170,80, colors[DARK_RED]
			, 10);
		DrawString(50, 140, "xx ATTACK xx", colors[DARK_GREEN]);


		///////////// Move Button ///////////////////

	
	DrawRoundRect(250, 100, 170, 80, colors[DARK_BLUE]
			, 10);
		DrawString(250, 140, "%%MOVE%%", colors[DARK_GREEN]);
	
		////////////  Fortify /////////////////////
		DrawRoundRect(450, 100, 170, 80, colors[YELLOW]
			, 10);
		DrawString(450, 140, "##FORTIFY##", colors[BROWN]);

	   }
	if (Troops1 == 0 || Troops2 == 0) {
		Troops1 = 0;
		Troops2 = 0;
	}
	

	glutSwapBuffers();// do not modify this line..
}

////////////////////////////////////////////////////  Second Board for Four Players which take array of Colours 
void GameDisplay2(int ter[56])/**/ {

	glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue background
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < 90; i++) {
		if (Count % 2 == 0) {
			DrawString(rand() % 1200, rand() % 1000, "*", colors[SNOW]);
		}
		else {
			DrawString(rand() % 1200, rand() % 1000, "*", colors[CHOCOLATE]);
		}
	}
	///// TURN IDENTIFIER 
	        


	DrawString(220, 950, "xxxxxxxxxxxxx WORLD MAP xxxxxxxxxxxxxx  ! ", colors[ORANGE]);
	DrawCircle(1086, 25, 400, colors[BLACK]);
	DrawCircle(1106, 1100, 350, colors[WHITE]);
	DrawString(1000, 900, Player_1, colors[color1]);
	DrawString(1000, 200, Player_2, colors[color2]);
	DrawString(930, 850, Player_3, colors[color3]);
	DrawString(880, 150,Player_4, colors[color4]);
	DrawCircle(1180, 860, 30, colors[BLUE]);
	DrawCircle(1130, 160, 30, colors[GREEN]);
	///// TROOPS SEEN 
	DrawString(930, 950, "TROOPS:", colors[GOLD]);
	DrawString(880, 300, "TROOPS:", colors[BROWN]);
	DrawCircle(1070, 960, 30, colors[BLUE]);
	DrawCircle(1020, 310, 30, colors[GREEN]);
	Troops1 = 30;
	Troops2 = 30;
	Troops3 = 30;
	Troops4 = 30;
	 int copy = 1;

	///////// TROOPS 
	string TOOPS1 = Num2Str(Troops1);
	string TOOPS2 = Num2Str(Troops2);
	string TOOPS3 = Num2Str(Troops3);
	string TOOPS4 = Num2Str(Troops4);
	///////// Puttin Values  /////////////////
	DrawString(1060, 950, TOOPS1, colors[RED]);
	DrawString(1010, 300, TOOPS2, colors[RED]);
	// Using Function to Convert integer to string ////////////////////////////////////////////
	string Teritory1 = Num2Str(T1);
	string Teritory2 = Num2Str(T2);
	/////////// Putting Value into Function ////////////////////////
	DrawString(1170, 850, Teritory1, colors[RED]);
	DrawString(1120, 150, Teritory2, colors[RED]);
	if (Count % 2 != 0) {
		DrawString(1000, 800, "Your Turn ", colors[RED]);
	}
	if (Count % 2 == 0) {
		DrawString(1000, 100, "Your Turn ", colors[BLUE]);
	}
	// For Dice roll 

	DrawRoundRect(1030, 500, 200, 200, colors[YELLOW]
		, 10);
	/*dice = Num2Str(Dice());*/
	DrawString(1080, 660, "xx Dice xx", colors[BROWN]);
	DrawCircle(1090, 590, 50, colors[WHITE]);
	DrawString(1080, 570, dice, colors[BROWN]);
	current_page = 4;
	/////////////// WORLD DOMINANCE ///////////////////////////////////////
	// MAP DRAW 
/////////////////////// teriitories Drawn //////////////////////////////
	territoryDraw3(50, 850, 23, ter[0], ter[0]);
	territoryDraw3(50, 750, 23, ter[1], ter[1]);
	territoryDraw3(150, 850, 23, ter[2], ter[2]);
	territoryDraw3(150, 750, 23, ter[3], ter[3]);
	territoryDraw3(200, 700, 23, ter[4], ter[4]);
	territoryDraw3(100, 700, 23, ter[5], ter[5]);
	territoryDraw3(50, 650, 23, ter[6], ter[6]);
	territoryDraw3(200, 600, 23, ter[7], ter[7]);
	territoryDraw3(100, 600, 23, ter[8], ter[8]);
	territoryDraw3(50, 550, 23, ter[9], ter[9]);
	territoryDraw3(50, 450, 23, ter[10], ter[10]);

	DrawString(250, 800, "XX NORTH AMERCIA XX", colors[GOLD]);
	// NORTH AMERICA 
	territoryDraw2(80, 315, 23, ter[11], ter[11]);
	territoryDraw2(80, 240, 23, ter[12], ter[12]);
	territoryDraw2(160, 315, 23, ter[13], ter[13]);
	territoryDraw2(160, 240, 23, ter[14], ter[14]);
	territoryDraw2(240, 315, 23, BLACK, BLACK);
	territoryDraw2(240, 240, 23, ter[16], ter[16]);
	territoryDraw2(320, 315, 23, ter[17], ter[17]);
	territoryDraw2(320, 240, 23, ter[18], ter[18]);
	// Africa 
	DrawString(170, 450, "XX AFRICA XX", colors[BROWN]);
	territoryDraw5(300, 600, 37, ter[19], ter[19]);
	territoryDraw5(350, 650, 37, ter[20], ter[20]);
	territoryDraw5(400, 700, 37, ter[21], ter[21]);
	territoryDraw5(450, 750, 37, ter[22], ter[22]);
	territoryDraw5(300, 500, 37, ter[23], ter[23]);
	territoryDraw5(350, 550, 37, ter[24], ter[24]);
	territoryDraw5(400, 600, 37, ter[25], ter[25]);
	territoryDraw5(450, 650, 37, ter[26], ter[26]);
	territoryDraw5(350, 450, 37, ter[27], ter[27]);
	territoryDraw5(400, 500, 37, ter[28], ter[28]);
	territoryDraw5(450, 550, 37, ter[29], ter[29]);
	territoryDraw5(500, 600, 37, ter[30], ter[30]);
	// ASIA 
	DrawString(600, 850, "XX ASIA XX ", colors[YELLOW]);
	territoryDraw4(550, 750, 37, ter[31], ter[31]);
	territoryDraw4(650, 750, 37, ter[32], ter[32]);
	territoryDraw4(550, 650, 37, ter[33], ter[33]);
	territoryDraw4(650, 650, 37, ter[34], ter[34]);
	territoryDraw4(750, 650, 37, ter[35], ter[35]);
	territoryDraw4(850, 650, 37, ter[36], ter[36]);
	territoryDraw4(600, 700, 37, ter[37], ter[37]);
	territoryDraw4(700, 700, 37, ter[38], ter[38]);
	territoryDraw4(800, 700, 37, ter[39], ter[39]);
	territoryDraw4(600, 600, 37, ter[40], ter[40]);
	territoryDraw4(700, 600, 37, ter[41], ter[41]);
	territoryDraw4(800, 600, 37, ter[42], ter[42]);
	territoryDraw4(650, 550, 37, ter[43], ter[43]);
	territoryDraw4(750, 550, 37, ter[44], ter[44]);
	territoryDraw4(850, 550, 37, ter[45], ter[45]);

	//////////South America region 

	DrawString(510, 470, "XX SOUTH AMERICA REGION XX", colors[BLUE]);
	territoryDraw6(620, 410, 37, ter[46], ter[46]);
	territoryDraw6(520, 410, 37, ter[47], ter[47]);
	territoryDraw6(420, 410, 37, ter[48], ter[48]);
	territoryDraw6(570, 360, 37, ter[49], ter[49]);
	territoryDraw6(470, 360, 37, ter[50], ter[50]);
	territoryDraw6(370, 360, 37, BLACK, BLACK);
	//////////////Button ///////////////////////////////////
	if (Troops1 <= 0 && Troops2 <= 0) {
		wood = -20;
		
		//////// Attack Button ////////////////////////

		DrawRoundRect(50, 100, 170, 80, colors[DARK_RED]
			, 10);
		DrawString(50, 140, "xx ATTACK xx", colors[DARK_GREEN]);


		///////////// Move Button ///////////////////


		DrawRoundRect(250, 100, 170, 80, colors[DARK_BLUE]
			, 10);
		DrawString(250, 140, "%%MOVE%%", colors[DARK_GREEN]);

		////////////  Fortify /////////////////////
		DrawRoundRect(450, 100, 170, 80, colors[YELLOW]
			, 10);
		DrawString(450, 140, "##FORTIFY##", colors[BROWN]);

	}
	if (Troops1 != 0 && Troops2 != 0) {
		exit(0);
	}

	glutSwapBuffers();// do not modify this line..
}


/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */
  /////////////////////  Print Able key Functions Coontrol the Game 
void PrintableKeys(unsigned char key, int x, int y) {


	if (key == 27/* Escape key ASCII*/) {
		current_page = 0;
		MenueDisplay();
		Player_1 = "";
		Player_2 = "";
		Player_3 = "";
		Player_4 = "";
		for (int i = 0; i < 56; i++) {
			arr[i] = 137;
		}
		T1 = 0;
		T2 = 0;
		Troops1 = 40;
		Troops2 = 40;
		wood = 0;
		// exit the program when escape key is pressed.
	}   
		if (current_page == 2 && key!=8) {
			Player_1 += key;
			ChosePlayer1();
		}
	/////////////////////////////////////////////////////////////Code Problem SEE it Later ;

	
	if (current_page==3 && key!= 8) {
		Player_2 += key;
		ChosePlayer2();
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (current_page == 3  && key== 8) {
		int size = Player_2.length();
		/*Player_2[size - 2] = '\0';*/
		Player_2[size - 1] = '\0';
		ChosePlayer2();

	}

	if (current_page == 2 && key == 8) {
		int size = Player_1.length();
		/*Player_2[size - 2] = '\0';*/
		Player_1[size - 1] = '\0';
		ChosePlayer1();

	}
	////////////////////// Player 1 Name for 4 Player Game //////////////////
	if (current_page == 5 && key != 8 && current_page!=3 && current_page != 6 && current_page != 7 && current_page !=8) {
		Player_1 += key;
		ChosePlayer14();
	}

	if (current_page == 5 && key == 8) {
		int size = Player_1.length();
		/*Player_2[size - 2] = '\0';*/
		Player_1[size - 1] = '\0';
		ChosePlayer14();
	}
	////////////////////// Player 2 Name for 4 Player Game //////////////////
	if (current_page == 6 && key != 8 && current_page != 3 && current_page != 5 && current_page != 7 && current_page !=8 ) {
		Player_2 += key;
		ChosePlayer24();
	}

	if (current_page == 6 && key == 8) {
		int size = Player_2.length();
		Player_2[size - 1] = '\0';
		ChosePlayer24();
	}
	////////////////////// Player 3 Name for 4 Player Game //////////////////
	if (current_page == 7 && key != 8 && current_page != 3) {
		Player_3 += key;
		ChosePlayer3();
	}

	if (current_page == 7 && key == 8) {
		int size = Player_3.length();
		Player_3[size - 1] = '\0';
		ChosePlayer3();
	}
	////////////////////// Player 4 Name for 4 Player Game //////////////////
	if (current_page == 8 && key != 8 && current_page != 3) {
		Player_4 += key;
		ChosePlayer4();
	}

	if (current_page == 8 && key == 8) {
		int size = Player_4.length();
		Player_4[size - 1] = '\0';
		ChosePlayer4();
	}
	//////////////////// Player Input for six Players Game /////////////////////////
	// starting from Player 1 to 6 /////////////////////////////////////
	// 
	// 
	// //////////////////////////////////////////////////////////////////////////////////
		

	if (key == 'b' || key == 'B') //Key for placing the bomb
	{  
		//do something if b is pressed
		cout << "b pressed" << endl;	
	}

	glutPostRedisplay();
}
void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
  void Timer(int m ) {
	
	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */

void MousePressedAndMoved(int x, int y) {
	cout << "X: " << x << endl;
	cout<<"Y: " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	
	glutPostRedisplay();
}
/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
////////////////  Mouse Function Which Control The Functionality of the Game 
void HandleMouseClicked(int button, int state, int x, int y) {


	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) // dealing only with left button
	{
		cout << x;
		cout << " ";
		cout << y;
		// Number of Players 
		if (x > 386 && y > 213 && x < 495 && y < 226 && current_page == 0) {
			PlayerChoice();
			current_page = 1;
		}
		// To Enter in Instruction Page 
		if (x > 372 && y > 315 && x < 585 && y < 324 && current_page == 0) {
			Instruction();
			current_page = 1;
		}
		// To Enter in CREDIT PAGE 
		if (x > 379 && y > 368 && x < 509 && y < 380 && current_page == 0) {
			Credits();
			current_page = 1;
		}
		//////////// Name Inputs For  Two Players /////////////// 
		//Name of Player Input and colour   Page 
		if (x > 93 && y > 247 && x < 293 && y < 307 && current_page == 1) {
			ChosePlayer1();
			current_page = 2;
		}
		// Player  2 Name 
		if (x > 307 && y > 352 && x < 508 && y < 409 && current_page == 2) {
			color1 = 5;
			color2 = 31;
			ChosePlayer2();
			current_page == 3;
		}

		// Player 2 Name 
		if (x > 612 && y > 339 && x < 806 && y < 424 && current_page == 2) {
			color1 = 31;
			color2 = 5;
			ChosePlayer2();
			current_page == 3;
		}
		//////////////// Name Inputs For  4 Players ////////////////////
		// starting from player 1 //////////////////
		//////////////////////////////////////////////////////////////
		if (x > 663 && y > 244 && x < 841 && y < 307 && current_page == 1) {
			current_page = 5;
			ChosePlayer14();
		}
		////////// Player_2 ///////////
		if (x > 407 && y > 393 && x < 658 && y < 453 && current_page == 5 && current_page != 6) {
			current_page = 6;
			ChosePlayer24();
		}
		//////// Player_3 /////////////
		if (x > 427 && y > 306 && x < 635 && y < 377 && current_page == 6 && current_page != 7 && current_page != 8) {
			current_page = 7;
			ChosePlayer3();
		}
		//////////// Player_4 //////////////
		if (x > 430 && y > 307 && x < 637 && y < 371 && current_page == 7 && current_page != 9 && current_page != 8) {
			current_page = 8;
			ChosePlayer4();
		}
		/////////////////// Colour Selection for Four Players ///////////////////
		if (x > 442 && y > 393 && x < 630 && y < 463 && current_page == 8 && current_page != 7 && current_page != 6 && current_page != 5) {
			current_page = 9;
			GameDisplay2(arr);
		}


		// Game Display 
		if (x > 430 && y > 567 && x < 653 && y < 623 && current_page == 3) {
			GameDisplay(arr);
			current_page = 4;
		}

		/////////////////////////////////////// OCUPATION AFTER FIRST DICE ROLL //////////////////////////////////////////////////; For Two Players 
		//////// Teritory 1 

		if(Troops1!=0 || Troops2!=0){
		if (x > 80 && y > 99 && x < 117 && y < 146 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[0] = 5;
				T1++;
				Troops1 = Troops1 - 2;
			}
			else {
				arr[0] = 68;
				T2++;
				Troops2 = Troops2 - 4;
			}

			GameDisplay(arr);
			Count++;
		}
		///////////  Teritory 2 
		if (x > 73 && y > 191 && x < 141 && y < 223 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[1] = 5;
				T1++;
				Troops1 = Troops1 - 2;
			}
			else {
				arr[1] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		//////////////   Teritory 3 
		if (x > 178 && y > 108 && x < 236 && y < 139 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[2] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[2] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		//////////////   Teritory 4
		if (x > 180 && y > 191 && x < 237 && y < 226 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[3] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[3] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 5 /////////////
		if (x > 226 && y > 241 && x < 285 && y < 265 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[4] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[4] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 6 /////////////
		if (x > 126 && y > 237 && x < 185 && y < 267 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[5] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[5] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}

		////// Territory 7 /////////////
		if (x > 77 && y > 280 && x < 136 && y < 304 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[6] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[6] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 8 /////////////
		if (x > 229 && y > 324 && x < 287 && y < 343 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[7] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[7] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////// Territory 9 /////////////

		if (x > 113 && y > 313 && x < 169 && y < 363 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[8] = 5;
				T1++;
				Troops1 = Troops1 - 2;
			}
			else {
				arr[8] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 10 /////////////
		if (x > 83 && y > 359 && x < 121 && y < 403 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[9] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[9] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 11 /////////////
		if (x > 91 && y > 440 && x < 133 && y < 480 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[10] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[10] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 12 /////////////
		if (x > 93 && y > 521 && x < 116 && y < 556 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[11] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[11] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 13 /////////////
		if (x > 101 && y > 577 && x < 119 && y < 615 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[12] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[12] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 14 /////////////
		if (x > 173 && y > 520 && x < 232 && y < 558 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[13] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[13] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 15 /////////////
		if (x > 176 && y > 584 && x < 203 && y < 625 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[14] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[14] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 16 /////////////
		if (x > 264 && y > 537 && x < 281 && y < 549 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[15] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[15] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 17 /////////////
		if (x > 249 && y > 522 && x < 301 && y < 630 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[16] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[16] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 18 /////////////
		if (x > 331 && y > 519 && x < 361 && y < 552 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[17] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[17] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 19 /////////////
		if (x > 323 && y > 587 && x < 356 && y < 617 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[18] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[18] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 20 /////////////
		if (x > 341 && y > 316 && x < 373 && y < 357 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[19] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[19] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 21 /////////////
		if (x > 387 && y > 275 && x < 430 && y < 315 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[20] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[20] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 22 /////////////
		if (x > 437 && y > 228 && x < 468 && y < 266 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[21] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[21] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 23 /////////////
		if (x > 485 && y > 127 && x < 521 && y < 222 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[22] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[22] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 24 /////////////
		if (x > 338 && y > 418 && x < 361 && y < 436 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[23] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[23] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 25 /////////////
		if (x > 391 && y > 377 && x < 418 && y < 391 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[24] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[24] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 26 /////////////
		if (x > 434 && y > 334 && x < 466 && y < 352 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[25] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[25] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 27 /////////////
		if (x > 492 && y > 291 && x < 519 && y < 309 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[26] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[26] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		//////// Territory 28 /////////////
		if (x > 390 && y > 463 && x < 412 && y < 475 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[27] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[27] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 29 /////////////
		if (x > 441 && y > 418 && x < 462 && y < 434 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[28] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[28] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 30 /////////////
		if (x > 482 && y > 378 && x < 515 && y < 391 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[29] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[29] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 31 /////////////
		if (x > 544 && y > 334 && x < 554 && y < 351 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[30] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[30] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 32 /////////////
		if (x > 592 && y > 206 && x < 618 && y < 223 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[31] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[31] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 33 /////////////
		if (x > 691 && y > 206 && x < 718 && y < 223 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[32] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[32] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 34 /////////////
		if (x > 590 && y > 293 && x < 616 && y < 307 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[33] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[33] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 35 /////////////
		if (x > 687 && y > 292 && x < 718 && y < 307 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[34] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[34] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 36 /////////////
		if (x > 793 && y > 288 && x < 820 && y < 307 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[35] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[35] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 37 /////////////
		if (x > 887 && y > 291 && x < 915 && y < 307 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[36] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[36] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 38 /////////////
		if (x > 642 && y > 250 && x < 665 && y < 266 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[37] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[37] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 39 /////////////
		if (x > 744 && y > 251 && x < 767 && y < 265 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[38] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[38] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 40 /////////////
		if (x > 845 && y > 251 && x < 867 && y < 266 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[39] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[39] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 41 /////////////
		if (x > 638 && y > 335 && x < 665 && y < 351 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[40] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[40] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 42 /////////////
		if (x > 750 && y > 336 && x < 765 && y < 348 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[43] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[43] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 43 /////////////
		if (x > 845 && y > 338 && x < 863 && y < 351 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[42] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[42] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 44 /////////////
		if (x > 695 && y > 275 && x < 798 && y < 393 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[41] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[43] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 45 /////////////
		if (x > 793 && y > 379 && x < 821 && y < 391 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[44] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[44] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 46 /////////////
		if (x > 890 && y > 376 && x < 914 && y < 393 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[45] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[45] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 47 /////////////
		if (x > 661 && y > 495 && x < 683 && y < 510 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[46] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[46] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 48 /////////////
		if (x > 551 && y > 495 && x < 584 && y < 511 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[47] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[47] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 49 /////////////
		if (x > 453 && y > 494 && x < 485 && y < 511 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[48] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[48] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 50 /////////////
		if (x > 607 && y > 537 && x < 646 && y < 551 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[49] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[49] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
		}
		////// Territory 51 /////////////
		if (x > 516 && y > 538 && x < 533 && y < 549 && current_page == 4) {
			if (Count % 2 == 0) {
				arr[50] = 5;
				T1++;
				Troops1 = Troops1 - 2;


			}
			else {
				arr[50] = 68;
				T2++;
				Troops2 = Troops2 - 2;
			}
			GameDisplay(arr);
			Count++;
			
		}
	}
		
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////// Territory 52 /////////////
		










		// Leader Board Display 
		if (x > 321 && y > 263 && x < 555 && y < 279 && current_page == 0) {
			int array[10] = { 0,0,0,0,0,0,0,0,0,0 };
			string Player[10] = { Player_1,"Player_2","Player_3","Player_4","Player_5","Player_6","Player_7","Player_8","Player_9","Player_10" };
			LEADERBOARD(Player, array);
			current_page = 1;
		}

		// For Menue ;
		if (current_page == 1 && x > 405 && y > 726 && x < 549 && y < 743) {
			MenueDisplay();
			current_page = 0;
		}
		// when press for Player 1
		if (x > 1047 && y > 250 && x < 1219 && y < 415 && wood <= 2 ) {
			GameDisplay(arr);
			if (Count % 2 == 0) {
				Dec1 = Dice();
				dice = Num2Str(Dec1);
			}
			else {
				Dec2 = Dice();
				dice = Num2Str(Dec2);
			}
			/*DrawString(1080, 660, "xxDicexx", colors[BROWN]);
			DrawCircle(1090, 590, 50, colors[WHITE]);
			DrawString(1080, 570, dice, colors[BROWN]);*/
			if (Dec1 > Dec2) {
				DrawString(1000, 170, Player_1 +"Got More Dice !", colors[BROWN]);
			}
			else {
				DrawString(1000, 170, Player_2 + "Got More Dice !", colors[BROWN]);
			
			}

			//////////////////////////////////  dice roll decision ///////////////////// 
			Count++;
			wood++;
		}
		


		glutPostRedisplay();
		/*}*/
	}
	
}


	/*
	 * our gateway main function
	 * */
	int main(int argc, char* argv[]) {


		for (int i = 0; i < 56; i++) {
			arr[i] = 137;
		}
		//b = new Board(60, 60); // create a new board object to use in the Display Function ...
		static string Player_1;
		static  string dice;
		int width = 1220, height = 1000; // i have set my window size to be 800 x 600
		//b->InitalizeBoard(width, height);
		InitRandomizer(); // seed the random number generator...
		glutInit(&argc, argv); // initialize the graphics library...
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
		glutInitWindowPosition(0, 0); // set the initial position of our window
		glutInitWindowSize(width, height); // set the size of our window
		glutCreateWindow("PF Project"); // set the title of our game window
		SetCanvasSize(width, height); // set the number of pixels...
		////////////////// Reading Data into File 
		readDataFromFile(ar,Player);
		////////// Performing Function On the Data 
		LEADERBOARD(Player, ar);
		//////////// Writing Data Again into the file

		writeDataToFile(ar, Player);
		///////////// Game menue Functions Which Start the Game .
		MenueDisplay();
		
		/*glutDisplayFunc(GameDisplay);*/
		/*glutMouseFunc(MouseClicked);*/
		/*glutDisplayFunc(GameDisplay);*/
		// Register your functions to the library,
		// you are telling the library names of function to call for different tasks.
		//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
		//glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
		glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
		glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
		// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
		glutTimerFunc(1000.0, Timer, 0);
		glutMouseFunc(HandleMouseClicked);
		glutPassiveMotionFunc(MouseMoved);//Mouse
		glutMotionFunc(MousePressedAndMoved);//Mouse
		// now handle the control to library and it will call our registered functions when
		// it deems necessary...
		glutMainLoop();
		return 1;
	}


#endif /* AsteroidS_CPP_ */
