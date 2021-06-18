#include "node.hpp"

Node::Node() {
	this->stu = NULL;
	this->link = NULL;
}

Node::Node(StudentPtr& d, Node* link) {
	this->setData(d);
	this->setLink(link);
}

StudentPtr Node::getData() { return this->stu; }
void Node::setData(StudentPtr st) { this->stu = st; }

Node* Node::getLink()const { return this->link; }
void Node::setLink(Node* link) { this->link = link; }