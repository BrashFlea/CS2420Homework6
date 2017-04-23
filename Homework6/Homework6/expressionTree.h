#ifndef H_Expression_Tree
#define H_Expression_Tree

#include "binaryTree.h"

#include <iostream>
#include <string>

class ExpressionTree : private BinaryTree<std::string>{

   public:
      ExpressionTree();
      ExpressionTree(std::string exp);
      void setExpression(std::string exp);
      double getResult() const;
      void printParseTreeInOrder(std::ostream& os) const;
      void printParseTreePostOrder(std::ostream& os) const;
	  bool isOperator(char ch) const;
};


#endif
