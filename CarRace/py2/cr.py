#car race soln in py for code eval by steven a dunn

import sys

def timed_lap(track, top_speed, time_to_accelerate, time_to_brake):
    time = 0.0
    speed = 0.0

    acceleration = top_speed / time_to_accelerate
    deceleration = top_speed / time_to_brake

    for i in xrange(0, len(track), 2):
        segment_length = float(track[i])
        segment_turn = int(track[i+1])

        acceleration_time = (top_speed - speed) / acceleration
        acceleration_distance = (speed * acceleration_time) + (0.5 * acceleration * acceleration_time * acceleration_time)

        turn_speed = top_speed - (top_speed * (segment_turn/180.0))

        deceleration_time = (top_speed - turn_speed) / deceleration
        deceleration_distance = (top_speed * deceleration_time) - (0.5 * deceleration * deceleration_time * deceleration_time)

        constant_distance = segment_length - (acceleration_distance + deceleration_distance)
        constant_drive_time = constant_distance / top_speed

        time += acceleration_time + constant_drive_time + deceleration_time
        speed = turn_speed
    return time * 3600.0

f = open(sys.argv[1], 'r')
track = f.readline().split()
results = {}
for line in f:
    car_num, top_speed, time_to_accelerate, time_to_brake = line.split()
    time = timed_lap(track, int(top_speed), float(time_to_accelerate)/3600.0, float(time_to_brake)/3600.0)
    results[int(car_num)] = time
f.close()

for key in sorted(results, key=results.get):
    print "%d %.2f" % (key, results[key])