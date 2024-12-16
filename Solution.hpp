#ifndef SOLUTION_HPP
#define SOLUTION_HPP
#include "Table.hpp"
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        void run();
    private:
        vector<Table> visitedTables;
        queue<Table> myQueue;
        bool existsInQueue(const Table&);
};

#endif