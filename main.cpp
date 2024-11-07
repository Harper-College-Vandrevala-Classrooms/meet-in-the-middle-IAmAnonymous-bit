using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    ifstream read;
    string name;
    vector<int> integers;

    cout << "Enter Filename: ";
    getline(cin, name);
    read.open(name);

    if(read.is_open())
    {
        string line;
        while(getline(read, line, ','))
        {
            int val;
            try
            {
                val = stoi(line);
                integers.push_back(val);
            }
            catch(const invalid_argument &e)
            {
                continue;
            }
        }
    } else {
        cout << "File named \"" << name << "\" does not exist" << endl;
    }
    read.close();

    sort(integers.begin(), integers.end());

    cout << "The median of \"" << name << "\" is: " << integers[integers.size()/2] << endl;

    return 0;
}