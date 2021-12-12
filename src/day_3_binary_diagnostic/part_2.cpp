#include <bits/stdc++.h>

using namespace std;

uint32_t get_ox(vector<int>& data, uint32_t bit_id) {
    if (data.size() == 1) {
        return data[0];
    }
	uint32_t counter = 0;
    uint32_t is_non_zero;
    vector<uint32_t> start_one_ids, start_zero_ids;
    for (uint32_t i=0; i < data.size(); i++) {
        is_non_zero = data[i] & (1 << bit_id);
        if (is_non_zero) {
            start_one_ids.push_back(i);
            counter++;
        } else {
            start_zero_ids.push_back(i);
        }
    }
    const uint32_t half_size = data.size() / 2;
    vector<int> sub_set;
    if (counter >= (data.size() - counter)) {
        for (auto i : start_one_ids) {
            sub_set.push_back(data[i]);
        }
    } else {
        for (auto i : start_zero_ids) {
            sub_set.push_back(data[i]);
        }
    }
    return get_ox(sub_set, --bit_id);
}

uint32_t get_co2(vector<int>& data, uint32_t bit_id) {
    if (data.size() == 1) {
        return data[0];
    }
	uint32_t counter = 0;
    uint32_t is_non_zero;
    vector<uint32_t> start_one_ids, start_zero_ids;
    for (uint32_t i=0; i < data.size(); i++) {
        is_non_zero = data[i] & (1 << bit_id);
        if (is_non_zero) {
            start_one_ids.push_back(i);
            counter++;
        } else {
            start_zero_ids.push_back(i);
        }
    }
    const uint32_t half_size = data.size() / 2;
    vector<int> sub_set;
    if (counter >= (data.size() - counter)) {
        for (auto i : start_zero_ids) {
            sub_set.push_back(data[i]);
        }
    } else {
        for (auto i : start_one_ids) {
            sub_set.push_back(data[i]);
        }
    }
    return get_co2(sub_set, --bit_id);
}

uint64_t get_life_support_rating(ifstream* input, uint32_t bit_len) {
    string line;
    vector<int32_t> data;
    while (getline(*input, line)) {
		data.push_back(stoi(line, 0, 2));
    }
    uint32_t ox = get_ox(data, bit_len - 1);
    uint32_t co2 = get_co2(data, bit_len - 1);
    uint64_t life_support_rating = ox * co2;
    return life_support_rating;
}

int main(int argc, char** argv) {
    ifstream input;
    input.open("./input.txt");

    if (!input.is_open()) {
        exit(EXIT_FAILURE);
    }

    uint32_t bit_len = 12;
    uint64_t life_support_rating = get_life_support_rating(&input, bit_len);
    cout << life_support_rating << endl; // 5941884
    input.close();
}