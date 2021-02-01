// laba3-OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
class Object {
public:
	Object() {
		cout << "Object()\n";
	}
	virtual ~Object() {
		cout << "~Object()\n";
	}
};
class Cat :public Object {
public:
	Cat() {
		cout << "Cat()\n";
	}
	~Cat() {
		cout << "~Dog()\n";
	}

};
class Dog :public Object {
public:
	Dog() {
		cout << "Dog()\n";
	}
	~Dog() {
		cout << "~Dog()\n";
	}

};
class Storage {
protected:
	int size;
	Object** object;
public:
	int count;
	Storage(int size) {
		cout << "Storage(int size)\n";
		this->size = size;
		count = 0;
		object = new Object * [size];
		for (int i = 0; i < size; i++) {
			object[i] = NULL;
		}
	}
	void addObject(Object* newObject, int i) {
		if (i < size && object[i] == NULL) {
			object[i] = newObject;
			count++;
			cout << "объект добавлен void addObject(Object* newObject,int i) по индексу " << i << endl;
			cout << "количество элементов в хранилище" << " " << count << endl;
		}
		else {
			cout << "по индексу " << i << " уже находится элемент" << endl;
		}
	}
	void delObject(int i) {
		if (object[i] != NULL) {
			object[i] = NULL;
			count--;
			cout << "объект удалился void delObject(int i)  " << "по индексу " << i << endl;
			cout << "количество элементов в хранилище" << " " << count << endl;
		}
		else {
			cout << "ошибка void delObject(int i)\n";
			cout << "по индексу " << i << " нет элемента" << endl;
		}
	}
	~Storage() {
		delete[] object;//удаляются не сами объекты, а ссылки 
	}
};
int main()
{
	setlocale(LC_ALL, "rus");
	Storage p(10);
	Object* c = new Cat;
	p.addObject(c, 5);
	p.delObject(5);
	Object* d = new Dog;
	p.addObject(d, 3);
	Object* d2 = new Dog;
	p.addObject(d2, 5);
	Object* c2 = new Cat;
	p.addObject(c, 5);
	p.delObject(2);
	
}

