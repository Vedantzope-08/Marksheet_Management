#include <iostream>
#include <fstream>
#include <cstring> 
#include <cstdio> 
#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

int add() {
    return 5 + 4;
}

void bubblesort(vector<int> &arr, int n) {
    for (int i = n - 1; i >= 0; i--) {
        int didswap = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                didswap = 1;
            }
        }
        if (didswap == 0) {
            break;
        }
    }
}

float marks() {
    int n = 3, m = 4;
    vector<int> cae;
    vector<int> tae;
    cout << "Enter the marks of CAE" << endl;
    for (int i = 0; i < n; i++) {
        int a;
        cout << i + 1 << ":- ";
        cin >> a;
        cae.push_back(a);
    }
    bubblesort(cae, n);
    cout << "Enter the marks of TAE" << endl;
    for (int i = 0; i < m; i++) {
        int a;
        cout << i + 1 << ":- ";
        cin >> a;
        tae.push_back(a);
    }
    bubblesort(tae, m);

    int ese;
    cout << "Enter marks obtained in ESE:- ";
    cin >> ese;

    float avg;

    avg = (cae[n - 1] + cae[n - 2]) / 2.0 + tae[m - 1] + tae[m - 2] + ese;

    return avg;
}

int main() {
    int s;
    vector<string> sub;
    vector<float> totalmarks;
    string n;
    cout << "Enter the name of Student: ";
    cin >> n;
    int rn;
    cout << "Enter the Roll No: ";
    cin >> rn;
    cout << "Enter the number of subjects: ";
    cin >> s;
    for (int i = 0; i < s; i++) {
        string a;
        cout << "Enter the name of subject: ";
        cin >> a;
        sub.push_back(a);

        float b = marks();
        totalmarks.push_back(b);
    }

    ofstream my_file("test.txt");

    if (!my_file) {
        cout << "Error: Unable to open the file." << endl;
        return 1; 
    }

  
    my_file<<"\t \tG H Raisoni College of Engineering and Management"<<endl;
    my_file<<"\t \t \t Autonomus Institute Affilated To"<<endl;
    my_file<<"\t \t \t Savitriai Phule Pune University"<<endl;
    my_file<<"\t \tName:- "<<n<<"\t \tRoll No:- "<<rn<<endl;
 

    for (int j = 0; j < s; j++) {
        my_file <<"\t \t"<< sub[j] <<"\t \t"<<totalmarks[j]<< endl;
    }

    my_file.close();

    const char* name = n.c_str(); 
    char oldname[] = "test.txt";
    char newname[10]; 
    strcpy(newname, name);

    if (rename(oldname, newname) != 0) {
        perror("Error renaming file");
        return 1;
    }

    cout << "File renamed successfully." << endl;

    return 0;
}

