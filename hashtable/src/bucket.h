#include <iostream>
#include <string>

using namespace std;

#ifndef BUCKET_H
#define BUCKET_H

class Bucket {
public:
	Bucket();
	Bucket(int size);
	~Bucket();

	int local_depth;
	int size;
	int * valueArr;

	void Insert(int value);
	void Remove(int value);
	void Clear(int value);
	bool Update(int value, int newValue);
	bool Find(int value);
	void Search(int value);


	bool IsFull();
	bool IsEmpty();

	string Display();

	void Sort();

	bool Check(int value);
};

#endif 