import random as r

for i in range(1, 11) :
    name = "";
    if(i != 10) : name += "0";
    name += str(i) + ".in";
    f = open(name, "w");
    n = r.randint(1, 1000);
    m = r.randint(1, int(n/2));
    f.write(str(n) + " " + str(m) + "\n");
    f.close();

