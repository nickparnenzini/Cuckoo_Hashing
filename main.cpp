#include "cuckoo_hashing.h"
#include <iostream>

int main()
{
    CuckooHashing hash_table(10);
    hash_table.insert(5);
    int x = hash_table.find(5);
    std::cout << "Value found: " << x << std::endl;
    hash_table.delete_value(5);
    x = hash_table.find(5);
    std::cout << "Value found: " << x << std::endl;
}