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
    void markComplete(Task task);
    void completedTask();
    void list();

    void add()
    {
        string title;
        int priority;
        cout << "\nEnter task title/description: ";
        getline(cin,title);
        cout << "\nEnter priority: 0:Low, 1:Medium, 2:High -> ";
        cin >> priority;
        Priority prior;
        if(priority==0)
            prior=Priority::low;
        else if(priority==1)
            prior=Priority::medium;
        else if(priority==2)
            prior=Priority::high;
        else    
            return;
            
        Task t(title, prior);
        
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
        cout << "Select ID"
    }
};
int main(int argc, char *argv[])
{

    ToDoList todo;
    if (argc < 2)
    {
        todo.displayMenu();
    }

    return 0;
}