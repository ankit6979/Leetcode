#include<bits/stdc++.h>
using namespace std;

class FoodRatings {
public:
    struct myCmp{
        constexpr bool operator()(pair<string, int> const& a, pair<string, int> const& b){
            if(a.second == b.second){
                if(a.first > b.first){
                    return true;
                }
                return false;
            }
            return a.second<b.second;
        }
    };

    map<string, int> dish_rating;
    map<string, string> dish_cuisine;
    typedef pair<string, int> pd;
    map<string, priority_queue<pd, vector<pd>, myCmp>> cuisines_dish_mp;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i<foods.size(); i++){
            this->dish_rating[foods[i]] = ratings[i];
            this->cuisines_dish_mp[cuisines[i]].push(make_pair(foods[i], ratings[i]));
            dish_cuisine[foods[i]] = cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        this->dish_rating[food] = newRating;
        this->cuisines_dish_mp[dish_cuisine[food]].push(make_pair(food, newRating));
    }
    
    string highestRated(string cuisine) {
        while(!cuisines_dish_mp[cuisine].empty()){
            pair<string, int> curr_food = cuisines_dish_mp[cuisine].top();
            if(curr_food.second == dish_rating[curr_food.first]){
                return curr_food.first;
            }
            cuisines_dish_mp[cuisine].pop();
        }
        return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */