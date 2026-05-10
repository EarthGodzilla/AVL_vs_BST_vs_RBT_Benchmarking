#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>
#include "bst.h"
#include "avl.h"
#include "rbt.h"
#include "timer.h"
using namespace std;

//DataStructures
/*#include "include/bst.h"
#include "include/avl.h"
#include "include/rbt.h"
#include "include/timer.h"*/

constexpr  int N = 10000;
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
can run :
g++ -std=c++17 main.cpp src/*.cpp -Iinclude -O2 -o benchmark
or 
g++ -std=c++17 main.cpp src/bst.cpp src/avl.cpp src/rbt.cpp -Iinclude -O2 -o benchmark

*/

void print(const vector<int>& data){
    BST bst, bst2;
    AVL avl, avl2;
    RBT rbt, rbt2;
   // Timer t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12;
    // moved to when used for more accurate timing

    // benchmark insertions, unsorted data
    cout << " UNSORTED INSERT BENCHMARK \n";
    Timer t1;
    for (int x : data){
         bst.insert(x);
        }
    cout << "BST Insert: " << t1.elapsedMs() << " ms\n";

    Timer t2;
    for (int x : data) {
        avl.insert(x);
    }
    cout << "AVL Insert: " << t2.elapsedMs() << " ms\n";

    Timer t3;
    for (int x : data) {
        rbt.insert(x);
    }
    cout << "RBT Insert: " << t3.elapsedMs() << " ms\n";

    // search benchmark
    Timer t4;
    for (int x : data) {
        bst.search(x);
    }   
    cout << "\nBST Search: " << t4.elapsedMs() << " ms\n";

    Timer t5;
    for (int x : data) {
        avl.search(x);
    }
    cout << "AVL Search: " << t5.elapsedMs() << " ms\n";

    Timer t6;
    for (int x : data) {
        rbt.search(x);
    }
    cout << "RBT Search: " << t6.elapsedMs() << " ms\n";

    // height benchmark
    cout << "\nTree Heights:\n";
    cout << "BST: " << bst.height() << "\n";
    cout << "AVL: " << avl.height() << "\n";
    cout << "RBT: " << rbt.height() << "\n";

    auto sorted = generateSorted();


    cout << "\n\n SORTED INSERT BENCHMARK \n";

    // benchmark sorted insertions
    Timer t7;
    for (int x : sorted) {
        bst2.insert(x);
    }//worst case Fails if too big like 5 million, stack overflow
    cout << "BST Sorted Insert: " << t7.elapsedMs() << " ms\n";

    Timer t8;
    for (int x : sorted) {
        avl2.insert(x);
    }
    cout << "AVL Sorted Insert: " << t8.elapsedMs() << " ms\n";

    Timer t9;
    for (int x : sorted) {
        rbt2.insert(x);
    }
    cout << "RBT Sorted Insert: " << t9.elapsedMs() << " ms\n";

    //search benchmark sorted
    cout<<"\n\nSorted Search\n";
    Timer t10;
    for (int x : sorted) {
        bst2.search(x);
    }
    cout << "BST Sorted Search: " << t10.elapsedMs() << " ms\n";

    Timer t11;
    for (int x : sorted) {
        avl2.search(x);
    }
    cout << "AVL Sorted Search: " << t11.elapsedMs() << " ms\n";
    
    Timer t12;
    for (int x : sorted) {
        rbt2.search(x);
    }
    cout << "RBT Sorted Search: " << t12.elapsedMs() << " ms\n";

        // height benchmark sorted
    cout << "\nSorted Heights:\n";
    cout << "BST: " << bst2.height() << "\n";
    cout << "AVL: " << avl2.height() << "\n";
    cout << "RBT: " << rbt2.height() << "\n";

}