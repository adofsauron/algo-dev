#include <iostream>
#include <string>
#include <math.h>

#include "hashtable.h"
#include "bucket.h"

int ExtensibleHashTable::hash(int key) {
    int index;
    index = ((key+484)*5533) % directory_size;
    return index;
}

void ExtensibleHashTable::split(int key) {
    int index;
    index = this->hash(key);
    Bucket* newBucket = new Bucket(bucket_size);
    newBucket->local_depth = bucketArr[index]->local_depth;//copy the local depth

    if (global_depth == bucketArr[index]->local_depth) {
        this->doubleArr();
        int newIndex = this->hash(key);
        for (int i = 0; i < bucket_size; i++) {
            if (hash(bucketArr[index]->valueArr[i]) == newIndex) {
                newBucket->Insert(bucketArr[index]->valueArr[i]);
                bucketArr[index]->Remove(bucketArr[index]->valueArr[i]);
            }
        }

        newBucket->local_depth++;
        bucketArr[newIndex] = newBucket;
        //add the depth number with same connection
        int index_same_connection;
        if (newIndex >= directory_size/2) {
            index_same_connection = newIndex - int(pow(2,global_depth-1)); 
        } else {
            index_same_connection = newIndex + int(pow(2,global_depth-1)); 
        } 

        bucketArr[index_same_connection]->local_depth++;
    } else {
        int newIndex;
        if (index >= directory_size/2) {
            newIndex = index - int(pow(2,global_depth-1)); 
        } else {
            newIndex = index + int(pow(2,global_depth-1)); 
        } 
        for (int i = 0; i < bucket_size; i++) {
            if (hash(bucketArr[index]->valueArr[i]) == newIndex) {
                newBucket->Insert(bucketArr[index]->valueArr[i]);
                bucketArr[index]->Remove(bucketArr[index]->valueArr[i]);
            }   
        }
        newBucket->local_depth++;
        bucketArr[newIndex] = newBucket;
        bucketArr[index]->local_depth++;
    }
}

void ExtensibleHashTable::doubleArr() {
    Bucket **newArr = new Bucket* [2*(directory_size)];

    for (int i = 0; i < directory_size; i++) {
        int newIndex = int(pow(2,global_depth));
        newArr[i] = bucketArr[i];
        newArr[i+newIndex] = bucketArr[i];
    }
    bucketArr = newArr;

    global_depth++;
    directory_size = int(pow(2,global_depth));
}

int ExtensibleHashTable::getSize() {
    return bucket_size;
}

int ExtensibleHashTable::getDS() {
    return directory_size;
}


int ExtensibleHashTable::getGD() {
    return global_depth;
}


//public function:
ExtensibleHashTable::ExtensibleHashTable() {
    this->global_depth = 1;
    this->bucket_size = 4;
    this->directory_size = int(pow(2,global_depth));
    this->bucketArr = new Bucket* [directory_size];
    for(int i = 0 ; i <directory_size ; i++ ) {
        bucketArr[i] = new Bucket();
    }
}

ExtensibleHashTable::ExtensibleHashTable(int size) {
    this->global_depth = 1;
    this->bucket_size = size;
    this->directory_size = int(pow(2,global_depth));
    this->bucketArr = new Bucket* [directory_size];
    for(int i = 0 ; i <directory_size ; i++ ) {
        this->bucketArr[i] = new Bucket(size);
    }
}

ExtensibleHashTable::~ExtensibleHashTable() {
    for(int i = 0 ; i <directory_size ; i++ ) {
        delete(bucketArr[i]);
    }

    if (this->bucketArr) {
        delete(this->bucketArr);
    }
}


bool ExtensibleHashTable::Find(int key) {
    int index;
    index = this->hash(key);
    if (bucketArr[index]->Find(key)) {
        return true;
    }
    else {
        return false;
    }
}

void ExtensibleHashTable::Insert(int key) {
    int index;
    index = this->hash(key);
    if (bucketArr[index]->Check(key)) {
        std::cout << "Duplicated numbers > Bucket Size: Stop." << std::endl;
    } else{
        if (!bucketArr[index]->IsFull()) {
            bucketArr[index]->Insert(key);
                
        } else{
            this->split(key);
            int newIndex = this->hash(key);
            bucketArr[newIndex]->Insert(key);
        }        
    }
}

bool ExtensibleHashTable::Remove(int key) {
    int index;
    index = this->hash(key);
    if (bucketArr[index]->Find(key)) {
        bucketArr[index]->Clear(key);
        return true;
    } else {
        return false;
    }  
}

void ExtensibleHashTable::Print() {
    std::cout << "Global_depth:" << getGD() << std::endl;
    std::cout << "Bucket_size:" << getSize() << std::endl;
    std::cout << "Directory_size:" << getDS() << std::endl;
    for(int i = 0 ; i < directory_size ; i++ ) {
        bucketArr[i]->Sort();
        std::cout << i << ": " << bucketArr[i] << " --> " << bucketArr[i]->Display() << std::endl;
    }
}

