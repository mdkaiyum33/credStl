#include <iostream>
#include <fstream> 
#include <windows.h>
#include <wincred.h>

#pragma comment(lib, "advapi32.lib")

using namespace std;


// void writeToFile(const string &filename, const string &content ){
//     ofstream outfile(filename);
//     if(!outfile.is_open()){
//         cerr << "[-] Error opening file..";
//     }
//     outfile << content;
//     outfile.close();
//     cout << "[+] Written to file successfully.";
// }

void listCredentials(){
    DWORD count;
    PCREDENTIAL* credentials;
    if(CredEnumerate(NULL,0, &count, &credentials)){
        cout << "[+] Found " << count << " stored credentials \n";
        for(DWORD i = 0; i <= count; i++){
            cout << credentials[i]->TargetName << "\n";
        }
        CredFree(credentials);
    } else {
        cerr << "[-] Failed to enumerate credentials" << GetLastError() << "\n";
    }

}

int main(){
    listCredentials();
    return 0;
}