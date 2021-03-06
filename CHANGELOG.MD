Changelog
Project: Darksnakes
Team: Alan Eurich, Yannik Keller

Software used: CLion, Board of Symbols


### Alan Eurich

# 22-12-2017
- Created project
- Added implementation for BoS in CLion
- Added path for libraries
- Added function for drawing snakes onto the field
- Added logic and functions for the AI movement and their pathfinding
- Added function for updating the snakes 60 times per second

# 23-12-2017
- Added function for putting the 'food' item onto the field
- Added function for player movement and behaviour with walls and food
- Added function for the snake to become one field larger when it eats the food
- Added function for game over screen
- Added game properties such as player count, enemy count and difficulty
- Added function and logic to let the snake move around changing the last and the first field to the color it needs to be

# 9-1-2017
- Added input functions and logic
- Added random map placement for the player, enemies and food
- Added function for main menu

# 10-1-2018
- Changed 'textFarbe2' so it would fit the need of the project
- Added 'fontSize' so it can be accessed via code
- Changed 'loeschen()' so it would delete all text
- Changed 'loeschen()' so it would delete everything not only text
- Added menuInput logic
- Change 'sleep' function to sleep properly between frames reducing CPU consumption be ~25%
- Added cross platform sleeping function


# 11-1-2018
- Added acceptance for right and left arrow for convertToUpAndDown Input
- Fixed refresh rate of main menu
- Added missing arrows
- Deleted a whole bunch of unnessecary code added smoother and much less code
- Added logic for changing player count, enemy count and difficulty so the game would actually take the changes and start with it
- Deleted BoS made triangles and added better looking ones
- Animated 'You Died' text to become bigger over two seconds
- Changed board size back to 60*60
- Added timer until a new game is started when in game over screen
- Fixed minor errors and warnings

# 12-1-2018
- Fixed important error that did not let the game start on any other computer than Alan's


### Yannik Keller

# 10-1-2018
- Brought into project
- Added main menu design: color and text

# 11-1-2018
- Added main menu choosing options such as 'Start Game' or 'Difficulty'
- Added game over screen background and text
- Added triangles next to text to show that changes can be made forming an arrow
- Added function that deletes not more highlighted and not used triangles/arrows
- Fixed bug where the arrows were flashing 60times/s
- Added main menu logic for starting the game by pressing enter
- Fixed logic for triangles
- Deleted triangles made in BoS
- Designed game over screen: added color and text