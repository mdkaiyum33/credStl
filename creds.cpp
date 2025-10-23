#include <iostream>
#include <fstream> 

using namespace std;

int main(){
    ofstream outfile("creds.txt");
    if(!outfile.is_open()){
        cerr << "[-] Error Opening File.";
        return 1;
    }
    outfile << "[+] Starting Program..\n";
    outfile.close();

    cout << "[+] Written in file successfully :)";
    return 0;
}