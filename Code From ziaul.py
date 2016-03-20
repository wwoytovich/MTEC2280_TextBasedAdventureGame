#emailed to me 3/19/2016 @ 5:40 pm 
# uploaded for ziaul because he was having issues getting it uploaded
import random

monsterX = ["Dragon", "slim", "golin", "ogre", "nekomata",  "ghost", "zombie"]
monsterZ = ["ghoul", "skeleton", "spider", "snake", "kobolt", "red boar"]


monsterXSize = len(teamA)
monsterZSize = len(teamX)

while(monsterXSize >= 0 or teamXSize >= 0):
    monsterXSize = len(teamA)
    monsterZSize = len(teamX)
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
        
      else:
      if("you meet monster");
      else:(fight or run)
      if(run)
      get away from the monsters
      if(fight)
      attack or guard monster
       
