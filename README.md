# milrem_race - bronze to gold 
milrem, coders-strike-back, bronze -> gold


### About:

https://www.codingame.com/multiplayer/bot-programming/coders-strike-back

	This puzzle game starts with a step by step tutorial that will help 
	you get familiar with CodinGame’s multiplayer games. 
	It provides an easy introduction to bot programming through a starship race.

	The aim of the game is of course to win the race against other players! 
	To succeed in this challenge, 
	you will be able to use different mathematical concepts such as 
	trajectory calculation, collisions, speed vector, or inertia.

	The game is very simple to start. 
	Rules are easy to understand and it only requires a few lines of code to move your ship around.

	However, it has near-infinite possibilities of evolution as you can improve your artificial intelligence step by step, while sharpening your coding skills.

### Rules:

	The game is played on a map 16000 units wide and 9000 units high. The coordinate X=0, Y=0 is the top left pixel.

	The checkpoints work as follows:

		The checkpoints are circular, with a radius of 600 units.
		The disposition of the checkpoints is selected randomly for each race.

	The pods work as follows:

		If none of your pods make it to their next checkpoint in under 100 turns, you are eliminated and lose the game.
		The pods may move normally outside the game area.


	Note: You may activate debug mode in the settings panel () to view additional game data.
	
### Goals:

	Achieve as high rank as possible
	Use c++
	Document features/progress
	
### Running updates:

#### 12. 25. 2021 - Beat bronze! 
Using drift calculations, successfully beat bronze league



### Bronze features/logic:

Current logic pseudocode:

	If angle > 90 (+ or-): 
	  thrust 15
	elif boosts_left > 0 and distance > 7000 and angle cone within 15(+ or -):
	  use BOOST, boosts_left = 0 // boosts always start at 1 but > is more general than == ? for later updates
	  print distance and using boost
	elif distance > 2500:
	  thrust = 100
	else:
	  thrust = 45
 
 ### Existing functions:
 
	get_speed
	get_acceleration
 
### Current logic path:

![Alt text](doc/images/3_radius_inertia.png?raw=true "3 current pathing types")

### Current todo:
 
	 empirically measure max speed, max acceleration (+ and -)
	 
	 shift direction to avoid drifting
 
 #### Plan for measurements:
 	
 	Create square path within boundaries x=(0 .. 16000) y= (0.. 9000)
	
	
![Alt text](doc/images/4_spd_acc_measure.png?raw=true "box for acc/speed")

Measure velocity (euclidean distance between two points) and acceleration (change in velocity), find either 0 for acc or max velocity


#### Plan for drifting (edit2: works! bronze -> silver -> gold!!)

Add the negative x or y velocity vector to target, with some constant k (starting from 2)

![Alt text](doc/images/5_drift_adjustment.png?raw=true "box for acc/speed")

## Reached gold with simply drift correction and aimed acceleration!

#### New rules

The game is played on a map 16000 units wide and 9000 units high. The coordinate X=0, Y=0 is the top left pixel.

The checkpoints work as follows:

    The checkpoints are circular, with a radius of 600 units.
    Checkpoints are numbered from 0 to N where 0 is the start and N-1 is the last checkpoint.
    The disposition of the checkpoints is selected randomly for each race.

The pods work as follows:

    To pass a checkpoint, the center of a pod must be inside the radius of the checkpoint.
    To move a pod, you must print a target destination point followed by a thrust value. Details of the protocol can be found further down.
    The thrust value of a pod is its acceleration and must be between 0 and 100.
    The pod will pivot to face the destination point by a maximum of 18 degrees per turn and will then accelerate in that direction.
    You can use 1 acceleration boost in the race, you only need to replace the thrust value by the BOOST keyword.
    You may activate a pod's shields with the SHIELD command instead of accelerating. This will give the pod much more weight if it collides with another. However, the pod will not be able to accelerate for the next 3 turns.
    The pods have a circular force-field around their center, with a radius of 400 units, which activates in case of collisions with other pods.
    The pods may move normally outside the game area.
    If none of your pods make it to their next checkpoint in under 100 turns, you are eliminated and lose the game. Only one pod need to complete the race.


## Expert Rules
On each turn the pods movements are computed this way:

    Rotation: the pod rotates to face the target point, with a maximum of 18 degrees (except for the 1rst round).
    Acceleration: the pod's facing vector is multiplied by the given thrust value. The result is added to the current speed vector.
    Movement: The speed vector is added to the position of the pod. If a collision would occur at this point, the pods rebound off each other.
    Friction: the current speed vector of each pod is multiplied by 0.85
    The speed's values are truncated and the position's values are rounded to the nearest integer.

	Collisions are elastic. The minimum impulse of a collision is 120.
	A boost is in fact an acceleration of 650. The number of boost available is common between pods. If no boost is available, the maximum thrust is used.
	A shield multiplies the Pod mass by 10.
	The provided angle is absolute. 0° means facing EAST while 90° means facing SOUTH.
	
## The program must first read the initialization data from standard input. Then, within an infinite loop, read the contextual data from the standard input and provide to the standard output the desired instructions.

##   Game Input
### Initialization input
	Line 1: laps : the number of laps to complete the race.
	Line 2: checkpointCount : the number of checkpoints in the circuit.
### Next checkpointCount lines : 
	2 integers checkpointX , checkpointY for the coordinates of checkpoint.
### Input for one game turn
	First 2 lines: Your two pods.
	Next 2 lines: The opponent's pods.
	Each pod is represented by: 6 integers, x & y for the position. vx & vy for the speed vector. 
	angle for the rotation angle in degrees. 
	nextCheckPointId for the number of the next checkpoint the pod must go through.

### Output for one game turn
	Two lines: 2 integers for the target coordinates of your pod followed by thrust , the acceleration to give your pod, 
	or by SHIELD to activate the shields, or by BOOST for an acceleration burst. One line per pod.
	
#### Constraints
	0 ≤ thrust ≤ 100
	2 ≤ checkpointCount ≤ 8
	Response time first turn ≤ 1000ms
	Response time per turn ≤ 75ms

