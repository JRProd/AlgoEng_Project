/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConferenceConflictParam.cpp
 * Author: jake.rowland
 * 
 * Created on September 30, 2018, 8:05 PM
 */

#include "ConferenceConflictParams.h"

int ConferenceConflictParams::getSessions() {
    return sessions;
}

int ConferenceConflictParams::getAttendees() {
    return attendees;
}

int ConferenceConflictParams::getSessionsPerAttende() {
    return sesPerAtte;
}

int ConferenceConflictParams::getLowerBound() {
    return lower;
}

int ConferenceConflictParams::getTwoTieredTier() {
    return tier;
}

float ConferenceConflictParams::getTwoTieredSplit() {
    return split;
}

int ConferenceConflictParams::getOutput() {
    return output;
}

int ConferenceConflictParams::getOutputNewLine() {
    return outputNewLine;
}

int ConferenceConflictParams::getPBatch() {
    return pBatch;
}

int ConferenceConflictParams::getEBatch() {
    return eBatch;
}

Dist ConferenceConflictParams::getDistribution() {
    return dist;
}

ConflictHandler* ConferenceConflictParams::getConflictHandler() {
    return conflictHandler;
}

bool ConferenceConflictParams::getUsedHashSet() {
    return useHashSet;
}


ConferenceConflictParams::Builder* ConferenceConflictParams::Builder::setSessions(int sess) {
    sessions = sess;
    return this;
}

ConferenceConflictParams::Builder* ConferenceConflictParams::Builder::setAttendees(int atte) {
    attendees = atte;
    return this;
}

ConferenceConflictParams::Builder* ConferenceConflictParams::Builder::setSessionsPerAttendee(int sesAtte) {
    sesPerAtte  = sesAtte;
    return this;
}

ConferenceConflictParams::Builder* ConferenceConflictParams::Builder::setLowerBound(int low) {
    lower = low;
    return this;
}

ConferenceConflictParams::Builder* ConferenceConflictParams::Builder::setTwoTieredTier(int ti) {
    tier = ti;
    return this;
}

ConferenceConflictParams::Builder* ConferenceConflictParams::Builder::setTwoTieredSplit(float splt) {
    split = splt;
    return this;
}

ConferenceConflictParams::Builder* ConferenceConflictParams::Builder::setShowOutput(int out) {
    output = out;
    return this;
}

ConferenceConflictParams::Builder* ConferenceConflictParams::Builder::setOutputNewLine(int outNewLine) {
    outputNewLine = outNewLine;
    return this;
}

ConferenceConflictParams::Builder* ConferenceConflictParams::Builder::setPBatchSize(int pBtch) {
    pBatch = pBtch;
    return this;
}

ConferenceConflictParams::Builder* ConferenceConflictParams::Builder::setEBatchSize(int eBtch) {
    eBatch = eBtch;
    return this;
}

ConferenceConflictParams::Builder* ConferenceConflictParams::Builder::setDistribution(Dist distro) {
    dist = distro;
    return this;
}

ConferenceConflictParams::Builder* ConferenceConflictParams::Builder::setConflictHandler(ConflictSizeConstrinat size) {
    switch(size) {
        case ConflictSizeConstrinat::M:
            conflictHandler = new ConflictList(sessions);
            break;
        case ConflictSizeConstrinat::N2:
            conflictHandler = new ConflictGraph(sessions);
            break;
        default:
            conflictHandler = new ConflictGraph(sessions);
            break;
    }
    return this;
}

ConferenceConflictParams::Builder* ConferenceConflictParams::Builder::setUseHashSet(bool hash) {
    useHashSet = hash;
    return this;
}


const ConferenceConflictParams* ConferenceConflictParams::Builder::build() {
    return new ConferenceConflictParams(
            sessions,
            attendees,
            sesPerAtte,
            lower,
            tier,
            split,
            output,
            outputNewLine,
            pBatch,
            eBatch,
            dist,
            conflictHandler,
            useHashSet);
}


ConferenceConflictParams::ConferenceConflictParams(
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
        bool hash) {
    sessions = sess;
    attendees = atten;
    sesPerAtte = sesAttn;
    lower = low;
    tier = ti;
    split = splt;
    output = out;
    outputNewLine = outNewLine;
    pBatch = pBtch;
    eBatch = eBtch;
    dist = distro;
    conflictHandler = handler;
    useHashSet = hash;
}
        
