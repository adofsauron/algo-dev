#include <iostream>
#include <string>
#include <sstream>

#include "bucket.h"

Bucket::Bucket() {
    this->local_depth = 1;
    this->size = 4;
    this->valueArr = new int[size];
    for (int i = 0 ; i < size; i++) {
    	valueArr[i] = 0;
    }
}

Bucket::Bucket(int size) {
    this->local_depth = 1;
    this->size = size;
	this->valueArr = new int[size];
	for (int i = 0 ; i < size; i++) {
    	this->valueArr[i] = 0;
    }
}

Bucket::~Bucket() {
	delete []this->valueArr;
}

void Bucket::Insert(int value) {
	for (int i = 0 ; i < size; i++ ) {
		if (valueArr[i] == 0) {
			valueArr[i] = value;
			break;
		}
	}
}

void Bucket::Remove(int value) {
	for (int i = 0 ; i < size; i++ ) {
		if (valueArr[i] == value) {
			valueArr[i] = 0;
			break;
		}
	}
}

void Bucket::Clear(int value) {
	for (int i = 0 ; i < size; i++ ) {
		if (valueArr[i] == value) {
			valueArr[i] = 0;
		}
	}
}

bool Bucket::Update(int value, int newValue) {
	for (int i = 0 ; i < size; i++ ) {
		if (valueArr[i] == value) {
			valueArr[i] = newValue;
			return true;
		}
	}

	return false;
}

bool Bucket::Find(int value) {
	for (int i = 0 ; i < size; i++ ) {
		if (valueArr[i] == value) {
				return true;
		}
	}
	return false;
}

void Bucket::Search(int value) {
	for (int i = 0 ; i < size; i++ ) {
		if (valueArr[i] == value) {
				std::cout << "Found: Index" << i << std::endl;
		}
	}
}

bool Bucket::IsEmpty() {
    for (int i = 0 ; i < size; i++ ) {
		if (valueArr[i] != 0) {
			return false;
		}
	}
	return true;
}

bool Bucket::IsFull() {
    for (int i = 0 ; i < size; i++ ) {
		if (valueArr[i] == 0) {
			return false;
		}
	}
	return true;
}


std::string Bucket::Display() {
	std::string s;
	s = "[";
	if(valueArr[0] == 0) {
			s += std::string("-");
		} else {
			s += std::string(std::to_string(valueArr[0]));
		}
	for (int i = 1 ; i < size; i++ ) {
		s += std::string(",");
		if(valueArr[i] == 0) {
			s += std::string("-");
		} else {
			s += std::string(std::to_string(valueArr[i]));
		}
	}

	s += std::string("]") + std::string(" (") + std::string(std::to_string(local_depth)) + std::string(")");
	return s;
}

void Bucket::Sort() {
	for (int i = 0 ; i < size; i++ ) {
		if (valueArr[i] == 0) {
			for (int j = i+1; j < size; j++) {
				if (valueArr[j]!=0) {
					valueArr[i] = valueArr[j];
					valueArr[j] = 0;
				}
			}
		}
	}
}

bool Bucket::Check(int value) {
    for (int i = 0 ; i < size; i++ ) {
		if (valueArr[i] != value) {
			return false;
		}
	}
	return true;
}
