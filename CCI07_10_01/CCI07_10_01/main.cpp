/*

	Build mine sweeper.

*/

#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

using namespace std;

//#define FLUSH cin.ignore(numeric_limits<size_t>::max(),'\n');

enum STATE{ CLICK=-5, QMARK=-4, FLAG=-3, COVER=-2, BOMB=-1, EMPTY=0, };
int DIRECTIONS[8][2] = { {-1, 1}, {0, 1}, {1, 1},
					     {-1, 0},         {1, 0},
					     {-1,-1}, {0,-1}, {1,-1} };

enum CCOLOR{ BLACK=0, BLUE,   GREEN,  AQUA,  RED,  PURPLE,  YELLOW,  WHITE,
			 GRAY,    LBLUE, LGREEN, LAQUA, LRED, LPURPLE, LYELLOW, BWHITE };

	//0 = Black	8 = Gray
	//1 = Blue	9 = Light Blue
	//2 = Green a = Light Green
	//3 = Aqua	b = Light Aqua
	//4 = Red	c = Light Red
	//5 = Purple	d = Light Purple
	//6 = Yellow	e = Light Yellow
	//7 = White	f = Bright White

class Board{
private:
	bool **bombGrid; // Grid of where the bombs are.
	int **stateGrid; // Grid of the current state of the board.
	int numberOfBombs;
	int rows, colm;
	bool gameOver;
	int numberOfSquares;

	// We could have two grids. One that holds all the bombs locations and another that is the state of the grid.
	// The stateGrid holds all the information and only goes to the bombGrid for information on where the bombs are.
	// We can manipulate the stateGrid to what ever we want and check the bombGrid for important information.

public:
	Board();
	void gamePrefs();
	void buildBoard(int rows, int colm, int b);
	void setupBoard();
	void getMove(); // Get the player input.
	void makeMove(int x, int y, STATE pMove); // Apply move to game board.
	void revealSquare(int x, int y); // Reveal and update squares.
	void endGame(); // 
	void print(); // Print the game grid for the player.
	void printDebug(); // Print the bombGrid and the stateGrid.

	bool getGO(){ return gameOver; }
	void setGO(bool inB){ gameOver = inB; }

};

Board::Board(): stateGrid(nullptr), bombGrid(nullptr), numberOfBombs(0), rows(0), colm(0), gameOver(false),
				numberOfSquares(0){
	
}

/*

*/
void Board::gamePrefs(){
	gameOver = false;
	bool bad_input = true;
	do{
		int c;
		cout << "Choose difficulty." << endl;
		cout << "Easy(1), Medium(2), Hard(3): " ;

		cin >> c;
		if(cin.fail()){
			cout << "Input failed." << endl;
			cin.clear();
			//cin.ignore(numeric_limits<streamsize>::max(),'\n'); // Doesn't work with #include <Windows.h>
			cin.ignore(INT_MAX,'\n');
			continue;
		} else {
			//cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cin.ignore(INT_MAX,'\n');
		}

		switch(c){
			case 1: this->buildBoard(5, 5, 5);    this->setupBoard(); bad_input = false; break;
			case 2: this->buildBoard(10, 10, 20); this->setupBoard(); bad_input = false; break;
			case 3: this->buildBoard(15, 15, 45); this->setupBoard(); bad_input = false; break;
			default:
				cout << "Input out of range." << endl; break;
		};
	} while(bad_input);
}

/*
	Setup a new board to play on.
	rows: number of rows on the board.
	colm: number of colms on the board.
	b: number of bombs in play.

	What should be the smallest & largest board size?
	What should be the min & max number of bombs?
	We'll have preset boards so numbers don't get too crazy.
	1 row, 1 colm, 1000 bombs...
	With presets we don't need to check for crazy edge cases.
*/
void Board::buildBoard(int r, int c, int b){
	delete stateGrid; // Remove old grid.
	delete bombGrid; // Remove old grid.
	rows = r;
	colm = c;
	numberOfBombs = b; // Set number of bombs.
	numberOfSquares = r * c;

	// New state grid.
	stateGrid = new int*[rows]();
	for(int i=0; i<rows; i++){
		stateGrid[i] = new int[colm]();
	}

	// Initialize stateGrid.
	for(int i=0; i<rows; i++){
		for(int j=0; j<colm; j++){
			stateGrid[i][j] = COVER;
		}
	}

	bombGrid = new bool*[rows]();
	for(int i=0; i<rows; i++){
		bombGrid[i] = new bool[colm]();
	}
}

/*
	Randomize the current board.
*/
void Board::setupBoard(){
	// If we try to place the bombs randomly, on small boards with a high number of bombs, we could
	// end up looping a lagre number of times trying to place the last few bombs.
	// Instead of this, place the bombs in the grid and then swap spaces in the grid around.

	// Place the bombs in the grid.
	for(int i=0; i<numberOfBombs/rows; i++){
		int len = (i + 1)*colm > numberOfBombs ? ((i + 1) * 5) % numberOfBombs : colm;
		for(int j=0; j<len; j++){
			bombGrid[i][j] = true; // TRUE = bomb
		}
	}

	// We could just loop through the bombs again swapping them with something else, but we'll
	// cycle through the entire grid so every space get a change to swap.
	for (int i = 0; i<rows; i++) {\
		for (int j = 0; j<colm; j++) {
			int x = rand() % rows;
			int y = rand() % colm;
			if(bombGrid[i][j] != bombGrid[y][x]){ // Only swap if the spaces are different. Don't swap empty spaces or bombs with bombs.
				if(bombGrid[i][j] == true){ // Swap bomb into random space.
					bombGrid[y][x] = true; // bomb
					bombGrid[i][j] = false;
				} else { // Swap space with random found bomb.
					bombGrid[y][x] = false;
					bombGrid[i][j] = true; // bomb
				}	
			}
			
		}
	}
}

void Board::getMove(){
	bool badData = true;
	string input = "";
	int x, y, move;
	STATE osta;
	do{
		x = y = move = -1;
		cout << "Enter x and y: ";
		cin >> x >> y;
		
		if(cin.fail()){ // Player entered crap.
			cout << "x/y input failed." << endl;
			cin.clear();
			//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.ignore(INT_MAX, '\n');
			continue;
		} else {
			//cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//WE'll try to make it so the user can enter row + colm + move in one line.
		}
		

		if( x <= 0 || x > colm || y <= 0 || y > rows){ // Player entered spot outside of the grid.
			cout << "x or y out of range." << endl;
			badData = true;
			//cin.ignore(numeric_limits<streamsize>::max(), '\n'); // used for the row+colm+move feature.
			cin.ignore(INT_MAX,'\n');
			continue;
		}

		cout << "Enter action Click(1), Flag(2), Mark(3): ";
		cin >> move;
		cout << endl;

		if (cin.fail()) { // Player entered crap.
			cout << "Action input failed." << endl;
			cin.clear();
			//cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.ignore(INT_MAX,'\n');
			continue;
		} else {
			//cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.ignore(INT_MAX,'\n');
		}

		if( move < 1 || move > 3){
			cout << "Action out of range." << endl;
			badData = true;
			continue;
		} else {
			switch(move){
				case 1: osta = CLICK; break;
				case 2: osta = FLAG; break;
				case 3: osta = QMARK; break;
			};
			badData = false;
		}
	} while(badData);
	system("cls");
	makeMove(x-1, y-1, osta);
}

void Board::makeMove(int x, int y, STATE pMove){
	if(y < 0 || y >= rows){ return; }
	if (x < 0 || x >= colm) { return; }
	switch(pMove){
		case CLICK:
			if (stateGrid[y][x] == FLAG || stateGrid[y][x] == QMARK) { // Unmark square.
				stateGrid[y][x] = COVER;
			} else if(bombGrid[y][x] == true){ // Check to see if player stepped on a mine.
				this->endGame();
				return;
			} else {
				revealSquare(x, y);
				if(numberOfSquares == numberOfBombs){ // Check if there're no more squares.
					this->endGame();
					return;
				}
			}
			break;
		case FLAG:
			if(stateGrid[y][x] == COVER || stateGrid[y][x] == QMARK){ // Convert covered/qmark square to flag.
				stateGrid[y][x] = FLAG;
			} else if(stateGrid[y][x] == FLAG ){ // Unflag square.
				stateGrid[y][x] = COVER;
			} // else { } tried to flag revealed square.
			break;
		case QMARK:
			if(stateGrid[y][x] == COVER || stateGrid[y][x] == FLAG){ // Convert covered/flag to qmark.
				stateGrid[y][x] = QMARK;
			} else if(stateGrid[y][x] == QMARK){ // unmark square.
				stateGrid[y][x] = COVER;
			} // else { } tried to qmark an invalid square.
			break;
		default:
			break;
	};
}

void Board::revealSquare(int x, int y){
	if(stateGrid[y][x] == COVER || stateGrid[y][x] == FLAG || stateGrid[y][x] == QMARK){
		int sstate = 0;
		for(int i=0; i<8; i++){
			int tx = x + DIRECTIONS[i][0];
			int ty = y + DIRECTIONS[i][1];
			if(tx < 0 || tx >= colm || ty < 0 || ty >= rows){ continue; }
			if(bombGrid[ty][tx] == true){
				sstate++;
			}			
		}
		stateGrid[y][x] = sstate;
		numberOfSquares--;
		if(sstate == 0){ // Square was empty so reveal other squares.
			for (int i = 0; i<8; i++) {
				int tx = x + DIRECTIONS[i][0];
				int ty = y + DIRECTIONS[i][1];
				if (tx < 0 || tx >= colm || ty < 0 || ty >= rows) { continue; }
				revealSquare(tx, ty);
			}
		}
	}
}

void Board::endGame(){
	gameOver = true;
	cout << "Game over." << endl;
	for(int i=0; i<rows; i++){
		for(int j=0; j<colm; j++){
			if(this->bombGrid[i][j] == true){
				this->stateGrid[i][j] = BOMB;
			}
		}
	}
	this->print();
	if(numberOfSquares == numberOfBombs){
		cout << "The winner is you!" << endl;
	} else {
		cout << "You died." << endl;
	}
}

/*
	Print the current board.
*/

void Board::print(){
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (stateGrid == nullptr || bombGrid == nullptr) {
		cout << "No grid." << endl;
		return;
	}
	// Numbers across top.
	cout << "    ";
	for(int i=1; i<=colm; i++){
		cout << ' ' << setw(2) << left << i;
	}
	cout << endl;

	for(int i=0; i<rows; i++){
		cout << setw(3) << right << i+1 << ' '; // Number down left side.
		for(int j=0; j<colm; j++){
			//cout << "[" << grid[i][j] << "]";
			cout << "[";
			switch(stateGrid[i][j]){
				case COVER: cout << "-"; break;
				case EMPTY: cout << " "; break;
				case BOMB:  SetConsoleTextAttribute(hConsole, BLACK+LRED*16); cout << "B"; break;
				case FLAG:  SetConsoleTextAttribute(hConsole, BLACK+LGREEN*16); cout << "F"; break;
				case QMARK: SetConsoleTextAttribute(hConsole, BLACK+LYELLOW*16); cout << "?"; break;
				case 1: SetConsoleTextAttribute(hConsole, LBLUE); cout << stateGrid[i][j]; break;
				case 2: SetConsoleTextAttribute(hConsole, LYELLOW); cout << stateGrid[i][j]; break;
				case 3: SetConsoleTextAttribute(hConsole, LGREEN); cout << stateGrid[i][j]; break;
				case 4: SetConsoleTextAttribute(hConsole, LRED); cout << stateGrid[i][j]; break;
				case 5: SetConsoleTextAttribute(hConsole, LPURPLE); cout << stateGrid[i][j]; break;
				case 6: SetConsoleTextAttribute(hConsole, LBLUE+RED*16); cout << stateGrid[i][j]; break;
				case 7: SetConsoleTextAttribute(hConsole, LYELLOW+RED*16); cout << stateGrid[i][j]; break;
				case 8: SetConsoleTextAttribute(hConsole, LGREEN+RED*16); cout << stateGrid[i][j]; break;
			}
			SetConsoleTextAttribute(hConsole, WHITE);
			cout << "]";
		}
		cout << ' ' << i+1; // Numbers down right side.
		cout << resetiosflags(ios::right) << endl;
	}
	// Numbers across bottom.
	cout << "    ";
	for (int i = 1; i <= colm; i++) {
		cout << ' ' << setw(2) << left << i;
	}
	cout << endl;
}

/*

*/
void Board::printDebug(){
	if(stateGrid == nullptr || bombGrid == nullptr){
		cout << "No grid." << endl;
		return;
	}

	// Numbers across top.
	cout << '\t';
	for (int i = 1; i <= colm; i++) {
		cout << i << '\t';
	}
	cout << endl;

	for(int i=0; i<rows; i++){
		cout << i+1; // Numbers down side.
		for(int j=0; j<colm; j++){
			cout << "\t[" << (bombGrid[i][j]?true:false) << "]";
		}
		cout << endl;
	}
	cout << "////////////////////////////////////////" << endl;

	// Numbers across top.
	cout << '\t';
	for (int i = 1; i <= colm; i++) {
		cout << i << '\t';
	}
	cout << endl;

	for(int i=0; i<rows; i++){
		cout << i+1;
		for(int j=0; j<colm; j++){
			cout << "\t[" << stateGrid[i][j] << "]";
		}
		cout << endl;
	}
}

bool askYN( const string& msg ){
	string input;
	do{
		cout << msg << endl;
		cout << "Yes/No?: ";
		cin >> input;

		if(cin.fail()){ // Cin failed some how clear and reset.
			cout << "Input failed." << endl;
			cin.clear();
			//cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cin.ignore(INT_MAX,'\n');
			continue;
		} else {
			// Input was fine. Clear and keep going.
			//cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cin.ignore(INT_MAX,'\n');
		}

		if(input[0] == 'Y' || input[0] == 'y' || input[0] == 'N' || input[0] == 'n'){
			break;
		} else {
			cout << "Input not yes or no." << endl;
		}
	} while(true);
	return (input[0] == 'Y' || input[0] == 'y');
}

int main(void){

	SetConsoleTitle("Mine Sweeper.");

	srand(time(nullptr));

	Board aBoard;
	do{
		system("cls");
		aBoard.gamePrefs();
		while(!aBoard.getGO()){
			//aBoard.printDebug();
			//system("cls");
			aBoard.print();
			aBoard.getMove();
		}
	} while(askYN("Keep playing?"));

	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}