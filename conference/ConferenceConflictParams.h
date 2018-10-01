/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
    ConflictSizeConstrinat getConflictSizeConstrinat() const;
    bool getUsedHashSet() const;
    int getDebugMode() const;
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
        Builder* setConflictSizeConstrinat(ConflictSizeConstrinat size);
        Builder* setUseHashSet(bool hash);
        Builder* setDebugMode(int debug);
        const ConferenceConflictParams* build();
    private:
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
        ConflictSizeConstrinat conflictSize;
        bool useHashSet = false;
        int debugMode = 0;
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
    ConflictSizeConstrinat conflictSize;
    bool useHashSet;
    int debugMode;
    
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
            ConflictSizeConstrinat size,
            bool hash,
            int debug);
};

#endif /* CONFERENCECONFLICTPARAM_H */

