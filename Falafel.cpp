#include <iostream>   
#include <iomanip>    
#include <cctype>     
void displayMenu();   // function prototype
using namespace std;

const double PriceFalafel = 5.15;
const double PriceSoda    = 2.24;
const double PriceChips  = 1.57;

int main(int argc, char* argv[])
{
    double subtotal = 0.00;
    double price;
    char selection;
    double taxRate = 0.07;
    double salesTax;
    int countFalafal = 0;
    int countSoda = 0;
    int countChips = 0;

    displayMenu();
    do
    {
        price = 0;
        cout << "Make your selection (F,S,C,or T): ";
        cin >> selection;
        switch (toupper(selection))
        {
        case 'F':
            price = PriceFalafel;
            countFalafal++;
            break;
        case 'S':
            price = PriceSoda;
            countSoda++;
            break;
        case 'C':
            price = PriceChips;
            countChips++;
            break;
        case 'T':
            break;
        default:
            cout << "Illegal selection, try again." << endl;
        }
        subtotal += price;
    } while (selection != 'T' && selection != 't');
    
    salesTax = taxRate * subtotal;
    cout << countFalafal << "Falafel(s)" << endl;
    cout << countSoda << "Soda(s)" << endl;
    cout << countChips << "Chips" << endl;
    cout << "Sales tax $" << setprecision(2) << fixed << salesTax << endl;
    cout << "Subtotal $" << setprecision(2) << fixed << (subtotal + salesTax) << endl;
    return 0;
}

void displayMenu()
{
    cout << setiosflags(ios::fixed | ios::showpoint); // to make the cout fixed to 2 deci places
    cout << setprecision(2);  
    cout << endl;   
    cout << "F = falafel  $" << PriceFalafel << endl;
    cout << "S = soda     $" << PriceSoda << endl;
    cout << "C = chips   $" << PriceChips << endl;
    cout << "T = total" << endl;
}