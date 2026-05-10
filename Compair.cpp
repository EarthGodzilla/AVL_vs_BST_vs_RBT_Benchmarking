#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>
#include <set>
#include <map>
#include "include/timer.h"

using namespace std;

constexpr int N = 10000;

void print(const vector<int>& data);

vector<int> generateRandom() {
    vector<int> v(N);
    iota(v.begin(), v.end(), 0);
    shuffle(v.begin(), v.end(), mt19937{random_device{}()});
    return v;
}

vector<int> generateSorted() {
    vector<int> v(N);
    iota(v.begin(), v.end(), 0);
    return v;
}

int main() {
    auto data = generateRandom();
    print(data);
    return 0;
}
/*
void print(const vector<int>& data){
    BST bst, bst2;
    AVL avl, avl2;
    RBT rbt, rbt2;
    set<int> s, s2;
    map<int,int> m, m2;

    cout << " UNSORTED INSERT BENCHMARK \n";

    Timer t1;
    for (int x : data){
        bst.insert(x);
    }
    cout << "BST Insert: " << t1.elapsedMs() << " ms\n";

    Timer t2;
    for (int x : data){
        avl.insert(x);
    }
    cout << "AVL Insert: " << t2.elapsedMs() << " ms\n";

    Timer t3;
    for (int x : data){
        rbt.insert(x);
    }
    cout << "RBT Insert: " << t3.elapsedMs() << " ms\n";

    Timer t13;
    for (int x : data){
        s.insert(x);
    }
    cout << "set Insert: " << t13.elapsedMs() << " ms\n";

    Timer t14;
    for (int x : data){
        m.emplace(x, x);
    }
    cout << "map Insert: " << t14.elapsedMs() << " ms\n";

    Timer t4;
    for (int x : data){
        bst.search(x);
    }
    cout << "\nBST Search: " << t4.elapsedMs() << " ms\n";

    Timer t5;
    for (int x : data){
        avl.search(x);
    }
    cout << "AVL Search: " << t5.elapsedMs() << " ms\n";

    Timer t6;
    for (int x : data){
        rbt.search(x);
    }
    cout << "RBT Search: " << t6.elapsedMs() << " ms\n";

    Timer t15;
    for (int x : data){
        s.find(x);
    }
    cout << "set Search: " << t15.elapsedMs() << " ms\n";

    Timer t16;
    for (int x : data){
        m.find(x);
    }
    cout << "map Search: " << t16.elapsedMs() << " ms\n";

    cout << "\nTree Heights:\n";
    cout << "BST: " << bst.height() << "\n";
    cout << "AVL: " << avl.height() << "\n";
    cout << "RBT: " << rbt.height() << "\n";

    auto sorted = generateSorted();

    cout << "\n\n SORTED INSERT BENCHMARK \n";

    Timer t7;
    for (int x : sorted){
        bst2.insert(x);
    }
    cout << "BST Sorted Insert: " << t7.elapsedMs() << " ms\n";

    Timer t8;
    for (int x : sorted){
        avl2.insert(x);
    }
    cout << "AVL Sorted Insert: " << t8.elapsedMs() << " ms\n";

    Timer t9;
    for (int x : sorted){
        rbt2.insert(x);
    }
    cout << "RBT Sorted Insert: " << t9.elapsedMs() << " ms\n";

    Timer t17;
    for (int x : sorted){
        s2.insert(x);
    }
    cout << "set Sorted Insert: " << t17.elapsedMs() << " ms\n";

    Timer t18;
    for (int x : sorted){
        m2.emplace(x, x);
    }
    cout << "map Sorted Insert: " << t18.elapsedMs() << " ms\n";

    cout << "\n\nSorted Search\n";

    Timer t10;
    for (int x : sorted){
        bst2.search(x);
    }
    cout << "BST Sorted Search: " << t10.elapsedMs() << " ms\n";

    Timer t11;
    for (int x : sorted){
        avl2.search(x);
    }
    cout << "AVL Sorted Search: " << t11.elapsedMs() << " ms\n";

    Timer t12;
    for (int x : sorted){
        rbt2.search(x);
    }
    cout << "RBT Sorted Search: " << t12.elapsedMs() << " ms\n";

    Timer t19;
    for (int x : sorted){
        s2.find(x);
    }
    cout << "set Sorted Search: " << t19.elapsedMs() << " ms\n";

    Timer t20;
    for (int x : sorted){
        m2.find(x);
    }
    cout << "map Sorted Search: " << t20.elapsedMs() << " ms\n";

    cout << "\nSorted Heights:\n";
    cout << "BST: " << bst2.height() << "\n";
    cout << "AVL: " << avl2.height() << "\n";
    cout << "RBT: " << rbt2.height() << "\n";
}*/

void print(const vector<int>& data){
    set<int> s, s2;
    map<int,int> m, m2;

    cout << " UNSORTED INSERT BENCHMARK \n";

    Timer t1;
    for (int x : data){
        s.insert(x);
    }
    cout << "set Insert: " << t1.elapsedMs() << " ms\n";

    Timer t2;
    for (int x : data){
        m.emplace(x, x);
    }
    cout << "map Insert: " << t2.elapsedMs() << " ms\n";

    Timer t3;
    for (int x : data){
        s.find(x);
    }
    cout << "\nset Search: " << t3.elapsedMs() << " ms\n";

    Timer t4;
    for (int x : data){
        m.find(x);
    }
    cout << "map Search: " << t4.elapsedMs() << " ms\n";

    auto sorted = generateSorted();

    cout << "\n\n SORTED INSERT BENCHMARK \n";

    Timer t5;
    for (int x : sorted){
        s2.insert(x);
    }
    cout << "set Sorted Insert: " << t5.elapsedMs() << " ms\n";

    Timer t6;
    for (int x : sorted){
        m2.emplace(x, x);
    }
    cout << "map Sorted Insert: " << t6.elapsedMs() << " ms\n";

    cout << "\n\nSorted Search\n";

    Timer t7;
    for (int x : sorted){
        s2.find(x);
    }
    cout << "set Sorted Search: " << t7.elapsedMs() << " ms\n";

    Timer t8;
    for (int x : sorted){
        m2.find(x);
    }
    cout << "map Sorted Search: " << t8.elapsedMs() << " ms\n";
}