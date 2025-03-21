#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

// Function to display tasks
void displayTasks(const vector<Task>& tasks) {
    cout << "\nTo-Do List:\n";
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". [" << (tasks[i].completed ? "✔" : " ") << "] " << tasks[i].description << endl;
    }
}

// Function to add a task
void addTask(vector<Task>& tasks) {
    string desc;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, desc);
    tasks.push_back({desc, false});
    cout << "Task added successfully!\n";
}

// Function to mark a task as completed
void completeTask(vector<Task>& tasks) {
    displayTasks(tasks);
    if (tasks.empty()) return;
    
    int taskNum;
    cout << "Enter task number to mark as completed: ";
    cin >> taskNum;
    
    if (taskNum > 0 && taskNum <= tasks.size()) {
        tasks[taskNum - 1].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

// Function to remove a task
void removeTask(vector<Task>& tasks) {
    displayTasks(tasks);
    if (tasks.empty()) return;
    
    int taskNum;
    cout << "Enter task number to remove: ";
    cin >> taskNum;
    
    if (taskNum > 0 && taskNum <= tasks.size()) {
        tasks.erase(tasks.begin() + (taskNum - 1));
        cout << "Task removed successfully!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

// Main function
int main() {
    vector<Task> tasks;
    int choice;

    while (true) {
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: displayTasks(tasks); break;
            case 3: completeTask(tasks); break;
            case 4: removeTask(tasks); break;
            case 5: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}
