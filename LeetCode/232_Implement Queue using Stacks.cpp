#include<stdio.h>
#include<stack>


using namespace std;




class MyQueue {
public:
	/** Initialize your data structure here. */
	stack<int> st;
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		stack<int> st2;
		st2.push(x);
		stack<int>st3;
		while (!st.empty()) {
			int temp = st.top();
			st.pop();
			st3.push(temp);
		}
		while (!st3.empty()) {
			int temp = st3.top();
			st3.pop();
			st2.push(temp);
		}
		st = st2;
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int temp = st.top();
		st.pop();
		return temp;
	}

	/** Get the front element. */
	int peek() {
		return st.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return st.empty();
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {

	MyQueue* obj = new MyQueue();
	obj->push(1);
	obj->push(2);
	obj->push(3);
	//int param_2 = obj->pop();
	int param_3 = obj->peek();
	bool param_4 = obj->empty();
	return 0;
}