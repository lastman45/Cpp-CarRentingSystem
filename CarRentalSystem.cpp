#include <iostream>
#include <conio.h> // used for delay function
#include <stdlib.h>
using namespace std;

struct Cars
{
    string Company[7] = {"Nissan", "Toyota", "Audi", "BMW", "Honda", "Ford", "Mercedes"};
    string Model[7] = {"GT-R", "Camry", "A4", "3 Series", "C", "R8", "Q7"};
    string Color[7] = {"Yellow", "Black", "Red", "Silver", "Grey", "Blue", "Aqua"};
    string MaxSpeed[7] = {"80km/h", "200km/h", "300km/h", "250km/h", "320km/h", "400km/h", "250km/h"};
    int Date[7] = {2010, 2011, 2012, 2013, 2014, 2015, 2016};
    int Price[7] = {10000, 20000, 30000, 40000, 35000, 27000, 450000};
} Car;

struct LeaseInfo
{
    string Name[100];
    string ID[100];
    int PaymentAcc[100];
} Lease;

void Menu()
{
    for (int i = 0; i < 7; ++i)
    {
        cout << "Enter " << (i + 1) << "\t- To Select " << Car.Company[i] << endl;
    }
}

void Details(int Choice)
{
    system("cls");
    cout << "\nYou Have Selected - " << Car.Company[Choice - 1] << endl;
    cout << "\nModel : " << Car.Model[Choice - 1] << endl;
    cout << "\nColour : " << Car.Color[Choice - 1] << endl;
    cout << "\nMaximum Speed : " << Car.MaxSpeed[Choice - 1] << endl;
    cout << "\nPrice : " << Car.Price[Choice - 1] << endl;
}

void CheckLease(int k)
{
    if (Lease.PaymentAcc[k] >= Car.Price[k])
        cout << "\nPayment Has Been confirmed" << endl;
    else
        cout << "\nKindly Pay up Quoted Price" << endl;
}

void UserInput(int TheChoice)
{
    system("cls");
    int j = TheChoice - 1; // Use the choice directly
    cout << "\nProvide Your Personal Details\n";
    cout << "\nEnter Your Name : ";
    cin >> Lease.Name[j]; // Use j for indexing
    cout << "\nEnter Your ID : ";
    cin >> Lease.ID[j];
    cout << "\nRenting Fee : ";
    cin >> Lease.PaymentAcc[j];

    CheckLease(j);
}

int Login();

int main()
{
    Login(); // calling login function to authenticate user

    string Decide = "Yes";
    cout << "CAR RENTAL SYSTEM\n";
    cout << "\nSelect an option from the menu: " << endl;
    while (Decide != "Exit")
    {
        Menu();
        cout << "\nYour Choice(1-7): ";
        int TheChoice;
        cin >> TheChoice;
        if (TheChoice < 1 || TheChoice > 7)
        {
            cout << "\nInvalid option! Please select between 1-7.\n";
            system("pause");
            system("cls");
            continue; // Skip the rest of the loop and start again
        }
        Details(TheChoice);
        cout << "\nAre you sure you want to proceed? (Yes/No/Exit): ";
        cin >> Decide;
        if (Decide == "Yes" || Decide == "yes")
            UserInput(TheChoice);

        cout << "\nDo you want to continue? (Yes/No): ";
        cin >> Decide;
        if (Decide == "No" || Decide == "no")
            break;

        system("cls");
    }

    return 0;
}

int Login()
{
    string Pass = ""; // Initialize the password variable
    char Ch;
    cout << "\nCAR RENTALS SYSTEM LOGIN\n";
    cout << "\nEnter Password: ";
    Ch = getch();      // Get character without echoing
    while (Ch != '\r') // Loop until the user presses enter
    {
        Pass.push_back(Ch); // Append character to the password string
        cout << '*';        // display * for each character entered
        Ch = getch();       // Get the next character
    }
    if (Pass == "pass") // setting password as pass
    {
        cout << "\nAccess Granted\n\n";
        system("pause"); // pause for user to see the message
        system("cls");
    }
    else
    {
        cout << "\nAccess Denied. Please try again.\n\n";
        system("pause");
        system("cls");
        Login(); // Recursively call the function to ask for password again
    }
}
