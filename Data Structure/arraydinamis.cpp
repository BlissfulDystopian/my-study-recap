#include <iostream>
#include <stack>

//	Dynamics array
int main() {
	std::string s = "aaabbbbbcccdccdcdef";
	std::stack<char> cc;
	for(char c : s) {
		if(cc.empty()) cc.push(c);
		else if(!cc.contain(c)) cc.push(c);
	}
	std::cout << cc.length() << std::endl;
	return 0;
}
