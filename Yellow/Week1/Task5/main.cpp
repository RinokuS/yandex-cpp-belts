#include <iostream>
#include <map>
#include <stdexcept>
#include <vector>
#include <set>

using namespace std;

class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const{
        return team.at(person);
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person){
        team[person][TaskStatus::NEW]++;
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count){
        TasksInfo new_tasks, old_tasks = team[person];

        task_count -= old_tasks[TaskStatus::NEW];
        if (task_count > 0){
            new_tasks[TaskStatus::IN_PROGRESS] += old_tasks[TaskStatus::NEW];
            team[person][TaskStatus::IN_PROGRESS] += old_tasks[TaskStatus::NEW];
            team[person][TaskStatus::NEW] -= old_tasks[TaskStatus::NEW];
            old_tasks[TaskStatus::NEW] -= old_tasks[TaskStatus::NEW];
        } else{
            new_tasks[TaskStatus::IN_PROGRESS] += old_tasks[TaskStatus::NEW] + task_count;
            team[person][TaskStatus::IN_PROGRESS] += old_tasks[TaskStatus::NEW] + task_count;
            team[person][TaskStatus::NEW] -= old_tasks[TaskStatus::NEW] + task_count;
            old_tasks[TaskStatus::NEW] -= old_tasks[TaskStatus::NEW] + task_count;

            UpdateDict(new_tasks);
            UpdateDict(old_tasks);
            UpdateDict(team[person]);
            old_tasks.erase(TaskStatus::DONE);
            return make_tuple(new_tasks, old_tasks);
        }

        task_count -= old_tasks[TaskStatus::IN_PROGRESS];
        if (task_count > 0){
            new_tasks[TaskStatus::TESTING] += old_tasks[TaskStatus::IN_PROGRESS];
            team[person][TaskStatus::TESTING] += old_tasks[TaskStatus::IN_PROGRESS];
            team[person][TaskStatus::IN_PROGRESS] -= old_tasks[TaskStatus::IN_PROGRESS];
            old_tasks[TaskStatus::IN_PROGRESS] -= old_tasks[TaskStatus::IN_PROGRESS];
        } else{
            new_tasks[TaskStatus::TESTING] += old_tasks[TaskStatus::IN_PROGRESS] + task_count;
            team[person][TaskStatus::TESTING] += old_tasks[TaskStatus::IN_PROGRESS] + task_count;
            team[person][TaskStatus::IN_PROGRESS] -= old_tasks[TaskStatus::IN_PROGRESS] + task_count;
            old_tasks[TaskStatus::IN_PROGRESS] -= old_tasks[TaskStatus::IN_PROGRESS] + task_count;

            UpdateDict(new_tasks);
            UpdateDict(old_tasks);
            UpdateDict(team[person]);
            old_tasks.erase(TaskStatus::DONE);
            return make_tuple(new_tasks, old_tasks);
        }

        task_count -= old_tasks[TaskStatus::TESTING];
        if (task_count > 0){
            new_tasks[TaskStatus::DONE] += old_tasks[TaskStatus::TESTING];
            team[person][TaskStatus::DONE] += old_tasks[TaskStatus::TESTING];
            team[person][TaskStatus::TESTING] -= old_tasks[TaskStatus::TESTING];
            old_tasks[TaskStatus::TESTING] -= old_tasks[TaskStatus::TESTING];
        } else{
            new_tasks[TaskStatus::DONE] += old_tasks[TaskStatus::TESTING] + task_count;
            team[person][TaskStatus::DONE] += old_tasks[TaskStatus::TESTING] + task_count;
            team[person][TaskStatus::TESTING] -= old_tasks[TaskStatus::TESTING] + task_count;
            old_tasks[TaskStatus::TESTING] -= old_tasks[TaskStatus::TESTING] + task_count;

            UpdateDict(new_tasks);
            UpdateDict(old_tasks);
            UpdateDict(team[person]);
            old_tasks.erase(TaskStatus::DONE);
            return make_tuple(new_tasks, old_tasks);
        }

        UpdateDict(new_tasks);
        UpdateDict(old_tasks);
        UpdateDict(team[person]);
        old_tasks.erase(TaskStatus::DONE);
        return make_tuple(new_tasks, old_tasks);
    }

private:
    map<string, TasksInfo> team;
    void UpdateDict(map<TaskStatus, int>& dict){
        set<TaskStatus> s;
        for(const auto& [key, value]: dict){
            if (value == 0){
                s.insert(key);
            }
        }

        for(const auto& i: s){
            dict.erase(i);
        }
    }
};

