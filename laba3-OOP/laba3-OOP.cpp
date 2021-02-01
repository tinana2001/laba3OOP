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
		if ((i < size) && (object[i] == NULL)) {
			object[i] = newObject;
			count++;
			cout << "объект добавлен void addObject(Object* newObject,int i) по индексу " << i << endl;
			cout << "количество элементов в хранилище" << " " << count << endl;
			cout << "size: " << size << endl;
		}
		else {
			if (object[i] != NULL) {
				cout << "Ошибка addObject\n";
				cout << "по индексу " << i << " уже находится элемент" << endl;
				increaseSize(1);
				addObject2(newObject);
			}
		}	
	}
	void addObject2(Object* o) {//добавление в первый попавшийся
		for (int i = 0; i < size; i++) {
			if (object[i] == NULL) {
				object[i] = o;
				cout << "объект добавлен void addObject2(Object* o)" << endl;
				cout << i << endl;
				break;
			}
		}
		cout << "size: " << size << endl;
	}
	void delObject(int i) {
		if (object[i] != NULL) {
			object[i] = NULL;
			count--;
			if (count < 0) {
				count = 0;
			}
			cout << "объект удалился void delObject(int i)  " << "по индексу " << i << endl;
			cout << "количество элементов в хранилище" << " " << count << endl;
		}
		else {
			cout << "ошибка void delObject(int i)\n";
			cout << "по индексу " << i << " нет элемента" << endl;
		}
		cout << "size: " << size << endl;
	}
	Object* getObject(int i) {
		if (object[i] != NULL) {
			cout << "Object* getObject(int i) i=" << i << endl;
			return object[i];
		}
	}
	void increaseSize(int newsize) {
		Object** object2 = new Object * [newsize + size];
		cout << "void increaseSize(int newsize)" << endl;
		for (int i = 0; i < (size + newsize); i++) {
			object2[i] = NULL;
		}
		for (int i = 0; i < size; i++) {
			if (object[i] != NULL) {
				object2[i] = object[i];
			}
		}
		delete[] object;
		object = object2;
		size = newsize + size;
		cout << size << endl;

	}
	int getsize() {
		return size;
	}

	~Storage() {
		delete[] object;//удаляются не сами объекты, а ссылки 
		cout << "~Storage\n";
	}
};
int main()
{
	setlocale(LC_ALL, "rus");
	Storage p(50);
	for (int i = 0; i < 100; i++) {
		if (rand() % 2 == 0) {
			if (rand() % 5 == 0) {
				Object* c = new Cat;
				p.addObject(c, rand() % p.getsize());
			}
			else {
				Object* c = new Dog;
				p.addObject(c, rand() % p.getsize());
			}
		}
		else {
			if (rand() % 3 == 1) {
				p.delObject(rand() % p.getsize());
			}
			else {
				p.getObject(rand() % p.getsize());
			}
		}
	}
	
}

