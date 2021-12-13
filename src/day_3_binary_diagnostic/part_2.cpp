#include <bits/stdc++.h>

using namespace std;

struct stats {
    uint32_t counter;
    vector<uint32_t> starts_one_ids;
    vector<uint32_t> starts_zero_ids;
};

stats get_data_stats(vector<int>& data, uint32_t bit_id) {
	uint32_t counter = 0;
    uint32_t is_non_zero;
    vector<uint32_t> starts_one_ids, starts_zero_ids;
    for (uint32_t i=0; i < data.size(); i++) {
        is_non_zero = data[i] & (1 << bit_id);
        if (is_non_zero) {
            starts_one_ids.push_back(i);
            counter++;
        } else {
            starts_zero_ids.push_back(i);
        }
    }
    return {
        counter,
        starts_one_ids,
        starts_zero_ids,
    };
}

uint32_t get_ox(vector<int>& data, uint32_t bit_id) {
    if (data.size() == 1) {
        return data[0];
    }
    stats data_stats = get_data_stats(data, bit_id);
    vector<int> sub_set;
    if (data_stats.counter >= (data.size() - data_stats.counter)) {
        for (auto i : data_stats.starts_one_ids) {
            sub_set.push_back(data[i]);
        }
    } else {
        for (auto i : data_stats.starts_zero_ids) {
            sub_set.push_back(data[i]);
        }
    }
    return get_ox(sub_set, --bit_id);
}

uint32_t get_co2(vector<int>& data, uint32_t bit_id) {
    if (data.size() == 1) {
        return data[0];
    }
    stats data_stats = get_data_stats(data, bit_id);
    vector<int> sub_set;
    if (data_stats.counter >= (data.size() - data_stats.counter)) {
        for (auto i : data_stats.starts_zero_ids) {
            sub_set.push_back(data[i]);
        }
    } else {
        for (auto i : data_stats.starts_one_ids) {
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
    const uint32_t ox = get_ox(data, bit_len - 1);
    const uint32_t co2 = get_co2(data, bit_len - 1);
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