#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        Task newTask;
        newTask.description = description;
        newTask.completed = false;
        tasks.push_back(newTask);
        cout << "Task added: " << description << endl;
    }

    void markTaskAsCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Task marked as completed: " << tasks[index].description << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void displayTasks() {
        cout << "To-Do List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << "[" << i + 1 << "] ";
            if (tasks[i].completed) {
                cout << "[X] ";
            } else {
                cout << "[ ] ";
            }
            cout << tasks[i].description << endl;
        }
    }
};

int main() {
    ToDoList toDoList;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Task\n";
        cout << "2. Mark Task as Completed\n";
        cout << "3. Display Tasks\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string description;
                cout << "Enter task description: ";
                cin.ignore(); // Consume the newline character left in the stream
                getline(cin, description);
                toDoList.addTask(description);
                break;
            }
            case 2: {
                int index;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> index;
                toDoList.markTaskAsCompleted(index - 1); // Adjust index to match vector indexing
                break;
            }
            case 3:
                toDoList.displayTasks();
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}
