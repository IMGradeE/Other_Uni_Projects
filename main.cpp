/*
 * Name: Payton Wilkes
 * Date: 1/26/22
 * Description: Welcome to the spaghetti factory*/

#include <iostream>

void getInput(int* mynums);
void whilecalculate(int *mynums);
using namespace std;


/* fetch number from array with for loop (continue if -1), pass to while loop;
 * in each cycle until index == 0 do remainder division by the index value, (index value starts as n).
 * If remainder == 0, add number to variable containing result, else continue.
 * When (inner) while loop finishes, evaluate by (result - n)
 * if the value == 0, perfect; v<0, deficient; v>0 abundant.
 *     Could store values in array and print all at once, not going to.
 *
 * Cout result, echoing original value (could also echo divisors if desired, not going to)
 * */

int main() {
    cout <<"This program can tell you whether each number in a set is abundant, perfect, or deficient! "
           "\nYou can input a maximum of 10 values, but if you want to put in less, just enter a -1."
           "\n\nEnjoy!\n";

    int mynums[10];
    getInput(mynums);
    whilecalculate(mynums);
    return 0;
}


void getInput(int *mynums) {
    for (int i = 0; i < 10; ++i){
        cout << "\nPlease enter a number (-1 if finished): ";
        cin >> mynums[i];
        if (mynums[i] == -1)
            break;
    }
}

void whilecalculate(int *mynums) {
    /* could generate and iterate through all int values in range(item) as an array and then do floor &
     * remainder division in if cond; add both the quotient and divisor to result if r=0, delete from list
     * (half as many checks to get all divisors, I think; may use more memory than it would be worth)*/
    for (int i = 0; i < 10; ++i) {
        string whatis;
        int x = mynums[i];
        int y = mynums[i];
        int sumdiv = 0;

        if (mynums[i] == (-1)) {
            break;
        }
        while (x > 1) {
            --x;
            if ((y % x) == 0)
                sumdiv += x;
        }
        int result = (sumdiv - y);
        if (result > 0) {
            whatis = " is an abundant number.";
        } else if (result == 0) {
            whatis = " is a perfect number.";
        } else {
            whatis = " is a deficient number.";
        }
        if (mynums[i] == 0) {
            whatis = " is not defined in this framework.";
        }
        if ((mynums[i] <= 5) & (mynums[i] > 0)){
            whatis = " is a deficient number.";
        }
        cout << mynums[i] << whatis << "\n";
    }
    cout << "\nRun finished. Have a great day.";
}