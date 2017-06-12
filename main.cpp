#include <iostream>
#include <string>
#include <cstdlib>                                              // for atoi() atof()

int isFeet(std::string);                                        // declaration

class Distance
{
private:
    int feet;
    double inches;
public:
    Distance() : feet(0), inches(0.0)                           // declaration no arguments
    {}
    Distance(int feet_, double inches_): feet(feet_),inches(inches_) // constructor 2 arguments
    {}
    void showDist()
    {
        std::cout << feet << "\'-" << inches << "\"";
    }
    void getData();
};

void Distance::getData() {                                      // get length from user
    std::string instr;                                          // for input string
    while (true)
    {
        std::cout << "\nEnter feet: ";
        std::cin.unsetf(std::ios::skipws);                      // do not skip white spaces
        std::cin >> instr;                                      // get feet as string
        if(isFeet(instr))                                       // is it a correct value?
        {
            std::cin.ignore(10, '\n');                          // if yes delete chars, including new line
            feet = atoi(instr.c_str());                         // convert to integer
            break;
        }
        std::cin.ignore(10, '\n');                              // delete chars, including new line
        std::cout << "Feet must be an integer less then 1000\n";
    }
    while(true)                                                 // cycle until inches are right
    {
        std::cout << "Enter inches: ";
        std::cin.unsetf(std::ios::skipws);                      // do not skip white space
        std::cin >> inches;                                     // get inches(type double)
        if (inches >= 12 || inches < 0.0)
        {
            std::cout << "Inches must be between 0.0 and 11.99\n";
            std::cin.clear(std::ios::failbit);                  // artificially set failbit
        }
        if (std::cin.good())                                    // check for cin failure
        {                                                       // most comonly non-digit
            std::cin.ignore(10, '\n');                          // delete new line
            break;
        }
        std::cin.clear( );                                      // error clear the error state
        std::cin.ignore(10, '\n');                              // delete chars, including new line
        std::cout << "Incorrect inches input\n";                // try again
    }// end while inches
}

int isFeet(std::string str)                                     // return true if the string is a correct feet value
{
    int slen = str.size();                                      // get length
    if(slen == 0 || slen > 5)                                   // no input (0) or input is too long
        return 0;                                               // not an int
    for(int j = 0; j < slen; j++)                               // check each character if not digit or minus
    if ( (str[j] < '0' || str[j] >'9') && str[j] != '-')
        return 0;
    double n = atof(str.c_str());                               // convert to double
    if (n < -999.0|| n > 999.0)                               // is it out of range?
    return 0;                                                   // if so, not correct feet
    return 1;                                                   // it is correct feet
}

int main() {
    Distance distance;                                          // make distance object
    char answer;
    do{
        distance.getData();                                     // get its value from user
        std::cout << "\nDistance: ";
        distance.showDist();                                    // display distance
        std::cout << "Do another (y/n)?: ";
        std::cin >> answer;
        std::cin.ignore(10, '\n');                              // delete characters including new line
    }while (answer != '\n');                                    // cycle until new line
    system("pause");
    return 0;
}
