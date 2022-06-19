#include <iostream>

#include "hashtable.h"

int	main(int argc, char **argv)
{
    ExtensibleHashTable ht;

    ht.Insert(1);
    ht.Insert(2);
    ht.Insert(3);

    ht.Print();

    
    if(ht.Remove(2)) {
        std::cout << "remove key 2 ok" << std::endl;
    }

    ht.Print();

    if (ht.Find(1)) {
        std::cout << "find key 1" << std::endl;
    }

    if (!ht.Find(2)) {
        std::cout << "not find key 2" << std::endl;
    }

    return 0;
}
