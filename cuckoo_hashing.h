#include <vector>
#include <climits>

const int MAX_M = 15;

class CuckooHashing
{

public:
    CuckooHashing(int m);
    void insert(int key);
    void delete_value(int key);
    int find(int key);

private:
    int compute_first_hash(int x);
    int compute_second_hash(int x);

    std::vector<int> first_hash_table;
    std::vector<int> second_hash_table;
};