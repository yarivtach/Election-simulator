#pragma once
#include "SelectionPolicy.h"

class Simulation;
class Party;
class Coalition;

using std::vector;


class Agent
{
public:

    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);//constructor
    Agent();//default constructor
    ~Agent();// destructor
    Agent(const Agent& other);//copy constructor
    Agent(Agent &&other);// move copy constructor
    Agent(const Agent& other ,const Graph &g , int agentId , int partyId);
    Agent& operator=(const Agent& other);//assignment oppertor
    Agent& operator=(Agent&& other);//move assignment operator
    int getId() const; // get the agent id
    int getPartyId() const;
    SelectionPolicy &getSelectionPolicy();
    int getCoalitionId(); 
    void setCoalitionId(int coalitionId);
    vector<int> getOffers();
    void setOffers(vector<int> &Offers);
    void step(Simulation &sim);
    
private:
    
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int mCoalitionId;
    vector<int> mOffers; 
};
