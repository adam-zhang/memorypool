#include <iostream>
#include "MemoryPool.h"

using namespace std;

class Person
{
	public:
		Person()
		{
			cout << "constructor" << endl;
		}
	public:
		std::string name;
		size_t age;
};

int main(int argc, char** argv)
{
	MemoryPool<Person> pool;
	Object<Person> o;
	std::array<Object<Person>, 512> a;
	cout << "Hello World." << endl;
	return 0;
}
