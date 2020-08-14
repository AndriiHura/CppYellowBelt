// PA5_TaskTracker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include <string>
#include<map>
#include <tuple>

using namespace std;

enum class TaskStatus {
    NEW, 
    IN_PROGRESS,
    TESTING, 
    DONE
};

using TasksInfo = map<TaskStatus, int>;

void RemoveZeroTasks(TasksInfo& tasks) {
    TasksInfo tmpTasks = tasks;
    for (auto& task : tmpTasks) {
        if (task.second == 0) {
            tasks.erase(task.first);
        }
    }
}

TasksInfo operator-(const TasksInfo& lhs, const TasksInfo& rhs) {
    TasksInfo result;
    for (const auto& el : lhs) {
        if (lhs.count(el.first) == 1 && rhs.count(el.first) == 1)
        {
            result[el.first] = lhs.at(el.first) - rhs.at(el.first);
        }
        else if (lhs.count(el.first) == 1) {
            result[el.first] = lhs.at(el.first);
        }
    }
    RemoveZeroTasks(result);
    return result;
}




class TeamTasks {
public:

    const TasksInfo& GetPersonTasksInfo(const string& person) const {
        return PersonToTasks.at(person);
    }

    void AddNewTask(const string& person) {
        ++PersonToTasks[person][TaskStatus::NEW];
    }

    int GetPersonNumOfTasks(const string& person) const {
        int numOfTasks = 0;
        for (const auto& p : PersonToTasks.at(person)) {
            if (p.first != TaskStatus::DONE) {
                numOfTasks += p.second;
            }
        }
        return numOfTasks;
    }

    

   
   


   void UpdateTaskType(const TaskStatus st, int& task_count, TasksInfo& tasks,
   TasksInfo& updatedTasks, const TasksInfo& ConstTasks) 
   {
       if (ConstTasks.count(st) == 1) {//If map contains NEW

           if (ConstTasks.at(st) >= task_count) {//If we will update only NEW
               tasks[st] -= task_count;
               updatedTasks[static_cast<TaskStatus>(static_cast<int>(st)+1)] = task_count;
               tasks[static_cast<TaskStatus>(static_cast<int>(st) + 1)] += task_count;
               task_count = 0;
               
              
           }
           else {
               int NumOfTasks = ConstTasks.at(st);
               
               updatedTasks[static_cast<TaskStatus>(static_cast<int>(st) + 1)] = NumOfTasks;
               task_count -= NumOfTasks;
               tasks[st] -= NumOfTasks;
               tasks[static_cast<TaskStatus>(static_cast<int>(st) + 1)] += NumOfTasks;
               
           }
       }
    }

    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) 
    {
        if (PersonToTasks.count(person) == 0) {
            return { {},{} };
        }
        int PersonNumOfTasks = GetPersonNumOfTasks(person);
        if (task_count > PersonNumOfTasks) {
            task_count = PersonNumOfTasks;
            if (task_count == 0) {
                return { {},{} };
            }
        }
        const TasksInfo ResultHelper = PersonToTasks[person];
        TasksInfo& tmpInfo = PersonToTasks[person];
        TasksInfo updatedTasks;
        TasksInfo notUpdatedTasks;

        for (auto& tType : tmpInfo) {
            if (task_count > 0) {
                UpdateTaskType(tType.first, task_count, tmpInfo, updatedTasks, ResultHelper);
                if (task_count == 0) {
                    notUpdatedTasks = tmpInfo - updatedTasks;
                    RemoveZeroTasks(updatedTasks);
                    RemoveZeroTasks(notUpdatedTasks);
                    RemoveZeroTasks(tmpInfo);
                    notUpdatedTasks.erase(TaskStatus::DONE);
                    updatedTasks.erase(TaskStatus::NEW);

                    return { updatedTasks , notUpdatedTasks };
                }
            }
            
        }
    }
private:
    map<string, TasksInfo> PersonToTasks;
};

void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
        ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
        ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
        ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}
void PrintTasksInfo(const TasksInfo& updated_tasks, const TasksInfo& untouched_tasks) {
    std::cout << "Updated: [";
    PrintTasksInfo(updated_tasks);
    std::cout << "] ";

    std::cout << "Untouched: [";
    PrintTasksInfo(untouched_tasks);
    std::cout << "] ";

    std::cout << std::endl;
}

int main() {
    TeamTasks tasks;
    TasksInfo updated_tasks, untouched_tasks;

    //for (int i = 0; i < 5; ++i) {
    //    tasks.AddNewTask("Alice");
    //}
    //cout << "Alice's tasks: ";
    //PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
    //cout << endl;
    //


    //tie(updated_tasks, untouched_tasks) =
    //    tasks.PerformPersonTasks("Alice", 5);
    //cout << "Updated Alice's tasks: ";
    //PrintTasksInfo(updated_tasks);
    //cout << "Untouched Alice's tasks: ";
    //PrintTasksInfo(untouched_tasks);
    //cout << endl;

    //cout << "Alice's tasks: ";
    //PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
    //cout << endl;


    //tie(updated_tasks, untouched_tasks) =
    //    tasks.PerformPersonTasks("Alice", 5);
    //cout << "Updated Alice's tasks: ";
    //PrintTasksInfo(updated_tasks);
    //cout << "Untouched Alice's tasks: ";
    //PrintTasksInfo(untouched_tasks);
    //cout << "Alice's tasks: ";
    //PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
    //cout << endl;



    //tie(updated_tasks, untouched_tasks) =
    //    tasks.PerformPersonTasks("Alice", 1);
    //cout << "Updated Alice's tasks: ";
    //PrintTasksInfo(updated_tasks);
    //cout << "Untouched Alice's tasks: ";
    //PrintTasksInfo(untouched_tasks);
    //cout << "Alice's tasks: ";
    //PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
    //cout << endl;


    //for (int i = 0; i < 5; ++i) {
    //    tasks.AddNewTask("Alice");
    //}
    //cout << "Alice's tasks: ";
    //PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
    //cout << endl;


    //tie(updated_tasks, untouched_tasks) =
    //    tasks.PerformPersonTasks("Alice", 2);
    //cout << "Updated Alice's tasks: ";
    //PrintTasksInfo(updated_tasks);
    //cout << "Untouched Alice's tasks: ";
    //PrintTasksInfo(untouched_tasks);
    //cout << "Alice's tasks: ";
    //PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
    //cout << endl;

    //tie(updated_tasks, untouched_tasks) =
    //    tasks.PerformPersonTasks("Alice", 4);
    //cout << "Updated Alice's tasks: ";
    //PrintTasksInfo(updated_tasks);
    //cout << "Untouched Alice's tasks: ";
    //PrintTasksInfo(untouched_tasks);
    //cout << "Alice's tasks: ";
    //PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
    //cout << endl;


    ///* TEST 2 */
    //std::cout << "\nJack" << std::endl;

    //tasks.AddNewTask("Jack");

    //tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Jack", 1);
    //PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 1}, {}]

    //tasks.AddNewTask("Jack");

    //tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Jack", 2);
    //PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 1, "TESTING": 1}, {}]

    //PrintTasksInfo(tasks.GetPersonTasksInfo("Jack"));

    //PrintTasksInfo(tasks.GetPersonTasksInfo("Jack")- updated_tasks);

    //tasks.AddNewTask("Jack");

    //PrintTasksInfo(tasks.GetPersonTasksInfo("Jack"));  // {"NEW": 1, "IN_PROGRESS": 1, "TESTING": 1, "DONE": 0}
    //std::cout << std::endl;

    //tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Jack", 3);
    //PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 1, "TESTING": 1, "DONE": 1}, {}]

    //PrintTasksInfo(tasks.GetPersonTasksInfo("Jack"));  // {"IN_PROGRESS": 1, "TESTING": 1, "DONE": 1}
    //std::cout << std::endl;

    /* TEST 3 */
    std::cout << "\nLisa" << std::endl;

    for (auto i = 0; i < 5; ++i) {
        tasks.AddNewTask("Lisa");
    }

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 5);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 5}, {}]

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 5);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"TESTING": 5}, {}]

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 1);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"DONE": 1}, {"TESTING": 4}]

    for (auto i = 0; i < 5; ++i) {
        tasks.AddNewTask("Lisa");
    }

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 2);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 2}, {"NEW": 3, "TESTING": 4}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"NEW": 3, "IN_PROGRESS": 2, "TESTING": 4, "DONE": 1}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 4);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 3, "TESTING": 1}, {"IN_PROGRESS": 1, "TESTING": 4}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"IN_PROGRESS": 4, "TESTING": 5, "DONE": 1}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 5);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"TESTING": 4, "DONE": 1}, {"TESTING": 4}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"TESTING": 8, "DONE": 2}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 10);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"DONE": 8}, {}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"DONE": 10}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 10); //ERROR
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{}, {}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"DONE": 10}
    std::cout << std::endl;

    tasks.AddNewTask("Lisa");

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"NEW": 1, "DONE": 10}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 2);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 1}, {}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"IN_PROGRESS": 1, "DONE": 10}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Bob", 3);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{}, {}]


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
