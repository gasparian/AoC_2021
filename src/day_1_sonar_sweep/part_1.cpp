#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

int main(int argc, char** argv) {
    ifstream input;
    string fpath = get_current_dir_name();
    fpath.append("/input.txt");
    cout << fpath << endl;
    input.open(fpath);

    if (!input.is_open()) {
        exit(EXIT_FAILURE);
    }

    string str;
	int32_t prev = -1, counter = 0, curr; 
    while (getline(input, str)) {
        curr = atoi(str.c_str());
		if (prev < 0) {
			prev = curr;
			continue;
		}
		if (prev < curr) {
			counter++;
		}
		prev = curr;
    }
    input.close();
    cout << counter << endl;
}