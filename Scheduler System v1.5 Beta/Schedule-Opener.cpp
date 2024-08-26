#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Specify the file name
    const char* filename = "schedule.txt";
    
    // Create an input file stream object
    ifstream file(filename);
    
    // Check if the file was opened successfully
    if (!file) {
        cerr << "Error: Could not open the file " << filename << endl;
        return 1; // Return a non-zero value to indicate an error
    }
    
    // Variable to hold each line of the file
    char line[256]; // Buffer to store each line of the file
    
    // Read the file content line by line
    while (file.getline(line, sizeof(line))) {
    	system("Color A");
        cout << line << endl; // Output each line to the console
    }
    
    // Close the file
    file.close();
    
    return 0; // Return 0 to indicate success
}

