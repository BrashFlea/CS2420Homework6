#include "expressionTree.h"

//Creates an empty expression tree
ExpressionTree::ExpressionTree():BinaryTree(){
	/*
	Makes an empty Expression Tree with:
		root = NULL;
		size = 0;
	*/
}

//Creates an expression tree from the given expression
ExpressionTree::ExpressionTree(std::string expr):BinaryTree(){
	root = new BinaryTreeNode<std::string>();
	root->data = "";
	root->left = NULL;
	root->right = NULL;
	BuildTree(expr, root);

}


void ExpressionTree::BuildTree(std::string expr, BinaryTreeNode<std::string> * curr){
	//Go left
	//Go right
	//Return
	if (!expr[pos]) {
		return;
	}
	// go left
	if (expr[pos] == '(') {
		curr->left = new BinaryTreeNode<std::string>();
		pos++;
		BuildTree(expr, curr->left);
	}
	// save current data (pos changed by going left)
	if (expr[pos] && isdigit(expr[pos])) {
		std::string number = "";
		while (expr[pos] && isdigit(expr[pos]))
		{
			number += expr[pos];
			pos++;
		}
		curr->data = number;
		return;
	}
	// go right
	if (isOperator(expr[pos])) {
		curr->data = expr[pos];
		curr->right = new BinaryTreeNode<std::string>();
		pos++;
		BuildTree(expr, curr->right);
	}
	//Check for closed parthesies
	if (expr[pos] == ')') {
		pos++;
		return;
	}


}

//Clear the previous tree and builds a new tree from the given expression
void ExpressionTree::setExpression(std::string exp){
	pos = 0;

	//Clear the previous tree
	BinaryTreeNode<std::string> * tmp = root;

	//Empty tree check
	if (tmp) {
		deleteTree(tmp);
	}

	//Build  a new tree from expression
	root = new BinaryTreeNode<std::string>();
	root->data = "";


	BuildTree(exp, tmp);
}

//Returns the results of evaluating the expression tree
double ExpressionTree::getResult() const{
   //Just to make it compile
   return getResult(root);
}

double ExpressionTree::getResult(BinaryTreeNode<std::string> * ptr) const {
	//Default return value for empty tree
	double def = 0.00;
	int index = 0;

	if (ptr == NULL) {
		return def;
	}

	if (ptr->left == NULL && ptr->right == NULL) {
		return std::stod(ptr->data); //string to double conversion
	}
	else {
		double result = 0.0;
		int index = 0;
		double left = getResult(ptr->left);
		double right = getResult(ptr->right);
		char op = ptr->data[index];

		switch (op) {
		case '+':
			result = left + right;
			break;

		case '-':
			result = left - right;
			break;

		case '*':
			result = left * right;
			break;

		case '/':
			result = left / right;
			break;

		case '^':
			result = pow(left, right);
			break;

		default:
			result = left + right;
			break;
		}

		return result;
	}

}

//Prints the tree using inOrderTraversal
void ExpressionTree::printParseTreeInOrder(std::ostream& os) const{
	os << toStringInOrder();
}

//Prints the tree using postOrderTraversal
void ExpressionTree::printParseTreePostOrder(std::ostream& os) const{
	os << toStringPostOrder();
}

//Determines if a char is an operator
//Returns true/false
bool ExpressionTree::isOperator(char ch) const{

	return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';

}

