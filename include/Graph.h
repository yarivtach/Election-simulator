#pragma once
#include <vector>
#include "Party.h"
#include "Graph.h"

using std::vector;

class Graph
{
public:
    Graph(vector<Party> vertices, vector<vector<int>> edges);
    int getMandates(int partyId) const;
    int getEdgeWeight(int v1, int v2) const;
    int getNumVertices() const;
    const Party &getParty(int partyId) const;
    Party &getPartyN(int partyId);
    const vector<Party> &getVertices() const;
    vector<Party> &getVerticesN();
    vector<int> getNeighbors(int PartyId) const;
    void OfferAParty(int partyId, int CoalId);
    bool AlreadyJoined(int PartyId) const;

private:
    vector<Party> mVertices;
    vector<vector<int>> mEdges;
};
