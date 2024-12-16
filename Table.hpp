#ifndef TABLE_HPP
#define TABLE_HPP 

#include <stack>
#include <vector>
#include <string>

#define NUM_RINGS 9

using namespace std;

class Table {
    private:
        // represents the spikes
        stack<int> left;
        stack<int> mid;
        stack<int> right;
    public:
        Table();
        // if possible, makes the move on the current table
        // returns true if the move has been made
        bool leftToMid();
        bool leftToRight();
        bool midToLeft();
        bool midToRight();
        bool rightToLeft();
        bool rightToMid();
        bool isSolved();
        void display();
        vector<string> steps; // stores the steps to get to the current game table 
        bool operator==(const Table& a) const { return (a.left == left && a.mid == mid && a.right == right); }
};

#endif