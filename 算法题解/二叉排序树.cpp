#include <iostream> 
using namespace std;

class Tree
{
public:
	Tree();
	Tree(int val);
	~Tree();
	void input(int val);
	void output();
private:
	class Node
	{
	public:
		Node *l;
		Node *r;
		int val;
	};
	Node *head;
	void insert(int val, Node *p);
	void outp(Node *p);
	void delAll(Node *p);
};

Tree::Tree()
{
	head = new Node;
	head->l = NULL;
	head->r = NULL;
	head->val = 0;
}

Tree::Tree(int val)
{
	head = new Node;
	head->l = NULL;
	head->r = NULL;
	head->val = val;
}

Tree::~Tree()
{
	delAll(head);
} 

void Tree::delAll(Node *p)
{
	if (p->l != NULL)
	{
		delAll(p->l);
	}
	if (p->r != NULL)
	{
		delAll(p->r);
	}
	delete p;
}

void Tree::input(int val)
{
	insert(val, head);
}

void Tree::insert(int val, Node *p)
{
	if (val < p->val)
	{
		if (p->l == NULL)
		{
			Node *q = new Node;
			q->l = NULL;
			q->r = NULL;
			q->val = val;
			p->l = q;
			return;
		}
		insert(val, p->l);
	}
	if (p->r == NULL)
	{
		Node *q = new Node;
		q->l = NULL;
		q->r = NULL;
		q->val = val;
		p->r = q;
		return;
	}
	insert(val, p->r);
	
}

void Tree::output()
{
	outp(head);
}

void Tree::outp(Node *p)
{
	if (p->l != NULL)
	{
		outp(p->l);
	}
	cout << p->val << " ";
	if (p->r != NULL)
	{
		outp(p->r);
	}
}

int main()
{
	Tree x(1);
	x.input(5);
	x.input(7);
	x.input(2);
	x.input(9);
	x.input(0);
	x.input(8);
	x.output();
	return 0;
}
