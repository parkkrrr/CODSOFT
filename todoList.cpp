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
    int id;
    string title;
    bool completed;
    Priority priority;
    Task(string title, Priority priority, bool completed = false)
    {
        this->id = generateUID();
        this->title = title;
        this->priority = priority;
    }
    // Task(string title, int priority, bool completed = false) : title(title), priority(priority), completed(completed)
    // {
    //     id = generateUID();
    // }
    Task() {}
};

class ToDoList
{
    vector<Task> task;
    string filename;

public:
    ToDoList(string &filename) : filename(filename) {}

    // void add();
    // void remove();
    // void update();
    // void displayMenu();
    // void markComplete();
    // void completedTask();
    // void list();
    // void saveFile();
    // void loadFile();

    void saveFile()
    {
        ofstream file(filename);

        if (!file.is_open())
        {
            cerr << "### Error saving tasks\n";
            return;
        }

        for (auto &task : task)
            file << task.id << "," << task.title << "," << static_cast<int>(task.priority) << "," << (task.completed ? "1" : "0") << "\n";

        file.close();
    }

    void loadFile()
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cerr << "### File not found. Creating a new file." << endl;
            ofstream newFile(filename);
            newFile.close();
        }

        // task.clear();

        string str;
        while (getline(file, str))
        {
            stringstream ss(str);
            string id, title, priority, completed;
            if (getline(ss, id, ',') && getline(ss, title, ',') && getline(ss, priority, ',') && getline(ss, completed, ','))
            {
                Task task(title, static_cast<Priority>(stoi(priority)), (completed == "1"));
                task.id = stoi(id);
                this->task.emplace_back(task);
            }
        }
        file.close();
    }

    void add()
    {
        string title;
        int priority;
        cout << "\n(+) Enter task title/description -> ";
        cin.ignore();
        getline(cin, title);
        cout << "\n(+) Enter priority: 0:Low, 1:Medium, 2:High -> ";
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
            system("pause");
            system("cls");
            cout << "-------TO-DO-LIST-------\n";
            cout << "1.Add\n2.Remove\n3.Update\n4.Mark Complete\n5.Completed Task\n6. Display all Task\n7.Exit\n->";

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
                cout << "### You have entered Wrong option.\n";
            }
        }
    }

    void update()
    {
        list();
        int id;
        cout << "(+) Enter the ID -> ";
        cin >> id;
        for (auto i = task.begin(); i < task.end(); i++)
        {
            if (i->id == id)
            {
                string title;
                cout << "(+) Title : (Press Enter for Default value) -> ";
                cin.ignore();
                getline(cin, title);

                if (cin.fail())
                    cin.clear();
                else
                    i->title = title;
                int priority;
                cout << "(+) Priority : (0:Low, 1:Medium, 2:High) -> ";
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
        cout << "\n(+) Enter the ID -> ";
        cin >> id;
        for (auto &task : task)
        {
            if (task.id == id)
            {
                task.completed = true;
                cout << "\n(+) Task " << task.title << " has been marked as complete.\n";
                return;
            }
        }
    }

    void remove()
    {
        list();
        int id;
        cout << "(-) Enter the ID -> ";
        cin >> id;
        for (auto i = task.begin(); i != task.end(); i++)
            if (i->id == id)
            {
                task.erase(i);
                return;
            }
    }

    void completedTask()
    {
        for (auto &task : task)
            if (task.completed == true)
                cout << "\n->" << task.id << "\n->" << task.title << "\n";
    }

    void list()
    {
        for (auto &task : task)
            cout << "\n->" << task.id << "\n->" << task.title << "\n";
    }

    bool isEmpty()
    {
        // if (task.empty())
        //     return true;
        // return false;
        return task.empty();
    }
};

int main(int argc, char *argv[])
{
    // system("cls");
    string filename = "todo.txt";
    ToDoList todo(filename);
    todo.loadFile();

    if (argc < 2)
        todo.displayMenu();

    if (argc > 1)
    {
        string arg = argv[1];

        if (arg == "add")
        {
            todo.add();
            todo.saveFile();
            system("cls");
        }

        else if (arg == "help")
        {
            cout << "Usage:\n\t$ " << argv[0] << " add\n\t$ " << argv[0] << " remove\n\t$ " << argv[0] << " update\n\t$ " << argv[0] << " display\n";
            system("cls");
        }

        else if (arg == "remove")
        {
            todo.remove();
            todo.saveFile();
            system("cls");
        }

        else if (arg == "update")
        {
            todo.update();
            todo.saveFile();
            system("cls");
        }

        else if (arg == "display")
            if (todo.isEmpty())
                cout << "List is Empty\n";
            else
                todo.list();

        else
            todo.displayMenu();
    }
    system("pause");
    return 0;
}