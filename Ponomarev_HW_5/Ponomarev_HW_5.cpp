// Ponomarev_HW_5.cpp

#include <iostream>
#include <iterator>
#include <string>
#include <unordered_set>
#include <vector>
#include <list>
#include <deque>
#include <queue>

using namespace std;

template<typename T>
void print(T it, T end)
{
    unordered_set<string> count(it, end);
    copy(count.begin(), count.end(), ostream_iterator<string>(cout, ", "));
}

void task_1()
{
    vector<string> v{ "dog", "cat", "parrot", "dog", "mouse", "cat", "hamster" };
    cout << "vector: ";
    print(v.begin(), v.end());
    cout << endl;

    list<string> l(v.begin(), v.end());
    cout << "list: ";
    print(l.begin(), l.end());
    cout << endl;

    deque<string> d(v.begin(), v.end());
    cout << "deque: ";
    print(d.begin(), d.end());
    cout << endl;
}

//=================================================================================================

string getWords(string& s)
{
    string punctuationMarks{ ".!?" };
    string temp;

    for (const char &c : s)
    {
        temp.push_back(c);

        if (punctuationMarks.find(c) != string::npos)
        {
            s.erase(0, temp.size());
            if (temp[0] == ' ')
            {
                temp.erase(0, 1);
            }

            return temp;
        }
    }

    return {};
}

void task_2()
{
    unordered_set<string, hash<string>> words;
    string current;
    string newString;

    while (getline(cin, current))
    {
        if (!current.empty())
        {
            newString += current + ' ';

            while (true)
            {
                string word(move(getWords(newString)));

                if (word.empty())
                {
                    break;
                }
                words.insert(move(word));
            }
        }
    }

    priority_queue<pair<size_t, string>> q;

    for (const auto &word : words)
    {
        q.push({ word.size(), word });
    }

    while (!q.empty())
    {
        cout << q.top().first << ": " << q.top().second << endl;
        q.pop();
    }
}



int main()
{
    task_1();
    task_2();

    return 0;
}

