#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // For the reverse function

using namespace std;

// Function to reverse the contents of a file and save it to another file
void reverseFileContent(const string& inputFile, const string& outputFile) {
    // Open the input file for reading
    ifstream input(inputFile);
    if (!input) {
        cerr << "Error: Could not open the input file." << endl;
        return;
    }

    // Open the output file for writing
    ofstream output(outputFile);
    if (!output) {
        cerr << "Error: Could not open the output file." << endl;
        input.close();
        return;
    }

    // Read the entire content of the input file into a string
    string content((istreambuf_iterator<char>(input)), istreambuf_iterator<char>());
    
    // Reverse the string content
    reverse(content.begin(), content.end());

    // Write the reversed content to the output file
    output << content;

    // Close the files
    input.close();
    output.close();
}

int main() {
    string userInput;
    string inputFileName = "CSC450_CT5_mod5.txt"; // The file we append to
    string outputFileName = "CSC450-mod5-reverse.txt"; // The file where reversed content goes

    // Open the file in append mode to add new data
    ofstream file(inputFileName, ios::app);
    if (!file) {
        cerr << "Error: Could not open the file to append data." << endl;
        return 1; // Exit if the file can't be opened
    }

    // Ask the user for input to append to the file
    cout << "Enter some text to add to the file: ";
    getline(cin, userInput);

    // Append the user's input to the file
    file << userInput << endl;

    // Close the file after appending
    file.close();

    // Call the function to reverse the file content and save to another file
    reverseFileContent(inputFileName, outputFileName);

    cout << "Your text has been added, and the file contents have been reversed into another file." << endl;
    return 0;
}
