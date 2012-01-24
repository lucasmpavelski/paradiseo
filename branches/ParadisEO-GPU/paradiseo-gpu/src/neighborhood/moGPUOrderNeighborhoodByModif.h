/*
  <moGPUOrderNeighborhoodByModif.h>
  Copyright (C) DOLPHIN Project-Team, INRIA Lille - Nord Europe, 2006-2012

 Karima Boufaras, Thé Van LUONG

  This software is governed by the CeCILL license under French law and
  abiding by the rules of distribution of free software.  You can  use,
  modify and/ or redistribute the software under the terms of the CeCILL
  license as circulated by CEA, CNRS and INRIA at the following URL
  "http://www.cecill.info".

  As a counterpart to the access to the source code and  rights to copy,
  modify and redistribute granted by the license, users are provided only
  with a limited warranty  and the software's author,  the holder of the
  economic rights,  and the successive licensors  have only  limited liability.

  In this respect, the user's attention is drawn to the risks associated
  with loading,  using,  modifying and/or developing or reproducing the
  software by the user in light of its specific status of free software,
  that may mean  that it is complicated to manipulate,  and  that  also
  therefore means  that it is reserved for developers  and  experienced
  professionals having in-depth computer knowledge. Users are therefore
  encouraged to load and test the software's suitability as regards their
  requirements in conditions enabling the security of their systems and/or
  data to be ensured and,  more generally, to use and operate it in the
  same conditions as regards security.
  The fact that you are presently reading this means that you have had
  knowledge of the CeCILL license and that you accept its terms.

  ParadisEO WebSite : http://paradiseo.gforge.inria.fr
  Contact: paradiseo-help@lists.gforge.inria.fr
*/

#ifndef __moGPUOrderNeighborhoodByModif_h
#define __moGPUOrderNeighborhoodByModif_h

#include <neighborhood/moOrderNeighborhood.h>
#include <eval/moGPUEvalByModif.h>

/**
 * An ordered neighborhood with parallel evaluation
 */

template<class N>
class moGPUOrderNeighborhoodByModif: public moOrderNeighborhood<N> {

 public:

  /**
   * Define type of a solution corresponding to Neighbor
   */

  typedef N Neighbor;
  typedef typename Neighbor::EOT EOT;

  using moOrderNeighborhood<Neighbor>::neighborhoodSize;
  using moOrderNeighborhood<Neighbor>::currentIndex;

  /**
   * Constructor
   * @param _neighborhoodSize the size of the neighborhood
   * @param _eval show how to evaluate neighborhood of a solution at one time
   */

 moGPUOrderNeighborhoodByModif(unsigned int _neighborhoodSize,
			 moGPUEval<Neighbor>& _eval) :
  moOrderNeighborhood<Neighbor> (_neighborhoodSize), eval(_eval) {
  }

  /**
   * Initialization of the neighborhood
   *@param _solution the solution to explore
   *@param _neighbor the first neighbor
   */

  virtual void init(EOT & _solution, Neighbor & _neighbor) {

    moOrderNeighborhood<Neighbor>::init(_solution, _neighbor);
    //Compute all neighbors fitness at one time
    eval.neighborhoodEval(_solution,0,1);
  }

  /**
   * Return the class name.
   * @return the class name as a std::string
   */
  virtual std::string className() const {
    return "moGPUOrderNeighborhoodByModif";
  }

 protected:
  moGPUEval<Neighbor>& eval;
};

#endif
