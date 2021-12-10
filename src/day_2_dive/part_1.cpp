#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
    ifstream input;
    input.open("./input.txt");

    if (!input.is_open()) {
        exit(EXIT_FAILURE);
    }

    string line, item, key;
    int32_t val, depth = 0, horiz = 0;
    stringstream ss;
    while (getline(input, line)) {
        ss << line;
        getline(ss, key, ' ');
        getline(ss, item);
        val = atoi(item.c_str());
        if (key == "forward") {
            horiz += val;
        } else if (key == "up") {
            depth -= val;
        } else if (key == "down") {
            depth += val;
        }
        ss.clear();
    }
    cout << "depth: " << depth << "; horizontal pos.: " << horiz << "; mult.: " << depth * horiz << endl;
    input.close();
}