/* Programmer: Liam McAleavey
 * Class: CS 2250
 * Due Date: Feb 12, 2020
 * Description: This program takes input of a string and either encrypts
 *              or decrypts it using a Caesar-shift cipher. It can also
 *              brute force the string through the whole alphabet.
 */

#include <iostream>
#include <string>

using namespace std;

// Function prototypes
void DisplayMenu();
int ProcessMenuInput(int minRange, int maxRange, const string& menuType);
int PromptForInteger(int minRange, int maxRange, const string& menuType);
string PromptForString(const string& prompt);
void Encrypt(string& strToProcess, int shiftValue);
void Decrypt(string& strToProcess, int shiftValue);
void BruteForce(string& strToProcess);

// main()
// Parameters:
//      none
// Return Value:
//      int - Returns a 0 if main executed correctly, and a 1 if it did not
// Description:
//      Governs the main loop of giving the user a menu, processing their
//      input, and then calling a function to encrypt or decrypt a string
//      based on that input
int main()
{
    int userInput = 0;              // We'll use this to store our user's menu input
    int shiftValue = 0;             // Stores the amount the user wants to shift the string
    string stringToProcess = "";    // Stores the user's string

    // Display the welcome message. This should only happen once.
    cout << "Welcome to the Tali-banned Encrypter!" << endl
        << "Make a selection from the menu and then follow the prompts." << endl;

    // Now we'll enter the main loop of the program. By design, we'll always want this to run
    // at least once, so a do-while works great for this
    do
    {
        // Begin by displaying the menu to our user
        DisplayMenu();

        // Now start getting their input for the menu
        userInput = ProcessMenuInput(1, 4, "menu");

        // Process the input based on the return value
        switch (userInput)
        {
        case 1:
            // Get the string to encrypt
            stringToProcess = PromptForString("Please enter the message to encrypt: ");

            // Get the shift value
            shiftValue = ProcessMenuInput(1, 25, "");

            // Encrypt it based on our input
            Encrypt(stringToProcess, shiftValue);
            cout << "Encrypted as: " << endl << stringToProcess << endl;
            break;

        case 2:
            // Get the string to encrypt
            stringToProcess = PromptForString("Please enter the message to decrypt: ");

            // Get the shift value
            shiftValue = ProcessMenuInput(1, 25, "");

            // Decrypt it based on our input
            Decrypt(stringToProcess, shiftValue);
            cout << "Decrypted as: " << endl << stringToProcess << endl;
            break;

        case 3:
            // Get the string to encrypt
            stringToProcess = PromptForString("Please enter the message to decrypt: ");

            // Encrypt it based on our input
            BruteForce(stringToProcess);
            break;

        default:
            cout << "Thank you Caesar!  See ya!";
        }

    } while (userInput != 4);

    return 0;
}

// DisplayMenu()
// Parameters:
//      none
// Return Value:
//      none
// Description:
//      Prints out the main menu to the console
void DisplayMenu()
{
    cout << "*************************************" << endl
        << "* 1 - Encrypt a message" << endl << "* 2 - Decrypt a message" << endl
        << "* 3 - Brute - force decrypt a message" << endl
        << "* 4 - Quit" << endl << "*************************************" << endl;
}

// ProcessMenuInput()
// Parameters:
//      int minRange - the minimum integer value allowed for the particular input
//      int maxRange - the maximum integer value allowed for the particular input
//      string menuType - defines the kind of input we want
// Return Value:
//      int - Returns the (allowed) value of the user's input
// Description:
//      Uses the PromptForInteger() function to get an integer from the user, and
//      then ensures that value is within range before returning it
int ProcessMenuInput(int minRange, int maxRange, const string& menuType);
{
    int input = 0;      // this will store whatever is passed back from PromptForInteger

    input = PromptForInteger(minRange, maxRange, menuType);

    // If we get back something invalid, we'll print an error and try again
    while (input < minRange || input > maxRange)
    {
        cout << "Invalid choice, ";

        input = PromptForInteger(minRange, maxRange, menuType);
    }

    //Return the proper input
    return input;
}

// PromptForInteger()
// Parameters:
//      int minRange - the minimum integer value allowed for the particular input
//      int maxRange - the maximum integer value allowed for the particular input
//      string menuType - defines the kind of input we want
// Return Value:
//      int - Returns a the integer input the user gave us
// Description:
//      Gives the user a specific prompt for input based on the parameters. With a
//      menuType of "menu", it will prompt for a main menu input. Otherwise, it is a
//      shift value
int PromptForInteger(int minRange, int maxRange, const string& menuType);
{
    int input = 0;          // this will store whatever the user inputs

    // Print out a specific prompt to the user depending on the input we want
    if (menuType == "menu")
    {
        cout << "Please make a menu selection (" << minRange << "-" << maxRange << "): ";
    }

    else
    {
        cout << "Please enter the shift value(" << minRange << " - " << maxRange << "): ";
    }

    // Take in an input and return it
    cin >> input;
    cin.ignore();

    return input;
}

// PromptFoString()
// Parameters:
//      string prompt - the prompt we want to give to the user
// Return Value:
//      string - returns whatever the user inputs without processing
// Description:
//      Takes in a string, and uses it to prompt the user to input a string.
//      Then returns the string the user entered.
string PromptForString(const string& prompt)
{
    string inputString = "";    // Holds the string the user is going to input

    // Prompt the user for a string and collect it
    cout << prompt;
    getline(cin, inputString);

    return inputString;
}

// Encrypt()
// Parameters:
//      string strToProcess - the string the user wants to manipulate
//      int shiftValue - the amount to shift each character
// Return Value:
//      none
// Description:
//      Takes in a string, and shifts each character forward by the shift value
//      before printing the shifted string
void Encrypt(string& strToProcess, int shiftValue)
{
    for (int i = 0; i < strToProcess.length(); i++)
    {
        if (isalpha(strToProcess[i]))
        {
            for (int j = 0; j < shiftValue; j++)
            {
                if (strToProcess[i] == 'Z' || strToProcess[i] == 'z')
                {
                    strToProcess[i] -= 25;
                }

                else strToProcess[i]++;
            }
        }
    }
}

// Decrypt()
// Parameters:
//      string strToProcess - the string the user wants to manipulate
//      int shiftValue - the amount to shift each character
// Return Value:
//      none
// Description:
//      Takes in a string, and shifts each character backward by the shift value
//      before printing the shifted string
void Decrypt(string& strToProcess, int shiftValue)
{
    for (int i = 0; i < strToProcess.length(); i++)
    {
        if (isalpha(strToProcess[i]))
        {
            for (int j = 0; j < shiftValue; j++)
            {
                if (strToProcess[i] == 'A' || strToProcess[i] == 'a')
                {
                    strToProcess[i] += 25;
                }

                else strToProcess[i]--;
            }
        }
    }
}

// BruteForce()
// Parameters:
//      string strToProcess - the string the user wants to manipulate
// Return Value:
//      none
// Description:
//      Takes in a string, and uses the decrypt function to run the string
//      through all 26 possible variations of that string
void BruteForce(string& strToProcess)
{
    cout << "Decrypted as :" << endl;
    for (int i = 1; i < 26; i++)
    {
        Decrypt(strToProcess, 1);
        cout << strToProcess << endl;
    }
}