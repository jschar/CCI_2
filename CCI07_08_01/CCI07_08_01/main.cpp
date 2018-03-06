/*

	Othello/Reversi 8x8 board. Discs.

*/

#include <iostream>
#include <iomanip>
#include <sstream>
//#include <bitset>


using namespace std;

int DIRECTION[8][2] = { {1,0}, {1,1}, {0,1}, {-1,1}, {-1,0}, {-1,-1}, {0,-1}, {1,-1} };

#define EMPTY 0
#define WHITE 1
#define BLACK 2
#define OTHER(x) (3-(x))

// Converts (x,y) to index of the board array.
#define CONV_21(x, y) (((y) << 3)+(x))
#define ON_BOARD(x, y) ((x) >= 0 && (x) < 8 && (y) >= 0 && (y) < 8 )

#define ROW 8
#define COLM 8

class Board{
private:
	char *gameBoard;
	char wt; // Whose turn.

public:
	Board();
	void setTile(int x, int y, char inSta);
	void flipTile(int x, int y);
	void print();
	bool legalMove(int x, int y);
	void makeMove(int x, int y);
	void playTurn();
};

Board::Board(){
	wt = WHITE;
	gameBoard = new char[ROW*COLM]();
	this->setTile(3,3,WHITE); this->setTile(4,3,BLACK);
	this->setTile(3,4,BLACK); this->setTile(4,4,WHITE);
}

void Board::setTile(int x, int y, char inSta){
	if(!ON_BOARD(x, y)){ return; }
	gameBoard[CONV_21(x,y)] = inSta;
}

void Board::flipTile(int x, int y){
	if(ON_BOARD(x, y) && gameBoard[CONV_21(x,y)] != EMPTY){
		gameBoard[CONV_21(x, y)] = OTHER(gameBoard[CONV_21(x, y)]);
	}
}

#define WIDTH 3
void Board::print(){
	cout << setw(WIDTH) << " ";
	for( int i=1; i<=ROW; i++ ){
		//cout << left << setw(WIDTH) << i;
		cout << " " << i << " ";
	}
	cout << endl;
	for(int y=0; y<ROW; y++){
		cout << setw(WIDTH) << y+1;
		for(int x=0; x<COLM; x++){
			stringstream ss;
			ss << "[";
			switch(gameBoard[CONV_21(x,y)]){
				case 0: ss << "-"; break;
				case 1: ss << "W"; break;
				case 2: ss << "B"; break;
			};
			ss << "]";
			cout << setw(WIDTH) << ss.str();
		}
		cout << endl;
	}
	cout << endl;
}

bool Board::legalMove(int x, int y){
	if(!ON_BOARD(x, y)){ return false; }
	if(gameBoard[CONV_21(x, y)] != EMPTY){ return false; }
	char *a = gameBoard;
	bool result = false;
	for (int dir = 0; dir<8; dir++) {
		char dx = DIRECTION[dir][0];
		char dy = DIRECTION[dir][1];
		char tx = x + 2 * dx;
		char ty = y + 2 * dy;
		/* need to be at least 2 grids away from the edge and a oppenent piece
		adjacent in the direction */
		if (!ON_BOARD(tx, ty) || a[CONV_21(x + dx, y + dy)] != OTHER(wt))
			continue;
		while (ON_BOARD(tx, ty) && a[CONV_21(tx, ty)] == OTHER(wt)) {
			tx += dx;
			ty += dy;
		}
		if (ON_BOARD(tx, ty) && a[CONV_21(tx, ty)] == wt) {
			result = true;
			break;
		}
	}
	return result;
}

/*

	If a legal move is to be made then there must be aleast one opponent piece and one player piece, a minimum of two
, a total of three pieces. Check in all eight directions using the DIRECTION array and some math with vectors.
If the move is valid flip the pieces along the vector.

*/
void Board::makeMove(int x, int y){
	if(!ON_BOARD(x,y)){ return ; }
	if(gameBoard[CONV_21(x,y)] != EMPTY){ return; }
	gameBoard[CONV_21(x,y)] = wt;
	char *a = gameBoard;
	for(int dir=0; dir<8; dir++){ // Loop through all eight directions.
		int dx = DIRECTION[dir][0]; // X component of the direction vector.
		int dy = DIRECTION[dir][1]; // Y component of the direction vector.

		// tx and ty are multiplied by two because its the minimum space you need for a legal move.
		int tx = x + 2*dx; // Terminating x point.
		int ty = y + 2*dy; // Terminating y point.
		
		if(!ON_BOARD(tx, ty) || a[CONV_21(x+dx, y+dy)] != OTHER(wt)){
			// If the targetx/y is off the board or the immediate next piece isn't the opposite color,
			// then the direction is incorrect.
			continue;
		}
		// Move targetx/y outward along the vector.
		while(ON_BOARD(tx,ty) && a[CONV_21(tx,ty)] == OTHER(wt)){
			tx += dx;
			ty += dy;
		}
		if(ON_BOARD(tx,ty) && a[CONV_21(tx, ty)] == wt){
			tx -= dx;
			ty -= dy;
			while(a[CONV_21(tx,ty)] == OTHER(wt)){
				a[CONV_21(tx, ty)] = wt;
				tx -= dx;
				ty -= dy;
			}
		}
	}
}

void Board::playTurn(){
	//print board.
	this->print();
	bool takingTurn = true;
	
	while(takingTurn){
		//promted current player for move.
		cout << ((wt == WHITE)?"White's":"Black's") << " turn." << endl;
		cout << "Pick an X and Y: ";
		int x, y;
		cin >> x >> y;
		x -= 1;
		y -= 1;
		if(legalMove(x,y)){
			makeMove(x,y);
			takingTurn = false;
		}
	}
	//Check is board is still playable.
	//Switch players.
	wt = OTHER(wt);
}

int main(void){
	
	Board aBoard;
	aBoard.print();

	aBoard.playTurn();
	aBoard.print();
	aBoard.playTurn();
	aBoard.print();

	cout << "End of line" << endl;
	cin.ignore();
	return 0;
}