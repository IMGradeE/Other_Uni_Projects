#include <iostream>
#include <sstream>
#include <string>
#include <random>
using namespace std;
/*
We are going to simulate some battles. You can choose a game like pokemon, chess, etc.
The main thing is to create a base class that a bunch of other classes inherit off of.

In chess for example the base class would have a move function but each piece implements the move function differently.
 This idea requires 2d arrays, you don't have to implement an enemy since the 2d array is complicated enough.
*/


class Base_chess{

public:
    Base_chess(){
        tiles[7][5] += 2;
        tiles[start_y][start_x] += 1;
    };
    virtual ~Base_chess(){
    };
     virtual void move(){
        cout << "using wrong def";
    };
    string DisplayChar = "";
    string getDisplay(string name);
    string whitespace(int n);
    int to_x;
    int to_y;

    int tiles[8][8]{0};
    int start_y = 0;
    int start_x = 4;
    bool wincond = false;
};

class Rook: public Base_chess{
public:
    Rook(){
        DisplayChar = "Rk";
    };

    void move(){
        do {
            cout <<"\nPlease enter the y coordinate of the space you would like to move to (enter 10 to quit): ";
            cin >> to_y;

            cout <<"\nPlease enter the x coordinate of the space you would like to move to (enter 10 to quit): ";
            cin >> to_x;
            --to_x;
            --to_y;
            if ((to_x <= 7 && to_x >= 0) && (to_y <= 7 && to_y >= 0)) {
                if (((to_x != start_x) && (to_y == start_y)) || ((to_y != start_y) && (to_x == start_x))) {
                    tiles[start_y][start_x] -= 1;
                    tiles[to_y][to_x] += 1;
                    start_y = to_y;
                    start_x = to_x;
                    if (tiles[to_y][to_x] == 3)
                        wincond = true;
                    break;
                }else{
                    cout << "\nThat move is not legal with this piece. Please try again.";
                    continue;
                }
            }else if((to_y == 9)||(to_x == 9)){
                cout << "quitting";
                break;
            }else{
                cout << "\nThat was not a valid position on the game board. Please try again.";
                continue;
            }
        }while(true);
    };

};

class King: public Base_chess{
public:
    King(){
        DisplayChar = "Kg";
    }
    void move() {
        int to_x;
        int to_y;

        do {
            cout <<"\nPlease enter the y coordinate of the space you would like to move to (enter 10 to quit): ";
            cin >> to_y;

            cout <<"\nPlease enter the x coordinate of the space you would like to move to (enter 10 to quit): ";
            cin >> to_x;
            --to_x;
            --to_y;
            if ((to_y <= 7 && to_y >= 0) && (to_x <= 7 && (to_x >= 0))) { //TODO What the fuck?
                if(((to_x == start_x + 1)||(to_x == start_x)||(to_x == start_x - 1)) && ((to_y == start_y + 1)||(to_y == start_y)||(to_y == start_y - 1))){
                    /*¯\_(ツ)_/¯ ¯\_(ツ)_/¯¯\_(ツ)_/¯*/ // TODO seriously, WHAT?
                    tiles[start_y][start_x] -= 1;
                    tiles[to_y][to_x] += 1;
                    start_y = to_y;
                    start_x = to_x;
                    if (tiles[to_y][to_x] == 3)
                        wincond = true;
                    break;
                }else{
                    cout << "\nThat move is not legal with this piece. Please try again.";
                    continue;
                }
            }else if((to_y == 9)||(to_x == 9)){
                cout << "quitting";
                break;
            }else{
                cout << "\nThat was not a valid position on the game board. Please try again.";
                continue;
            }
        }while(true);
    }
};

class Queen: public Base_chess{
public:
    Queen(){
        DisplayChar = "Qn";
    }
    void move() {
        int to_x;
        int to_y;

        do {
            cout <<"\nPlease enter the y coordinate of the space you would like to move to (enter 10 to quit): ";
            cin >> to_y;

            cout <<"\nPlease enter the x coordinate of the space you would like to move to (enter 10 to quit): ";
            cin >> to_x;
            --to_x;
            --to_y;
            if ((to_y <= 7 && to_y >= 0) && (to_x <= 7 && to_x >= 0)) {
                if (((to_x != start_x) && (to_y == start_y)) || ((to_y != start_y) && (to_x == start_x))) {
                    tiles[start_y][start_x] -= 1;
                    tiles[to_y][to_x] += 1;
                    start_y = to_y;
                    start_x = to_x;
                    if (tiles[to_y][to_x] == 3)
                        wincond = true;
                    break;
                }
                if(((to_x > to_y) && (start_x > start_y)) && ((to_x - to_y) == (start_x - start_y))){
                    tiles[start_y][start_x] -= 1;
                    tiles[to_y][to_x] += 1;
                    start_y = to_y;
                    start_x = to_x;
                    if (tiles[to_y][to_x] == 3)
                        wincond = true;
                    break;
                }else if(/* OR (this is stupid but my brain is mush right now ¯\_(ツ)_/¯*/((start_y != to_x) && (start_y != to_y)) && (to_x != start_x)){
                    tiles[start_y][start_x] -= 1;
                    tiles[to_y][to_x] += 1;
                    start_y = to_y;
                    start_x = to_x;
                    if (tiles[to_y][to_x] == 3)
                        wincond = true;
                    break;
                }else{
                    cout << "\nThat move is not legal with this piece. Please try again.";
                    continue;
                }
            }else if((to_y == 9)||(to_x == 9)){
                cout << "quitting";
                break;
            }else{
                cout << "\nThat was not a valid position on the game board. Please try again.";
                continue;
            }
        }while(true);
    }
};

class Bishop: public Base_chess{
public:
    Bishop(){
        DisplayChar = "Bp";
    }
    void move(){
        int to_x;
        int to_y;
        do {
            cout <<"\nPlease enter the y coordinate of the space you would like to move to (enter 10 to quit): ";
            cin >> to_y;

            cout <<"\nPlease enter the x coordinate of the space you would like to move to (enter 10 to quit): ";
            cin >> to_x;
            --to_x;
            --to_y;
            if ((to_y <= 7 && to_y >= 0) && (to_x <= 7 && to_x >= 0)) {
                if(((to_x > to_y) && (start_x > start_y)) && ((to_x - to_y) == (start_x - start_y))){
                    tiles[start_y][start_x] -= 1;
                    tiles[to_y][to_x] += 1;
                    start_y = to_y;
                    start_x = to_x;
                    if (tiles[to_y][to_x] == 3)
                        wincond = true;
                    break;
                }else if(/* OR (this is stupid but my brain is mush right now ¯\_(ツ)_/¯*/((start_y != to_x) && (start_y != to_y)) && (to_x != start_x)){
                    tiles[start_y][start_x] -= 1;
                    tiles[to_y][to_x] += 1;
                    start_y = to_y;
                    start_x = to_x;
                    if (tiles[to_y][to_x] == 3)
                        wincond = true;
                    break;
                }else{
                    cout << "\nThat move is not legal with this piece. Please try again.";
                }
            }else if((to_y == 9)||(to_x == 9)){
                cout << "quitting";
                break;
            }else{
                cout << "\nThat was not a valid position on the game board. Please try again.";
                continue;
            }
        }while(true);
    };
};

class Pawn: public Base_chess{
public:
    Pawn(){
        DisplayChar = "Pn";
    }
    char choice;
    void move(){
        cout << "Pawn can only move forward. Sorry.\n";
        --tiles[start_y][start_x];
        ++start_y;
        if (tiles[start_y][start_x + 1] == 2){
            ++tiles[start_y][start_x + 1];
            wincond = true;
        }else if (tiles[start_y][start_x - 1] == 2){
            cout << "\nDo you uh, want to keep moving forward? (rhetorical, you were born to win. It was never up to you. Press any key+enter to continue.\n";
            cin >> choice;
            ++tiles[start_y][start_x - 1];
            wincond = true;
        }else{
            ++tiles[start_y][start_x];
        }
        cout << "\nDo you uh, want to keep moving forward? (rhetorical, program execution is terminal. Press any key+enter to continue.\n";
        cin >> choice;
    }
};

string Base_chess::getDisplay(string name) {
    int lineid = 1;
    stringstream output;
    for (int j = 7; j >= 0; --j) {
        if (j >= 0) {
            output << Base_chess::whitespace(10) << j+1<< " ";
            for (int i = 0; i < 8; ++i) {
                output << "|";
                if(tiles[j][i] == 3){
                    output << "W!";
                }else if (tiles[j][i] == 2){
                    output << "!p";
                }else if (tiles[j][i] == 1){
                    output << name;
                }else {
                    if (lineid % 2 == 0 ^ i % 2 == 0) {
                        output << "__";
                    } else /*if (lineid%2 != 0 && i%2 == 0)*/{
                        output << "||";
                    }
                }
            }
            output << "|";
            ++lineid;
            output << "\n";
        }
    }
    output << "            ";
    for (int k = 1; k <= 8; ++k) {
        output << " " << k << " ";
    }
    output << "\n";
    return output.str();
}

string Base_chess::whitespace(int n) {
    char space = '\0';
    stringstream str;

    for (n; n > 0; --n) {
        str << space;
    }
    return str.str();
}

// Int for board, move functions return to board the pieceid and location
// Base_chess IS board, and hardcode positions for start values.

int main() {
    int choice = 0;
    Base_chess* piece = new Base_chess;
    //TODO Remember you have (multiple) backups of this file
    cout << piece->getDisplay("na");
    cout << "Choose a piece from the following options:\n"<< "1: Pawn\n2: Rook\n3: King\n4: Queen\n5: Bishop\n6: Quit";
    cin >> choice;
    int i;
    Pawn p;
    Rook r;
    King k;
    Queen q;
    Bishop b;
    switch (choice) {
        case 1: {
            piece = &p;
            break;
        }
        case 2: {
            piece = &r;
            break;
        }
        case 3: {
            piece = &k;
            break;
        }
        case 4: {
            piece = &q;
            break;
        }
        case 5: {
            piece = &b;
            break;
        }
    }
    if (5 >= choice && choice >=1) {
        do {
            i = 0;
            cout << piece->getDisplay(piece->DisplayChar);
            piece->move();
            cout << piece->getDisplay(piece->DisplayChar);
            i++;
            if(piece->wincond)
                cout<< "\n You've won; but at what cost?";
        } while (!(piece->wincond) || (piece->to_y == 10 || piece->to_x == 10));
    }
    cout << "\nThanks for stopping by.\n";

}
