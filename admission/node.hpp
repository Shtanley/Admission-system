#ifndef NODE_HPP
#define NODE_HPP

#include "Dstudent.hpp"
#include "student.hpp"
//#include "Istudent.hpp"

class Node {
	public:
	Node();
	Node(StudentPtr& data, Node* link);

	StudentPtr getData();
	void setData(StudentPtr stu);

	Node* getLink()const;
	void setLink(Node* link);

	private:
	StudentPtr stu;
	Node* link;
};

typedef Node* NodePtr;

#endif