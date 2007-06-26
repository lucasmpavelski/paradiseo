// -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*-

//-----------------------------------------------------------------------------
// moeoDetTournamentSelect.h
// (c) OPAC Team (LIFL), Dolphin Project (INRIA), 2007
/*
    This library...

    Contact: paradiseo-help@lists.gforge.inria.fr, http://paradiseo.gforge.inria.fr
 */
//-----------------------------------------------------------------------------

#ifndef MOEODETTOURNAMENTSELECT_H_
#define MOEODETTOURNAMENTSELECT_H_

#include <comparator/moeoComparator.h>
#include <comparator/moeoFitnessThenDiversityComparator.h>
#include <selection/moeoSelectOne.h>
#include <selection/moeoSelectors.h>

/**
 * Selection strategy that selects ONE individual by deterministic tournament.
 */
template < class MOEOT > class moeoDetTournamentSelect:public moeoSelectOne < MOEOT >
{
public:

    /**
     * Full Ctor.
     * @param _comparator the comparator (used to compare 2 individuals)
     * @param _tSize the number of individuals in the tournament (default: 2)
     */
    moeoDetTournamentSelect (moeoComparator < MOEOT > & _comparator, unsigned int _tSize = 2) : comparator (_comparator), tSize (_tSize)
    {
        // consistency check
        if (tSize < 2)
        {
            std::
            cout << "Warning, Tournament size should be >= 2\nAdjusted to 2\n";
            tSize = 2;
        }
    }


    /**
     * Ctor without comparator. A moeoFitnessThenDiversityComparator is used as default.
     * @param _tSize the number of individuals in the tournament (default: 2)	 
     */
    moeoDetTournamentSelect (unsigned int _tSize = 2) : comparator (defaultComparator), tSize (_tSize)
    {
        // consistency check
        if (tSize < 2)
        {
            std::
            cout << "Warning, Tournament size should be >= 2\nAdjusted to 2\n";
            tSize = 2;
        }
    }


    /**
     * Apply the tournament to the given population
     * @param _pop the population
     */
    const MOEOT & operator() (const eoPop < MOEOT > &_pop)
    {
        // use the selector
        return mo_deterministic_tournament (_pop, tSize, comparator);
    }


protected:

    /** the comparator (used to compare 2 individuals) */
    moeoComparator < MOEOT > & comparator;
    /** a fitness then diversity comparator can be used as default */
    moeoFitnessThenDiversityComparator < MOEOT > defaultComparator;
    /** the number of individuals in the tournament */
    unsigned int tSize;

};

#endif /*MOEODETTOURNAMENTSELECT_H_ */
