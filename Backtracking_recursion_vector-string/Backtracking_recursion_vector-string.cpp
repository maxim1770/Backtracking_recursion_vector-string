#include <iostream>
#include <string>
#include <vector>

using namespace std;

int func_1(vector<string>& words, vector<string>& dist, int dl) {
    if (words.size() == 0) {
        if (dist.size() >= 2) {
            string temp_11 = dist[dist.size() - 2];
            string temp_22 = dist[dist.size() - 1];
            if (temp_11.substr(temp_11.length() - 1, 1) != temp_22.substr(0, 1)) {
                return dl;
            }
            else {
                return dist.size();
            }
        }
    }
    if (dist.size() >= 2) {
        string temp_1 = dist[dist.size() - 2];
        string temp_2 = dist[dist.size() - 1];
        if (temp_1.substr(temp_1.length() - 1, 1) != temp_2.substr(0, 1)) {
            return dl;
        }
    }
    for (int i = 0; i < words.size(); i++) {
        string temp_3 = words[i];
        vector<string> dist_copy(dist.size());
        copy(dist.begin(), dist.end(), dist_copy.begin());
        words.erase(words.begin() + i);
        dist_copy.push_back(temp_3);
        if (dist.size() > func_1(words, dist_copy, dl)) {
            dl = dist.size();
        }
        else {
            dl = func_1(words, dist_copy, dl);
        }
        words.insert(words.begin() + i, temp_3);
    }
    return dl;
}

int func_2(vector<string>& words, vector<string>& dist, int dl) {
    if (words.size() == 0) {
        if (dist.size() >= 2) {
            string temp_1 = dist[dist.size() - 2];
            string temp_2 = dist[dist.size() - 1];
            if (temp_1.substr(temp_1.length() - 1, 1) != temp_2.substr(0, 1)) {
                return dl;
            }
            else {
                int temp_cnt = 0;
                for (int i = 0; i < dist.size(); i++) {
                    temp_cnt += dist[i].length();
                }
                return temp_cnt;
            }
        }
    }
    if (dist.size() >= 2) {
        string temp_1 = dist[dist.size() - 2];
        string temp_2 = dist[dist.size() - 1];
        if (temp_1.substr(temp_1.length() - 1, 1) != temp_2.substr(0, 1)) {
            return dl;
        }
    }
    for (int i = 0; i < words.size(); i++) {
        string temp_3 = words[i];
        vector<string> dist_copy(dist.size());
        copy(dist.begin(), dist.end(), dist_copy.begin());
        words.erase(words.begin() + i);
        dist_copy.push_back(temp_3);
        int temp_str = 0;
        for (int i = 0; i < dist.size(); i++) {
            temp_str += dist[i].length();
        }
        if (temp_str > func_2(words, dist_copy, dl)) {
            dl = temp_str;
        }
        else {
            dl = func_2(words, dist_copy, dl);
        }
        words.insert(words.begin() + i, temp_3);
    }
    return dl;
}

int func_3(vector<string>& words, vector<string>& dist, int dl) {
    if (words.size() == 0) {
        if (dist.size() >= 2) {
            string temp_11 = dist[dist.size() - 2];
            string temp_22 = dist[dist.size() - 1];
            if (temp_11.substr(temp_11.length() - 1, 1) != temp_22.substr(0, 1)) {
                return dl;
            }
            else if (dist.size() >= 1) {
                string temp_33 = dist[dist.size() - 1];
                string temp_44 = dist[0];
                if (temp_33.substr(temp_33.length() - 1, 1) == temp_44.substr(0, 1)) {
                    return dist.size();
                }
            }
            else {
                return dl;
            }
        }
    }
    int temp_dl = 0;
    if (dist.size() >= 2) {
        string temp_11 = dist[dist.size() - 2];
        string temp_22 = dist[dist.size() - 1];
        if (temp_11.substr(temp_11.length() - 1, 1) != temp_22.substr(0, 1)) {
            return dl;
        }
        string temp_33 = dist[dist.size() - 1];
        string temp_44 = dist[0];
        if (temp_33.substr(temp_33.length() - 1, 1) == temp_44.substr(0, 1)) {
            temp_dl = dist.size();
        }
    }
    for (int i = 0; i < words.size(); i++) {
        string temp_3 = words[i];
        vector<string> dist_copy(dist.size());
        copy(dist.begin(), dist.end(), dist_copy.begin());
        words.erase(words.begin() + i);
        dist_copy.push_back(temp_3);
        if (temp_dl > func_3(words, dist_copy, dl)) {
            dl = temp_dl;
        }
        else {
            dl = func_3(words, dist_copy, dl);
        }
        words.insert(words.begin() + i, temp_3);
    }
    return dl;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    vector<string> words;
    vector<string> dist;
    int num_word, dl_1, dl_2, dl_3;
    int dl = 0;
    string temp_string;
    while (true) {
        cout << "Введите количество слов: ";
        cin >> num_word;
        if (num_word < 2) {
            cout << "Ошибка! Слов должно быть больше 1\n";
        }
        else {
            break;
        }
    }
    words.reserve(num_word);
    dist.reserve(0);
    cout << "Введите слова в строку: ";
    for (int i = 0; i < num_word; i++) {
        cin >> temp_string;
        words.push_back(temp_string);
    }
    dl_1 = func_1(words, dist, dl);
    dl_2 = func_2(words, dist, dl);
    dl_3 = func_3(words, dist, dl);
    cout << "Ответ по первой задаче: " << dl_1 << endl;
    cout << "Ответ по второй задаче: " << dl_2 << endl;
    cout << "Ответ по третьей задаче: " << dl_3 << endl;
}

