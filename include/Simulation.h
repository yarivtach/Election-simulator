#pragma once
#include <vector>
#include "Graph.h"
#include "Agent.h"
#include "Coalition.h"

using std::string;
using std::vector;

class Party;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);
    void step();
    bool shouldTerminate() const;
    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    vector<Agent> getAgentsN();
    const Party &getParty(int partyId) const;
    vector<int> getWasOfferedByCoalitionId(int CoalitionId);
    void DuplicateAgent( Agent &original, int PartyId);
    vector<Coalition>& getCoalitionVector();
    Coalition &getCoalitionById(int CoalId);
    void OfferAParty(int partyId, int CoalId);
    int getCoalitionByAgent(int agntId); 
    vector<Party> getVertices();
    const vector<vector<int>> getPartiesByCoalitions() const;

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<Coalition> mCoalitionVector;
};
