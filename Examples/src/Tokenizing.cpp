#include <iostream>
#include <sstream>	// for stringstream
#include <vector>

using namespace std;

vector<string> Tokenizer(string s, char delimiter)
{
	vector<string> tokens;
	string token;

	stringstream checkl(s);

	// Tokenizing w.r.t. space ' '
	while(getline(checkl, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}

// rvalue referece for printTokens(Tokenizer(l1, ''));
void printTokens(vector<string> &&strVec) {
	for(size_t i=0; i<strVec.size(); i++) {
		cout << strVec[i] << endl;
	}
	cout << endl;
}
	
int main() {
	string l1 = "GeeksForGeeks is a must try";
	string l2 = "GeeksForGeeks-is-a-must-try";
	string l3 = "GeeksForGeeks - is - a - must - try";

	printTokens(Tokenizer(l1, ' '));
	printTokens(Tokenizer(l2, '-'));
	printTokens(Tokenizer(l3, '-'));
	printTokens(Tokenizer(l3, ' '));
	vector<string> t=Tokenizer(l3, ' ');
	//printTokens(t);	// compilation error
	printTokens(move(t));	// compilation error
	
	return 0;
}
