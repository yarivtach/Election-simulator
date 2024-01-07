#pragma once
#include <vector>
#include "Agent.h"
using std::vector;

class Coalition;

class JoinPolicy {
    
    public:
        JoinPolicy();
        virtual ~JoinPolicy();
        virtual void buildChoose(int CoalitionId) = 0;
        virtual int join( vector<Coalition> &CoalitionVector) = 0;
        virtual JoinPolicy* getType() = 0;
        virtual vector<int> getOffer() = 0;
        virtual void setOffer(vector<int> O) = 0;
        virtual int select(vector<Coalition>& VC, vector<int> WOV) = 0;

};

class MandatesJoinPolicy : public JoinPolicy 
{
    private:
        vector<int> mOffer;
    public:
        MandatesJoinPolicy();
        virtual ~MandatesJoinPolicy();
        virtual vector<int> getOffer();
        virtual void buildChoose(int CoalitionId);// add the coalition which offer to DS
        virtual int join( vector<Coalition> &CoalitionVector);
        virtual JoinPolicy* getType();
        virtual void setOffer(vector<int> O);
        virtual int select(vector<Coalition>& VC, vector<int> WOV);
};

class LastOfferJoinPolicy : public JoinPolicy 
{
    private:
        vector<int> mOffer;
    public:
        LastOfferJoinPolicy();
        virtual ~LastOfferJoinPolicy();
        virtual vector<int> getOffer();
        virtual void buildChoose(int CoalitionId);//update the choose
        virtual int join( vector<Coalition> &CoalitionVector);
        virtual JoinPolicy* getType();
        virtual void setOffer(vector<int> O);
        virtual int select(vector<Coalition>& VC, vector<int> WOV);
};