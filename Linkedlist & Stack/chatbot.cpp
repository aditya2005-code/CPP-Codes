#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

class ChatBot {
private:
    unordered_map<string, string> responses;
    string fileName;

    void loadResponses() {
        ifstream file(fileName);
        if (file.is_open()) {
            string key, value;
            while (getline(file, key) && getline(file, value)) {
                responses[key] = value;
            }
            file.close();
        } else {
            cout << "Unable to open the file. Starting with an empty response database.\n";
        }
    }

    void saveResponses() {
        ofstream file(fileName);
        if (file.is_open()) {
            for (const auto &pair : responses) {
                file << pair.first << "\n";
                file << pair.second << "\n";
            }
            file.close();
        } else {
            cout << "Error saving responses to file.\n";
        }
    }

public:
    ChatBot(const string &file) : fileName(file) {
        loadResponses();
    }

    ~ChatBot() {
        saveResponses();
    }

    void addResponse(const string &question, const string &answer) {
        responses[question] = answer;
        cout << "Response added!\n";
    }

    void chat() {
        string input;
        cout << "ChatBot: Hello! How can I help you today? (Type 'exit' to quit)\n";

        while (true) {
            cout << "You: ";
            getline(cin, input);

            if (input == "exit") {
                cout << "ChatBot: Goodbye! Have a great day!\n";
                break;
            }

            if (responses.find(input) != responses.end()) {
                cout << "ChatBot: " << responses[input] << "\n";
            } else {
                cout << "ChatBot: I don't know the answer to that. Can you teach me? (yes/no)\n";
                string choice;
                getline(cin, choice);

                if (choice == "yes") {
                    cout << "Please provide the answer: ";
                    string answer;
                    getline(cin, answer);
                    addResponse(input, answer);
                } else {
                    cout << "Okay, let's continue chatting!\n";
                }
            }
        }
    }
};

int main() {
    ChatBot bot("chat_responses.txt");
    bot.chat();
    return 0;
}