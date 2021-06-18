#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "node.hpp"

using namespace std;

class List {
	public:	//should I de-reference Ptrs?
	List();
	//helper functions
	void headIns(NodePtr head, StudentPtr st);	//insert st at head
	void tailIns(NodePtr head, StudentPtr st);	//insert st at tail
	void insNext(NodePtr head, NodePtr node, StudentPtr st);	//insert st after node
	void FixName(string& name);

	void insDom(NodePtr head, StudentPtr st);	//main insert node func
	void printList(NodePtr head);
	bool delDom(NodePtr& head, string& firstName, string& lastName);
	bool delHeadTail(NodePtr& head, NodePtr& tail);

	private:
	NodePtr head;
	NodePtr tail;
};

#endif