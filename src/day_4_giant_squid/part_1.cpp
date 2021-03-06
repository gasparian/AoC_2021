#include <bits/stdc++.h>

using namespace std;

struct BoardLine {
    uint32_t matches;
    unordered_map<int32_t, bool> items;
};

typedef vector<BoardLine> Board;

vector<uint32_t> parse_numbers(ifstream& input) {
    string line, val_buff;
    vector<uint32_t> numbers;
    stringstream ss;
    getline(input, line);
    ss << line; 
    while (getline(ss, val_buff, ',')) {
        numbers.push_back(stoi(val_buff));
    }
    return numbers;
}

vector<Board> parse_boards(ifstream& input, uint32_t grid_size) {
    string line, val_buff;
    uint32_t val;
    stringstream ss;
    vector<Board> boards;
    uint32_t lines_counter = 1, vals_counter;
    Board board;
    BoardLine vert_board_lines[grid_size], board_line;
    for (auto& vert_board_line : vert_board_lines) {
        vert_board_line.matches = 0;
    }

    while (getline(input, line)) {
        if (line.size() == 0) {
            continue;
        }
        ss << line; 
        board_line = {0}; 
        vals_counter = 0;
        while (ss >> val_buff) {
            val = stoi(val_buff);
            vert_board_lines[vals_counter].items[val] = false;
            board_line.items[val] = false;
            vals_counter++;
        }
        ss.clear();
        board.push_back(board_line);
        if (lines_counter % grid_size == 0) {
            for (size_t i=0; i < grid_size; i++) {
                board.push_back(vert_board_lines[i]);
                vert_board_lines[i] = {};
            }
            boards.push_back(board);
            board = {};
        }
        lines_counter++;
	}
    input.close();
    return boards;
}

pair<Board, uint32_t> get_winner(vector<uint32_t>& numbers, vector<Board> boards, uint32_t grid_size) {
    for (uint32_t number : numbers) {
        for (auto& board : boards) {
            for (auto& board_line : board) {
                if (board_line.items.count(number) > 0) {
                    board_line.matches++;
                    board_line.items[number] = true;
                    if (board_line.matches == grid_size) {
                        return make_pair(board, number);
                    }
                }
            }
        }
    }
    return {};
}

uint32_t get_winner_result(Board& board, uint32_t number, uint32_t grid_size) {
    uint32_t a = 0;
    for (size_t i=0; i < grid_size; i++) {
        for (auto item : board[i].items) {
            if (!item.second) {
                a += item.first;
            }
        }
    }
    return a * number;
}

int main(int argc, char** argv) {
    ifstream input;
    input.open("./input.txt"); // 188 * 24 = 4512; 28082;

    if (!input.is_open()) {
        exit(EXIT_FAILURE);
    }

    const uint32_t grid_size = 5;
    vector<uint32_t> numbers = parse_numbers(input);
    vector<Board> boards = parse_boards(input, grid_size);
    auto winner = get_winner(numbers, boards, grid_size);
    cout << get_winner_result(winner.first, winner.second, grid_size) << endl;
}
