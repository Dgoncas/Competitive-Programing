#include <bits/stdc++.h>

using namespace std;

int main(){

	int n,op,number;

	while(cin>>n){

		stack<int> stack;
		queue<int> queue;
		priority_queue<int> prio;

		bool isStack = true, isQueue = true, isPrio = true;

		while(n--){
			cin>>op>>number;
			if(op ==1){
				stack.push(number);
				queue.push(number);
				prio.push(number);
			}else{
				if(stack.size() == 0 || stack.top() != number)
					isStack = false;
				else
					stack.pop();

				if(queue.size() == 0 || queue.front() != number)
					isQueue = false;
				else
					queue.pop();

				if(prio.size() == 0 || prio.top() != number)
					isPrio = false;
				else
					prio.pop();
			}
		}

		if(isStack + isQueue + isPrio > 1){
			cout<<"not sure"<<endl;
		}else{
			if(isStack + isQueue + isPrio == 0){
				cout<<"impossible"<<endl;
			}else{
				if(isStack)
					cout<<"stack"<<endl;
				if(isQueue)
					cout<<"queue"<<endl;
				if(isPrio)
					cout<<"priority queue"<<endl;
			}
		}

	}

	return 0;
}
