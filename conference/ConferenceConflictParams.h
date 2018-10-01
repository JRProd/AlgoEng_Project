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
#include "../conflicts/ConflictGraph.h"
#include "../conflicts/ConflictList.h"

class ConferenceConflictParams {
public:
    int getSessions();
    int getAttendees();
    int getSessionsPerAttende();
    int getLowerBound();
    int getTwoTieredTier();
    float getTwoTieredSplit();
    int getOutput();
    int getOutputNewLine();
    int getPBatch();
    int getEBatch();
    Dist getDistribution();
    ConflictHandler* getConflictHandler();
    bool getUsedHashSet();
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
        Builder* setConflictHandler(ConflictSizeConstrinat size);
        Builder* setUseHashSet(bool hash);
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
        ConflictHandler* conflictHandler = nullptr;
        bool useHashSet = false;
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
    ConflictHandler* conflictHandler;
    bool useHashSet;
    
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
            ConflictHandler* handler,
            bool hash);
};

#endif /* CONFERENCECONFLICTPARAM_H */

