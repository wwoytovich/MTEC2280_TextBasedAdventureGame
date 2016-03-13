xvalues = int(input("Dungeon rows please: "))
yvalues = int(input("Dungeon Columns please: "))
dungeonPOS = [[0 for x in range(yvalues)] for x in range(xvalues)] 
print(dungeonPOS)

currentDungeon = dungeonPOS

def clearOldroom():
	currentDungeon = [[0 for x in range(yvalues)] for x in range(xvalues)] 

def roomNavGOD():
	room = input("what room do you want to go into? (x,y)")
	roomx = int(room[0])
	roomy = int(room[2])
	clearOldroom
	currentDungeon[roomx][roomy] = 1
	print("you are in the " + room[0] + "," + room[2] + "room")

roomNavGOD()
print(currentDungeon)





while #the current cell does not equal the end cell	
	find availabe
	from current cell 
		if right cell is free then go there
		elif go down
		elif go up
		elif go left
	add one to counter
if counter 	ends
	call re-random bad cells