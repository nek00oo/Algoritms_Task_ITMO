#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class HashTableItem {
public:
    T value;
    bool used;

    HashTableItem() {
        used = false;
    }
};

template<typename T>
class KykyshkaTable {
private:
    int size;
    int maxIterations;
    //HashTableItem<T> *table1;
    //HashTableItem<T> *table2;
    vector<HashTableItem<T>> table1;
    vector<HashTableItem<T>> table2;

public:
    KykyshkaTable(int size) {
        this->size = size * 2;
        this->maxIterations = size * 4;
        /*table1 = new HashTableItem<T>[size * 2];
        table2 = new HashTableItem<T>[size * 2];*/
        table1 = vector<HashTableItem<T>>(size);
        table2 = vector<HashTableItem<T>>(size);
    }

    int hash1(pair<int,int> value) {
        return (hash<int>()(value.first)+hash<int>()(value.second)) % size;
    }

    int hash2(pair<int,int> value) {
        return ((2 * hash<int>()(value.first) + 1)+(2 * hash<int>()(value.first) + 1)) % size;
    }

    void insert(T value) {
        int i = 0;
        while (i < maxIterations) {
            int index1 = hash1(value);
            int index2 = hash2(value);

            if (!table1[index1].used) {
                table1[index1].value = value;
                table1[index1].used = true;
                return;
            }

            if (!table2[index2].used) {
                table2[index2].value = value;
                table2[index2].used = true;
                return;
            }


            T temp = table1[index1].value;
            table1[index1].value = value;
            value = temp;
            i++;

            temp = table2[index2].value;
            table2[index2].value = value;
            value = temp;
            i++;
        }

        rebuild();
        insert(value);
    }

    bool search(T value) {
        int index1 = hash1(value);
        int index2 = hash2(value);

        if (table1[index1].used && table1[index1].value == value)
            return true;

        if (table2[index2].used && table2[index2].value == value)
            return true;

        return false;
    }

    void rebuild() {
        int newSize = size * 2;
       /* auto *newTable1 = new HashTableItem<T>[newSize];
        auto *newTable2 = new HashTableItem<T>[newSize];*/
        vector<HashTableItem<T>> newTable1(newSize);
        vector<HashTableItem<T>> newTable2(newSize);

        for (int i = 0; i < size; i++) {
            if (table1[i].used)
                insert(table1[i].value);

            if (table2[i].used)
                insert(table2[i].value);
        }

        size = newSize;
        table1 = newTable1;
        table2 = newTable2;
    }

};

int main() {
    int n;
    cin >> n;
    KykyshkaTable<pair<int,int>> Table(n);
    pair<int, int> pair;
    //KykyshkaTable<int> Table2(n*2);
    for (int i = 0; i < n; ++i) {
        cin >> pair.first >> pair.second;
        Table.insert(pair);
    }


    return 0;
}