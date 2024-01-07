
#include "Agent.h"
#include <vector>
#include "Party.h"
#include "Simulation.h"
#include "Coalition.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy) ,mCoalitionId(agentId), mOffers({})
{
    // You can change the implementation of the constructor, but not the signature!


}

Agent::Agent():mAgentId() , mPartyId() , mSelectionPolicy() , mCoalitionId(), mOffers({}){}

Agent:: ~Agent() // Destructor
{
    if(mSelectionPolicy){delete mSelectionPolicy;}
}


Agent::Agent(const Agent& other): mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(nullptr), mCoalitionId(other.mCoalitionId), mOffers({})  // Copy Constructor
{
    mSelectionPolicy = other.mSelectionPolicy->getType();
    mOffers = other.mOffers;
}

Agent::Agent(const Agent& other ,const Graph &g , int agentId , int partyId): mAgentId(agentId) , mPartyId(partyId), mSelectionPolicy(nullptr), mCoalitionId(other.mCoalitionId), mOffers({})
{
    mSelectionPolicy = other.mSelectionPolicy->getType();
    mOffers = mSelectionPolicy->buildChoose(g , partyId);
}

Agent:: Agent(Agent &&other): mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(), mCoalitionId(other.mCoalitionId), mOffers(other.getOffers()) //Move Constructor
{
    mSelectionPolicy = other.mSelectionPolicy;
    other.mSelectionPolicy =nullptr;
}

Agent& Agent::operator=(const Agent& other) //Assignment Operator
{
    if(this != &other)
    {

        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy->getType();
        mOffers = other.mOffers;
        mCoalitionId = other.mCoalitionId;
    }
    return *this;
}

Agent& Agent:: operator=(Agent&& other) // Move Assignment Operator
{
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    mSelectionPolicy =other.mSelectionPolicy;
    mCoalitionId = other.mCoalitionId;
    other.mSelectionPolicy = nullptr;
    return *this;

}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

SelectionPolicy& Agent::getSelectionPolicy()
{
    return *mSelectionPolicy;
}

int Agent::getCoalitionId()
{
    return mCoalitionId;
}

void Agent:: setCoalitionId(int coalitionId)
{
    mCoalitionId = coalitionId;
}

vector<int> Agent:: getOffers()
{
    return mOffers;
}

void Agent::setOffers(vector<int> &Offers)
{
    mOffers = Offers;
}

void Agent:: step(Simulation &sim)
{
    // TODO: implement this method
    vector<int> offerCoalition = sim.getWasOfferedByCoalitionId(mCoalitionId);
    int nextOffer = mSelectionPolicy -> select(mOffers, offerCoalition);
    while(nextOffer != -1 && sim.getGraph().AlreadyJoined(nextOffer))
    {
        nextOffer = mSelectionPolicy -> select(mOffers, offerCoalition);
    }
    if(nextOffer != -1)
    {
        sim.OfferAParty(nextOffer, mCoalitionId);
        sim.getCoalitionById(mCoalitionId).OfferAParty(nextOffer);
    }
}


