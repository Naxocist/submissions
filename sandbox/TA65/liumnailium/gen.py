import random as r

for i in range(1, 11) :
    n = r.randint(1, 2000);
    name = "";
    if(i != 10): name += "0";
    name += str(i) + ".in";
    f = open(name, "w");
    f.write(str(n) + "\n");
    f.close();
