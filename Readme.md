Endless Runner

This my endless runner where you try to dodge incomming obstacles.

My binary is under the shipping version Windows 10 package under Releases tab as a ZIP

Part 1:

In this first pass of the endless runner game, I have achieved a loose coupling of the classes by making the classes weakly assiciated with each other. So changes in one class does not effect the performance of the other.

The Classes I have used here are:

Ground Base Class: 
Just a simple class that constanly moves in backwards direction. They also spawn a ObstacleClass, if they are assigned one, at the start of their lifespawn. After the Player reaches a certain point, trigger if you will, they will destroy themselfs and, if any, the children that are attached to them.

Obstacle Class:
And obstacle just damages the player if they contact them 

Ground Spawner:
Spawns a ground on start, and when last spawn reaches up to certain distance, in this case it's the size of the ground, they will spawn another.

Runner Character:
Handles the left and right inputs of the player. A spring arm is attached to the player and to that a camera is attached;

HealthComponent:
Handles the health related stuff of the player, player has 3 healths and when they connect with a box, they will lose one. After a health loss event happens, player will go into a grace period where they cannot take any damage. And if their health reaches 0 They will let the GameMode that player is dead.

EndlessRunnerGameModeBase Class:
Will get notified when the player died. When this happens it will create a widget in the blueprint side to notify the player that tthey are dead and will restart the level after a certain time