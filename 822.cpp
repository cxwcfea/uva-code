/*
 * =====================================================================================
 *
 *       Filename:  822.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/20/2014 21:07:07
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  cxwcfea(cxwcfea@163.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Topic {
    int serve_time;
    queue<int> items;
};

struct People {
    int id;
    vector<int> topics;
    int last_start_time;
    int next_available_time;
};

int main() {
#ifdef Debug
    freopen("822.in", "r", stdin);
#endif
    int num_of_topics, num_of_people, cases = 0;
    while (true) {
        scanf("%d", &num_of_topics);
        if (num_of_topics == 0)
            break;
       
        int total_topics = 0;
        map<int, Topic> topic_map;
        for (int i = 0; i < num_of_topics; ++i) {
            int key;
            scanf("%d", &key);
            Topic &temp = topic_map[key];
            int last_time, num, interval;
            scanf("%d %d %d %d", &num, &last_time, &temp.serve_time, &interval);
            total_topics += num;
            temp.items.push(last_time);
            for (int j = 1; j < num; ++j) {
                last_time += interval;
                temp.items.push(last_time);
            }
        }
        
        scanf("%d", &num_of_people);
        vector<People> peoples;
        for (int i = 0; i < num_of_people; ++i) {
            People temp;
            int temp_num, v;
            scanf("%d %d", &temp.id, &temp_num);
            for (int j = 0; j < temp_num; ++j) {
                scanf("%d", &v);
                temp.topics.push_back(v); 
            }
            temp.next_available_time = 0;
            peoples.push_back(move(temp));
        }
        
        int time = 0;
        while (true) {
            bool updated = false;

            for (int i = 0; i < num_of_people; ++i) {
                if (peoples[i].next_available_time > time) {
                    continue;
                }
                
                if (peoples[i].next_available_time == time) {
                    if (peoples[i].next_available_time > 0) {
                        //printf("People %d finish its job at %d\n", peoples[i].id, time);
                        --total_topics;
                        if (!total_topics)
                            break;
                    }
                } 

                if (peoples[i].next_available_time <= time) {
                    for (auto &v : peoples[i].topics) {
                        Topic &temp_topic = topic_map[v];
                        if (!temp_topic.items.empty() && temp_topic.items.front() <= time) {
                            peoples[i].last_start_time = time;
                            peoples[i].next_available_time = time + temp_topic.serve_time; 
                            temp_topic.items.pop();
                            updated = true;
                            //printf("People %d take job %d at %d\n", peoples[i].id, v, time);
                            break;
                        }
                    }
                }
            }

            if (updated) {
                sort(peoples.begin(), peoples.end(), [](const People &a, const People &b) {
                    return a.last_start_time < b.last_start_time;
                });
            }

            if (!total_topics)
                break;

            ++time;
        }
        printf("Scenario %d: All requests are serviced within %d minutes.\n", ++cases, time);
    }
    return 0;
}
