#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>
#include <cmath>

int main() {
    // Initialization input
    // Line 1: laps : the number of laps to complete the race.
    // Line 2: checkpointCount : the number of checkpoints in the circuit.
    int laps;
    int current_lap;
    int checkpoint_count;
    int checkpoint_id_one;
    int checkpoint_id_two;
    // coordinates of the checkpoints
    std::vector<std::vector<int>> checkpoints;

    /*
     * Input for one game turn
     * First 2 lines: Your two pods.
     * Next 2 lines: The opponent's pods.
     * Each pod is represented by: 6 integers,
         * x & y for the position.
         * vx & vy for the speed vector.
         * angle for the rotation angle in degrees.
         * nextCheckPointId for the number of the next checkpoint the pod must go through.
    */
    // Declaring my pods my_pod_one, my_pod_two, enemy pods as: enemy_pod_one, enemy_pod_two;
    std::vector<int> my_pod_one;
    std::vector<int> my_pod_two;
    std::vector<int> enemy_pod_one;
    std::vector<int> enemy_pod_two;
    // Vector of pods
    std::vector<std::vector<int>> pods = {my_pod_one, my_pod_two, enemy_pod_one, enemy_pod_two};

    // temp variables
    int i; // used for loops
    int cin_input; // pod loop
    std::vector<int> coordinates; // temp vector for inserting coordinates into coordinate vector

    // initialization input: laps, checkpoint_count, checkpoint coordinates
    std::cin >> laps >> checkpoint_count;
    i = 0;
    std::cerr << "laps: " << laps << ", checkpoint_count: " << checkpoint_count << std::endl;

    while (i < checkpoint_count){
        for (int j = 0; j < 2; j++){
            std::cin >> cin_input;
            coordinates.push_back(cin_input);
            std::cerr << "read coordinate: " << cin_input << std::endl;
        }
        std::cin.ignore();
        checkpoints.push_back(coordinates);
        coordinates.clear();
        i++;
    }
    // initialize pod vectors
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
    while (1) {
        // updating pod vectors - 6 input integers
        for (std::vector<int>& pod: pods) { // loop through every pod in pods
            i = 0;
            while (i < 6) { // i goes 0 to 5 because 6 integer variables get pushed into every vector
                std::cin >> cin_input;
                pod[i] = cin_input; // something wrong with this line
                i++;
            }
            std::cin.ignore();
        }

        // outputs
        checkpoint_id_one = pods[0][5];
        checkpoint_id_two = pods[1][5];
        // my pod 1
        std::cout << checkpoints[checkpoint_id_one][0] << " " << checkpoints[checkpoint_id_one][1] << " 100" << std::endl;
        // my pod 2
        std::cout << checkpoints[checkpoint_id_two][0] << " " << checkpoints[checkpoint_id_two][1] << " 100" << std::endl;

    }
// #pragma clang diagnostic pop
}