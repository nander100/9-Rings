#include "Table.hpp"
#include <iostream>

Table::Table() {
    for (unsigned int i = NUM_RINGS; i >= 1; --i) {
        left.push(i);
    }
}

bool Table::leftToMid() {
    if (left.empty()) return false; // there are no values on the left side (cannot move from nothing)
    int leftVal = left.top();

    //get the mid top value
    int midVal;
    if(mid.empty()) midVal = 10;
    else midVal = mid.top();

    if(leftVal > midVal) return false; // if the side we are moving to is smaller

    // move the disc
    left.pop();
    mid.push(leftVal);
    return true; 
}

bool Table::leftToRight() {
    if (left.empty()) return false; // there are no values on the left side (cannot move from nothing)
    int leftVal = left.top();

    //get the right top value
    int rightVal;
    if(right.empty()) rightVal = 10;
    else rightVal = right.top();

    if(leftVal > rightVal) return false; // if the side we are moving to is smaller

    // move the disc
    left.pop();
    right.push(leftVal);
    return true; 
}

bool Table::midToLeft() {
    if (mid.empty()) return false; // there are no values on the mid side (cannot move from nothing)
    int midVal = mid.top();

    //get the left top value
    int leftVal;
    if(left.empty()) leftVal = 10;
    else leftVal = left.top();

    if(midVal > leftVal) return false; // cannot move large onto small

    // move the disc
    mid.pop();
    left.push(midVal);
    return true;
}
bool Table::midToRight() {
    if (mid.empty()) return false; // there are no values on the mid side (cannot move from nothing)
    int midVal = mid.top();

    //get the right top value
    int rightVal;
    if(right.empty()) rightVal = 10;
    else rightVal = right.top();

    if(midVal > rightVal) return false; // if the side we are moving to is smaller

    // move the disc
    mid.pop();
    right.push(midVal);
    return true; 
}

bool Table::rightToLeft() {    
    if (right.empty()) return false; // there are no values on the right side (cannot move from nothing)
    int rightVal = right.top();

    //get the right top value
    int leftVal;
    if(left.empty()) leftVal = 10;
    else leftVal = left.top();
    
    if(rightVal > leftVal) return false; // if the side we are moving to is smaller

    // move the disc
    right.pop();
    left.push(rightVal);
    return true;
}

bool Table::rightToMid() {
    if (right.empty()) return false; // there are no values on the right side (cannot move from nothing)
    int rightVal = right.top();

    //get the right top value
    int midVal;
    if(mid.empty()) midVal = 10;
    else midVal = mid.top();

    if(rightVal > midVal) return false; // if the side we are moving to is smaller

    // move the disc
    right.pop();
    mid.push(rightVal);
    return true;
}

bool Table::isSolved(){
    if(left.empty() && mid.empty()) return true;
    else if(left.empty() && right.empty()) return true;
    else return false;
}

void Table::display() {
    for(unsigned int i = 0; i < steps.size(); ++i) {
        cout << steps[i]<< endl;
    }
    cout << "Optimal solution: " << steps.size() << endl;
}
