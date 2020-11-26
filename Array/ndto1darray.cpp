//Address of nd array when are mapped into 1d array i.e. when stored in
//contiguous memory.
#include <iostream>

using namespace std;

int rowmajor(int[], int[], int length);
int colmajor(int[], int[], int len);

int main()
{
    int dimensions;
    cout << "Enter total no. of dimensions in matrix: ";
    cin >> dimensions;

    /*Array containing effective length of Each axis in dimension. 
  E.g. is lower bound is 4 and upper bound is 10 the effective length is 
  10-4+1 = 7*/
    int length[dimensions];

    /*Array containing effective distance of indexes i.e. distance from lower
  bound. */
    int effectivedis[dimensions];

    int bounds[dimensions][2];
    //Input lower and upper bound of each dimension.
    for (int i = 0; i < dimensions; i++)
    {
        cout << "Enter lower and upper bound of " << i + 1 << " dimension: ";
        cin >> bounds[i][0] >> bounds[i][1];
        length[i] = bounds[i][1] - bounds[i][0] + 1;
    }
    cout << "Enter element indexes you want address of with spaces in between \n"
         << "i.e. if you want addessess of element a[3][1][5] enter: 3 1 5: ";
    //Array to store index of which we want address.
    int add[dimensions];
    for (int i = 0; i < dimensions; i++)
    {
        cin >> add[i];
    }

    //Calculating effective distance
    for (int i = 0; i < dimensions; i++)
    {
        effectivedis[i] = add[i] - bounds[i][0];
    }
    int baseAdd;
    cout << "Enter base address i.e. address of first element: ";
    cin >> baseAdd;
    cout << "Enter weight i.e. size each element have: ";
    int weight;
    cin >> weight;
    cout << "#Select Row major or column major: \n"
         << "1. Row Major.\n"
         << "2. Column Major.\n";
    int temp, value = 0;
    cin >> temp;
    switch (temp)
    {
    case 1:
    {
        value = (rowmajor(effectivedis, length, dimensions));
        cout << "The address by rowMajor is: ";
        break;
    }
    case 2:
    {
        value = colmajor(effectivedis, length, dimensions);
        cout << "The address by columnMajor is: ";
        break;
    }
    default:
    {
        cout << "Enter Valid input.";
        break;
    }
    }

    int address = baseAdd + (weight * value);
    cout << address;
}

int rowmajor(int effectivedis[], int length[], int len)
{
    int add = 0;
    int pos;
    //Calculating address in row major
    //formula => ((((E1 x L2) + E2) x L3 + E3)Ln + En)
    for (int i = 0, j = len; i < j; ++i)
    {
        add *= length[i];
        add += effectivedis[i];
        cout << "current add: " << add;
    }
    cout << "final add: " << add;
    return add;
}

int colmajor(int effectivedis[], int length[], int len)
{
    int add = 0;
    for (int i = len - 1; i >= 0;--i)
    {
        add *= length[i];
        add += effectivedis[i];
    }
    return add;
}