#include <iostream>
#include <string>
#include <stack>

std::string transform(const std::string& expr) {

	std::string rpn;

	std::stack<std::stack<char> > operators;
	operators.push(std::stack<char>());

	std::stack<char>* context = &operators.top();

	for (size_t i = 0; i < expr.size(); ++i) {
		switch (expr[i]) {
			case '(':
				// create new context
				operators.push(std::stack<char>());
				// switch the context
				context = &operators.top();
				break;

			case ')':
				while (!context->empty()) {
					rpn += context->top();
					context->pop();
				}
				// delete current context
				operators.pop();
				// switch the context
				context = &operators.top();
				break;

			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
			case '%':
				context->push(expr[i]);
				break;

			default:
				rpn += expr[i];
				break;
		}
	}

	return rpn;
}

int main() {

	int cases = 0;
	std::cin >> cases;

	while (cases-- > 0) {
		std::string expr;
		std::cin >> expr;
		std::cout << transform(expr) << '\n';
	}

	return 0;
}
