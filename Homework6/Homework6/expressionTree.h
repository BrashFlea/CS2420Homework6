#ifndef H_Expression_Tree
#define H_Expression_Tree

#include "binaryTree.h"

#include <iostream>
#include <string>

class ExpressionTree : private BinaryTree<std::string>{
   private:
	   int pos = 0;

   public:
      ExpressionTree();
      ExpressionTree(std::string exp);
	  void BuildTree(std::string expr, BinaryTreeNode<std::string> * curr);
      void setExpression(std::string exp);
      double getResult() const;
      void printParseTreeInOrder(std::ostream& os) const;
      void printParseTreePostOrder(std::ostream& os) const;
	  bool isOperator(char ch) const;
};


#endif
