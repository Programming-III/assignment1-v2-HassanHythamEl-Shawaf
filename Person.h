#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person {
private:
	string name;
	int id;
public:
	Person();
	Person(string name, int id);
	~Person();
	void display();
	string getName();
	void setName(string name);
	int getId();
	void setId(int id);
};
#endif
