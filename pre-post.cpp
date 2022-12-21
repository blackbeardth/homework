#include "stack-array.cpp"
#include <cstring>
#include <string>
#include <cstdlib>
#define MAX_STRLEN 256

class PostfixEvaluator {
protected:
	Stack<int> stack;
public:
	int evaluate(string &str)
	{
		int val1, val2, temp;
		int size = str.length();
		for (int i = 0; i < size; i++)
		{
			if (str[i] == ' ')
				continue;
			else if (isdigit(str[i]))
			{
				temp = 0;
				while (isdigit(str[i]))
					temp = temp * 10 + (int)(str[i++] - '0');
				i--;
				stack.push(temp);
			}
			else
			{
				val1 = stack.pop();
				val2 = stack.pop();
				switch (str[i]) {
				case '+' :
					stack.push(val2 + val1);
					break;
				case '-' :
					stack.push(val2 - val1);
					break;
				case '*' :
					stack.push(val2 * val1);
					break;
				case '/' :
					stack.push(val2 / val1);
					break;
				case '%' :
					stack.push(val2 % val1);
					break;
				}
			}
		}
		return stack.pop();
	}
};

class PrefixEvaluator {
protected:
	Stack<int> stack;
public:
	void swap(char &x, char &y) {
		char temp = x;
		x =  y;
		y = temp;
	}
	int evaluate(string &str) {
		string strTemp;
		int val1, val2, temp;
		int size = str.length();
		// parse expression in a reverse fashion
		for (int i = size - 1; i >= 0; i--) {
			if (str[i] == ' ')
				continue;
			else if (isdigit(str[i])) {
				strTemp = "";
				while (isdigit(str[i]))
					strTemp.append(string(1, str[i--]));
				i++;
				for (int i = 0; i < strTemp.length() / 2; i++)
					swap(strTemp[i], strTemp[strTemp.length() - i - 1]);
				temp = atoi(strTemp.c_str());
				stack.push(temp);
			}
			else {
				val1 = stack.pop();
				val2 = stack.pop();
				switch (str[i]) {
				case '+':
					stack.push(val1 + val2);
					break;
				case '-':
					stack.push(val1 - val2);
					break;
				case '*':
					stack.push(val1 * val2);
					break;
				case '/':
					stack.push(val1 / val2);
					break;
				case '%':
					stack.push(val1 % val2);
					break;
				}
			}
		}
		return stack.pop();
	}
};

int main() {
	string pre = "- * 5 + 6 2 / 12 4";
	string post = "5 6 2 + * 12 4 / -";
	PrefixEvaluator preEval;
	PostfixEvaluator postEval;
	cout << "Prefix: " << preEval.evaluate(pre) << endl;
	cout << "Postfix: " << postEval.evaluate(post) << endl;
}