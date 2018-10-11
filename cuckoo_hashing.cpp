#include "cuckoo_hashing.h"

CuckooHashing::CuckooHashing(int m) {
    first_hash_table.resize(m);
    second_hash_table.resize(m);
}

void CuckooHashing::insert(int key) {
    int y = compute_first_hash(key);
    if (first_hash_table[y] == INT_MAX) {
        // evict the old value
        int old_value = first_hash_table[y];
        first_hash_table[y] = key;
        y = compute_second_hash(old_value);
        second_hash_table[y] = old_value;
    }
    else {
        first_hash_table[y] = key;
    }
}

void CuckooHashing::delete_value(int key) {
    int y = compute_first_hash(key);
    if (first_hash_table[y] == key) {
        first_hash_table[y] = INT_MAX;
    }
    else {
        y = compute_second_hash(key);
        if (second_hash_table[y] == key) {
            second_hash_table[y] = INT_MAX;
        }
    }
}

int CuckooHashing::find(int key) {
    int y = compute_first_hash(key);
    if (first_hash_table[y] == key) {
        return first_hash_table[y];
    }
    else {
        y = compute_second_hash(key);
        if (second_hash_table[y] == key) {
            return second_hash_table[y];
        }
    }
    return INT_MAX;
}

int CuckooHashing::compute_first_hash(int x) {
    return x % MAX_M;
}

int CuckooHashing::compute_second_hash(int x) {
    return (x / MAX_M) % MAX_M;
}