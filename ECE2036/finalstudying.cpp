#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T> void printVector(vector<T> &listRef)
{
    if (listRef.empty() == true)
        cout << "The list is empty!!!" << endl;
    else
    {
        for (int i = 0; i < listRef.size(); i++)
            cout << listRef[i] << " " ;
        cout << "\n\n"<< endl;
    }
}

int main2()
{
    vector <double> values;
    
    system("clear");
    
    cout << "Examples of pushing from the end" << endl;
    values.push_back(2.71);
    values.push_back(3.14);
    values.push_back(1.61);
    printVector(values);
    
    
    cout << "I can print out the size and capacity " << endl;
    cout << "Size: " << values.size() << endl;
    cout << "Capacity: " << values.capacity() << endl;
    
    cout << "I can pop of the back" << endl;
    values.pop_back();
    printVector(values);
    
    cout << "I can pop off the back again " << endl;
    values.pop_back();
    printVector(values);
    
    cout << "Examples of pushing 2.71, 3.14, 1.61" << endl;
    values.push_back(2.71);
    values.push_back(3.14);
    values.push_back(1.61);
    printVector(values);
    
    cout << "I can also resize the vector to have 10 elements" << endl;
    values.resize(10);
    printVector(values);
    
    return 0;
}

#include <iostream>
using namespace std;

template <typename T1, typename T2, typename T3>
T1 sumfunction( T2 param1, T3 param2)
{
    return ( (T1) (param1 + param2));
}


int main()
{
    
    double doubleNum1 = 4.8;
    double doubleNum2 = 10.8;
    int intNum1 = 2;
    int intNum2 = 8;
    
    system ("clear");
    
    cout << "Mixing "<< doubleNum1 << " & " << intNum1  << endl;
    
    cout << " Example with this mixing to return a double = " <<  sumfunction <double>(doubleNum1, intNum1) << endl;
    cout << "Example with this mixing to return a int = " <<  sumfunction <int>(doubleNum1, intNum1) << endl;
    cout << endl;
    
    cout << "Mixing "<< doubleNum1 << " & " << doubleNum2  << endl;
    cout << "Example with these doubles returning a double = " << sumfunction <double> (doubleNum1, doubleNum2) << endl;
    cout << endl;
    
    cout << "Mixing "<< intNum1 << " & " << intNum2  << endl;
    cout << "Example with these ints and returning an int = " << sumfunction <int> (intNum1, intNum2) << endl;
    
    return 0;
    
}
