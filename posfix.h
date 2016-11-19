#ifndef POSFIX_H
#define POSFIX_H

#include <stack>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class posFix{
	public:
		posFix(string s);
};
void posFix(string s){
	stack <char> pilha;
    stringstream x;
    int i = 0;

	pilha.push(s[i]);

	while(s[i]!= '\0'){
        if(isdigit(s[i])){
           x << s[i] << " ";
        }
        if((s[i] == '*') || (s[i] == '+') || (s[i] =='-')){
            pilha.push(s[i]);
        }
        if(s[i] == ')'){
            x << pilha.top() << " ";
            pilha.pop();
        }
        i++;
	}
 	s = x.str() ;
 	cout << s;
}

#endif
