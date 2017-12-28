import json 
fp = open("C:\\Python27\\db2.json", "r")
data = json.load(fp)
fp.close()

#strength = map(int,raw_input().split())
ap = 2

readData = open("C:\\xampp\\htdocs\\project\\data.json", "r")
strength = json.load(readData)
"""
for i in range (0, ap):
    strength[i] = 
    x = readData.read(4)
    x = x[1:-1]
    y = int(readData.read(3))
    print y

    #print(y)
    strength[x] = abs(y)

readData.close()
"""
#print(strength)
#print(data)
    
    
   
def avg(x):
    return sum(x)/len(x)

def findRoom():
    global data, strength
    minimum = 999
    naam = ""
    room = ""
    for i in range (len(data)):
        k = list(data.values())[i]
        #print (k,strength)
        #total = abs(strength[0] - avg(k.values()[0]))+abs(strength[1] - avg(k.values()[1]))
        val = {}
        total = 0
        for j in (strength.keys()):
            #val[j] = 
            total += abs(strength[j]-avg(k[j]))
            
        if total<minimum:
            minimum = total
            room = list(data.keys())[i]
            """if (abs(strength[0] - avg(k.values()[0]))<abs(strength[1] - avg(k.values()[1]))):
                naam = k.keys()[0]
            else:
                naam = k.keys()[1] """
            
    #data[room].values()[0].append(strength[0])
    #data[room].values()[1].append(strength[1])
    for j in (strength.keys()):
        k = dict (data[room].items())
        k[j].append(strength[j])
            
    #print naam #, room
    print (room)
    """
    print ("Do you want to store values in database?")
    c = raw_input()
    if(c=='y'):
        fp = open("db2.json", "w")
        json.dump(data, fp)
        fp.close()
    #data[naam][room]
    """
findRoom()
input()



#etc3=80 etc5=70 [[63 2 ][93 22]]  [[3 27][33 47]]
#[:3]
#dist = []
#allVals = []
##for i in range (len(data)):
##    for j in range(2):
##        val = abs(strength[j] - data[i][j])
##        #dist.append()
##        if(val<minimum) :
##            minimum = val
##            naam = data[i]
##        
##print(min(dist))
            
    #temp = []
    #temp.append(abs(strength[0] - k.values()[0]))
    #temp.append(abs(strength[1] - k.values()[1]))
    #allVals.append(temp)
    
##for i in allVals:
##     val = abs()
##        #dist.append()
##        if(val<minimum) :
##            minimum[j] = val
##            naam = k.keys()[j]


##data = {"robo": {
##            "ETC3": [85, 90] , "ETC5": [55]},
##	"218":	{
##	    "ETC3": 87 , "ETC5": 58}, 
##        "222":	{
##	    "ETC3": 89 , "ETC5": 35}}
'''
import json 
fp = open("C:\\Python27\\db2.json", "r")
data = json.load(fp)
fp.close()

#strength = map(int,raw_input().split())
ap = 2

readData = open("C:\\xampp\\htdocs\\project\\data.json", "r")
strength = {}

for i in range (0, ap):
    
    x = readData.read(5)
    x = x[1:-1]
    y = int(readData.read(3))
    print (y)

    #print(y)
    strength[x] = abs(y)

readData.close()

#print(strength)
#print(data)
    
    
   
def avg(x):
    return sum(x)/len(x)

def findRoom():
    global data, strength
    minimum = 999
    naam = ""
    room = ""
    for i in range (len(data)):
        k = data.values()[i]
        #print k
        #total = abs(strength[0] - avg(k.values()[0]))+abs(strength[1] - avg(k.values()[1]))
        val = {}
        total = 0
        for j in (strength.keys()):
            #val[j] = 
            total += abs(strength[j]-avg(k[j]))
            
        if total<minimum:
            minimum = total
            room = data.keys()[i]
            """if (abs(strength[0] - avg(k.values()[0]))<abs(strength[1] - avg(k.values()[1]))):
                naam = k.keys()[0]
            else:
                naam = k.keys()[1] """
            
    #data[room].values()[0].append(strength[0])
    #data[room].values()[1].append(strength[1])
    for j in (strength.keys()):
        k = dict (data[room].items())
        k[j].append(strength[j])
            
    #print naam #, room
    print (room)
    """
    print ("Do you want to store values in database?")
    c = raw_input()
    if(c=='y'):
        fp = open("db.json", "w")
        json.dump(data, fp)
        fp.close()
    #data[naam][room]
    """
findRoom()


'''
