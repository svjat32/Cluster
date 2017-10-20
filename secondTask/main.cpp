#include <stdio.h>
#include <iostream>
#include <ctime>
#include <stdlib.h>     /* srand, rand */

using namespace std;

int main(){
    int const N = 1000;
    cout << "Hello, World! "<<endl;
    srand(time(0));
    static int firstArr[N][N];
    static int secondArr[N][N];
    static int result[N][N];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            firstArr[i][j] = rand() % 50 - rand() % 50;
            secondArr[i][j] = rand() % 50 - rand() % 50;
        }
    }
    float start_time = clock();
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            result[i][j] = 0;
            for (int k = 0; k < N; k++){
                result[i][j]+=firstArr[i][k]*secondArr[k][j];
            }
        }
    }
    float end_time = clock();
    float onString = end_time - start_time;
    start_time = clock();
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            result[i][j] = 0;
            for (int k = 0; k < N; k++){
                result[j][i]+=firstArr[j][k]*secondArr[k][i];
            }
        }
    }
    end_time = clock();
    
    float onCollomn = end_time - start_time;
    static int trans[N][N];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            trans[i][j] = secondArr[j][i];
        }
    }
    start_time = clock();
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            result[i][j] = 0;
            for (int k = 0; k < N; k++){
                result[i][j]+=firstArr[i][k]*trans[k][j];
            }
        }
    }
    end_time = clock();
    
    float onTrans = end_time - start_time;

    cout << "on Strings: " << onString << "on Collomns: " << onCollomn << " with Trans on string: " << onTrans<<endl;
    return 0;
    }