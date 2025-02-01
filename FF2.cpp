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


	void printList(){
		node* cur = head; 
		while(cur != nullptr){
			std::cout << cur->data << "->";
			cur = cur->next;
		}
		std::cout << std::endl;
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

	void addNodeByAddress(node* newNode){
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

	bool alreadyUsed(node* visitedHead, int val){
		while(visitedHead!= nullptr){
			if(visitedHead->data == val){
				return true;
			}
			visitedHead = visitedHead->next;
		}
		return false;
	}

	node* createFreqList(){
		node* curr = head;
		linkedList* freqList = new linkedList();
		linkedList* visited = new linkedList();
		int count;
		if(curr->next == nullptr){ //only has 1 element
				freqList->addNode(1);
				return freqList->head;
		}
		while(curr != nullptr){
			node* temp = curr->next;
			count = 1;
			if(visited->alreadyUsed(visited->head, curr->data)){
					curr = curr->next;
					continue;
			}
			while(temp != nullptr){
				if(temp->data == curr->data){
					count++;
				}
				temp = temp->next;
			}
			visited->addNode(curr->data);
			curr = curr->next;
			freqList->addNode(count);
		}
		delete visited;
		return freqList->head;
	}
};

int main(int argc, char* argv[]){
	linkedList* list = new linkedList();
	list->addNode(1);
	list->addNode(2);
	list->addNode(3);
	list->addNode(1);
	list->addNode(2);
	list->addNode(3);
	list->addNode(1);
	list->addNode(5);
	list->addNode(6);
	list->addNode(2);

	list->printList();
	std::cout << std::endl;
	linkedList* freqList = new linkedList();
	freqList->addNodeByAddress(list->createFreqList());

	freqList->printList();
	return 0;
}