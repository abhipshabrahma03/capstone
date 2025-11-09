@@ -1,14 +1,9 @@
//-------------------DAY 5----------------------//
#include <bits/stdc++.h>
#include <filesystem>
#include <chrono>
#include <cstdlib>
using namespace std;
namespace fs = std::filesystem;

// ---------- Command History ----------
vector<string> command_history;

// ---------- Existing Commands ----------
void cmd_pwd() {
    cout << fs::current_path().string() << "\n";
@@ -157,39 +152,20 @@ void cmd_help() {
    cout << "info <file>        - Show file info\n";
    cout << "find <name>        - Search by filename\n";
    cout << "tree               - Display folder tree\n";
    cout << "clear              - Clear the screen\n";
    cout << "history            - Show all commands used\n";
    cout << "help               - Show this help message\n";
    cout << "exit               - Exit the explorer (with confirmation)\n";
    cout << "exit               - Exit the explorer\n";
    cout << "------------------------------------------\n\n";
}

// ---------- New Day 5 Commands ----------
void cmd_history() {
    if (command_history.empty()) {
        cout << "No commands yet.\n";
        return;
    }
    for (size_t i = 0; i < command_history.size(); ++i)
        cout << i + 1 << ": " << command_history[i] << "\n";
}

void cmd_clear() {
    system("clear");  // Clears terminal
}

// ---------- Main ----------
int main() {
    cout << "Simple File Explorer - Final Build\n";
    cout << "Simple File Explorer - Day 4\n";
    cout << "Type 'help' for list of commands.\n";

    string line;
    while (true) {
        cout << fs::current_path().string() << " $ ";
        getline(cin, line);
        if (line.empty()) continue;
        command_history.push_back(line);

        stringstream ss(line);
        string cmd, arg1, arg2;
        ss >> cmd >> arg1 >> arg2;
@@ -205,18 +181,11 @@ int main() {
        else if (cmd == "info") cmd_info(arg1);
        else if (cmd == "find") cmd_find(arg1);
        else if (cmd == "tree") cmd_tree();
        else if (cmd == "history") cmd_history();
        else if (cmd == "clear") cmd_clear();
        else if (cmd == "help") cmd_help();
        else if (cmd == "exit") {
            cout << "Are you sure you want to exit? (y/n): ";
            string confirm;
            getline(cin, confirm);
            if (confirm == "y" || confirm == "Y") break;
        }
        else if (cmd == "exit") break;
        else if (!cmd.empty()) cout << "Unknown command\n";
    }

    cout << "Exiting File Explorer. Goodbye!\n";
    cout << "Exiting File Explorer\n";
    return 0;
}