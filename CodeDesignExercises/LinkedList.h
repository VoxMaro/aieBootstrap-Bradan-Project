#pragma once

template<typename T>
class LinkedList {
public:

	class LinkNode {
	public:
		LinkNode* next;
		LinkNode* prev;
		T item;
	};

	class iterator{
	public:
		iterator() { node = nullptr; }
		iterator(LinkNode* pointer) { node = pointer; }
		iterator operator=(const iterator &it) { this->node = it.node; return *this; }
		T& operator*() { return (node->item); }

		iterator operator++()
		{
			this->node = node->next;
			return *this;
		}
		iterator operator++(int)
		{
			iterator temp = *this;
			++*this;
			return temp;
		}
		iterator operator--()
		{
			this->node = node->prev;
			return *this;
		}
		iterator operator--(int)
		{
			iterator temp = *this;
			--*this;
			return temp;
		}
		bool operator==(const iterator & it) 
		{
			if (this->node == it.node) return true;
			return false;
		}
		bool operator!=(const iterator & it)
		{
			if (this->node != it.node) return true;
			return false;
		}
	
		LinkNode* node;
	};
	void pushFront(T val) {
		LinkNode* tempNode = new LinkNode;
		tempNode->item = val;
		if (!empty()) {
			tempNode->next = firstNode;
			firstNode->prev = tempNode;
		}
		else { 
			tempNode->next = nullptr; 
			lastNode = tempNode;
		}
		tempNode->prev = nullptr;
		firstNode = tempNode;
	}
	void pushBack(T val) {
		LinkNode* tempNode = new LinkNode;
		tempNode->item = val;
		if (!empty()) {
			tempNode->prev = lastNode;
			lastNode->next = tempNode;
		}
		else {
			tempNode->prev = nullptr;
			firstNode = tempNode;
		}
		tempNode->next = nullptr;
		lastNode = tempNode;
	}
	void insert(iterator it, T val) {
		LinkNode* tempNode = new LinkNode;
		tempNode->item = val;
		tempNode->prev = it.node;
		tempNode->next = it.node->next;
		it.node->next->prev = tempNode;
		it.node->next = tempNode;
	}
	
	iterator begin() { return iterator(firstNode); }
	iterator end() { return iterator(lastNode); }

	T first() {
		if (!empty()) return firstNode->item;
	}
	T last() {
		if (!empty()) return lastNode->item;
	}

	int count() {
		if (empty()) return 0;
		iterator it = begin();
		int i = 0;
		while (it != ++end())
		{
			i++;
			it++;
		}
		return i;
	}
	//void erase(iterator it) {
	//	if (it == begin()) {
	//		popFront();
	//		//it = begin();
	//		return;
	//	}
	//	else if (it == end()) {
	//		popBack();
	//		//it = end();
	//		return;
	//	}
	//	else {
	//		it.node->prev->next = it.node->next;
	//		it.node->next->prev = it.node->prev;
	//		delete it.node;
	//	}
	//	
	//}
	iterator erase(iterator it) {
		iterator temp;
		
		//else temp.node = it.node->next;

		if (it == begin()) {
			popFront();
			temp = ++begin();
			
		}
		else if (it == end()) {
			popBack();
			temp.node = nullptr;
			
		}
		else {
			it.node->prev->next = it.node->next;
			it.node->next->prev = it.node->prev;
			temp.node = it.node->next;
			delete it.node;
		}
		return temp;

	}
	void remove(T removeVal) {
		for (iterator it = begin(); it != ++end();)
		{
			//iterator next;
			//if(it != end()) next = it.node->next;
			if (*it == removeVal) { it = erase(it);}
			//if (it == nullptr) break;
			else { it++; }
		}
	}
	
	void popBack() {
		if (lastNode->prev == nullptr) {
			delete lastNode;
			lastNode = nullptr;
			firstNode = nullptr;
		}
		else {
			LinkNode* temp = lastNode->prev;
			delete lastNode;
			temp->next = nullptr;
			lastNode = temp;
		}
	}
	void popFront() {
		if (firstNode->next == nullptr) {
			delete firstNode;
			lastNode = nullptr;
			firstNode = nullptr;
		}
		else {
			LinkNode* temp = firstNode->next;
			delete firstNode;
			temp->prev = nullptr;
			firstNode = temp;
		}
	}

	bool empty() {return firstNode == nullptr;}
	
	void clear() {
		/*for (auto iter = begin(); iter != ++end(); iter++) {
			popFront();

		}*/
		unsigned int u = count();
		for (unsigned int i = 0; i < u; i++) {
			popFront();
		}
	}

private:
	

	LinkNode* firstNode = nullptr;
	LinkNode* lastNode = nullptr;

	
};

