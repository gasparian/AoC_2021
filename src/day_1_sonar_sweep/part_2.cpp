#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
    ifstream input;
    input.open("./input.txt");

    if (!input.is_open()) {
        exit(EXIT_FAILURE);
    }

    size_t w_size = 3;
    string str;
	int32_t prev = 0, counter = 0, curr, val, front;
	deque<int32_t> w;
    while (getline(input, str)) {
        val = atoi(str.c_str());
		w.push_back(val);
		if (w.size() <= w_size) {
			prev += val;
			continue;
		}
		front = w.front();
		w.pop_front();
		curr = prev - front + val;
		if (prev < curr) {
			counter++;
		}
		prev = curr;
    }
    input.close();
    cout << counter << endl;
}