#include "Party.h"
#include "Simulation.h"
#include "Coalition.h"


Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) , mIterator(0), mWasOfferedVector()
{
    // You can change the implementation of the constructor, but not the signature!
    
}

Party:: Party(): mId(), mName(), mMandates(), mJoinPolicy(), mState() , mIterator(), mWasOfferedVector(){}

Party:: ~Party(){if(mJoinPolicy) delete mJoinPolicy;} // Destructor

Party::Party(const Party& other): mId(other.mId), mName(other.mName), mMandates(other.mMandates),mJoinPolicy(other.mJoinPolicy), mState(other.mState), mIterator(other.mIterator), mWasOfferedVector()//copy constructor
{
    mJoinPolicy = other.mJoinPolicy->getType();
    mJoinPolicy->setOffer(other.mJoinPolicy->getOffer());
}

Party& Party::operator=(const Party& other)
{
    if(this !=&other)
    {
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mState = other.mState;
        mIterator = other.mIterator;
        mJoinPolicy = other.mJoinPolicy->getType();
        mJoinPolicy->setOffer(other.mJoinPolicy->getOffer());
        mWasOfferedVector = other.mWasOfferedVector;
    }
    return *this;
}

Party& Party::operator=(Party&& other)
{
    
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mJoinPolicy = other.mJoinPolicy;
    other.mJoinPolicy = nullptr;
    mState = other.mState;
    mIterator = other.mIterator;
    mWasOfferedVector = other.mWasOfferedVector;
    return *this;
}

int Party::getIterator()
{
    return mIterator;
}

void Party::nextIteration()
{
    mIterator++;
}

int Party::getId() const{
    return mId;
}


State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string& Party::getName() const
{
    return mName;
}

void Party::NewOffer(int CoalitionId)
{
    mWasOfferedVector.push_back(CoalitionId);
}

void Party::join(Coalition& C)
{
    if(mState != Joined)
    {
        setState(Joined);
        C.setCoalVolum(mMandates);
        C.setCoalMembers(mId);
    }
}

void Party::OfferAParty(int CoalId) 
{
    setState(CollectingOffers);
    NewOffer(CoalId);
}

void Party::step( Simulation &s)
{
    // TODO: implement this method
    if(mState == CollectingOffers)
    {
        nextIteration();
        if(mIterator == 3)
        {
            vector<Coalition> &VC = s.getCoalitionVector();
            int choose = mJoinPolicy -> select(VC, mWasOfferedVector);
            for(Coalition &C : VC)
            {
                if(C.getCoalitionId() == choose)
                {
                    join(C);
                    vector<Agent> agnts = s.getAgentsN();
                    Agent toCopy = agnts[choose];
                    s.DuplicateAgent(toCopy, mId);

                }
            }
        }
    }
}

