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


/*
 * The original idea is very good, I have nothing to improve.
 * Idea: 
 *
 *    Using two stacks, 
 *    1) one stack is the real stack to store the data.
 *    2) another stack store the minimal number when it changes.
 *
 *    For example:
 *
 *        if we keep pushing the following numbers:
 *        5 1 1 2 3 2 
 *        the minial number stack will be: 
 *        5 1 1   <-- only store the number which <= cureent minimal number
 *   
 *    Then, when we pop up the stack.
 *
 *    we need compare whether the current number is the current minial number.
 *    if it is, then we need popup the number in minimal number stack.
 *        
 */
class MinStack {
    private:
        //Using a minData struct to remove the duplication in minimal stack
        //which can save the memory.
        struct minData{
            int min;
            int cnt;    // reference count
            minData():min(0), cnt(0) {}
            minData(int m, int c):min(m),cnt(c){}
        };
        std::stack<int> myStack; //real stack store the data
        std::stack<minData> minStack; //minimal number stack store the number 
        int min; //current minial number

    public:

        void push(int x) {
            if(myStack.empty()){
                min = x;
                minStack.push(minData(x,1));
            } else {
                if (min >= x ){
                    min = x;
                    //if current minial number already pushed, then just add the reference coount.
                    if (minStack.top().min == x){
                        minStack.top().cnt++;
                    }else{
                        minStack.push(minData(x,1));
                    }
                }
            }
            myStack.push(x);

        }

        void pop() {
            if (myStack.empty())
                return;

            int top_val = myStack.top();
            myStack.pop();
            if (minStack.top().min == top_val) {
                //de-reference the count at first.
                if (minStack.top().cnt > 1){
                    minStack.top().cnt--;
                } else {
                    minStack.pop();
                    min = minStack.top().min;
                }
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
            minStack = std::stack<minData>();
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

