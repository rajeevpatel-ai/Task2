#include <iostream>
#include <string>
#include <map>

// Function to display a greeting message
void displayGreeting() {
    std::cout << "ChatBot: Hello! I'm ChatBot. How can I assist you today?\n";
}

// Function to get a response from the chatbot based on user input
std::string getResponse(const std::string& userInput) {
    // A map of predefined responses
    std::map<std::string, std::string> responses = {
        {"hello", "Hi there! How can I help you?"},
        {"how are you", "I'm just a program, but I'm functioning perfectly! How about you?"},
        {"what is your name", "I'm ChatBot, your virtual assistant."},
        {"bye", "Goodbye! Have a great day!"},
        {"help", "Sure! I can assist with basic queries. Just ask me."}
    };

    // Search for the user input in the map
    std::string inputLower = userInput;
    for (auto& c : inputLower) c = tolower(c); // Convert to lowercase for case-insensitive matching

    if (responses.find(inputLower) != responses.end()) {
        return responses[inputLower];
    } else {
        return "I'm sorry, I don't understand that. Can you try rephrasing?";
    }
}

int main() {
    displayGreeting();

    std::string userInput;
    while (true) {
        std::cout << "You: ";
        std::getline(std::cin, userInput);

        // Exit the chatbot if the user types "bye"
        if (userInput == "bye" || userInput == "Bye") {
            std::cout << "ChatBot: Goodbye! Have a great day!\n";
            break;
        }

        // Get and display the chatbot's response
        std::string response = getResponse(userInput);
        std::cout << "ChatBot: " << response << std::endl;
    }

    return 0;
}