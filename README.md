# milrem_race - gold 
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
