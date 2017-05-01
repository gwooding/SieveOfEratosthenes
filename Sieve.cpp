#include <iostream>

using namespace std;

bool* findPrimesUnder(int n)
{
    if(n < 1)
    {
        throw "n needs to be above zero";
    }
    if ( n < 3)
    {
        return NULL;
    }

    bool* possibilities = new bool[n];

    for(int i = 0; i < n; i++){
        possibilities[i] = true;
    }

    possibilities[0] = false;
    possibilities[1] = false;

    for(int k = 2; k < n; k++){

        if(possibilities[k] == true) {

            int m = k;
            int jump = m;

            while(m < n){
                m = m + jump;
                possibilities[m] = false;
            }
        }
    }

    return possibilities;
}


//change name from main to run tests, also change altmain method in Catch.h to main to run tests
int main()
{
    int n = 0;

    cout << "Please select the ceiling for natural numbers that you would like to search" << endl;

    cin >> n;

    bool *primeBooleanMatrix = findPrimesUnder(n);

    for(int i = 0; i < n; i++){
        if(primeBooleanMatrix[i] == true){
            std::cout << i << ", ";
        }
    }

    delete [] primeBooleanMatrix;      // Not absolutely necessary, but
    //   a good idea.
    cin.ignore();

    return 0;
}