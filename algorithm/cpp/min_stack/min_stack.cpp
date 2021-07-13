// Source : 
// Author : Edgar Wu
// Date   : 13/07/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

    MinStack() initializes the stack object.
    void push(val) pushes the element val onto the stack.
    void pop() removes the element on the top of the stack.
    int top() gets the top element of the stack.
    int getMin() retrieves the minimum element in the stack.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2


*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <vector>
#include <string>
#include <iostream>
#include <sstream>


using namespace std;
#include <stack>
#include <map>


/*
 * Idea: 
 *
 *    Using stack and map
 *    1) one stack is the real stack to store the data.
 *    2) map is used to store the minimal number when it changes. Map is implemented by RB tree. 
        So when you pop element, you just remove the element from the map.
        Then the 1st element will always be the minimum value.
        Map is a <key, val> pair. The value here is the ref count.
        We use value as the ref count here.
        You have to remove the pair from map only when the ref count == 0.
        And you only have to redefine min value when you remove element from map.
 *
 *        
 */
class MinStack {
    private:
        std::stack<int> myStack; //real stack store the data
        //std::stack<int> minStack; //minimal number stack store the number 
        std::map<int, int> minMap;
        std::map<int, int>::iterator iter;
        int min; //current minial number

    public:

        void push(int x) {
            if(myStack.empty()){
                min = x;
                minMap[x] = 1;
            } else {
                // in push case,  change min value directly
                if (min > x)
                    min = x;
                 addMap(x);
            }
            myStack.push(x);

        }

        void addMap(int x) {           
            iter = minMap.find(x);
            if (iter == minMap.end()) {
                minMap[x] = 1;
            } else {
                // inc ref count if found
                minMap[x]++;
            }
        }

        void pop() {
            if (myStack.empty())
                return;

            int top_val = myStack.top();
            myStack.pop();

            iter = minMap.find(top_val);
            if (1 == iter->second) {
                // this is the last element, so we need to erase it from the map
                minMap.erase(iter);
                // here is the special case that we need to handle
                if (min == top_val) {
                    // The element we need to remove from the map is the minimum one
                    // So have to find a new minimum one after remove the element from the map
                    // In a sorted map, the first element (pointed by begin()) is always the minimum one
                    iter = minMap.begin();
                    min = iter->first;
                }
            } else {
                // dec ref count
                iter->second--;
            }
            
            
        }


        int top() {
            return myStack.top();
        }

        int getMin() {
            return min;
        }
        void clear() {          
            myStack = std::stack<int>();
            minMap.clear();
        }

};





int main()
{
    cout << "--- expected output [0, 0, 0, 2]" << endl;
    MinStack ms;
    ms.push(2);
    ms.push(0);
    ms.push(3);
    ms.push(0);

    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.getMin() << endl;


    ms.clear();

    cout << "--- expected output [2147483647 2147483646 2147483646 2147483647 2147483647 -2147483648 -2147483648 2147483647 " << endl;

    ms.push(2147483646);
    ms.push(2147483646);
    ms.push(2147483647);

    cout << ms.top() << endl;
    ms.pop();
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.getMin() << endl;
    ms.pop();

    ms.push(2147483647);
    cout << ms.top() << endl;
    cout << ms.getMin() << endl;
    ms.push(-2147483648);
    cout << ms.top() << endl;
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.getMin() << endl;


    return 0;
}

