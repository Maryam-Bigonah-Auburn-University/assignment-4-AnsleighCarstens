#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Player {
private:
    string name;
    int score;

public:
    // Constructor to initialize player with name and score
    Player(string playerName, int playerScore) {
        name = playerName;
        score = playerScore;
    }

    // Function to get player's name
    string getName() const {
        return name;
    }

    // Function to get player's score
    int getScore() const {
        return score;
    }

    // Function to set player's name (if needed)
    void setName(string playerName) {
        name = playerName;
    }

    // Function to set player's score (if needed)
    void setScore(int playerScore) {
        score = playerScore;
    }
};

class PlayerManager {
private:
    vector<Player> players;

public:
    // Add a new player (up to 10 players)
    void addPlayer(string playerName, int playerScore) {
        if (players.size() < 10) {
            players.push_back(Player(playerName, playerScore));
            cout << "Player added successfully!" << endl;
        } else {
            cout << "Player limit reached! Cannot add more players." << endl;
        }
    }

    // Print all player names and scores
    void printPlayers() const {
        if (players.empty()) {
            cout << "No players available." << endl;
        } else {
            cout << "Player List:" << endl;
            for (const auto& player : players) {
                cout << "Name: " << player.getName() << ", Score: " << player.getScore() << endl;
            }
        }
    }

    // Get a player's score by name
    void getPlayerScore(const string& playerName) const {
        bool found = false;
        for (const auto& player : players) {
            if (player.getName() == playerName) {
                cout << "Player " << playerName << " has a score of " << player.getScore() << "." << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Player " << playerName << " not found." << endl;
        }
    }

    // Remove a player by name
    void removePlayer(const string& playerName) {
        for (auto it = players.begin(); it != players.end(); ++it) {
            if (it->getName() == playerName) {
                players.erase(it);
                cout << "Player " << playerName << " removed successfully." << endl;
                return;
            }
        }
        cout << "Player " << playerName << " not found." << endl;
    }
};

// Main program to demonstrate functionality
int main() {
    PlayerManager manager;
    int choice;
    string playerName;
    int playerScore;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Player\n";
        cout << "2. Print Players\n";
        cout << "3. Get Player Score\n";
        cout << "4. Remove Player\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter player name: ";
                cin >> playerName;
                cout << "Enter player score: ";
                cin >> playerScore;
                manager.addPlayer(playerName, playerScore);
                break;
            case 2:
                manager.printPlayers();
                break;
            case 3:
                cout << "Enter player name: ";
                cin >> playerName;
                manager.getPlayerScore(playerName);
                break;
            case 4:
                cout << "Enter player name: ";
                cin >> playerName;
                manager.removePlayer(playerName);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}

