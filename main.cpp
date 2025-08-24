#include <iostream>
#include <string>
#include <vector>
#include <random>

std::string getrandomword() {
    std::vector<std::string> words{"apple", "milk", "cheese", "bober"};
    std::random_device dev;
    std::mt19937 ran(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(words.size() - 1);
    auto max{dist(ran)};
    return words[max];
};
void mygame() {
    const std::string myword{getrandomword()};
    std::string word (myword.length(), '_');

    int x{0};
    bool win{false};

    while (word != myword && x < 5) {
        std::cout << " next letter "<< " wrong  " << x <<  '\n';
        char guess{};
        std::cin >> guess;

        bool printed{false};

        for (size_t i{0}; i < myword.length(); ++i) {
            if (myword[i] == guess ) {
                word[i] = guess;
                std::cout << word << '\n';
                printed = true;
            }
        }

        if (printed) {
            std::cout << "is good answer +1" << std::endl;
        } else {
            ++x;
            std::cout << "is wrong answer try again" << std::endl;
        }

        if (word == myword) {
            std::cout << "you won" << '\n';
            win = true;
            break;
        }
        if (x == 5) {
            std::cout << "you lose" << '\n';
        };

    };
}
int main() {
    while (true) {
        std::cout << "you want play?" << " y/n " << std::endl;
        char nr{};
        std::cin >> nr;
        switch (nr) {
            case('y') : mygame();
            case('n') : break;
            default:
                std::cout << " non letter " << '\n';
        }
    }
}
