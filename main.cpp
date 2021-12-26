#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>
#include <cmath>

int calculate_boost(int angle, int range){ // return range from 0 to 100 depending on relative angle, if at 90 degrees, boost = 0
    int boost = 0;
    if (angle > 90){
        return boost;
    } else {
        boost = (1 - angle/90)*100;
    }
    return boost;
}

int main() {
    // Initialization input
    // Line 1: laps : the number of laps to complete the race.
    // Line 2: checkpointCount : the number of checkpoints in the circuit.
    int laps;
    int current_lap;
    int checkpoint_count;
    int checkpoint_id_one;
    int checkpoint_id_two;
    int boost_one;
    int boost_two;
    int k;
    std::vector<std::vector<int>> checkpoints; // coordinates of the checkpoints

    // Declaring my pods my_pod_one, my_pod_two, enemy pods as: enemy_pod_one, enemy_pod_two;
    // indices & variables - 0 x, 1 y, 2 vx, 3 vy, 4 angle, 5 next checkpoint id
    std::vector<int> my_pod_one;
    std::vector<int> my_pod_two;
    std::vector<int> enemy_pod_one;
    std::vector<int> enemy_pod_two;
    std::vector<std::vector<int>> pods = {my_pod_one, my_pod_two, enemy_pod_one, enemy_pod_two};

    // temp variables
    int i; // used for loops
    int cin_input; // pod loop
    std::vector<int> coordinates; // temp vector for inserting coordinates into coordinate vector

    // initialization input: laps, checkpoint_count, checkpoint coordinates
    std::cin >> laps >> checkpoint_count;
    i = 0;
    std::cerr << "laps: " << laps << ", checkpoint_count: " << checkpoint_count << std::endl;

    // initialize the checkpoint coordinates vector
    while (i < checkpoint_count){
        for (int j = 0; j < 2; j++){
            std::cin >> cin_input;
            coordinates.push_back(cin_input);
        }
        std::cin.ignore();
        checkpoints.push_back(coordinates);
        coordinates.clear();
        i++;
    }

    // initialize pod vectors - default values 0 so i can insert by index later
    for (std::vector<int>& pod: pods){
        i = 0;
        while (i < 6) {
            pod.push_back(0);
            i++;
        }
    }

    // Game loop
#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
    while (true) {
        // updating pod vectors - 6 input integers
        for (std::vector<int>& pod: pods) { // loop through every pod in pods
            i = 0;
            while (i < 6) { // 6 integer variables per pod vector
                std::cin >> cin_input;
                pod[i] = cin_input; //
                i++;
            }
            std::cin.ignore();
        }

        // outputs
        checkpoint_id_one = pods[0][5];
        checkpoint_id_two = pods[1][5];
        boost_one = calculate_boost(pods[0][4], 0);
        boost_two = calculate_boost(pods[1][4], 0);
        k = 2;

        // my pod 1
        std::cout << checkpoints[checkpoint_id_one][0] - k*pods[0][2] << " " <<
                     checkpoints[checkpoint_id_one][1] - k*pods[0][3] << " " << boost_one << std::endl;
        // my pod 2
        std::cout << checkpoints[checkpoint_id_two][0] << " " << checkpoints[checkpoint_id_two][1] << " " << boost_two << std::endl;

    }
// #pragma clang diagnostic pop
}