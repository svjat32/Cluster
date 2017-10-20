
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <stdlib.h>     /* srand, rand */

using namespace std;

int main(){
    cout << "Hello, World! "<<endl;
    srand(time(0));
    float start_time = clock();
    static int firstArr[10000][10000];
    for (int i = 0; i < 10000; i++){
        for (int j = 0; j < 10000; j++){
            firstArr[i][j] = rand() % 50 - rand() % 50;
        }
    }
    
    float end_time = clock();
    float onString = end_time - start_time;
    start_time = clock();
    static int secondArr[10000][10000];
    for (int i = 0; i < 10000; i++){
        for (int j = 0; j<10000; j++){
            secondArr[j][i] = rand() % 50 - rand() % 50;
        }
    }
    
    end_time = clock();
    float onCollomn = end_time - start_time;

    cout << "on Strings: " << onString << "on Collomns: " << onCollomn << endl;
    return 0;
    }