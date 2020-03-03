#include<stdio.h>
#include<queue>

using namespace std;

class MyStack {
public:
	/** Initialize your data structure here. */
	queue<int> q;
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		queue<int> temp;
		temp.push(x);
		while (!q.empty()) {
			temp.push(q.front());
			q.pop();
		}
		q = temp;
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int res = q.front();
		q.pop();
		return res;
	}

	/** Get the top element. */
	int top() {
		return q.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q.empty();
	}
};

int main() {
	MyStack* obj = new MyStack();
	obj->push(2);
	int param_2 = obj->pop();
	int param_3 = obj->top();
	bool param_4 = obj->empty();
	return 0;
}