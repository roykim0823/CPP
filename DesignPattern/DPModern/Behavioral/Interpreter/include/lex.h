#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::ostream;

struct Token {
  	enum Type { integer, plus, minus, lparen, rparen } type;
  	string text;

 	explicit Token(Type type, const string& text)
    : type{type}, text{text} {}

  	friend ostream& operator<<(ostream& os, const Token& obj) {
    	return os << "`" << obj.text << "`";
  	}
};

vector<Token> lex(const string& input) {
	vector<Token> result;

  	for (int i = 0; i < input.size(); ++i) {
    	switch (input[i]) {
    	case '+':
      		result.push_back(Token{ Token::plus, "+" });
      		break;
    	case '-':
      		result.push_back(Token{ Token::minus, "-" });
      		break;
    	case '(':
      		result.push_back(Token{ Token::lparen, "(" });
      		break;
    	case ')':
      		result.push_back(Token{ Token::rparen, ")" });
      		break;
    	default:
      		// number
      		ostringstream buffer;
      		buffer << input[i];
      		for (int j = i + 1; j < input.size(); ++j) {
        		if (isdigit(input[j])) {
          			buffer << input[j];
          			++i;
        		} else {
          			result.push_back(Token{ Token::integer, buffer.str() });
          			break;
        		}
      		}
    	}
  	}
  	return result;
}
