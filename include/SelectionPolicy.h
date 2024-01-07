#pragma once
#include <vector>
using std::vector;

class Graph;
class Party;

class SelectionPolicy {

    public:
        SelectionPolicy();
        virtual ~SelectionPolicy();
        virtual SelectionPolicy* getType() = 0;
        virtual bool WasOffered(int partyId, vector<int> &WasOfferedVector) = 0;
        virtual int select(vector<int> &Offers, vector<int> &WasOfferedVector) = 0;
        virtual vector<int> buildChoose(const Graph& G, int PartyId) = 0;
};

class MandatesSelectionPolicy: public SelectionPolicy
{ 

    public:
        MandatesSelectionPolicy();//default constructor
        virtual ~MandatesSelectionPolicy();
        virtual SelectionPolicy* getType();
        virtual bool WasOffered(int partyId, vector<int> &WasOfferedVector);
        virtual int select(vector<int> &Offers, vector<int> &WasOfferedVector);
        virtual vector<int> buildChoose(const Graph& G, int PartyId);
};
class EdgeWeightSelectionPolicy: public SelectionPolicy
{ 

    public:
        EdgeWeightSelectionPolicy();//default constructor
        virtual ~EdgeWeightSelectionPolicy();
        virtual SelectionPolicy* getType();
        virtual bool WasOffered(int partyId, vector<int> &WasOfferedVector);
        virtual int select(vector<int> &Offers, vector<int> &WasOfferedVector);
        virtual vector<int> buildChoose(const Graph& G, int PartyId);


};
