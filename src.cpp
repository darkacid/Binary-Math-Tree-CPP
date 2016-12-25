#include <iostream>
#include <string>
#include <cctype>
#include <typeinfo>

using namespace std;

class Node
{
public:

	Node* left;
	Node* right;

	double num;
	char op;
	bool isOp;

	Node(char op) :op(op) { isOp = true; }
	Node(double num) :num(num) { isOp = false; }
	Node(int num) :num(num) { isOp = false; }
};

double exploreNode(Node *root_node)
{
	if (root_node->isOp)
	{
		double firstnum = exploreNode(root_node->left);
		double secondnum = exploreNode(root_node->right);
		char op = root_node->op;

		switch(op)
		{
		case '+':return firstnum + secondnum;
			break;
		case '-':return firstnum - secondnum;
			break;
		case '*':return firstnum * secondnum;
			break;
		case '/':return firstnum / secondnum;
			break;
		}
	}
	else
		if(root_node->num)
			return root_node->num;

}
Node createNode(string commands)
{
	commands = "1 3 4 * 4 / + 5 -";

}
string selectNum(string commandsPart,int index)
{
	string numString="";
	bool isSpace = false;

	for(int len=0;len<commandsPart.length();len++)
	{
		cout << "isdigit: " << isdigit(commandsPart[index+len]) << endl;
		if (isdigit(commandsPart[index+len]) || commandsPart[index + len]=='.'|| commandsPart[index + len]=='-' )
			numString = commandsPart.substr(index, len+1);
		else			
			return numString;
	}
	return numString;
}

int main()
{
	Node* root=new Node('-');
	root->left = new Node('+');
	root->left->left = new Node(1);
	root->left->right = new Node(4);

	root->right = new Node(3);
	//cout << "The answer is: " << exploreNode(root);

	cout<<"The number is: "<<selectNum("abc 255 95.9",4);//Get the num at index

	return 0;
}