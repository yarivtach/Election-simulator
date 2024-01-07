#include "Simulation.h"
#include "Agent.h"
#include "Party.h"
#include "Graph.h"
#include "Coalition.h"
#include "SelectionPolicy.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) , mCoalitionVector()
{
    // You can change the implementation of the constructor, but not the signature!
    for(Agent &A : mAgents)
    {
        int PartyId = A.getPartyId();
        int PartyMandate = mGraph.getMandates(PartyId);
        mCoalitionVector.push_back(Coalition(A.getId(), PartyMandate, PartyId));
        vector<int> Offers = A.getSelectionPolicy().buildChoose(mGraph,PartyId);
        A.setOffers(Offers);
    }

}

void Simulation::step()
{
    // TODO: implement this method
    for(Party &p : mGraph.getVerticesN())
    {
        p.step(*this);
    }
    for(Agent &a : mAgents)
    {
        a.step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    // TODO implement this method
     for(const Coalition &C : mCoalitionVector)
     {
         if(C.Alla_Beyadi())
         {
             return true;
         }
     }
    for(const Party &p : mGraph.getVertices())
    {
        if(p.getState() != Joined)
        {
            return false;
        }
    }
    return true;
}


const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

vector<Agent> Simulation::getAgentsN()
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

vector<int> Simulation:: getWasOfferedByCoalitionId(int CoalitionId)
{
    vector<int> WOBC;
    for (Coalition &c: mCoalitionVector)
    {
        if(CoalitionId == c.getCoalitionId())
        {
            return c.getWasOfferedVector();
        }
    }
    return WOBC;
}

void Simulation::DuplicateAgent( Agent &original, int PartyId)
{
    Agent copy = Agent(original , mGraph , mAgents.size() , PartyId);
    copy.setCoalitionId(original.getCoalitionId());
    mAgents.push_back(copy);
}

vector<Coalition>& Simulation:: getCoalitionVector()
{
    return mCoalitionVector;
}

Coalition &Simulation::getCoalitionById(int CoalId)
{
    return mCoalitionVector[CoalId];
}

void Simulation::OfferAParty(int partyId, int CoalId)
{
    mGraph.OfferAParty(partyId, CoalId);
}

int Simulation::getCoalitionByAgent(int agntId)
{
    for(Agent &a: mAgents)
    {
        if(a.getId() == agntId)
        {
           return a.getCoalitionId(); // return coalition and the func should return int
        }
    }
    return -1;
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    vector<vector<int>> ans;
    for(const Coalition &C: mCoalitionVector)
    {
        ans.push_back(C.getCoalMembers());
    }
    return ans;
}
