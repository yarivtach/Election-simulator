#include "JoinPolicy.h"
#include "Coalition.h"

JoinPolicy::JoinPolicy(){}
JoinPolicy::~JoinPolicy(){}

MandatesJoinPolicy::MandatesJoinPolicy(): mOffer()// Constructor
{

}

MandatesJoinPolicy:: ~MandatesJoinPolicy()
{

}
//MandatesJoinPolicy::MandatesJoinPolicy(){}//default constrctor

void MandatesJoinPolicy:: buildChoose(int CoalitionId)
{
    mOffer.push_back(CoalitionId);
}

int MandatesJoinPolicy::join( vector<Coalition> &VC)
{
    int max = -1;
    int ans = -1;
    for(int c : mOffer)
    {
        for(Coalition &C : VC)
        {
            if(C.getCoalitionId() == c)
            {
                if(max < C.getCoalVolume())
                {
                    max = C.getCoalVolume();
                    ans = c;
                }
            }
        }
    }
     return ans;
 }

JoinPolicy* MandatesJoinPolicy::getType()
{
    return new MandatesJoinPolicy();
}

vector<int> MandatesJoinPolicy::getOffer()
{
    return mOffer;
}

void MandatesJoinPolicy::setOffer(vector<int> O)
{
    mOffer = O;
}

int MandatesJoinPolicy::select(vector<Coalition>& VC, vector<int> WOV)
{
    int max = 0;
    int S = -1;
    for(int i : WOV)
    {
        if(max < VC[i].getCoalVolume())
        {
            max = VC[i].getCoalVolume();
            S = i;
        }
    }
    return S;
}

//*******************************************************************************
//*******************************************************************************


LastOfferJoinPolicy::LastOfferJoinPolicy():mOffer(){}; // Constructor
//LastOfferJoinPolicy::LastOfferJoinPolicy(){}
LastOfferJoinPolicy::~LastOfferJoinPolicy()
{
    
}

void LastOfferJoinPolicy:: buildChoose(int CoalitionId)
{
    mOffer.push_back(CoalitionId);
}

int LastOfferJoinPolicy::join( vector<Coalition> &CoalitionVector)
{
    return mOffer[mOffer.size()-1];
}

JoinPolicy* LastOfferJoinPolicy::getType()
{
    return new LastOfferJoinPolicy();
}

vector<int> LastOfferJoinPolicy::getOffer()
{
    return mOffer;
}

void LastOfferJoinPolicy::setOffer(vector<int> O)
{
    mOffer = O;
}

int LastOfferJoinPolicy::select(vector<Coalition>& VC, vector<int> WOV)
{
    return WOV[WOV.size()-1];
}