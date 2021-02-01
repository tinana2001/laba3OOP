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
int main()
{

}

