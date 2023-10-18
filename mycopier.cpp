#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define FILE_PATH "/home/debian"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage is source-file followed by destination-file" << endl;
        return 1;
    }

    // define source and destination file paths
    string sourceFilePath = string(FILE_PATH) + "/" + argv[1];
    string destinationFilePath = string(FILE_PATH) + "/" + argv[2];
    string line;

    // open ifstream (reading) and ofstream (writing)
    ifstream sourceFile(sourceFilePath.c_str());
    ofstream destinationFile(destinationFilePath.c_str());

    // if unable to open files print "Unable to open files"
    if (!sourceFile.is_open() || !destinationFile.is_open()) {
        cerr << "Unable to open files" << endl;
        return 1;
    }


    // copy contents of source file to destination file line by line
    while (getline(sourceFile, line)) {
        destinationFile << line << endl;
    }

    // close both files
    sourceFile.close();
    destinationFile.close();

    // in console, print success message 
    cout << "File contents copied from " << sourceFilePath << " to " << destinationFilePath << endl;

    return 0;
}