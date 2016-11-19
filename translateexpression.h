#ifndef TRANSLATEEXPRESSION_H
#define TRANSLATEEXPRESSION_H

#include <stack>
#include <string>
#include <iostream>

using namespace std;

class translateExpression{
	public:
		translateExpression(string s);
};

int translateExpression(string s){
	stack<int> op;
    int i = s.size(), temp;
    
	while (s[i] >= 0){
        if (s[i] > 47 && s[i] < 58){
            temp = s[i] - 48;
            op.push(temp);
        }
		else if (s[i] == '*'){
            temp = op.top();
            op.pop();
            temp *= op.top();
            op.pop();
            op.push(temp);
        }
		else if (s[i] == '+'){
            temp = op.top();
            op.pop();
            temp += op.top();
            op.pop();
            op.push(temp);
        }
        i--;
    }
    return op.top(); 
}

#endif
