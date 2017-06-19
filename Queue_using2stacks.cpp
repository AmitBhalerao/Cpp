/*
Implementing Queue using 2 stacks
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;   
        void push(int x) {
             stack_newest_on_top.push(x);
        }

        void pop() {
            if(stack_oldest_on_top.empty())
            {
                while(!stack_newest_on_top.empty())
                {
                    stack_oldest_on_top.push(stack_newest_on_top.top());
                    stack_newest_on_top.pop();
                }
            }
            stack_oldest_on_top.pop();
        }

        int front() {
			if(stack_oldest_on_top.empty())
            {
                while(!stack_newest_on_top.empty())
                {
                    stack_oldest_on_top.push(stack_newest_on_top.top());
                    stack_newest_on_top.pop();
                }
            }
            return stack_oldest_on_top.top();
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cout<<("\nNo.of quries: ");
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cout<<("\nPush= 1 Pop= 2 firstElemet: 3? choice: ");
	cin >> type;
        if(type == 1) {
            cout<<("No. to push: ");
	    cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    
    return 0;
}
