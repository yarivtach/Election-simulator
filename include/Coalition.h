#pragma once
#include <vector>

class Agent;
using std::vector;


class Coalition
{
public:

Coalition(int CoalitionId, int CoalVol, int PartyId);//constructor
Coalition();
~Coalition(); // Destructor
Coalition(const Coalition& other); // Copy Constructor
Coalition(Coalition&& other); // Move Constructor
Coalition& operator=(const Coalition& other); // Assignment Operator
Coalition& operator=(Coalition&& other); //Move Assignment Operator
int getCoalitionId();
void setCoalitionId(int Id);
int getCoalVolume();
vector<int> getCoalMembers() const;// return the party which is a coalition's member
void setCoalVolum(int toAdd);// add the mandates's party to the coalition
void setCoalMembers(int partyId);// add a member to a coalition
vector<int> getWasOfferedVector();// return the parties which got an offer from the coalition
void setWasOfferedVector(int PartyId);// add an offer which has done
void OfferAParty(int PartyId);
bool Alla_Beyadi() const;// return if the coalition get at least 61 mandates


private:
    int mCoalitionId;
    int mCoalVolume;
    vector<int> mCoalMembers;
    vector<int> mWasOfferedVector;
};