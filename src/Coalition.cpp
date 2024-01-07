#include "Coalition.h"
#include <vector>
#include "Agent.h"

Coalition::Coalition(int CoalitionId, int CoalVol, int PartyId): mCoalitionId(CoalitionId), mCoalVolume(CoalVol), mCoalMembers(), mWasOfferedVector()
{
    mCoalMembers.push_back(PartyId);
}

Coalition::Coalition() : mCoalitionId(), mCoalVolume(), mCoalMembers({}), mWasOfferedVector({}){}

Coalition::~Coalition(){} // Destructor

Coalition::Coalition(const Coalition& other): mCoalitionId(other.mCoalitionId), mCoalVolume(other.mCoalVolume), mCoalMembers(other.mCoalMembers), mWasOfferedVector(other.mWasOfferedVector) // Copy Constructor
{}

Coalition::Coalition(Coalition&& other): mCoalitionId(other.mCoalitionId), mCoalVolume(other.mCoalVolume), mCoalMembers(other.mCoalMembers), mWasOfferedVector(other.mWasOfferedVector) // Move Constructor
{}

Coalition& Coalition::operator=(const Coalition& other) // Assignment Operator
{
    if(this != &other)
    {
        mCoalitionId = other.mCoalitionId;
        mCoalVolume = other.mCoalVolume;
        for(int CM: mCoalMembers)
        {
            mCoalMembers.push_back(CM);
        }
        for(int WO: other.mWasOfferedVector)
        {
            mWasOfferedVector.push_back(WO);
        }
    }
    return *this;
}

Coalition& Coalition::operator=(Coalition&& other) //Move Assignment Operator
{
    mCoalitionId = other.mCoalitionId;
    mCoalVolume = other.mCoalVolume;
    for(int CM: mCoalMembers)
    {
        mCoalMembers.push_back(CM);
    }
    for(int WO: other.mWasOfferedVector)
    {
        mWasOfferedVector.push_back(WO);
    }
    return *this;
}

int Coalition:: getCoalitionId()
{
    return mCoalitionId;
}

void Coalition::setCoalitionId(int Id)
{
    mCoalitionId = Id;
}

int Coalition::getCoalVolume()
{
    return mCoalVolume;
}

void Coalition:: setCoalVolum(int toAdd)
{
    mCoalVolume += toAdd;
}

 vector<int> Coalition::getCoalMembers() const
{
    return mCoalMembers;
}

void Coalition:: setCoalMembers(int partyId)
{
    mCoalMembers.push_back(partyId);
}

vector<int> Coalition::getWasOfferedVector()
{   
    return mWasOfferedVector;
}

void Coalition::setWasOfferedVector(int PartyId)
{
    mWasOfferedVector.push_back(PartyId);
}

bool Coalition::Alla_Beyadi() const
{
    return mCoalVolume > 60;
}

void Coalition::OfferAParty(int PartyId)
{
    setWasOfferedVector(PartyId);
}