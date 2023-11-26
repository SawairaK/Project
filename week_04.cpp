#include <iostream>
#include <cmath>
using namespace std;

class Hexagon
 {
private:
    double side_length;

public:
    Hexagon(double s) : side_length(s) {}

    double calcArea() 
	{
        return 1.5 * 1.732 * side_length;
    }

    double calcPeri() 
	{
        return 6 * side_length;
    }

    double calcAngleSum()
	 {
        return 6 * 120;
    }

    void display()
	 {
        cout << "1: Area of hexagon is: " << calcArea() << endl;
        cout << "2: Perimeter of hexagon is: " << calcPeri() << endl;
        cout << "3: Sum of angles of hexagon is: " << calcAngleSum() << endl;
    }
};

class Square 
{
private:
    double side_length;

public:
    Square(double s) : side_length(s) {}

    double calcAreaSquare()
	 {
        return pow(side_length, 2);
    }

    double calcPeriSquare()
	 {
        return 4 * side_length;
    }

    void display()
	 {
        cout << "1: Area of square is: " << calcAreaSquare() << endl;
        cout << "2: Perimeter of square is: " << calcPeriSquare() << endl;
    }
};

int main()
 {
    string cnic;
    cout << "Enter your CNIC number: ";
    cin >> cnic;  
    int last_digit = cnic[cnic.length() - 1] - '0';  // Extract the last digit

    int hexagon_side_length = last_digit;
    int square_side_length = last_digit + 1;

    Hexagon hexagon(hexagon_side_length);
    Square square(square_side_length);

    while (true) 
	{
        cout << "Enter 1 to calculate:"<<endl<<"->Area"<<endl<<"->Perimeter"<<endl<<"->Sum of angles of hexagon" << endl;
        cout << "Enter 2 to calculate:"<<endl<<"->Area"<<endl<<"->Perimeter of square" << endl;
        cout << "Press any other key to exit:" << endl;

        char choice;
        cin >> choice;

        if (choice == '1') 
		{
            hexagon.display();
        } else if (choice == '2') 
		{
            square.display();
        } else 
		{
            break;
        }
    }

    return 0;
}


