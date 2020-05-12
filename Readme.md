# Final Project
## Text based adventure

As a heads up- I kept running into a problem with the program not wanting to run on the first try and then running again, 
with no changes to the code. It was also giving me a wierd error code that I can't remember located in a file I didn't make.
I suspect it has something to do with Visual studio or my computer. Just in case though,
it usually works on the second try of running the program. 


This is my Text based adventure game

Available commands
During a battle you will be prompted for what you would like to do, currently you can:
-attack           (deals damage to enemy)
-run              (25% chance to escape from enemy, losing you the combat reward but instanly ending the battle)
-inventory        (Shows you your inventory of usable Items, does not use up turn action)
-use [item]       (uses [item], does use turn action)

After combat you will be promted to pick a path, this leads to your next battle
-simply type 1 , 2 , or 3 to chose which path you would like to go down

Current Features:

3 encounters each with a separate enemy to fight
-Goblins(goblins)
-Coloseum(goliath and shoulder goblin)
-Forrest(assassin)

3 items
-Bandage(heals 15hp)
-Sword(adds 1 to player damage)
-Shield(adds 1 to player defense)


Currently using an item does not remove it from your inventory list. It is however removed from your inventory, so any item
you have used cannot be used again. This can be decieving when you type inventory and recieve a list of items you may or may
not have. In the furture, I will spend more time on figuring out how to remove specific parts of a vector or change what I 
am using for my inventory. For now though It works just not perfectly. 

As a heads up, the forest is deadly and statistically imposible at the begging of the game. I would recomend starting with
the coloseum and using the shield obtained from there in a goblin fight to boost defense while obataining a bandage.

The one downside to the game is that only 1 strategy is realistically viable and it quickly outpaces the fights as you get further 
into the game. Fixing this is relatively easy as I just need to add more enemies. As it is, my goal for this project  
was to prove my current level of proficiency and not my game balancing skills(Nonexistant). In the future, I will 
spend more time on balancing and extra features. 