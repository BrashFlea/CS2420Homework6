#include "expressionTree.h"

//Creates an empty expression tree
ExpressionTree::ExpressionTree():BinaryTree(){

}

//Creates an expression tree from the given expression
ExpressionTree::ExpressionTree(std::string exp):BinaryTree(){
}

//Clear the previous tree and builds a new tree from the given expression
void ExpressionTree::setExpression(std::string exp){
	//Clear the previous tree
	BinaryTreeNode<std::string> * tmp = this->getRoot();
	//Empty tree check
	if (tmp) {
		deleteTree(tmp);
	}
	//Build  a new tree from expression
	//ExpressionTree(exp);
}

//Returns the results of evaluating the expression tree
double ExpressionTree::getResult() const{
   //Just to make it compile
   return -1;
}

//Prints the tree using inOrderTraversal
void ExpressionTree::printParseTreeInOrder(std::ostream& os) const{
}

//Prints the tree using postOrderTraversal
void ExpressionTree::printParseTreePostOrder(std::ostream& os) const{
}

//Determines if a char is an operator
//Returns true/false
bool ExpressionTree::isOperator(char ch) const {
	switch (ch) {
	case '+':
		return true;
		break;
	case '-':
		return true;
		break;
	case '*':
		return true;
		break;
	case '/':
		return true;
		break;
	case '^':
		return true;
		break;
	}

	return false;
}
