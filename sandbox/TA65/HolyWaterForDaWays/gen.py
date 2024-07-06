import random as r

for i in range(1, 6) :
    name = "";
    if(i != 10): name += "0";
    name += str(i) + ".in";
    f = open(name, "w");
    n = r.randint(2, 1000);
    f.write(str(n) + "\n");
    for j in range(n) :
        e = r.randint(1, 1e5);
        f.write(str(e));
        if(j != n-1) : f.write(" ");
    
    f.close();
