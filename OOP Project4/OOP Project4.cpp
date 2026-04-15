
#include <iostream>
#include "clsUtil.h"
#include "clsDate.h"
    using namespace std;


    int main()
    {
     
      
        cout << "\n1. Random Key: " << clsUtil::GenerateKey() << endl;

        
        cout << "\n2. Generating 3 Keys:" << endl;
        clsUtil::GenerateKeys(3);

        
        string Text = "Hello";
        short EncryptionKey = 5;
        string Encrypted = clsUtil::EncryptText(Text, EncryptionKey);
        cout << "\n3. Encryption: " << Text << " -> " << Encrypted << endl;

        
        string Decrypted = clsUtil::DecryptionText(Encrypted, EncryptionKey);
        cout << "4. Decryption: " << Encrypted << " -> " << Decrypted << endl;

      
        int a = 10, b = 20;
        cout << "\n5. Before Swap: a=" << a << ", b=" << b << endl;
        clsUtil::Swap(a, b);
        cout << "   After Swap:  a=" << a << ", b=" << b << endl;

       
        clsDate Date1(15, 8, 2024);
        clsDate Date2(1, 1, 2025);
        cout << "\n6. Before Swap: Date1=" << clsDate::DateToString(Date1)
            << ", Date2=" << clsDate::DateToString(Date2) << endl;
        clsUtil::Swap(Date1, Date2);
        cout << "   After Swap:  Date1=" << clsDate::DateToString(Date1)
            << ", Date2=" << clsDate::DateToString(Date2) << endl;
}

