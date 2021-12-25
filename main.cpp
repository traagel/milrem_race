#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>
#include <cmath>

// Write an action using cout. DON'T FORGET THE "<< endl"
// To debug: cerr << "Debug messages..." << endl;

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

std::vector<int> get_x_y_velocity(int x, int y, int last_x, int last_y){
    int vel_x = x - last_x;
    int vel_y = y - last_y;
    std::vector <int> speed_vector = {vel_x, vel_y};
    return speed_vector;
}

float get_acceleration(float spd, float spd_old){
    float acc = spd - spd_old;
    return acc;
}

int main()
{
    // current and prev positions
    int x = 0, y = 0, last_x, last_y;
    bool first_round = true;

    std::string thrust; // stores thrust string because "BOOST" is a string and reduces type casting

    // checkpoint
    int next_checkpoint_x, next_checkpoint_y, next_checkpoint_dist, next_checkpoint_angle;
    // angle between your pod orientation and the direction of the next checkpoint

    // opponent info
    int opponent_x;
    int opponent_y;

    // derived stuff
    int boosts_left = 1;
    double checkpoint_distance;
    double velocity;

    int k; // drift adjustment constant k
    std::vector<int> vel_xy_vect;
    int target_x; // recalculated x value
    int target_y; // recalculated y value

    // game loop
#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
    while (1) {
        last_x = x;
        last_y = y;

        //get ship parameters
        std::cin >> x >> y >> next_checkpoint_x >> next_checkpoint_y >> next_checkpoint_dist >> next_checkpoint_angle;
        std::cin.ignore();

        // first round x y fix ? need more elegant solution later ..
        if (first_round){
            last_x = x;
            last_y = y;
            first_round = false;
        }

        //get enemy ship parameters
        std::cin >> opponent_x >> opponent_y;
        std::cin.ignore();

        checkpoint_distance = euclidean_distance(x, y, next_checkpoint_x, next_checkpoint_y);
        velocity = euclidean_distance(x,y,last_x,last_y);

        // calculate thrust
        if (angle_cone(next_checkpoint_angle, 90)){
            thrust = "15";
        } else if (boosts_left > 0 and checkpoint_distance > 7000 and not angle_cone(next_checkpoint_angle, 15)){
            std::cerr << "distance: " << checkpoint_distance << ", using boost" << std::endl;
            thrust = "BOOST";
            boosts_left = 0;
        } else if(checkpoint_distance > 2500) {
            thrust = "100";
        } else {
            thrust = "45";
        }

        //adjust for drift, some constant * x / y speed in opposite direction
        vel_xy_vect = get_x_y_velocity(x, y, last_x, last_y);
        k = 2; //starting from 2
        target_x = next_checkpoint_x - k*vel_xy_vect[0];
        target_y = next_checkpoint_y - k*vel_xy_vect[1];

        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"
        std::cerr << "calc dist: " << checkpoint_distance << std::endl;
        std::cerr << "input dist: " << next_checkpoint_dist << std::endl;
        std::cerr << "speed: " << velocity <<  std::endl;
        std::cerr << "checkpoint x: " << next_checkpoint_x << ", y:" << next_checkpoint_y << std::endl;
        std::cerr << "adjusted x: " << target_x << ", y:" << target_y << std::endl;
        // x, y, last_x, last_y
        std::cerr << "x:" << x << std::endl;
        std::cerr << "y:" << y << std::endl;
        std::cerr << "last_x:" << last_x << std::endl;
        std::cerr << "last_y:" << last_y << std::endl;

        //
        std::cerr << "vel x: " << vel_xy_vect[0] << std::endl;
        std::cerr << "vel y: " << vel_xy_vect[1] << std::endl;
        std::cout << target_x << " " << target_y << " " << thrust << std::endl;

    }
#pragma clang diagnostic pop
}