#pragma once
#include <string>
#include "JoinPolicy.h"
#include "Agent.h"

using std::string;
using std::vector;

class Coalition;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); //constructor
    Party();//default constructor
    ~Party();// destructor
    Party(const Party& other);//copy constructor
    Party& operator=(const Party& other);
    Party& operator=(Party&& other);
    int getIterator();
    void nextIteration();
    int getId() const;
    State getState() const;
    int getMandates() const;
    void setState(State state);
    const string &getName() const;
    void NewOffer(int CoalitionId);
    void join(Coalition& C);// join to the specific coalition
    void OfferAParty(int CoalId);
    void step( Simulation &s);
    
private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int mIterator;
    vector<int> mWasOfferedVector;
};
