#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

std::string generate_random_separator(int min_size = 141, int max_size = 141) {
    std::string separator;
    int size = rand() % (max_size - min_size + 1) + min_size;
    for (int i = 0; i < size; ++i) {
        separator += static_cast<char>('-'); // generating random lowercase letters
    }
    return separator;
}

std::string generate_big_text(const std::vector<std::string>& words) {
    if (words.empty()) {
        return "";
    }

    std::string separator = generate_random_separator();
    std::string big_text = separator;
    for (const auto& word : words) {
        big_text += word + separator;
    }
    return big_text;
}

int main() {
    std::vector<std::string> input_words = {"I", "G", "V", "A", "P", "S", "W", "C", "E"};

    std::vector<std::string> modified_input_words;
    srand(time(0)); // seeding random number generator
    for (const auto& word : input_words) {
        int copies = rand() % 20 + 1; // Generate 1 to 5 copies of each word
        for (int i = 0; i < copies; ++i) {
            modified_input_words.push_back(word);
        }
    }
    std::random_shuffle(modified_input_words.begin(), modified_input_words.end()); // Shuffle the modified input words

    std::string result = generate_big_text(modified_input_words);
    std::cout << result << std::endl;

    return 0;
}
