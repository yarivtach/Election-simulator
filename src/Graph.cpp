#include "Graph.h"
#include "Party.h"

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
{
    // You can change the implementation of the constructor, but not the signature!
}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}

const vector<Party> &Graph::getVertices() const
{
    return mVertices;
}

vector<Party> &Graph::getVerticesN() 
{
    return mVertices;
}

vector<int> Graph::getNeighbors(int PartyId) const 
{
    return mEdges[PartyId];   
}

Party& Graph::getPartyN(int partyId)
{
    return mVertices[partyId];
}

bool Graph::AlreadyJoined(int PartyId) const
{
    if(mVertices[PartyId].getState() == Joined)
        {
            return true;
        }
    return false;
}

void Graph::OfferAParty(int partyId, int CoalId) 
{
    mVertices[partyId].OfferAParty(CoalId);
}

