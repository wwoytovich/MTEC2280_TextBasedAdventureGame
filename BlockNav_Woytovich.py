xvalues = int(input("Dungeon rows please: "))
yvalues = int(input("Dungeon Columns please: "))
dungeonPOS = [[0 for x in range(yvalues)] for x in range(xvalues)] 
print(dungeonPOS)

currentDungeon = dungeonPOS

def clearOldroom():
	currentDungeon = [[0 for x in range(yvalues)] for x in range(xvalues)] 

def roomNavGOD():
	global roomx
	global roomy
	room = input("what room do you want to go into? (x,y)")
	roomx = int(room[0])
	roomy = int(room[2])
	clearOldroom
	currentDungeon[roomx][roomy] = 1
	print("you are in the " + room[0] + "," + room[2] + "room")

roomNavGOD()
print(currentDungeon)


while (currentDungeon[xvalues - 1][yvalues - 1] != 1):
	askDir = input("Where would you like to go? [North, South, East, West]")
	print(askDir.lower())
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
		print("Your input was incorrect or invalid. Please try again")
		print("you are currently in the " + str(roomx) + "," + str(roomy) + "room") #comment out later probably
		continue
			
	print("you are in the " + str(roomx) + "," + str(roomy) + "room") #comment out later probably
