// -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*-

// "two_opt.h"

// (c) OPAC Team, LIFL, 2003

/* This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.
   
   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.
   
   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
   
   Contact: cahon@lifl.fr
*/

#ifndef two_opt_h
#define two_opt_h

#include <eoPersistent.h>

#include <utility>
#include <moMove.h>

#include "route.h"

class TwoOpt : public moMove <Route>, public std :: pair <unsigned, unsigned>, public eoPersistent {

public :
  
  TwoOpt operator ! () const ;

  void operator () (Route & __route) ;

  void readFrom (std :: istream & __is) ;

  void printOn (std :: ostream & __os) const ;
} ;

#endif