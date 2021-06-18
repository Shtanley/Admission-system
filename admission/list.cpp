#include "list.hpp"

List::List() { 
	head = nullptr;
	tail = nullptr;
}

void List::headIns(NodePtr head, StudentPtr st) {
	NodePtr temp = new Node();
	temp->setData(st);
	temp->setLink(head);
	head = temp;
}
void List::tailIns(NodePtr head, StudentPtr st) {
	if (head == nullptr) {
		cout << "Empty List.\n";
		return;
	}
	else {
		NodePtr h = head;
		while (h->getLink() != nullptr) { h = h->getLink(); }

		NodePtr temp = new Node();
		temp->setLink(nullptr);
		temp->setData(st);

		h->setLink(temp);
	}
}
void List::insNext(NodePtr head, NodePtr node, StudentPtr st) {
	if (node == head) { headIns(head, st); }
	else {
		NodePtr temp = head;
		while (temp->getLink() != node) { temp = temp->getLink(); }

		NodePtr node = new Node();
		node->setData(st);
		node->setLink(node);
		temp->setLink(node);
	}
}

void List::insDom(NodePtr head, StudentPtr st) {	//Time complexity = O(n)
	if (head == nullptr) { headIns(head, st); }
	else {
		NodePtr temp = head;
		while (temp != nullptr) {
			if (compareRS(temp->getData(), st) == -1) {
				insNext(head, temp, st);
			}
			else if (compareRS(temp->getData(), st) == 0) {
				if (compareCGPA(temp->getData(), st) == -1) {
					insNext(head, temp, st);
				}
				else if (compareCGPA(temp->getData(), st) == 0) {
					if (compareProvince(temp->getData(), st) == 1) {
						insNext(head, temp, st);
					}
					else { temp = temp->getLink(); }
				}
				else { temp = temp->getLink(); }
			}
			else { temp = temp->getLink(); }
		}
		if (temp == nullptr) { tailIns(head, st); }
	}
}

void List::printList(NodePtr h) {
	int num;
	if (h == nullptr) {
		cout << "List is empty.\n";
		return;
	}
	else {
		NodePtr temp = h;
		while (temp != nullptr) {
			cout << temp->getData();
			cout << endl;
			temp = temp->getLink();
			num++;
		}
	}
	cout << "\n\tnum: " << num << endl;
}

void List::FixName(string& name) {
	if (name[0] >= 'a' && name[0] <= 'z') { name[0] = name[0] - 32; }

	int i = 1;
	while (name[i] != '\0') {
		if (name[i] >= 'A' && name[i] <= 'Z') { name[i] = name[i] + 32; }
		i++;
	}
}

bool List::delDom(NodePtr& head, string& f, string& l) {
	if (head == nullptr) {
		cout << "List is empty,\n";
		return false;
	}
	else {
		FixName(f);
		FixName(l);
		NodePtr temp1 = head;
		NodePtr temp2 = head;
		int num = 0, s = 0;
		while (temp1 != nullptr) {
			string  name1 = temp1->getData()->getFirstName(), name2 = temp1->getData()->getLastName();
			FixName(name1);
			FixName(name2);
			if (name1 != f || name2 != l) { num++; }
			temp1 = temp1->getLink();
		}
		while (temp2 != nullptr) {
			s++;
			temp2 = temp2->getLink();
		}
		if (num == s) { return false; }
		else {
			NodePtr before = head;
			NodePtr current = head->getLink();
			while (current != nullptr) {
				//check head node
				if (before->getData()->getFirstName() == f && before->getData()->getLastName() == l) {
					NodePtr temp3 = before;
					before = before->getLink();
					current = current->getLink();
					temp3->setLink(nullptr);	//sets the new value of head, the student after the previous head
					delete temp3;	//deletes the old head from memory
				}
				//if any member of the linked list contains a student with first name f and last name l remove them from the list
				string  name1 = current->getData()->getFirstName(), name2 = current->getData()->getLastName();
				FixName(name1);
				FixName(name2);
				if (name1 == f && name2 == l) {
					before->setLink(current->getLink());
					delete current;

					current = before->getLink();
				}
				current = current->getLink();
				before = before->getLink();	//sets the value at temp to the next value in the list, going down the list.
			}
			return true;
		}
	}
}

bool List::delHeadTail(NodePtr& head, NodePtr& tail){
	if (head == nullptr) {	//Check to make sure that the linked list is defined.
		cout << "List is empty.\n";
		return false;
	}
	else if (head->getLink() == nullptr) {
		NodePtr temp = head->getLink();
		head->setLink(nullptr);
		delete temp;
	}
	else {
		NodePtr temp = head;
		head = head->getLink();
		temp->setLink(nullptr);

		delete temp;	//delete value at head as it is dynamic memory and is no longer used.

		//Creates a new temperary node that becomes the node before the tail.
		NodePtr newTail = head;
		while (newTail->getLink() != tail) {
			newTail = newTail->getLink();
		}
		//Tail is set to this new temperary node.
		tail = newTail;
		tail->setLink(nullptr);
		//delete value at tail as it is dynamic memory and is no longer used.

		return true;
	}
}
