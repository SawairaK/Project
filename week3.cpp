#include <iostream>
using namespace std;
// Function to calculate and display cost for slab 1
void costSlab1(int data[][3]) 
{
    cout << "Bill Calculate for Slab 1 is:" << endl;
    for (int i = 0; i < 3; ++i)
	 {
        cout << data[0][i] * 10 << " ";
    }
    cout << endl;
}
// Function to calculate and display cost for slab 2
void costSlab2(int data[][3]) 
{
    cout << "Bill Calculate for Slab 2 is:" << endl;
    for (int i = 0; i < 3; ++i)
	 {
        cout << data[1][i] * 15 << " ";
    }
    cout << endl;
}
// Function to calculate and display cost for slab 3
void costSlab3(int data[][3])
 {
    cout << "Bill Calculate for Slab 3 is:" << endl;
    for (int i = 0; i < 3; ++i)
	 {
        cout << data[2][i] * 20 << " ";
    }
    cout << endl;
}

int main() 
{
	// Given Source Data 
    int sourceData[3][3] = {{55, 65, 75}, {120, 150, 170}, {210, 230, 240}};
    string studentID = "XY12345678";

    cout << "My Student ID is " << studentID << endl;

    int choice;
    cout << "Enter your choice:"<<endl<<"Press 1 to display the bill of slab 1 and slab 2"<<endl<<"Press 2 to display the bill of slab 3"<<endl<<"Press any other key to exit." << endl;
    cin >> choice;

    switch (choice) 
	{
        case 1:
            costSlab1(sourceData);
            costSlab2(sourceData);
            break;
        case 2:
            costSlab3(sourceData);
            break;
        default:
            cout << "Exiting..." << endl;
            break;
    }

    return 0;
}

