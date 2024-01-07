#include "SelectionPolicy.h"
#include "Party.h"
#include "Graph.h"

SelectionPolicy::SelectionPolicy(){}
SelectionPolicy::~SelectionPolicy(){}


MandatesSelectionPolicy::MandatesSelectionPolicy(){} // Constructor
MandatesSelectionPolicy::~MandatesSelectionPolicy(){}

SelectionPolicy* MandatesSelectionPolicy::getType()
{
    return new MandatesSelectionPolicy();
}

bool MandatesSelectionPolicy:: WasOffered(int partyId, vector<int> &WasOfferedVector)
{
for (int n : WasOfferedVector)
    {
        if(n == partyId)
        {
            return true;
        }
    }
    return false;
}

   int MandatesSelectionPolicy::select(vector<int> &Offers, vector<int> &WasOfferedVector)
    {
        int size = Offers.size();
        while( size != 0 && WasOffered(Offers.at(0), WasOfferedVector))
        {
            Offers.erase(Offers.begin());
            size--;
        }
        if(size != 0)
        {
            int temp = Offers.at(0);
            Offers.erase(Offers.begin());
            size--;
            return temp;
        }
        return -1;
    }

vector<int> MandatesSelectionPolicy::buildChoose(const Graph& G, int PartyId)
{
    vector<int> ans = {};
    vector<int> Neighbors = G.getNeighbors(PartyId);
    int max = 0;
    int toAdd=-1;
    int size = Neighbors.size();
    for (int i = 0; i < size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(Neighbors[j] != 0)
            {
                if(Neighbors[j] > max)
                {
                    max = G.getVertices()[j].getMandates();
                    toAdd = j;
                }
            }
        }
        ans.push_back(toAdd);
        Neighbors[toAdd] = 0;
        max = 0;
    }
    return ans;
}

    //*******************************************************************************
    //*******************************************************************************

    
    EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy(){}; // Constructor
    EdgeWeightSelectionPolicy:: ~EdgeWeightSelectionPolicy(){}

    SelectionPolicy* EdgeWeightSelectionPolicy::getType()
    {
        return new EdgeWeightSelectionPolicy();
    }

    bool EdgeWeightSelectionPolicy:: WasOffered(int partyId, vector<int> &WasOfferedVector)
    {
    for (int n : WasOfferedVector)
        {
            if(n == partyId)
            {
                return true;
            }
        }
    return false;
    }

    int EdgeWeightSelectionPolicy:: select(vector<int> &Offers, vector<int> &WasOfferedVector)
    {
        int size = Offers.size();
        int temp = -1;
        while(size != 0 && WasOffered(Offers.at(0), WasOfferedVector))
        {
            Offers.erase(Offers.begin());
            size--;
        }
        if(size > 0)
        {
            temp = Offers.at(0);
            Offers.erase(Offers.begin());
            size--;
        }
        return temp;
    }

    vector<int> EdgeWeightSelectionPolicy::buildChoose(const Graph& G, int PartyId)
    {
        vector<int> ans = {};
        vector<int> Neighbors = G.getNeighbors(PartyId);
        int max = 0;
        int toAdd = -1;
        int size = Neighbors.size();
        for (int i = 0; i < size; i++)
        {
            for(int j=0; j < size; j++)
            {
                if(Neighbors[j] > max)
                {
                    max = Neighbors[j];
                    toAdd = j;
                }
            }
            if(max == 0)
            {
                break;
            }
            ans.push_back(toAdd);
            Neighbors[toAdd] = 0;
            max = 0;
        }
        return ans;
    }