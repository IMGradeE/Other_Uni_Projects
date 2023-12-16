#include <iostream>
using namespace std;

enum Input{NORTH = 1, EAST, SOUTH, WEST
};
//
struct RandomWalkButNotRandom{
    int x;
    int y;
};


void Move(int& x, int& y, Input Direction) {
    switch (Direction) {
        case NORTH:
            ++y;
            break;
        case EAST:
            ++x;
            break;
        case SOUTH:
            --y;
            break;
        case WEST:
            --x;
            break;
        default:
            break;
    }
}



int main(){
    RandomWalkButNotRandom walk{0, 0};
    int in = 0;
    do
    {
        cout << "\nPosition: (" << walk.x << "," << walk.y
        << ")\nPlease enter the number associated with the direction you would like to move in the menu below:\n"
       "1. North\n"
       "2. East\n"
       "3. South\n"
       "4. West\n"
       "5. Quit\n";
        cin >> in;

        Move(walk.x, walk.y, static_cast<Input>(in));
    }
    while(in != 5);
    cout<< "\nGoodbye!";

    return 0;
}
