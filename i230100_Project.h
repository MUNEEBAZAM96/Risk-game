// Header File No . 1
// Name : Muneeb_ur_Rehman 
// Class : SE(B)
// Roll Number: 23i0100
// Course Instructor : Doctor Naveed Ahmad ;
// 
// 
// 
// 
// 
///////////////////////////// This is a Header  File Which has all Game Functions and Global Variable ///////////////////////////////
#include<iostream>
#include<iomanip>
#include<fstream>
#include<time.h>
#include<cstdlib>
using namespace std;
///////// Dice Function Which Gives number 0 .......... 6 ;//////////////////////////////
int Dice() {
	return rand() % 7;
}

//////////////////////////////////////////// Global Variables ////////////////////////////////////////////////
int current_page = 0;
int name_p = 0;
int Troops1 = 40;
int Troops2 = 40;
int Troops3 = 40;
int Troops4 = 40;
int Number_dice1;
int Number_dice2;
int Number_dice3;
int Number_dice4;
int Number_dice5;
int Number_dice6;
int c;
int arr[56];
static string Player_1;
static string Player_2;
static string Player_3;
static string Player_4;
static string Player_5;
static string Player_6;
bool flag = true
, temp = true;
int Count = 2;
int wood = 0 ,copper;//// Turn Check 
int T1 = 0,T2 = 0, T3 = 0 ,T4 = 0;
int ColP1, ColP2, ColP3, ColP4;///////////// Chosing Colour   Four Players  
int copy = 0 ;
//////////////////////////  Dice  Decision ////////////////////////////////////////////
int Dec1 = 0, Dec2 = 0;

///////////////////////////////////// Colour Selection /////////////////////////////////////////////// 5 RED ///// 2 Brown /////   68 Blue  ////  yellow 23  Orange 15  Cyan 48 ;
int Col1 = 5, Col2 = 68, Col3 = 2 , Col4 = 23  , col5 = 48 , col6 = 15;
///////////////////////////////////////////// Leader Board ////////////////////////////
////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int ar[10] = { 0,0,0,0,0,0,0,0,0,0};
string Player[10] = { Player_1,"Player_2","Player_3","Player_4","Player_5","Player_6"," Player_7","Player_8","Player_9","Player_10"};


static  string dice;
//////////////////////// Player _ Choice Function ////////////////////////////////
 void PlayerChoice(){
	 // Set a gradient background
	 glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue background
	 glClear(GL_COLOR_BUFFER_BIT);
	 DrawCircle(1086, 7, 400, colors[YELLOW_GREEN]);
	DrawRoundRect(320, 825, 250, 90, colors[BLUE]
		, 40);
	DrawRoundRect(65, 625, 250, 90, colors[BLUE]
		, 40);
	DrawRoundRect(625, 625, 250, 90, colors[BLUE]
		, 40);
	DrawRoundRect(235, 395, 250, 90, colors[BLUE]
		, 40);
	DrawLine(60,940 , 900, 940, 10, colors[RED]);
	DrawLine(60,940, 60, 360, 10, colors[RED]);
	DrawLine(60, 360, 900, 360, 10, colors[RED]);
	DrawLine(900,360 ,900,940 , 10, colors[RED]);
	
	
	DrawString(350, 850, "Number Of Players ", colors[CYAN]);

	DrawString(120, 660, "  2_Player! ", colors[BLACK]);

	DrawString(670, 660, " 4_Player!", colors[BLACK]);

	DrawString(310, 430, "6_Player!", colors[BLACK]);
	
	glutSwapBuffers();
}
 /// <summary>
 /// //////////////////  Player 1 Choice Function 
 /// </summary>
 void ChosePlayer1() {
	 // Set a gradient background
	 glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue background
	 glClear(GL_COLOR_BUFFER_BIT);
	 for (int i = 0; i < 300; i++) {
		 DrawString(rand() % 1200, rand() % 1000, "*", colors[WHITE]);
	 }
	 DrawCircle(1086, 7, 400, colors[YELLOW_GREEN]);
	 DrawLine(0, 800, 1200, 800, 50, colors[RED]);
	 DrawRoundRect(230, 200, 600, 800, colors[ORANGE]
		 , 40);
	 DrawString(450, 900, " Name PLayer 1:", colors[BLACK]);
	 DrawRoundRect(400, 750, 260, 90, colors[WHITE], 40);
	 DrawString(450, 780, Player_1, colors[BLACK]);
	 DrawString(450,650, "Choose Colour", colors[BLACK]);
	 DrawRoundRect(275, 495, 250, 90, colors[RED]
		 , 40);
	 DrawRoundRect(565, 495, 250, 90, colors[BLUE]
		 , 40);
	 DrawRoundRect(320, 90, 300, 90, colors[BROWN], 40);
	 DrawString(350, 130, "Press here to Move next", colors[GOLD]);
	 glutSwapBuffers();// do not modify this line...
 }

  //////////////////////////  Player 2  Choice Function ////////////

 void ChosePlayer2() {
	  // Setting page name 
	 current_page = 3;
	 // Set a gradient background
	 glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue background
	 glClear(GL_COLOR_BUFFER_BIT);
	 for (int i = 0; i < 300; i++) {
		 DrawString(rand() % 1200, rand() % 1000, "*", colors[YELLOW]);
	 }
	 DrawCircle(1086, 7, 400, colors[YELLOW_GREEN]);
	 DrawLine(0, 800, 1200, 800, 50, colors[RED]);
	 DrawRoundRect(230, 200, 600, 800, colors[BLUE]
		 , 40);
	 DrawString(450, 900, "Name of Player_2 ", colors[BLACK]);
	 DrawRoundRect(400, 750, 260, 90, colors[WHITE], 40);
	 DrawString(450, 780,Player_2, colors[BLACK]);


	 DrawRoundRect(400, 250, 260, 90, colors[GOLD], 40);
	 DrawString(430,290, "xx LETS PLAY xx !", colors[ORANGE]);
	 glutSwapBuffers();// do not modify this line..
 }



 /////////////////////////////////////// Name Input Function of Player 1 //////////////////////////////////////////////
 void ChosePlayer14() {
	 current_page = 5;
	 glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue background
	 glClear(GL_COLOR_BUFFER_BIT);
	 for (int i = 0; i < 300; i++) {
		 DrawString(rand() % 1200, rand() % 1000, "*", colors[YELLOW]);
	 }
	 DrawCircle(1086, 7, 400, colors[YELLOW_GREEN]);
	 DrawLine(0, 800, 1200, 800, 50, colors[RED]);
	 DrawRoundRect(230, 200, 600, 800, colors[BLUE]
		 , 40);
	 DrawString(450, 900, "Name of Player_1 ", colors[BLACK]);
	 DrawRoundRect(400, 750, 300, 90, colors[WHITE], 40);
	 DrawString(450, 780, Player_1, colors[BLACK]);


	 DrawRoundRect(400, 450, 260, 90, colors[GOLD], 40);
	 DrawString(400, 490, "XX PRESS HERE XX !", colors[ORANGE]);
	 glutSwapBuffers();// do not modify this line..
 }
 /////////////////////////////////////// Name Input Function of Player 2 //////////////////////////////////////////////
 void ChosePlayer24() {
	 current_page = 6;
	 glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue background
	 glClear(GL_COLOR_BUFFER_BIT);
	 for (int i = 0; i < 300; i++) {
		 DrawString(rand() % 1200, rand() % 1000, "*", colors[YELLOW]);
	 }
	 DrawCircle(1086, 7, 400, colors[YELLOW_GREEN]);
	 DrawLine(0, 800, 1200, 800, 50, colors[RED]);
	 DrawRoundRect(230, 200, 600, 800, colors[BLUE]
		 , 40);
	 DrawString(450, 900, "Name of Player_2 ", colors[BLACK]);
	 DrawRoundRect(400, 750, 300, 90, colors[WHITE], 40);
	 DrawString(450, 780, Player_2, colors[BLACK]);


	 DrawRoundRect(400, 550, 260, 90, colors[GOLD], 40);
	 DrawString(400, 590, "XX PRESS HERE XX !", colors[ORANGE]);
	 glutSwapBuffers();// do not modify this line..
 }
   /////////////////////////////////////// Name Input Function of Player 3 //////////////////////////////////////////////
 void ChosePlayer3() {
	 current_page = 7;
	 glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue background
	 glClear(GL_COLOR_BUFFER_BIT);
	 for (int i = 0; i < 300; i++) {
		 DrawString(rand() % 1200, rand() % 1000, "*", colors[YELLOW]);
	 }
	 DrawCircle(1086, 7, 400, colors[YELLOW_GREEN]);
	 DrawLine(0, 800, 1200, 800, 50, colors[RED]);
	 DrawRoundRect(230, 200, 600, 800, colors[BLUE]
		 , 40);
	 DrawString(450, 900, "Name of Player_3 ", colors[BLACK]);
	 DrawRoundRect(400, 750, 300, 90, colors[WHITE], 40);
	 DrawString(450, 780, Player_3, colors[BLACK]);


	 DrawRoundRect(400, 550, 260, 90, colors[GOLD], 40);
	 DrawString(420, 590, "XX PRESS HERE XX !", colors[ORANGE]);
	 glutSwapBuffers();// do not modify this line..
 }
                                      /////////////////////// NAME INPUT OF PLAYER 4  ///////////////////////////////////////////////
 void ChosePlayer4() {
	 current_page = 8;
	 glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue background
	 glClear(GL_COLOR_BUFFER_BIT);
	 for (int i = 0; i < 300; i++) {
		 DrawString(rand() % 1200, rand() % 1000, "*", colors[YELLOW]);
	 }
	 DrawCircle(1086, 7, 400, colors[YELLOW_GREEN]);
	 DrawLine(0, 800, 1200, 800, 50, colors[RED]);
	 DrawRoundRect(230, 200, 600, 800, colors[BLUE]
		 , 40);
	 DrawString(450, 900, "Name of Player_4 ", colors[BLACK]);
	 DrawRoundRect(400, 750, 300, 90, colors[WHITE], 40);
	 DrawString(450, 780, Player_4, colors[BLACK]);


	 DrawRoundRect(400, 450, 260, 90, colors[GOLD], 40);
	 DrawString(400, 490, "XX PRESS HERE XX !", colors[YELLOW]);
	 glutSwapBuffers();// do not modify this line..
 }

 /////////////////////// NAME INPUT OF PLAYER 5  ///////////////////////////////////////////////
 void ChosePlayer5() {
	 glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue background
	 glClear(GL_COLOR_BUFFER_BIT);
	 for (int i = 0; i < 300; i++) {
		 DrawString(rand() % 1200, rand() % 1000, "*", colors[YELLOW]);
	 }
	 DrawCircle(1086, 7, 400, colors[YELLOW_GREEN]);
	 DrawLine(0, 800, 1200, 800, 50, colors[RED]);
	 DrawRoundRect(230, 200, 600, 800, colors[BLUE]
		 , 40);
	 DrawString(450, 900, "Name of Player_5 ", colors[BLACK]);
	 DrawRoundRect(400, 750, 300, 90, colors[WHITE], 40);
	 DrawString(450, 780, Player_5, colors[BLACK]);


	 DrawRoundRect(400, 450, 260, 90, colors[GOLD], 40);
	 DrawString(400, 490, "XX PRESS HERE XX !", colors[YELLOW]);
	 glutSwapBuffers();// do not modify this line..
 }


 /////////////////////// NAME INPUT OF PLAYER 6 ///////////////////////////////////////////////
 void ChosePlayer6() {
	 glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue background
	 glClear(GL_COLOR_BUFFER_BIT);
	 for (int i = 0; i < 300; i++) {
		 DrawString(rand() % 1200, rand() % 1000, "*", colors[YELLOW]);
	 }
	 DrawCircle(1086, 7, 400, colors[YELLOW_GREEN]);
	 DrawLine(0, 800, 1200, 800, 50, colors[RED]);
	 DrawRoundRect(230, 200, 600, 800, colors[BLUE]
		 , 40);
	 DrawString(450, 900, "Name of Player_6 ", colors[BLACK]);
	 DrawRoundRect(400, 750, 300, 90, colors[WHITE], 40);
	 DrawString(450, 780, Player_6, colors[BLACK]);


	 DrawRoundRect(400, 450, 260, 90, colors[GOLD], 40);
	 DrawString(400, 490, "XX PRESS HERE XX !", colors[YELLOW]);
	 glutSwapBuffers();// do not modify this line..
 }

			
 
                               //////////////////////////////////// Chose Colour Function For Four players  ////////////////////////////////////////////////
 void ChooseColour41(int colour1 , int colour2 ,int colour3 , int colour4) {
	 current_page = 8;
	 // Setting  a gradient background   
	 glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue background
	 glClear(GL_COLOR_BUFFER_BIT);
	 for (int i = 0; i < 300; i++) {
		 DrawString(rand() % 1200, rand() % 1000, "*", colors[GOLD]);
	 }
	 DrawRoundRect(380, 870, 260, 90, colors[BLUE], 40);
	 DrawString(430, 900, "Player_1", colors[BLACK]);
	 DrawRoundRect(300, 670, 260, 90, colors[colour1], 40);
	 DrawRoundRect(480, 570, 260, 90, colors[colour2], 40);
	 
	 glutSwapBuffers();// do not modify this line..
		}
 ////////////////////////////////////////////   Chose Colour Function ///////////////////////////
 void ChooseColour42(int colour1, int colour2, int colour3) {
	 current_page = 8;
	 // Setting  a gradient background   
	 glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue background
	 glClear(GL_COLOR_BUFFER_BIT);
	 for (int i = 0; i < 300; i++) {
		 DrawString(rand() % 1200, rand() % 1000, "*", colors[GOLD]);
	 }
	 DrawRoundRect(380, 870, 260, 90, colors[BLUE], 40);
	 DrawString(430, 900, "Player_2", colors[BLACK]);
	 DrawRoundRect(300, 670, 260, 90, colors[colour1], 40);
	 DrawRoundRect(480, 570, 260, 90, colors[colour2], 40);
	 DrawRoundRect(300, 470, 260, 90, colors[colour3], 40);
	 DrawRoundRect(480, 370, 260, 90, colors[137], 40);

	 glutSwapBuffers();// do not modify this line..
 }
 /////////////////////////////////////////////////////////       Chose Colour Function ////////////////
 void ChooseColour43(int colour1, int colour2) {
	 current_page = 8;
	 // Setting  a gradient background   
	 glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue background
	 glClear(GL_COLOR_BUFFER_BIT);
	 for (int i = 0; i < 300; i++) {
		 DrawString(rand() % 1200, rand() % 1000, "*", colors[GOLD]);
	 }
	 DrawRoundRect(380, 870, 260, 90, colors[BLUE], 40);
	 DrawString(430, 900, "Player_2", colors[BLACK]);
	 DrawRoundRect(300, 670, 260, 90, colors[colour1], 40);
	 DrawRoundRect(480, 570, 260, 90, colors[colour2], 40);
	 DrawRoundRect(300, 470, 260, 90, colors[137], 40);
	 DrawRoundRect(480, 370, 260, 90, colors[137], 40);

	 glutSwapBuffers();// do not modify this line..
 }
 /////////////////////////////////////////// Colour Chose Function 
 void ChooseColour44(int colour1) {
	 current_page = 8;
	 // Setting  a gradient background   
	 glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue background
	 glClear(GL_COLOR_BUFFER_BIT);
	 for (int i = 0; i < 300; i++) {
		 DrawString(rand() % 1200, rand() % 1000, "*", colors[GOLD]);
	 }
	 DrawRoundRect(380, 870, 260, 90, colors[BLUE], 40);
	 DrawString(430, 900, "Player_2", colors[BLACK]);
	 DrawRoundRect(300, 670, 260, 90, colors[colour1], 40);
	 DrawRoundRect(480, 570, 260, 90, colors[137], 40);
	 DrawRoundRect(300, 470, 260, 90, colors[137], 40);
	 DrawRoundRect(480, 370, 260, 90, colors[137], 40);

	 glutSwapBuffers();// do not modify this line..
 }
 ///////////////////////////// Chose Colour 6 Player s ///////////////////////////////
   void ChooseColour4(int colour1, int colour2, int colour3, int colour4 , int colour5 , int colour6){
	 current_page = 8;
	 // Setting  a gradient background   
	 glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue background
	 glClear(GL_COLOR_BUFFER_BIT);
	 for (int i = 0; i < 300; i++) {
		 DrawString(rand() % 1200, rand() % 1000, "*", colors[GOLD]);
	 }
	 DrawRoundRect(380, 870, 260, 90, colors[BLUE], 40);
	 DrawString(430, 900, "Choose Colour", colors[BLACK]);
	 DrawRoundRect(300, 670, 260, 90, colors[colour1], 40);
	 DrawRoundRect(480, 570, 260, 90, colors[colour2], 40);
	 DrawRoundRect(300, 470, 260, 90, colors[colour3], 40);
	 DrawRoundRect(480, 370, 260, 90, colors[colour4], 40);
	 DrawRoundRect(300, 270, 260, 90, colors[colour5], 40);
	 DrawRoundRect(480, 170, 260, 90, colors[colour6], 40);
	 glutSwapBuffers();// do not modify this line..
 }

 /// <summary>
 /// ///////////// Instrunction Page 
 /// </summary>
 void Instruction() {
	 // Set a gradient background
	 glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue background
	 glClear(GL_COLOR_BUFFER_BIT);
	 for (int i = 0; i < 300; i++) {
		 DrawString(rand() % 1200, rand() % 1000, "*", colors[GOLD]);

	 }
	 DrawRoundRect(420, 870, 280, 80, colors[BROWN], 20);
	 DrawString(420, 900, " xxx INSTRUCTIONS xxx ", colors[ORANGE]);
	 DrawRoundRect(200, 730, 200, 80, colors[GREEN], 20);
	 DrawString(220, 770, " Objective :", colors[ORANGE]);
	 DrawString(160, 670, "  The Objective of game is Conquer the world by strategically deploying armies, capturing territories.", colors[ORANGE]);
	 DrawRoundRect(200, 570, 200, 80, colors[GREEN], 20);
	 DrawString(220, 590, " SET UP :", colors[ORANGE]);
	 DrawString(160, 500, " The more territories you own, the more armies you receive at the beginning of your turn.", colors[ORANGE]);
	 DrawString(400, 120, "Press here to Exit", colors[BLUE]);
	 glutSwapBuffers();// do not modify this line..
 }
 /// <summary>
 /// /////////// Credits page 
 /// </summary>
 void Credits() {
	 // Set a gradient background
	 glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue background
	 glClear(GL_COLOR_BUFFER_BIT);
	 for (int i = 0; i < 300; i++) {
		 DrawString(rand() % 1200, rand() % 1000, "*", colors[GOLD]);

	 }
	 DrawRoundRect(420, 870, 280, 80, colors[BROWN], 20);
	 DrawString(420, 900, " xxx CREDITS xxx ", colors[ORANGE]);
	 DrawRoundRect(200, 730, 200, 80, colors[GREEN], 20);
	 DrawString(220, 770, " Creater:", colors[ORANGE]);
	 DrawString(400, 680, " Muneeb ur Rehman  ", colors[ORANGE]);
	 DrawRoundRect(200, 570, 200, 80, colors[GREEN], 20);
	 DrawString(220, 590, " Roll No  :", colors[ORANGE]);
	 DrawString(460, 540, " 23i_0100  SE(B)", colors[ORANGE]);
	 DrawRoundRect(200, 370, 250, 80, colors[BROWN], 20);
	 DrawString(220, 390, "Course Instructor :", colors[ORANGE]);
	 DrawString(360, 300, "Doctor Naveed Ahmad !", colors[GOLD]);
	 DrawString(400,120, "Press here to Exit", colors[BLUE]);
	 glutSwapBuffers();// do not modify this line..
 }
  



 //////////////////////////////////////////////////////  Board For Four Players /////////////////////////////////////////////////////////
 

 

      