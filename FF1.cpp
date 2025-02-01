#include <iostream>

struct node{
	int data;
	node* next;

	node(int val){
		data = val;
		next = nullptr;
	}
};

class linkedList{

	public:
	node* head;
	
	linkedList(){
		head = nullptr;
	}
	void addNode(int val){
		node* newNode = new node(val);
		if(head == nullptr){
			head = newNode;
		}
		else{
			node* temp = head;
			while(temp->next != nullptr){
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
	void printList(){
		node* temp = head;
		while(temp != nullptr){
			std::cout << temp->data << "->";
			temp = temp->next;
		}
		std::cout << std::endl;
	}

	bool palindrome(){
		node* leftptr = head;
		return isPalindrome(head, leftptr);
	}

	bool isPalindrome(node* right, node*& leftptr){
		if(right == nullptr){
			return true;
		}
		if(isPalindrome(right->next, leftptr) == false){
			return false;
		}
		
		if(right->data != leftptr->data){
			return false;
		}
		leftptr = leftptr->next;
		return true;
	}
};


int main(int argc, char* argv[])
{
	linkedList list;
	for(int i = 0; i < 10; i++){
		list.addNode(i);
	}
	list.printList();
	std::cout << list.palindrome() << std::endl;

	linkedList list2;
	list2.addNode(1);
	list2.addNode(2);
	list2.addNode(3);
	list2.addNode(2);
	list2.addNode(1);

	list2.printList();

	std::cout << list2.palindrome() << std::endl;
	return 0;
}