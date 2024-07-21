#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>

class TitanicEntry {
public:
    int passengerId;
    bool survived;
    int pclass;
    std::string name;
    std::string sex;
    float age;
    int sibSp;
    int parch;
    float ticketFare;
    std::string cabin;
    std::string embarked;

    TitanicEntry(int passengerId, bool survived, int pclass, std::string name, std::string sex, float age,
                 int sibSp, int parch, float ticketFare, std::string cabin, std::string embarked)
        : passengerId(passengerId), survived(survived), pclass(pclass), name(name), sex(sex), age(age),
          sibSp(sibSp), parch(parch), ticketFare(ticketFare), cabin(cabin), embarked(embarked) {}
};

std::vector<TitanicEntry> readCSV(const std::string &filename) {
    std::vector<TitanicEntry> entries;
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    std::string line;
    // Skip the header
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        try {
            int passengerId = std::stoi(tokens[0]);
            bool survived = std::stoi(tokens[1]) == 1;
            int pclass = std::stoi(tokens[2]);
            std::string name = tokens[3] + tokens[4];
            std::string sex = tokens[5];
            float age = tokens[6].empty() ? -1 : std::stof(tokens[6]);
            int sibSp = std::stoi(tokens[7]);
            int parch = std::stoi(tokens[8]);
            float ticketFare = tokens[9].empty() ? -1 : std::stof(tokens[9]);
            std::string cabin = tokens[10];
            std::string embarked = tokens[11];

            entries.emplace_back(passengerId, survived, pclass, name, sex, age, sibSp, parch, ticketFare, cabin, embarked);
        } catch (const std::exception &e) {
            std::cerr << "Error parsing line: " << line << " - " << e.what() << std::endl;
        }
    }

    file.close();
    return entries;
}

int main() {
    try {
        std::vector<TitanicEntry> entries = readCSV("titanic.csv");
        std::cout << "Number of valid lines: " << entries.size() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
