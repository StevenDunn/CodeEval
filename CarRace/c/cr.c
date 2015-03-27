// car race soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float* array;
    size_t size;
    size_t used;
} Array;
void init(Array*, size_t);
void insert(Array*, float);

typedef struct {
    int key;
    float val;
} Pair;

typedef struct {
    Pair *data;
    size_t size;
    size_t used;
} Map;
void map_init(Map*, size_t);
void map_insert(Map*, Pair);
void map_sort(Map*);

void parse(Array*, char*);
float time_lap(Array*, int, float, float);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        fgets(line, sizeof(line), fp);

        Array track;
        init(&track, 1);
        parse(&track, line);

        Map results;
        map_init(&results, 1);
        while (fgets(line, sizeof(line), fp))
        {
            Array car_result;
            init(&car_result, 1);
            parse(&car_result, line);

            int car_num = (int)car_result.array[0];
            int top_speed = (int)car_result.array[1];
            float time_to_accelerate = car_result.array[2];
            float time_to_brake = car_result.array[3];

            float lap_time = time_lap(&track, top_speed, time_to_accelerate/3600.0, time_to_brake/3600.0);

            Pair result;
            result.key = car_num;
            result.val = lap_time;
            map_insert(&results, result);
        }
        map_sort(&results);
        for (int i = 0; i < results.used; ++i)
            printf("%d %.2f\n", results.data[i].key, results.data[i].val);
        fclose(fp);
    }
    return 0;
}

void parse(Array* arr, char* line)
{
    char *token = strtok(line, " ");
    while (token != NULL)
    {
        insert(arr, atof(token));
        token = strtok(NULL, " ");
    }
}

void init(Array* arr, size_t initSize)
{
    arr->array = (float*)malloc(initSize * sizeof(float));
    arr->size = initSize;
    arr->used = 0;
}

void insert(Array* arr, float element)
{
    if (arr->used == arr->size)
    {
        arr->size *= 2;
        arr->array = (float*)realloc(arr->array, arr->size * sizeof(float));
    }
    arr->array[arr->used++] = element;
}

void map_init(Map* map, size_t initSize)
{
    map->data = (Pair*)malloc(initSize * sizeof(Pair));
    map->size = initSize;
    map->used = 0;
}

void map_insert(Map* map, Pair p)
{
    if (map->used == map->size)
    {
        map->size *= 2;
        map->data = (Pair*)realloc(map->data, map->size * sizeof(Pair));
    }
    map->data[map->used++] = p;
}

void map_sort(Map* map)
{
    for (int i = 1; i < map->used; ++i)
        for (int j = 0; j < i; ++j)
            if (map->data[i].val < map->data[j].val)
            {
                Pair temp = map->data[i];
                map->data[i] = map->data[j];
                map->data[j] = temp;
            }
}

float time_lap(Array* track, int top_speed, float time_to_accelerate, float time_to_brake)
{
    float lap_time = 0.0;
    float speed = 0.0;

    float acceleration = top_speed / time_to_accelerate;
    float deceleration = top_speed / time_to_brake;

    for (int i = 0; i < track->used; i += 2)
    {
        float segment_length = track->array[i];
        float segment_turn = track->array[i+1];

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