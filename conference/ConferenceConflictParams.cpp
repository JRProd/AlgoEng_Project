/* 
 * File:   ConferenceConflictParam.cpp
 * Author: jake.rowland
 * 
 * Created on September 30, 2018, 8:05 PM
 */

#include "ConferenceConflictParams.h"

int ConferenceConflictParams::getSessions() const {
    return sessions;
}

int ConferenceConflictParams::getAttendees() const {
    return attendees;
}

int ConferenceConflictParams::getSessionsPerAttende() const {
    return sesPerAtte;
}

int ConferenceConflictParams::getLowerBound() const {
    return lower;
}

int ConferenceConflictParams::getTwoTieredTier() const {
    return tier;
}

float ConferenceConflictParams::getTwoTieredSplit() const {
    return split;
}

int ConferenceConflictParams::getOutput() const {
    return output;
}

int ConferenceConflictParams::getOutputNewLine() const {
    return outputNewLine;
}

int ConferenceConflictParams::getPBatch() const {
    return pBatch;
}

int ConferenceConflictParams::getEBatch() const {
    return eBatch;
}

Dist ConferenceConflictParams::getDistribution() const {
    return dist;
}

ConflictSizeConstraint ConferenceConflictParams::getConflictSizeConstrinat() 
        const {
    return conflictSize;
}

ConferenceConflictParams::Builder* 
        ConferenceConflictParams::Builder::setSessions(int sess) {
    sessions = sess;
    return this;
}

ConferenceConflictParams::Builder* 
        ConferenceConflictParams::Builder::setAttendees(int atte) {
    attendees = atte;
    return this;
}

ConferenceConflictParams::Builder* 
        ConferenceConflictParams::Builder::setSessionsPerAttendee(int sesAtte) {
    sesPerAtte  = sesAtte;
    return this;
}

ConferenceConflictParams::Builder* 
        ConferenceConflictParams::Builder::setLowerBound(int low) {
    lower = low;
    return this;
}

ConferenceConflictParams::Builder* 
        ConferenceConflictParams::Builder::setTwoTieredTier(int ti) {
    tier = ti;
    return this;
}

ConferenceConflictParams::Builder* 
        ConferenceConflictParams::Builder::setTwoTieredSplit(float splt) {
    split = splt;
    return this;
}

ConferenceConflictParams::Builder* 
        ConferenceConflictParams::Builder::setShowOutput(int out) {
    output = out;
    return this;
}

ConferenceConflictParams::Builder* 
        ConferenceConflictParams::Builder::setOutputNewLine(int outNewLine) {
    outputNewLine = outNewLine;
    return this;
}

ConferenceConflictParams::Builder* 
        ConferenceConflictParams::Builder::setPBatchSize(int pBtch) {
    pBatch = pBtch;
    return this;
}

ConferenceConflictParams::Builder* 
        ConferenceConflictParams::Builder::setEBatchSize(int eBtch) {
    eBatch = eBtch;
    return this;
}

ConferenceConflictParams::Builder* 
        ConferenceConflictParams::Builder::setDistribution(Dist distro) {
    dist = distro;
    return this;
}

ConferenceConflictParams::Builder* 
        ConferenceConflictParams::Builder::setConflictSizeConstrinat(
        ConflictSizeConstraint size) {
    conflictSize = size;
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
            conflictSize);
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
        ConflictSizeConstraint size) {
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
    conflictSize = size;
}