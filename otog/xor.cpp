#include<iostream>
main(){unsigned long x,y;while(std::cin>>x>>y)std::cout<<((x|y)&(~x|~y))<<'\n';}