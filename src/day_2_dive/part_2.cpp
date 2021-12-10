#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
    ifstream input;
    input.open("./input.txt");

    if (!input.is_open()) {
        exit(EXIT_FAILURE);
    }

    string line, item, key;
    int64_t val, depth = 0, horiz = 0, depth_aim = 0;
    stringstream ss;
    while (getline(input, line)) {
        ss << line;
        getline(ss, key, ' ');
        getline(ss, item);
        val = atol(item.c_str());
        if (key == "forward") {
            horiz += val;
            depth += val * depth_aim;
        } else if (key == "up") {
            depth_aim -= val;
        } else if (key == "down") {
            depth_aim += val;
        }
        ss.clear();
    }
    cout << "depth: " << depth << "; horizontal pos.: " << horiz << "; mult.: " << depth * horiz << endl;
    input.close();
}