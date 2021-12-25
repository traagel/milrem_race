#include <iostream>
#include <string>
//#include <vector>
//#include <algorithm>
#include <cmath>


double euclidean_distance(int x, int y, int next_checkpoint_x, int next_checkpoint_y){
    double dist;
    int delta_x = next_checkpoint_x-x;
    int delta_y = next_checkpoint_y-y;
    dist = sqrt(delta_x*delta_x + delta_y*delta_y);
    return dist;
}

bool angle_cone(int next_checkpoint_angle, int angle){
    if(next_checkpoint_angle > angle or next_checkpoint_angle < -angle){
        return true;
    } else {
        return false;
    }
}

float get_speed(int x, int y, int last_x, int last_y){
    float spd = (float(x) - float(last_x)) / (float(y) - float(last_y));
    return spd;
}

float get_acceleration(float spd, float spd_old){
    float acc = spd - spd_old;
    return acc;
}

int main()
{
    // current and prev positions
    int x = 0, y = 0, last_x, last_y;

    std::string thrust; // stores thrust string because "BOOST" is a string and reduces type casting

    // checkpoint
    int next_checkpoint_x, next_checkpoint_y, next_checkpoint_dist, next_checkpoint_angle;
    // angle between your pod orientation and the direction of the next checkpoint

    // opponent info
    int opponent_x;
    int opponent_y;

    // derived stuff
    int boosts_left = 1;
    float dist;
    float spd;

    // game loop
#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
    while (1) {
        last_x = x;
        last_y = y;

        //get ship parameters
        std::cin >> x >> y >> next_checkpoint_x >> next_checkpoint_y >> next_checkpoint_dist >> next_checkpoint_angle;
        std::cin.ignore();

        //get enemy ship parameters
        std::cin >> opponent_x >> opponent_y;
        std::cin.ignore();

        dist = euclidean_distance(x, y, next_checkpoint_x, next_checkpoint_y);
        spd = euclidean_distance(x,y,last_x,last_y);
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        if (angle_cone(next_checkpoint_angle, 90)){
            thrust = "15";
        } else if (boosts_left > 0 and dist > 7000 and not angle_cone(next_checkpoint_angle, 15)){
            std::cerr << "distance: " << dist << ", using boost" << std::endl;
            thrust = "BOOST";
            boosts_left = 0;
        } else if(dist > 2500) {
            thrust = "100";
        } else {
            thrust = "45";
        }

        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"
        std::cerr << "dist: " << dist << "speed: " << spd <<  std::endl;
        std::cout << next_checkpoint_x << " " << next_checkpoint_y << " " << thrust << std::endl;

    }
#pragma clang diagnostic pop
}