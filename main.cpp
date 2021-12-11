#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
int main()
{

    fstream appFile("appFile.txt",ios::out);
    fstream tempFile("tempFile.txt",ios::out);
    appFile.close();
    tempFile.close();
    char c,t,t2;
    FILE *thisFile = fopen(__FILE__, "r");
    do
    {

        c= fgetc(thisFile);
        appFile.open("appFile.txt",ios::out);
        tempFile.open("tempFile.txt",ios::in);
        appFile.put(c);
        // from temp to appFile
        do
        {
            tempFile.get(t);
            if(tempFile.eof())
                break;
            appFile.put(t);
        }
        while(!tempFile.eof());
        appFile.close();
        tempFile.close();
        //form appFIle to temp
        appFile.open("appFile.txt",ios::in);
        tempFile.open("tempFile.txt",ios::out);
        do
        {
            appFile.get(t2);
            if(appFile.eof())
                break;
            tempFile.put(t2);
        }
        while(!appFile.eof());
        appFile.close();
        tempFile.close();
    }
    while (c != EOF);

    appFile.open("appFile.txt",ios::in);
    do
    {
        appFile.get(c);
        cout<<c;
    }
    while(!appFile.eof());
    appFile.close();
    cout <<endl<<endl;
    return 0;
}
