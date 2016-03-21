import random

monsterX = ["Dragon", "slim", "golin", "ogre", "nekomata",  "ghost", "zombie"]
monsterZ = ["ghoul", "skeleton", "spider", "snake", "kobolt", "red boar"]


monsterXSize = len(monsterX)
monsterZSize = len(monsterZ)

while(monsterXSize >= 0 or monsterZSize >= 0):
    monsterXSize = len(monsterX)
    monsterZSize = len(monsterZ)
    #print("monsterX " + str(monsterXSize))
    #print("monsterZ " + str(MonsterZSize))
    if (monsterXSize > 0 and monsterZSize > 0):
        currentX = random.randrange(monsterXSize)
        currentZ = random.randrange(monsterZSize)
        print(monsterX[currentX] + " " + monsterZ[currentZ])
        print()
        monsterX.pop(currentX)
        monsterZ.pop(currentZ)
    else:
        if(monsterXSize >= 1):
            print(monsterX)

        if(monsterZSize >= 1):
            print(monsterZ)
        break
        
     
Dragon    hp:100
slim    hp:5
golin    hp:10
ogre    hp:80
nekomata    hp:60
ghost    hp:15
zombie    hp:25
ghoul    hp:45
skeleton    hp:35
spider    hp:20
snake    hp:30
kobolt     hp:40
red boar    Hp:50

