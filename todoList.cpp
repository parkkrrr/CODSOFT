#include <bits/stdc++.h>
using namespace std;

int generateUID()
{
    static long long counter = 0;
    return counter++;
}

enum class Priority
{
    low,
    high,
    medium
};

class Task
{
public:
    int id; // randomly generated
    string title;
    bool completed;
    Priority priority;
    Task(string title, Priority priority, bool completed = false)
    {
        this->id = generateUID();
        this->title = title;
        this->priority = priority;
    }
    Task() {}
};

class ToDoList
{
    vector<Task> task;

public:
    void add();
    void remove();
    void update();
    void displayMenu();
    void markComplete();
    void completedTask();
    void list();

    void add()
    {
        string title;
        int priority;
        cout << "\nEnter task title/description: ";
        getline(cin, title);
        cout << "\nEnter priority: 0:Low, 1:Medium, 2:High -> ";
        cin >> priority;
        Priority prior;
        if (priority == 0)
            prior = Priority::low;
        else if (priority == 1)
            prior = Priority::medium;
        else if (priority == 2)
            prior = Priority::high;
        else
            return;

        Task t(title, prior);
        task.emplace_back(t);
    }

    void displayMenu()
    {
        while (true)
        {
            cout << "-------TO-DO-LIST-------\n";
            cout << "1.Add\n2.Remove\n3.Update\n4.Mark Complete\n5.Completed Task\n6. Display all Task\n7.Exit\n";

            int op;
            cin >> op;
            switch (op)
            {
            case 1:
                add();
                break;
            case 2:
                remove();
                break;
            case 3:
                update();
                break;
            case 4:
                markComplete();
                break;
            case 5:
                completedTask();
                break;
            case 6:
                list();
                break;
            case 7:
                return;

            default:
                cout << "You have entered Wrong option.\n";
            }
        }
    }

    void update()
    {
        list();
        int id;
        cout << "Enter the ID -> ";
        cin >> id;
        for (auto i = task.begin(); i < task.end(); i++)
        {
            if (i->id == id)
            {
                string title;
                cout << "Title : (Press Enter for Default value) -> ";
                getline(cin, title);
                if (cin.fail())
                    cin.clear();
                else
                    i->title = title;
                int priority;
                cout << "Priority : (0:Low, 1:Medium, 2:High) -> ";
                cin >> priority;
                if (priority >= 0 || priority <= 0)
                    i->priority = static_cast<Priority>(priority);
                else
                    return;
            }
        }
    }

    void markComplete()
    {
        list();
        int id;
        cout << "Enter the ID -> ";
        cin >> id;
        for (Task &task : task)
        {
            if (task.id == id)
            {
                task.completed = true;
                cout << "\nTask " << task.title << " has been marked as complete.\n";
                return;
            }
        }
    }

    void remove()
    {
        list();
        int id;
        cout << "Enter the ID -> ";
        cin >> id;
        for (auto i = task.begin(); i < task.end(); i++)
            if (i->id == id)
                task.erase(i);
    }

    void completedTask()
    {
        for (Task &task : task)
            if (task.completed == true)
                cout << &task << "\n";
    }

    void list()
    {
        for (Task &task : task)
            cout << &task << "\n";
    }
};

int main(int argc, char *argv[])
{
    ToDoList todo;
    if (argc < 2)
        todo.displayMenu();

    if (argc > 1)
    {
        string args = argv[1];
        switch (args)
        {
        case "add":
            todo.add();
            break;

        case "help":
            cout << "Usage:\n\t$ " << argv[0] << " add\n\t$ " << argv[0] << " remove\n\t$ " << argv[0] << " update\n\t$ " << argv[0] << " display\n";
            break;

        case "remove":
            todo.remove();
            break;
        case "update":
            todo.update();
            break;

        case "display":
            todo.list();
            break;
        default: 
            todo.displayMenu();
        }
    }

    return 0;
}