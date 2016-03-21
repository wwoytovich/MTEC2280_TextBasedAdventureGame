# The story so far is that you have woken up in a dungeon
# you no nothing other than that you are a simple man and want to go home
# at home you have internet, tv, and your bed.
# you notice next to you a scrap from your favoite blanket
# this enrages you.
# now you want the blood of your enemys and to get a good nights rest

#imports
import random

#initalize dungeon forced
xvalues =  4 #int(input("Dungeon rows please: "))
yvalues =  4 #int(input("Dungeon Columns please: "))
dungeonPOS = [[0 for x in range(yvalues)] for x in range(xvalues)] 
#print(dungeonPOS)
roomx = 1
roomy = 1
currentDungeon = dungeonPOS
def clearOldroom():
	currentDungeon = [[0 for x in range(yvalues)] for x in range(xvalues)] 


# ////////////////////////////
#// this is code to go into any room at all
#/////////////////////////////
# def roomNavGOD():
	# global roomx
	# global roomy
	# room = input("what room do you want to go into? (x,y)")
	# roomx = int(room[0])
	# roomy = int(room[2])
	# clearOldroom
	# currentDungeon[roomx][roomy] = 1
	# print("you are in the " + room[0] + "," + room[2] + "room")
# roomNavGOD()
# print(currentDungeon)
#/////////////////////////////////////////////////////

# Get a monster
def scary():
	monsterX = ["Dragon", "slim", "golin", "ogre", "nekomata",  "ghost", "zombie"]
	monsterZ = ["ghoul", "skeleton", "spider", "snake", "kobolt", "red boar"]
	monsterXSize = len(monsterX)
	monsterZSize = len(monsterZ)
	currentX = random.randrange(monsterXSize)
	currentZ = random.randrange(monsterZSize)
	return monsterX[currentX] + "-" + monsterZ[currentZ]



#randomgenerator input probability
def randProb(prob):
	number = random.randint(0,99)
	if prob > number:
		return 0
	else:
		return 1		
#random probability
def randProbRand():
	probs = random.randint(0,99)
	guess = random.randint(0,99)
	if guess < probs:
		return 1
	else:
		return 0
		
		
#take damgage code
def takeDam():
	global pLife
	pLife -= random.randint(20,45)
	
	
#trap room
def trapRoom():
	global pLife
	tmp = input("You see a box on the ground, do you open it? ")
	if tmp.lower() == "yes":
		if randProb(20):
			print("Its a trap! You took damage")
			takeDam()
			print("You have " + str(pLife) +" health")
			if (pLife <= 0):
				print("you are dead. goodbye!")
				exit()
		else:
			print("There was a health in the box! +20 hp")
			pLife += 20
			print("You have " + str(pLife) +" health")
	else:
		print("You decided to not risk it....")
			
#monster encounter option
def monster():
	global pLife
	themunsters = True
	while themunsters:
		print("A monster steps out of the dark...")
		print("As it grows closer you can see its a " + scary())
		danger = input("What do you decide to do? [Run, Battle, Freeze (and hope it doenst see you)] ")
		if danger.lower() == "run":
			if randProb(80) == 1:
				print("You escaped")
				break
			else:
				tmp2 =  random.randint(0,50)
				pLife -= tmp2
				print("You took " + str(tmp2) + " damage while escaping")
				if (pLife <= 0):
					print("Unfortunately you died in the process...")
					print("you are dead. goodbye!")
					exit()
				break			
		elif danger.lower() == "battle":
			takeDam()
			print("Poor figting mechanics let you defeat the monster, but you were hurt")
			if (pLife <= 0):
				print("Unfortunately you died in the process...\n")
				print("you are dead. goodbye!\n\n")
				exit()
			print("You have " + str(pLife) +" health left over")
			break
		elif danger.lower() == "freeze":
			print("You freeze in place, holding your breath")
			input("Keep waiting?")
			if randProbRand() == 1:
				print("Holy shit! it worked")
				break
			else:
				print("It didnt work! You got hit")
				pLife -= random.randint(5,25)
				if (pLife <= 0):
					print("Unfortunately you died in the process...")
					print("you are dead. goodbye!")
					exit()
				print("You have " + str(pLife) +" health left over")
				break
		else:
			print("\nWhat? I didnt catch that.\n")
			continue
			
#the free roomm
def free():
	print("You enter a dimly lit room, you see a figure in the distance but cannot be sure that its real.")
#the health room
def healthUp():
	global pLife
	print("You stumble over the lip of the doorway.")
	print("You notice the room is an abandonded medical bay.")
	print("You walk over to the tables and see the mangled corpses.")
	print("Stepping back you fall on your ass and notice a needle that says \"+20 hp\" but it looks a little used... ")
	print("Deciding that its worth it to take the risk of long term disease you inject the contents into your thigh.")
	print("You gained some health!")
	pLife += random.randint(3,20)
	print("You have " + str(pLife) +" health left over")
#enocounter
def encounter():
	tmp = random.randint(0,102)
	if tmp < 10: #10 percetn
		healthUp()
	elif tmp >= 10 and tmp < 30: #20 percent
		free()
	elif tmp >= 30 and tmp < 70: # 40 percent
		monster()
	elif tmp >= 70 and tmp < 100: # 30 percnet
		trapRoom()
	elif 100 >= 103 and tmp < 103:
		print("You see a man on the ground begging for help. He offers to give you a great reward if you take him out of \nthe dungeon with you but as you agree a door shuts from behind you and when you turn back to him he is gone.")
		
	else:
		free()	
#initialize status of player interaction things, such as health, damage and level for begining of game
level = 1
pLife = 100


#place intro/story elements here




while level < 6 or pLife <= 0:	
	# this is code that allows you to go into a different room
	while (currentDungeon[xvalues - 1][yvalues - 1] != 1):
		askDir = input("\nWhere would you like to go? [North, South, East, West]\n")
		#print(askDir.lower())
		if askDir == "east" and (roomx + 1) <= (xvalues - 1):
			roomx = roomx + 1
			clearOldroom
			currentDungeon[roomx][roomy] = 1
		elif (((roomx - 1) > -1 ) and (askDir.lower() == "west")):
			roomx = roomx - 1
			clearOldroom
			currentDungeon[roomx][roomy] = 1
		elif ((askDir.lower() == "north") and ((roomy + 1) <= (yvalues - 1))):
			roomy = roomy + 1
			clearOldroom
			currentDungeon[roomx][roomy] = 1
		elif (((roomy - 1) > -1 ) and (askDir.lower() == "south")):
			roomy = roomy - 1
			clearOldroom
			currentDungeon[roomx][roomy] = 1
		else:
			print("\nThats not a way you can go! Try that again.")
			# print("You are currently in the " + str(roomx) + "," + str(roomy) + "room") #comment out later probably
			continue
		#print("you are in the " + str(roomx) + "," + str(roomy) + " room") #comment out later probably
		print("Health: " + str(pLife) + "\n")
		encounter()
	print("You go down a staircase to be troubled with the site of another maze of rooms and met with a sign painted in blood that reads \"Level"+ str(level) + "\" completed")
	xvalues *= 2
	yvalues *= 2
	dungeonPOS = [[0 for x in range(yvalues)] for x in range(xvalues)] 
	roomx = 1
	roomy = 1
	currentDungeon = dungeonPOS
	level += 1
	if level == 6:
		print("Finally stumbling past the last door you make it to the exit. Finally you don't have to play this game again!")
print("Your score is " + str(pLife * level))
print("You got to level number " + str(level))
print("with " + str(pLife) + " left")

	
	
	
	
	
	
	
	
	
	
	
