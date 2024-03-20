#include <iostream>
#include "LinkedList.cpp"
#define M0_90 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main()
{
    M0_90
    LinkedList<int> FirstList;
    LinkedList<int> SecondList;
    FirstList.Append(90);
    FirstList.Append(69);
    FirstList.Append(10);
    FirstList.Append(10);
    FirstList.Append(22);


    SecondList.Append(80);
    SecondList.Append(72);
    SecondList.Append(69);
    SecondList.Append(10);
    SecondList.Append(10);

    cout << "FirstList"<<endl;
    FirstList.display();
    cout<<"********************************************************"<<endl;
    cout << "secondList"<<endl;
    SecondList.display();
    cout<<"********************************************************"<<endl;
    cout<<"smallest value"<<endl;
    cout << SecondList.GetMinimumValue()<<endl;
    cout<<"********************************************************"<<endl;
    LinkedList<int> SharedValue;
    SharedValue=FirstList.intersection(SecondList);
    FirstList.merge(SecondList);
    cout << "intersection"<<endl;
    SharedValue.display();
    cout << endl;
    return 0;
}