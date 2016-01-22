#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

# define line_01 "              ___                _____________      _____________         \n"
# define line_02 "             |   |              |             |    |             |        \n"
# define line_03 "             |   |              |    _____    |    |    _____    |        \n"
# define line_04 "             |   |              |   |     |   |    |   |     |   |        \n"
# define line_05 "             |   |              |   |     |   |    |   |_____|   |        \n"
# define line_06 "             |   |              |   |     |   |    |             |        \n"
# define line_07 "             |   |              |   |     |   |    |            /	       \n"
# define line_08 "             |   |              |   |     |   |    |    _____   \\      \n"
# define line_09 "             |   |              |   |     |   |    |   |     |   |        \n"
# define line_10 "             |   |              |   |     |   |    |   |     |   |        \n"
# define line_11 "             |   |__________    |   |_____|   |    |   |_____|   |        \n"
# define line_12 "             |              |   |             |    |             |        \n"
# define line_13 "             |______________|   |_____________|    |_____________|        \n"
# define line_14 "\n\n"
# define line_15 "                               Legion of Balloon                \n\n"
# define line_16 "                      ___________________________________       \n"
# define line_17 "                    /                                     \\    \n"
# define line_18 "                   |     | 1 |     -     Play              |    \n"
# define line_19 "                   |     | 2 |     -     Instructions      |    \n"
# define line_20 "                   |     | 3 |     -     Set Difficulty    |    \n"
# define line_21 "                   |     | 0 |     -     Exit              |    \n"
# define line_22 "                    \\ ___________________________________ /    "

# define end_01 "                           __________________________       \n"
# define end_02 "                         /                            \\    \n"
# define end_03 "                        |                              |    \n"
# define end_04 "                        |        | GAME OVER |         |    \n"
# define end_05 "                        |                              |    \n"
# define end_06 "                         \\ __________________________ /    \n"

# define leave_01 "                           __________________________       \n"
# define leave_02 "                         /                            \\    \n"
# define leave_03 "                        |                              |    \n"
# define leave_04 "                        |        | GOOD - BYE |        |    \n"
# define leave_05 "                        |                              |    \n"
# define leave_06 "                         \\ __________________________ /    \n"

# define invalid_01 "                           __________________________       \n"
# define invalid_02 "                         /                            \\    \n"
# define invalid_03 "                        |                              |    \n"
# define invalid_04 "                        |      | INVALID CHOICE |      |    \n"
# define invalid_05 "                        |                              |    \n"
# define invalid_06 "                         \\ __________________________ /    \n"

# define instruction_01 "                         _______________________________  \n"
# define instruction_02 "                       /                                 \\    \n"
# define instruction_03 "                      |                                   |    \n"
# define instruction_04 "                      |      W    -  Move Archer Up       |    \n"
# define instruction_05 "                      |      S    -  Move Aecher Down     |   \n"
# define instruction_06 "                      |    SPACE  -  Fire Arrow           |    \n"
# define instruction_07 "                      |                                   |    \n"
# define instruction_08 "                       \\ _______________________________ /    \n"
# define instruction_09 "                                                          \n"

# define level_01 "                     _______________________________  \n"
# define level_02 "                   /                                 \\    \n"
# define level_03 "                  |                                   |    \n"
# define level_04 "                  |      1: Easy                      |    \n"
# define level_05 "                  |      2: Normal                    |    \n"
# define level_06 "                  |      3: Hard                      |   \n"
# define level_07 "                  |      4: Rigged Carnival Game      |    \n"
# define level_08 "                  |                                   |    \n"
# define level_09 "                   \\ _______________________________ /    \n"
# define level_10 "                                                           \n"

# define highScore_01 "          _______________________________________________________  \n"
# define highScore_02 "        /                                                         \\    \n"
# define highScore_03 "       |                                                           |    \n"
# define highScore_04 "       |                     Congratulations!                      |    \n"
# define highScore_05 "       |      You have beaten the old high score of "  
# define highScore_06 " points       |\n" 
# define highScore_07 "       |                with a score of "           
# define highScore_08 " points                   |\n" 
# define highScore_09 "       |                                                           |    \n"
# define highScore_10 "        \\ _______________________________________________________ /    \n"
# define highScore_11 "                                                             \n"


const int ROWS = 23;
const int COLS = 43;


const int difficulties = 4; // number of difficulty levels
int highScores[difficulties]; // array to hold a high score for each difficulty level in order

char gameSpace[ROWS][COLS];  // game map with borders

// setup and main game section
void frontPageMenu(); // prints main menu
void gameOverMenu(); // prints game over screen
void leaveMenu(); // prints game exit screen
void levelMenu(); // prints difficulty menu
void instructionMenu(); // prints instruction menu
void highScoreMenu(int &highScore, int &points); // prints high score congratulations screen
void invalidChoice();  // menu that appears if an invalid user input is entered
void game(int &diff);  // overal game function
void setDifficulty(int &diff); // sets game difficulty
void createMap(int &diff); // puts borders in game map according to difficulty
void printArray(char gameArray[ROWS][COLS]); // prints array to screen

// update section
int update(int diff);  // the function in which the main part of the game runs
char keyInput();  // takes in and returns keyboard input
void saveHighScore(int &points, int &highScore, int &diff);  // overwrites new high score to file if it is higher than old high score
void setCursor(int row, int col);  // places cursor in console screen

// classes section
class Mobile  // superclass of all objects
{
	public:
		Mobile();
		void printObject(int height, int width);  // print object from array to screen
		void eraseObject(int height, int width);  // remove object from underlying array and screen
		int row;  // row position
		int col;  // column position
};

class Balloon: public Mobile  // subclass for balloon objects
{
	public:
		Balloon();
		void placeObject(int row, int col); // place balloon in array
		void moveBalloonUp(); // moves balloon up in the array

		// next three are for collision detection
		int getBalloonY();
		int getBalloonX();
		int getBalloonY2();

		// next two are object size
		int height;
		int width;

	private:
		// collision detection variables
		int yPosition;
		int y2Position;
		int xPosition;
};

class Archer: public Mobile // subclass for archer objects (see balloon subclass)
{
	public:
		Archer();
		void placeObject(int row, int col);
		void moveArcherUp();
		void moveArcherDown();
		int getArcherY();
		int height;
		int width;
	private:
		int yPosition;
		int xPosition;

};

class Arrow: public Mobile  // subclass for arrow objects (see balloon subclass)
{
	public:
		Arrow();
		void placeObject(int row, int col);
		void moveArrowRight();
		int getArrowY();
		int getArrowX();
		int height;
		int width;
	private:
		int yPosition;
		int xPosition;
};


// MAIN CODE

int main()
{
	char userInput;
	int diff = 10;  // initialize to normal difficulty
	while (true)
	{
		userInput = ' '; // reset each loop
		frontPageMenu(); // puts menu and game in a loop until someone breaks it in the menu
		while (!_kbhit())
		{
		}
		userInput = keyInput();
		system("cls");  // clear the screen
		switch (userInput)
		{
			case '0':
				leaveMenu(); // print exit menu and end program
				break;
			case '1':
				game(diff); // run game
				break;
			case '2':
				instructionMenu(); // display instructions
				break;
			case '3':
				setDifficulty(diff); // change difficulty levels
				break;
			default:
				invalidChoice();  // print invalid choice notification
				system("pause");
		}
	}
	system("pause");
	return 0;
}


// SETUP AND MAIN GAME SECTION

void frontPageMenu() // prints front page menu
{
	system("Color B");
	{
		cout << line_01 << line_02 << line_03 << line_04 << line_05 << line_06 << line_07 << line_08 << line_09 << line_10 
			 << line_11 << line_12 << line_13 << line_14 << line_15 << line_16 << line_17 << line_18 << line_19 << line_20 
			 << line_21 << line_22 << endl;
	}
}


void gameOverMenu() // prints game over menu
{
	system("cls");
	system("Color A");
	cout << "\n\n\n\n\n\n\n\n\n"
		 << end_01 << end_02 << end_03 << end_04 << end_05 << end_06
		 << "\n\n\n\n\n\n\n\n\n";
	system("pause");
}

void invalidChoice() // prints invalid choice screen
{
	system("Color A");
	cout << "\n\n\n\n\n\n\n\n\n"
		 << invalid_01 << invalid_02 << invalid_03 << invalid_04 << invalid_05 << invalid_06
		 << "\n\n\n\n\n\n\n\n\n";
}

void leaveMenu() // prints game exit screen
{
	system("Color B");
	cout << "\n\n\n\n\n\n\n\n\n"
		 << leave_01 << leave_02 << leave_03 << leave_04 << leave_05 << leave_06
		 << "\n\n\n\n\n\n\n\n\n";
	Sleep(2000);
	exit(0);
}

void levelMenu() // prints difficulty menu
{
	system("Color B");
	cout << "\n\n\n\n\n\n\n\n\n\n\n"
		 << level_01 << level_02 << level_03 << level_04 << level_05 
		 << level_06 << level_07 << level_08 << level_09 << level_10
		 << "\n\n\n\n\n\n\n";
}

void instructionMenu() // prints instruction menu
{
	system("Color B");
	cout << "\n\n\n\n\n\n\n\n\n\n"
		 << instruction_01 << instruction_02 << instruction_03 << instruction_04 << instruction_05 
		 << instruction_06 << instruction_07 << instruction_08 << instruction_09
		 << "\n\n\n\n\n\n\n\n";
	system("pause");
}

void highScoreMenu(int &highScore, int &points) // prints high score congratulations screen
{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\n"
			 << highScore_01 << highScore_02 << highScore_03 << highScore_04 << highScore_05 
			 << highScore << highScore_06 << highScore_07 << points << highScore_08 
			 << highScore_09 << highScore_10 << highScore_11
			 << "\n\n\n\n\n\n\n";
		system("pause");
		system("cls");
}

void game(int &diff) // function that gets called to run the game
{
	createMap(diff); // fill borders in game map array based on difficulty

	system("cls");  // clear the screen

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	switch(diff)  // set colors based on difficulty
	{
			case 5:
				SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				break;
			case 10:
				SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				break;
			case 15:
				SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				break;
			case 30:
			default:
				SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED);
				break;
	}


	printArray(gameSpace); // print game map array borders to screen
	update(diff);
}

void setDifficulty(int &diff)
{
	levelMenu();
	while (!_kbhit())  // wait until keystroke
		{
		}
	int userInput = keyInput();
	system("cls");  // clear the screen
	switch (userInput) // convert user input to difficulty level
		{
			case '1':
				diff = 5; 
				break;
			case '2':
				diff = 10;
				break;
			case '3':
				diff = 15;
				break;
			case '4':
				diff = 30;
				break;
			default:
				invalidChoice();
				system("pause");
		}
}

void createMap(int &diff) // create game borders based on difficulty
{
	for (int i = 0; i<ROWS; i++)  // filling the center with blanks
	{
		for (int j = 1; j<COLS; j++)  
		{
			gameSpace[i][j] = ' ';
		}
	}

	for (int i = 0; i<ROWS; i++)  // left/right borders
	{
		gameSpace[i][0] = '|';
		gameSpace[i][(diff+10)+1] = '|';
	}

	
	for (int j = 0; j<=(diff+10)+1; j++)  // top/bottom borders
	{
		gameSpace[0][j] = '-';
		gameSpace[ROWS-1][j] = '-';
	}
}

void printArray(char array[ROWS][COLS]) // print array to screen
{
	for (int i = 0; i<ROWS; i++)  
	{
		cout << ' ';
		for (int j = 0; j<COLS; j++)  
		{
			cout << array[i][j];
		}
		cout << endl;
	}
}


// UPDATE SECTION

int update(int diff) // core game function
{
	int lives = 9; // number of balloons you can miss
	int points = 0; 
	int highScore;

	ifstream inStream;
	inStream.open("HighScore.txt");
	for (int i = 0; i < difficulties; i++)
	{
		inStream >> highScores[i]; // converts text file to array of high scores for each difficulty level
	}
	inStream.close();

	switch(diff) // loads appropriate high score for difficulty level
	{
	case 5:
		highScore = highScores[0];
		break;
	case 10:
		highScore = highScores[1];
		break;
	case 15:
		highScore = highScores[2];
		break;
	case 30:
		highScore = highScores[3];
		break;
	default:
		highScore = 0;
		break;
	}

	// print game info to bottom of game screen
	setCursor(ROWS + 1, 1);
	cout << "Points: " << points;

	setCursor(ROWS + 1, 15);
	cout << "Balloons: " << lives;

	setCursor(ROWS + 1, 30);
	cout << "High Score: " << highScore;

	bool arrowPresent = false; // there is no arrow initially present on the screen

	bool balloonPresent = false; // no balloon initially present on screen

	// create and place initial objects
	Balloon balloon;  
	Arrow arrow;
	Archer archer;
	archer.placeObject(10,3);
	archer.printObject(3,3);

	while(true)
	{
		if( (arrow.getArrowX() == balloon.getBalloonX()) && ((arrow.getArrowY() == balloon.getBalloonY()) || (arrow.getArrowY() == balloon.getBalloonY2())))  // if collision between arrow and balloon
		{
			balloon.eraseObject(2,2); // erase balloon
			balloonPresent = false;
			arrow.eraseObject(2,2); // erase arrow
			arrowPresent = false;
			points++;              // increase points
			setCursor(ROWS + 1, 1);
			cout << "Points: " << points;

			// note: collision only occurs if arrow tip is just next to left of the balloon, otherwise the arrow "passed by" the balloon and did not pop it
		}

		if (balloonPresent == false)  // if no balloon, make new one in a random place
		{
			balloon.placeObject(ROWS - 3, (rand()%diff)+10);  // increased difficulty increases range of balloon drops
			balloon.printObject(2,2);
			balloonPresent = true;
			Sleep(150);
		}

		if (balloon.getBalloonY() > 2)  // if balloon present and not at top, move it up
		{
			balloon.moveBalloonUp();
			Sleep(150);
		}

		else  // if balloon hits the top, erase balloon
		{
			balloon.eraseObject(2, 2);
			lives--;
			setCursor(ROWS + 1, 15);
			cout << "Balloons: " << lives << " ";

			if (lives < 0) // check to see if out of lives
			{
				saveHighScore(points, highScore, diff);
				gameOverMenu();
				return 0;
			}

			balloon.placeObject(ROWS - 3,(rand()%diff)+10); // create new balloon in a random place
			balloon.printObject(2,2);
		}
		
		if (arrowPresent == true && arrow.getArrowX() < (diff+10)) // if arrow not at border, move it right
		{
			arrow.moveArrowRight();
			Sleep(10);
		
		}
		
		if(arrow.getArrowX() >= (diff+10)) //erase the arrow if it reaches the border 
		{
			arrow.eraseObject(2,2);
			arrowPresent = false;

		}

		// check for keystrokes
		if (_kbhit() == true)  // checks for keyboard input and executes it if present. If not, it moves on.
		{
			char input = keyInput();
			//cout << input;

			switch (input)
			{
				case 'w': // up
				case 'W':
					if( archer.getArcherY() > 1) // if archer not at top, move up
						archer.moveArcherUp(); 
					break;
				case 's': // down
				case 'S':
					if(archer.getArcherY() < ROWS-4) // if archer not at bottom, move down
						archer.moveArcherDown();
					break;
				case ' ': // arrow
 					if(arrowPresent == false) // if no arrow, create arrow
					{	
						arrow.placeObject(archer.getArcherY() + 1,6);
						arrow.printObject(1,2);
						arrowPresent = true;
					}
					break;
				case 'q': // quit
				case 'Q': 
					saveHighScore(points, highScore, diff);
					gameOverMenu();
					return 0;
				default:
					break;
			}
		}
	}
}

char keyInput()  // gets key input from user
{
	char key = getch();
	return key;
}

void saveHighScore(int &points, int &highScore, int &diff)  // checks for new high score and saves all high scores back to text file
{
	if (points > highScore)
	{

		switch(diff) // stores high score in the correct difficulty level slot of array
		{
		case 5:
			highScores[0] = points;
			break;
		case 10:
			highScores[1] = points;
			break;
		case 15:
			highScores[2] = points;
			break;
		case 30:
			highScores[3] = points;
			break;
		default:
			highScore = 0;
			break;
		}

		ofstream outStream;  // save high scores back to file
		outStream.open("HighScore.txt");
		for (int i = 0; i < difficulties; i++)
		{
			outStream << highScores[i] << endl;
		}
		outStream.close();

		highScoreMenu(highScore, points); // print high score congratulations screen
		
	}
}

void setCursor(int row, int col)  // sets cursor at the requested row and column on screen
{
	COORD coordinate;
	coordinate.X = col;
	coordinate.Y = row;
	SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), coordinate);
}


// CLASSES SECTION

// MOBILE CLASS
Mobile::Mobile()  // superclass for all mobile objects
{
	row = 0;
	col = 0;
}

void Mobile::printObject(int height, int width) // prints object to screen
{
	for (int line = row; line < row+height; line++)
	{
		for (int space = col; space < col+width; space++)
		{
			setCursor(line, space);
			cout << gameSpace[line][space];
		}
	}
}

void Mobile::eraseObject(int height, int width) // erases object from array and screen
{
	for (int line = row; line < row+height; line++)
	{
		for (int space = col; space < col+width; space++)
		{
			gameSpace[line][space] = ' ';    // remove object from underlying game array
			setCursor(line, space);
			cout << gameSpace[line][space];  // remove from screen
		}
	}
}

// BALLOON SUBCLASS
Balloon::Balloon()
{
	height = 2;
	width = 2;
}

void Balloon::placeObject(int Brow, int Bcol)  // fills a section of array with balloon shape
{
	row = Brow;
	col = Bcol;
	gameSpace[row][col] = '/';
	gameSpace[row][col+1] = '\\';
	gameSpace[row+1][col] = '\\';
	gameSpace[row+1][col+1] = '/';
}

void Balloon::moveBalloonUp() // erases old balloon, moves balloon up in array, and prints it out to screen
{
	eraseObject(height, width);
	row--;
	placeObject(row, col);
	printObject(height, width);
}

int Balloon::getBalloonY()  // get lower y coordinate of collidable balloon area
{
	yPosition = row + 1;
	return yPosition;
}

int Balloon::getBalloonY2()  // get upper y coordinate of collidable balloon area
{
	y2Position = row + 2;
	return y2Position;
}

int Balloon::getBalloonX() // get x coordinate of collidable balloon area
{
	xPosition = col;
	return xPosition;
}

// ARCHER SUBCLASS (see balloon subclass for equivalent function descriptions)
Archer::Archer()
{
	height = 3;
	width = 3;
}

void Archer::placeObject(int Arow, int Acol)  // fills a section of array with archer shape
{
	row=Arow;
	col=Acol;
	gameSpace[row][col] = '(';
	gameSpace[row][col+1] = ')';
	gameSpace[row][col+2] = ' ';
	gameSpace[row+1][col] = '(';
	gameSpace[row+1][col+1] = ')';
	gameSpace[row+1][col+2] = '>';
	gameSpace[row+2][col] = '/';
	gameSpace[row+2][col+1] = '\\';
	gameSpace[row+2][col+2] = ' ';
}

void Archer::moveArcherUp()
{
	eraseObject(height, width);
	row--;
	placeObject(row, col);
	printObject(height, width);
}

void Archer::moveArcherDown()
{
	eraseObject(height, width);
	row++;
	placeObject(row, col);
	printObject(height, width);
}

int Archer::getArcherY() // get bow height of archer
{
	yPosition = row;
 	return yPosition;
}


// ARROW SUBCLASS (see balloon subclass for equivalent function descriptions)
Arrow::Arrow()
{
	height = 1;
	width = 2;
}

void Arrow::placeObject(int Arow, int Acol)  // fills a section of array with arrow shape
{
	row = Arow;
	col = Acol;
	gameSpace[row][col] = '-';
	gameSpace[row][col+1] = '>';
}

void Arrow::moveArrowRight()
{
	eraseObject(height, width);
	col++;
	placeObject(row, col);
	printObject(height, width);
}

int Arrow::getArrowY()
{
	yPosition = row + 1;
	return yPosition;
}

int Arrow::getArrowX()
{
	xPosition = col + 1;
	return xPosition;
}

