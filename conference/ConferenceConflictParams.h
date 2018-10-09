/* 
 * File:   ConferenceConflictParam.h
 * Author: jake.rowland
 *
 * Created on September 30, 2018, 8:05 PM
 */

#ifndef CONFERENCECONFLICTPARAMS_H
#define CONFERENCECONFLICTPARAMS_H

#include "../distributions/Distribution.h"

#include "../conflicts/ConflictHandler.h"

class ConferenceConflictParams {
public:
    // Getter methods
    int getSessions() const;
    int getAttendees() const;
    int getSessionsPerAttende() const;
    int getLowerBound() const;
    int getTwoTieredTier() const;
    float getTwoTieredSplit() const;
    int getOutput() const;
    int getOutputNewLine() const;
    int getPBatch() const;
    int getEBatch() const;
    Dist getDistribution()const;
    ConflictSizeConstraint getConflictSizeConstrinat() const;
    
    // Builder construct
    class Builder {
    public:
        Builder* setSessions(int sess);
        Builder* setAttendees(int atte);
        Builder* setSessionsPerAttendee(int sesAtte);
        Builder* setLowerBound(int low);
        Builder* setTwoTieredTier(int ti);
        Builder* setTwoTieredSplit(float splt);
        Builder* setShowOutput(int out);
        Builder* setOutputNewLine(int outNewLine);
        Builder* setPBatchSize(int pBtch);
        Builder* setEBatchSize(int eBtch);
        Builder* setDistribution(Dist distro);
        Builder* setConflictSizeConstrinat(ConflictSizeConstraint size);
        const ConferenceConflictParams* build();
    private:
        // Default values for the parameters
        int sessions = 1000;
        int attendees = 100;
        int sesPerAtte = 100;
        int lower = 0;
        int tier = 100;
        float split = .8;
        int output = 0;
        int outputNewLine = 50;
        int pBatch = 1000;
        int eBatch = 5000;
        Dist dist = Dist::Uniform;
        ConflictSizeConstraint conflictSize;
    };
private:
    int sessions;
    int attendees;
    int sesPerAtte;
    int lower;
    int tier;
    float split;
    int output;
    int outputNewLine;
    int pBatch;
    int eBatch;
    Dist dist;
    ConflictSizeConstraint conflictSize;
    
    // Private constructor
    ConferenceConflictParams(
            int sess,
            int atten,
            int sesAttn,
            int low,
            int ti,
            float splt,
            int out,
            int outNewLine,
            int pBtch,
            int eBtch,
            Dist distro,
            ConflictSizeConstraint size);
};

#endif /* CONFERENCECONFLICTPARAM_H */