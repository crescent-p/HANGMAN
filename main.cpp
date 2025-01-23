#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using ll = long long;

void precomp()
{
    
}

void solve()
{
    std::ifstream inputFile("words.txt"); 
    if (!inputFile.is_open())
    { 
        std::cerr << "Failed to open the file." << std::endl;
        return;
    }

    std::string line;
    std::map<int, std::set<std::string>> words;

    while (std::getline(inputFile, line))
    {
        while (std::getline(inputFile, line)) {
            for(auto&k: line) {
                if(k >= 'A' && k <= 'Z')
                    k -= ('A' - 'a');
            }
            words[line.length()].insert(line);
        }
        words[line.length()].insert(line);
    }
    reset:;
    std::cout << "How many letters in your word?" << std::endl;
    ll n;
    std::cin >> n;
    ll len = n;
    std::vector<char> ans(len, '?');
    std::set<char> banned;
    std::set<char> found;
    while (1)
    {
        std::cout << "Type an accepted letter followed by its position or . for entering banned letters or 0 to reset" << std::endl;
        char c;
        std::cin >> c;
        if(c == '0') {
            goto reset;
        }
        if(c <= '9' && c >= '1') {
            n++;
            continue;
        }
        int pos;
        if(c == '.') {
            char m;std::cin>>m;
            banned.insert(m);
            n++;
            std::vector<int> freq(26, 0);

            for (const auto &word : words[len])
            {
                bool correct = true;

                for (int i = 0; i < len; ++i)
                {
                    if ((word[i] != ans[i] && ans[i] != '?' )|| (ans[i] == '?' && found.find(word[i]) != found.end()))
                    {
                        correct = false;
                        break;
                    }
                    if(banned.find(word[i]) != banned.end()) {
                        correct =false;
                        break;
                    }
                }

                if (correct)
                {
                    std::cout << word << std::endl;
                    for (char ch : word)
                    {
                        if (ch >= 'a' && ch <= 'z')
                        {
                            freq[ch - 'a']++;
                        }
                        else if (ch >= 'A' && ch <= 'Z')
                        {
                            freq[ch - 'A']++;
                        }
                    }
                }
            }

            std::cout << "Next most frequent elements:" << std::endl;
            std::map<int, std::vector<char>> frequency;

            for (int i = 0; i < 26; ++i)
            {
                if (freq[i] > 0)
                {
                    frequency[freq[i]].push_back(i + 'a');
                }
            }
            int count = 0;
            for (auto it = frequency.rbegin(); it != frequency.rend() && count < 10; ++it, ++count)
            {
                for (char ch : it->second)
                {
                    std::cout << ch << " ";
                }
            }
            std::cout << std::endl;
            std::cout << "Your word is: " << std::endl;
            for (char ch : ans)
            {
                std::cout << ch;
            }
            std::cout << std::endl;
            continue;
        }
        std::cin >> pos;
        if(pos > len) {
            n++;
            continue;
        }
        ans[pos - 1] = c; 
        found.insert(c);
        std::vector<int> freq(26, 0);

        for (const auto &word : words[len])
        {
            bool correct = true;

            for (int i = 0; i < len; ++i)
            {
                if ((word[i] != ans[i] && ans[i] != '?' )|| (ans[i] == '?' && found.find(word[i]) != found.end()))
                {
                    correct = false;
                    break;
                }
                if(banned.find(word[i]) != banned.end()) {
                    correct =false;
                    break;
                }
            }

            if (correct)
            {
                std::cout << word << std::endl;
                for (char ch : word)
                {
                    if (ch >= 'a' && ch <= 'z')
                    {
                        freq[ch - 'a']++;
                    }
                    else if (ch >= 'A' && ch <= 'Z')
                    {
                        freq[ch - 'A']++;
                    }
                }
            }
        }

        std::cout << "Next most frequent elements:" << std::endl;
        std::map<int, std::vector<char>> frequency;

        for (int i = 0; i < 26; ++i)
        {
            if (freq[i] > 0)
            {
                frequency[freq[i]].push_back(i + 'a');
            }
        }

        int count = 0;
        for (auto it = frequency.rbegin(); it != frequency.rend() && count < 10; ++it, ++count)
        {
            for (char ch : it->second)
            {
                std::cout << ch << " ";
            }
        }
        std::cout << std::endl;
        std::cout << "Your word is: " << std::endl;
        for (char ch : ans)
        {
            std::cout << ch;
        }
        std::cout << std::endl;
    }

    std::cout << "Your word is: " << std::endl;
    for (char ch : ans)
    {
        std::cout << ch;
    }
    std::cout << std::endl;

    inputFile.close(); 
}

int main()
{
    precomp();
    ll t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}
