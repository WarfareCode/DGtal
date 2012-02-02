/**
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 **/

/**
 * @file testUmbrellaComputer.cpp
 * @ingroup Tests
 * @author Jacques-Olivier Lachaud (\c jacques-olivier.lachaud@univ-savoie.fr )
 * Laboratory of Mathematics (CNRS, UMR 5127), University of Savoie, France
 *
 * @date 2012/02/02
 *
 * Functions for testing class UmbrellaComputer.
 *
 * This file is part of the DGtal library.
 */

///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "DGtal/base/Common.h"
#include "DGtal/shapes/implicit/ImplicitBall.h"
#include "DGtal/geometry/nd/GaussDigitizer.h"
#include "DGtal/topology/LightImplicitDigitalSurface.h"
#include "DGtal/topology/DigitalSurface.h"
#include "DGtal/topology/UmbrellaComputer.h"
///////////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace DGtal;

///////////////////////////////////////////////////////////////////////////////
// Functions for testing class UmbrellaComputer.
///////////////////////////////////////////////////////////////////////////////

bool testUmbrellaComputer()
{
  using namespace Z3i;
  
  typedef Space::RealPoint RealPoint;
  typedef ImplicitBall<Space> EuclideanShape;
  typedef GaussDigitizer<Space,EuclideanShape> DigitalShape; 
  typedef GaussDigitizer<Space,EuclideanShape>::Domain Domain;
  typedef LightImplicitDigitalSurface<KSpace,DigitalShape> Boundary;
  typedef Boundary::SurfelConstIterator ConstIterator;
  typedef Boundary::Tracker Tracker;
  typedef Boundary::Surfel Surfel;
  typedef Boundary::DigitalSurfaceTracker DigitalSurfaceTracker;
  typedef DigitalSurface<Boundary> MyDigitalSurface;
  typedef UmbrellaComputer<DigitalSurfaceTracker> MyUmbrellaComputer;

  unsigned int nbok = 0;
  unsigned int nb = 0;
  trace.beginBlock ( "Testing block ... UmbrellaComputer" );
  // Creating shape
  Point c( 0, 0, 0 );
  EuclideanShape ball( c, 4 ); // ball r=4
  DigitalShape shape;
  shape.attach( ball );
  shape.init( RealPoint( -10.0, -10.0, -10.0 ), 
	      RealPoint( 10.0, 10.0, 10.0 ), 1.0 );
  // Creating cellular grid space around.
  Domain domain = shape.getDomain();
  KSpace K;
  nbok += K.init( domain.lowerBound(), domain.upperBound(), true ) ? 1 : 0; 
  nb++;
  trace.info() << "(" << nbok << "/" << nb << ") "
	       << "K.init() is ok" << std::endl;
  // Find start surfel on surface.
  Surfel bel = Surfaces<KSpace>::findABel( K, shape, 10000 );
  // Define surface container then surface itself.
  Boundary boundary( K, // cellular space
		     shape, // point predicate
                     SurfelAdjacency<KSpace::dimension>( true ), // adjacency
		     bel // starting surfel
		     );
  MyDigitalSurface digSurf( boundary ); // boundary is cloned

  // Get tracker on surface.
  DigitalSurfaceTracker* ptrTracker = boundary.newTracker( bel );
  MyUmbrellaComputer umbrella;
  KSpace::DirIterator dirIt = K.sDirs( bel );
  Dimension k = *dirIt;
  Dimension j = *(++dirIt);
  trace.beginBlock ( "Testing block ... forward umbrella" );
  umbrella.init( *ptrTracker, k, true, j );
  unsigned int nb_forward = 0;
  Surfel init_bel = bel;
  do {
    Point x = K.sKCoords( bel );
    trace.info() << x << std::endl;
    umbrella.next();
    ++nb_forward;
    bel = umbrella.surfel();
  } while ( bel != init_bel );
  trace.endBlock();
  trace.beginBlock ( "Testing block ... backward umbrella" );
  unsigned int nb_backward = 0;
  do {
    Point x = K.sKCoords( bel );
    trace.info() << x << std::endl;
    umbrella.previous();
    ++nb_backward;
    bel = umbrella.surfel();
  } while ( bel != init_bel );
  nb++, nbok += nb_forward == nb_backward ? 1 : 0;
  
  trace.info() << "(" << nbok << "/" << nb << ") "
               << " nb_forward(" << nb_forward
	       << ") == nb_backward(" << nb_backward << ")"
	       << std::endl;
  trace.endBlock();

  unsigned int nbsurfels = 0;
  for ( ConstIterator it = boundary.begin(), it_end = boundary.end();
        it != it_end; ++it )
    {
      ++nbsurfels;
    }
  trace.info() << nbsurfels << " surfels found." << std::endl;
  trace.endBlock();

  delete ptrTracker;
  return nbok == nb;
}


///////////////////////////////////////////////////////////////////////////////
// Standard services - public :

int main( int argc, char** argv )
{
  trace.beginBlock ( "Testing class UmbrellaComputer" );
  trace.info() << "Args:";
  for ( int i = 0; i < argc; ++i )
    trace.info() << " " << argv[ i ];
  trace.info() << endl;

  bool res = testUmbrellaComputer(); // && ... other tests
  trace.emphase() << ( res ? "Passed." : "Error." ) << endl;
  trace.endBlock();
  return res ? 0 : 1;
}
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
