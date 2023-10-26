#include <bits/stdc++.h>
#define endll '\n'
using namespace std;

struct card {
    int val; string suit;
    card(int v, string s) : val(v), suit(s) {}
    bool operator< (const card &other) const{
        return val < other.val;
    }
};

unordered_map<char, int> um = {{'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}}, tmp;

int convert(string val){
    int num = atoi(val.c_str());
    if(num) return num;

    return um[val[0]];
}


bool is_flush(multiset<card> d){
    set<string> chk;
    for(auto x : d) chk.insert(x.suit);
    return (chk.size() == 1);
}


bool is_straight(multiset<card> d){
    int chkV = (*(d.begin())).val;
    for(auto x : d){
        if(x.val != chkV) return false;
        chkV++;
    }
    return true;
}

bool royalFlush(multiset<card> d){
    if(!is_flush(d)) return false;

    int chkV = 10;
    for(auto x : d){
        if(x.val != chkV) return false;
        chkV++;
    }
    return true;
}


bool is_kind(multiset<card> d, int chk){

    for(auto x : tmp) if(x.second == chk) return true;
    return false;
}

bool fullHouse(multiset<card> d){

    if(tmp.size() > 2) return false;
    bool chk2 = false, chk3 = false;
    for(auto x : tmp){
        if(x.second == 2) chk2 = true;
        if(x.second == 3) chk3 = true;
    }
    if(chk2 && chk3) return true;
    return false;

}

bool is_pair(multiset<card> deck, int chk){

    int cnt = 0;
    for(auto x : tmp) if(x.second == 2) cnt++;

    if(cnt == chk) return true;
    return false;
}


int main(){

    int n; scanf("%d", &n);
    multiset<card> deck;
    while(n--){
        for(int i=0; i<5; ++i){
            string suit, val;
            cin >> val >> suit;
            deck.insert(card(convert(val), suit));
        }

        for(auto x : deck) tmp[x.val] += 1;

        if(royalFlush(deck)) printf("Royal Flush\n");
        else if(is_straight(deck) && is_flush(deck)) printf("Straight Flush\n");
        else if(is_kind(deck, 4)) printf("Four Of A Kind\n");
        else if(fullHouse(deck)) printf("Full House\n");
        else if(is_flush(deck)) printf("Flush\n");
        else if(is_straight(deck)) printf("Straight\n");
        else if(is_kind(deck, 3)) printf("Three Of A Kind\n");
        else if(is_pair(deck, 2)) printf("Two Pair\n");
        else if(is_pair(deck, 1)) printf("One Pair\n");
        else printf("High Card\n");
        deck.clear();
        tmp.clear();
    }
    return 0;
}
/*
1
A diamond
2 club
3 diamond
4 spade
5 club
*/
