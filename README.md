# CPP Game - story based adventure with slight RPG elements



### Operating system and Visual studio versions used to test and write the program:

##### OS: Windows 10 pro 10.0.19045 Build 19045
##### Visual studios: 2022 v143, windows SDK 10.0, 64x



### How does it play?

##### Player chooses their name and Race (No impact on gameplay), followed by story elements describing the world
##### and what is going on. for example the player is in the forest, infront is a mansion, to the right some sort
##### of creature. both are described, then the player chooses whether they would like to go towards the mansion
##### or creature. after each choice, extra story elements are given. player goes through this cycle till either 
##### the end or the player finds themselves in a battle situation ending in either victory or death.
##### input from player starts with string for the name, followed by choice in the form of integers
##### such as 1, 2, 3. each integers choice is shown on screen, telling the player what will happen
##### should they make the choice

![Screenshot](UML.png)



### Exception Handling

##### This application uses very simple exception handling. Aside from the name and race, only specific inputs are allowed.
##### The choices range from 1-4 in numeric value, and depending where the player is and how many options there are,
##### only those choices are allowed. For example go to mansion or towards the creature, plus exit, 3 choices
##### only inputs 0, 1, 2 are allowed, anything else gives the player an error message that the input is invalid.
##### the next area chosen could have, say, 0,1,2,3 choices, only those inputs will be allowed.
##### This is done with a while loop, using cin and the specific int set for said area for example
##### while (!(cin >> choice) || (choice < 0 || choice > 2)){
##### cout << "Invalid Input" << endl;
##### cin.clear();
##### cin.ignore(numeric_limits<streamsize>::max(), '\n');}
##### cin.ignore(numeric_limits<streamsize>::max(), '\n');



### Further details

##### this short game is mainly story based. you get story, you make choices on where to go, featuring 5 endings
##### with slight RPG elements such as a battle, and leveling. the player levels when defeating an enemy.
##### levels continue upon death should the player die from battle.


### USP

##### This is a short game, with minor RPG aspects, focussed on story and decision making. some decisions will improve the world
##### while others might make it worse.

##### [GitHub](https://github.com/KacperZmu/COMP3016)
##### [YouTube](https://www.youtube.com/watch?v=qr9d5a0s75I&ab_channel=Kacper)
