
#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

#include <iostream>
#include <string>

#include "bucket.h"

class ExtensibleHashTable {
public:
	ExtensibleHashTable();
	ExtensibleHashTable(int size);
	~ExtensibleHashTable();

	bool Find(int key);
	void Insert(int key);
	bool Remove(int key);
	void Print();

private:
		int global_depth;
		int bucket_size;
		int directory_size;
		Bucket **bucketArr;

		int hash(int key);
		void split(int key);
		void doubleArr();

		int getSize();
		int getDS();
		int getGD();
};

#endif // __HASH_TABLE_H__