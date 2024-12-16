#include "Solution.hpp"
#include <vector>
#include "Table.hpp"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void Solution::run() {
    // push the first value into the queue
    Table firstTable;
    visitedTables.push_back(firstTable);
    myQueue.push(firstTable);

    // Table tableToCheck;
    Table currentTable;
    Table LeftToMid;
    Table LeftToRight;
    Table MidToLeft;
    Table MidToRight;
    Table RightToLeft;
    Table RightToMid;

    while(1) {
        // get the value from the front of the queue
        currentTable = myQueue.front();
        myQueue.pop();

        if(currentTable.isSolved()) break; // checks the solution

        // left to mid
        LeftToMid = currentTable;
        if(LeftToMid.leftToMid()) { 
            if(!existsInQueue(LeftToMid)){ 
                LeftToMid.steps.push_back("Left to middle");
                myQueue.push(LeftToMid); 
                visitedTables.push_back(LeftToMid); 
            }
        }

        // left to right
        LeftToRight = currentTable;
        if(LeftToRight.leftToRight()){
            if(!existsInQueue(LeftToRight)){
                LeftToRight.steps.push_back("Left to right");
                myQueue.push(LeftToRight); 
                visitedTables.push_back(LeftToRight);
            }
        } 

        // mid to left
        MidToLeft = currentTable;
        if(MidToLeft.midToLeft()) {
            if(!existsInQueue(MidToLeft)){
                MidToLeft.steps.push_back("Mid to left");
                myQueue.push(MidToLeft);
                visitedTables.push_back(MidToLeft);
            }
        } 

        // mid to right 
        MidToRight = currentTable;
        if(MidToRight.midToRight()){
            if(!existsInQueue(MidToRight)){
                MidToRight.steps.push_back("Mid to Right");
                myQueue.push(MidToRight);
                visitedTables.push_back(MidToRight);
            }
        } 

        // right to left 
        RightToLeft = currentTable;
        if(RightToLeft.rightToLeft()){
            if(!existsInQueue(RightToLeft)){
                RightToLeft.steps.push_back("Right to left");
                myQueue.push(RightToLeft);
                visitedTables.push_back(RightToLeft);
            }
        } 

        // right to mid
        RightToMid = currentTable;
        if(RightToMid.rightToMid()){
            if(!existsInQueue(RightToMid)){
                RightToMid.steps.push_back("Right to middle");
                myQueue.push(RightToMid);
                visitedTables.push_back(RightToMid);
            }
        } 
    }
    currentTable.display();
}

bool Solution::existsInQueue(const Table& table) {
    for(unsigned int i = 0; i < visitedTables.size(); i++) {
        if(visitedTables.at(i) == table) return true;
    }
    return false;
}
