#include "LinkedList.h"
#include <iostream>


class tempObj {
public:
	tempObj() {
		num1 = 0;
		num2 = 0;
	}
	tempObj(int num){
		num1 = 1;
		num2 = num;
	}

	int num1, num2;

};
void problem() {


	LinkedList<tempObj*> list; //linked list of tempObj*
							   //tempObj has two values, num1 and num2. num1 is 1, num2 is set using constructor
	list.pushFront(new tempObj(3));
	
	tempObj* i;
	i = *(list.begin());

	std::cout << i->num2 << std::endl; //works

	std::cout << (*(list.begin()))->num2 << std::endl; //gives 'expression must have pointer type'
	std::cout << (**(list.begin())).num2 << std::endl; //gives 'class "LinkedList<T>::iterator [with T=tempObj *]" has no member "num2"'

	system("pause");
}

int main() {
	problem();
	//LinkedList<int> list;

	////list.pushFront(3);
	////list.pushFront(2);
	//list.pushFront(4);
	//list.pushFront(3);
	//list.pushFront(2);
	//list.pushFront(1);
	////list.insert(++list.begin(), 4);

	////*(list.begin()) += 1;

	////std::cout << *(list.begin()) << std::endl;
	////std::cout << list.last() << std::endl;
	////std::cout << list.count() << std::endl;
	////list.remove(4);
	//
 //   /*for (auto iter = list.begin(); iter != ++list.end();iter++) {
	//	std::cout << *iter << std::endl;
	//}*/
	//std::cout << list.count() << std::endl;
	////list.popBack();
	////list.clear();
	////std::cout << list.count() << std::endl;
	//system("pause");
	return 0;
}





