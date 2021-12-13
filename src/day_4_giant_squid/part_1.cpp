#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
    ifstream input;
    input.open("./test.txt"); // 188 * 24 = 4512

    if (!input.is_open()) {
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(input, line)) {
		cout << line << '\n';
	}
    input.close();
}
