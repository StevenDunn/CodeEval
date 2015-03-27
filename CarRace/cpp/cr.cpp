// car race soln in cpp for code eval by steven a dunn

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::map;
using std::string;
using std::vector;

vector<float> tokenize(string);
float time_lap(vector<float>, int, float, float);

int main (int argc, char* const argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        getline(input_file, line);
        vector<float> track = tokenize(line);
        map<float, int> results;
        while (getline(input_file, line))
        {
            vector<float> tokens = tokenize(line);
            int car_num = (int)tokens[0];
            int top_speed = (int)tokens[1];
            float time_to_accelerate = tokens[2];
            float time_to_brake = tokens[3];

            float lap_time = time_lap(track, top_speed, time_to_accelerate/3600.0, time_to_brake/3600.0);
            results[lap_time] = car_num;
        }
        for (map<float, int>::iterator i = results.begin(); i != results.end(); ++i)
        {
            cout << i->second << " ";
            cout << std::fixed << std::setprecision(2) << i->first << endl;
        }
        input_file.close();
    }
    return 0;
}

vector<float> tokenize(string input)
{
    vector<float> tokens;
    istringstream iss(input);
    string line;
    while (getline(iss, line, ' '))
        tokens.push_back(atof(line.c_str()));
    return tokens;
}

float time_lap(vector<float> track, int top_speed, float time_to_accelerate, float time_to_brake)
{
    float lap_time = 0.0;
    float speed = 0.0;

    float acceleration = top_speed / time_to_accelerate;
    float deceleration = top_speed / time_to_brake;

    for (int i = 0; i < track.size(); i += 2)
    {
        float segment_length = track[i];
        float segment_turn = track[i+1];

        float acceleration_time = (top_speed - speed) / acceleration;
        float acceleration_distance = (speed * acceleration_time) + (0.5 * acceleration * acceleration_time * acceleration_time);

        float turn_speed = top_speed - (top_speed * (segment_turn/180.0));

        float deceleration_time = (top_speed - turn_speed) / deceleration;
        float deceleration_distance = (top_speed * deceleration_time) - (0.5 * deceleration * deceleration_time * deceleration_time);

        float constant_distance = segment_length - (acceleration_distance + deceleration_distance);
        float constant_drive_time = constant_distance / top_speed;

        lap_time += acceleration_time + constant_drive_time + deceleration_time;
        speed = turn_speed;
    }
    return lap_time * 3600.0;
}
