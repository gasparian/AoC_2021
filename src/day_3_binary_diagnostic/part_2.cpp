#include <bits/stdc++.h>

using namespace std;

enum rating {
    OX,
    CO2,
};

uint32_t get_rating(vector<int>& data, uint32_t bit_id, rating r) {
    if (data.size() == 1) {
        return data[0];
    }
	uint32_t counter = 0;
    uint32_t is_non_zero;
    vector<int> starts_one, starts_zero;
    for (uint32_t i=0; i < data.size(); i++) {
        is_non_zero = data[i] & (1 << bit_id);
        if (is_non_zero) {
            starts_one.push_back(data[i]);
            counter++;
        } else {
            starts_zero.push_back(data[i]);
        }
    }
    bool most_common_is_one = counter >= (data.size() - counter);
    switch (r) {
    case OX:
        if (most_common_is_one) {
            return get_rating(starts_one, --bit_id, r);
        }
        return get_rating(starts_zero, --bit_id, r);
    case CO2:
        if (most_common_is_one) {
            return get_rating(starts_zero, --bit_id, r);
        }
        return get_rating(starts_one, --bit_id, r);
    }
    return 0;
}

uint64_t get_life_support_rating(ifstream* input, uint32_t bit_len) {
    string line;
    vector<int32_t> data;
    while (getline(*input, line)) {
		data.push_back(stoi(line, 0, 2));
    }
    const uint32_t ox = get_rating(data, bit_len - 1, OX);
    const uint32_t co2 = get_rating(data, bit_len - 1, CO2);
    return ox * co2;
}

int main(int argc, char** argv) {
    ifstream input;
    input.open("./input.txt");

    if (!input.is_open()) {
        exit(EXIT_FAILURE);
    }

    const uint32_t bit_len = 12;
    const uint64_t life_support_rating = get_life_support_rating(&input, bit_len);
    cout << life_support_rating << endl; // 5941884
    input.close();
}