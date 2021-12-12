#include <bits/stdc++.h>

using namespace std;

uint64_t get_power_consumption(ifstream* input, uint32_t bit_len) {
	uint32_t counter[bit_len] = {0};
    string line;
    uint32_t inp_size = 0, val, is_non_zero;
	uint32_t gamma = 0, epsilon = 0;
    while (getline(*input, line)) {
		val = stoi(line, 0, 2);
        for (uint32_t i=0; i < bit_len; i++) {
            is_non_zero = val & (1 << i);
            if (is_non_zero) counter[i]++;
        }
        inp_size++;
    }
    uint32_t half_size = inp_size / 2;
    for (uint32_t i=0; i < bit_len; i++) {
        if (counter[i] > half_size) {
            gamma |= 1 << i;
        } else {
            epsilon |= 1 << i;
        }
    }
    uint64_t power_consumption = epsilon * gamma;
    return power_consumption;
}

int main(int argc, char** argv) {
    ifstream input;
    input.open("./input.txt");

    if (!input.is_open()) {
        exit(EXIT_FAILURE);
    }

    uint32_t bit_len = 12;
    uint64_t power_consumption = get_power_consumption(&input, bit_len);
    cout << power_consumption << endl;
    input.close();
}