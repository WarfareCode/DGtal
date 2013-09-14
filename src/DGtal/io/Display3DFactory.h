/**
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 **/

#pragma once

/**
 * @file Display3DFactory.h
 * @author Martial Tola <http://liris.cnrs.fr/martial.tola/>
 * @date mercredi 21 septembre 2011
 *
 * @brief
 *
 * Header file for module Display3DFactory
 *
 * This file is part of the DGtal library.
 */

#if defined(Display3DFactory_RECURSES)
#error Recursive header files inclusion detected in Display3DFactory.h
#else // defined(Display3DFactory_RECURSES)
/** Prevents recursive inclusion of headers. */
#define Display3DFactory_RECURSES

#if !defined Display3DFactory_h
/** Prevents repeated inclusion of headers. */
#define Display3DFactory_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions

#include "DGtal/helpers/StdDefs.h"
#include "DGtal/base/Common.h"

#include "DGtal/io/DrawWithDisplay3DModifier.h"
#include "DGtal/geometry/curves/ArithmeticalDSS3d.h"
#include "DGtal/kernel/sets/DigitalSetBySTLSet.h"
#include "DGtal/kernel/sets/DigitalSetBySTLVector.h"
#include "DGtal/kernel/domains/HyperRectDomain.h"
#include "DGtal/topology/KhalimskySpaceND.h"
#include "DGtal/topology/Object.h"
#include "DGtal/kernel/PointVector.h"
#include "DGtal/geometry/curves/GridCurve.h"
#include "DGtal/shapes/Mesh.h"
#include "DGtal/geometry/tools/SphericalAccumulator.h"
#include "DGtal/io/colormaps/HueShadeColorMap.h"
#include "DGtal/io/colormaps/CColorMap.h"
#include "DGtal/images/ImageContainerBySTLVector.h"
#include "DGtal/images/ImageContainerBySTLMap.h"
#include "DGtal/images/ConstImageAdapter.h"
#include "DGtal/images/ImageAdapter.h"

//
//////////////////////////////////////////////////////////////////////////////

namespace DGtal
{
  /////////////////////////////////////////////////////////////////////////////
  // struct Display3DFactory
  /**
   * Description of struct 'Display3DFactory' <p>
   * \brief Factory for GPL Display3D:
   */
  struct Display3DFactory
  {


    // SphericalAccumulator
    /**
     * Display an spherical accumulator in 3D. Bin values are mapped
     * using a default HueShadeColorMap.
     *
     * @param display the display where to draw current display
     * @param accumulator the accumulator to display
     * @param shift translate vector for display purposes (default:
     * zero vector)
     * @param radius scale factor for the unit sphere radius (default:1)
     * @tparam TVector a vector model
     */
    template <typename TVector, typename Space, typename KSpace>
    static void draw( Display3D<Space, KSpace> & display, const DGtal::SphericalAccumulator<TVector> & accumulator,
                      const typename DGtal::SphericalAccumulator<TVector>::RealVector &shift =
                      typename DGtal::SphericalAccumulator<TVector>::RealVector(0,0,0),
                      const double radius=1.0);
    // SphericalAccumulator

    // Mesh
    /**
     * @brief drawAsFaces
     * @param display the display where to draw
     * @param aMesh the mesh to draw
     */
    template <typename TPoint, typename Space, typename KSpace>
    static void drawAsFaces( Display3D<Space, KSpace> & display, const DGtal::Mesh<TPoint> & aMesh);

    /**
     * @brief draw
     * @param display the display where to draw
     * @param aMesh the mesh to draw
     */
    template <typename TPoint, typename Space, typename KSpace>
    static void draw( Display3D<Space, KSpace> & display, const DGtal::Mesh<TPoint> & aMesh);
    // Mesh



    // ArithmeticalDSS3d
    /**
     * Default drawing style object.
     * @param str the name of the class
     * @param anObject the object to draw
     * @return the dyn. alloc. default style for this object.
     */
    template <typename TIterator, typename TInteger, int connectivity>
    static DGtal::DrawableWithDisplay3D * defaultStyle( std::string str, const DGtal::ArithmeticalDSS3d<TIterator,TInteger,connectivity> & anObject );

    /**
     * @brief drawAsBalls
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template <typename TIterator, typename TInteger, int connectivity, typename Space, typename KSpace>
    static void drawAsBalls( Display3D<Space, KSpace> & display, const DGtal::ArithmeticalDSS3d<TIterator,TInteger,connectivity> & anObject );

    /**
     * @brief drawAsBoundingBox
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template <typename TIterator, typename TInteger, int connectivity, typename Space, typename KSpace>
    static void drawAsBoundingBox( Display3D<Space, KSpace> & display, const DGtal::ArithmeticalDSS3d<TIterator,TInteger,connectivity> & anObject );

    /**
     * @brief draw
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template <typename TIterator, typename TInteger, int connectivity, typename Space, typename KSpace>
    static void draw( Display3D<Space, KSpace> & display, const DGtal::ArithmeticalDSS3d<TIterator,TInteger,connectivity> & anObject );
    // ArithmeticalDSS3d


    // DigitalSetBySTLSet
    /**
     * @brief defaultStyle
     * @param str the name of the class
     * @param anObject the object to draw
     * @return the dyn. alloc. default style for this object.
     */
    template<typename Domain>
    static DGtal::DrawableWithDisplay3D * defaultStyle( std::string str, const DGtal::DigitalSetBySTLSet<Domain> & anObject );

    /**
     * @brief drawAsPavingTransparent
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template<typename Domain, typename Space, typename KSpace>
    static void drawAsPavingTransparent( Display3D<Space, KSpace> & display, const DGtal::DigitalSetBySTLSet<Domain> & anObject );

    /**
     * @brief drawAsPaving
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template<typename Domain, typename Space, typename KSpace>
    static void drawAsPaving( Display3D<Space, KSpace> & display, const DGtal::DigitalSetBySTLSet<Domain> & anObject );

    /**
     * @brief drawAsGrid
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template<typename Domain, typename Space, typename KSpace>
    static void drawAsGrid( Display3D<Space, KSpace> & display, const DGtal::DigitalSetBySTLSet<Domain> & anObject );

    /**
     * @brief draw
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template<typename Domain, typename Space, typename KSpace>
    static void draw( Display3D<Space, KSpace> & display, const DGtal::DigitalSetBySTLSet<Domain> & anObject );
    // DigitalSetBySTLSet


    // DigitalSetBySTLVector
    /**
     * @brief Default drawing style object.
     * @param str the name of the class
     * @param anObject the object to draw
     * @return the dyn. alloc. default style for this object.
     */
    template<typename Domain>
    static DGtal::DrawableWithDisplay3D * defaultStyle( std::string str, const DGtal::DigitalSetBySTLVector<Domain> & anObject );

    /**
     * @brief drawAsPavingTransparent
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template<typename Domain, typename Space, typename KSpace>
    static void drawAsPavingTransparent( Display3D<Space, KSpace> & display, const DGtal::DigitalSetBySTLVector<Domain> & anObject );

    /**
     * @brief drawAsPaving
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template<typename Domain, typename Space, typename KSpace>
    static void drawAsPaving( Display3D<Space, KSpace> & display, const DGtal::DigitalSetBySTLVector<Domain> & anObject );

    /**
     * @brief drawAsGrid
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template<typename Domain, typename Space, typename KSpace>
    static void drawAsGrid( Display3D<Space, KSpace> & display, const DGtal::DigitalSetBySTLVector<Domain> & anObject );

    /**
     * @brief draw
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template<typename Domain, typename Space, typename KSpace>
    static void draw( Display3D<Space, KSpace> & display, const DGtal::DigitalSetBySTLVector<Domain> & anObject );
    // DigitalSetBySTLVector


    // HyperRectDomain
    /**
     * Default drawing style object.
     * @param str the name of the class
     * @param anObject the object to draw
     * @return the dyn. alloc. default style for this object.
     */
    template<typename TSpace>
    static DGtal::DrawableWithDisplay3D * defaultStyle( std::string str, const DGtal::HyperRectDomain<TSpace> & anObject );

    /**
     * @brief drawAsBoundingBox
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template<typename TSpace, typename Space, typename KSpace>
    static void drawAsBoundingBox( Display3D<Space, KSpace> & display, const DGtal::HyperRectDomain<TSpace> & anObject );

    /**
     * @brief drawAsGrid
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template<typename TSpace, typename Space, typename KSpace>
    static void drawAsGrid( Display3D<Space, KSpace> & display, const DGtal::HyperRectDomain<TSpace> & anObject );

    /**
     * @brief drawAsPavingBalls
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template<typename TSpace, typename Space, typename KSpace>
    static void drawAsPavingBalls( Display3D<Space, KSpace> & display, const DGtal::HyperRectDomain<TSpace> & anObject );

    /**
     * @brief drawAsPaving
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template<typename TSpace, typename Space, typename KSpace>
    static void drawAsPaving( Display3D<Space, KSpace> & display, const DGtal::HyperRectDomain<TSpace> & anObject );


    /**
     * @brief draw
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template<typename TSpace, typename Space, typename KSpace>
    static void draw( Display3D<Space, KSpace> & display, const DGtal::HyperRectDomain<TSpace> & anObject );


    // HyperRectDomain


    // KhalimskyCell
    /**
     * Default drawing style object.
     * @param str the name of the class
     * @param anObject the object to draw
     * @return the dyn. alloc. default style for this object.
     */
    template < Dimension dim, typename TInteger >
    static DGtal::DrawableWithDisplay3D * defaultStyle( std::string str, const DGtal::KhalimskyCell<dim, TInteger> & anObject );

    /**
     * @brief draw
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template < Dimension dim, typename TInteger, typename Space, typename KSpace>
    static void draw( Display3D<Space, KSpace> & display, const DGtal::KhalimskyCell<dim, TInteger> & anObject );
    // KhalimskyCell


    // Object
    /**
     * Default drawing style object.
     * @param str the name of the class
     * @param anObject the object to draw
     * @return the dyn. alloc. default style for this object.
     */
    template <typename TDigitalTopology, typename TDigitalSet>
    static DGtal::DrawableWithDisplay3D * defaultStyle( std::string str, const DGtal::Object<TDigitalTopology, TDigitalSet> & anObject );

    /**
     * @brief drawWithAdjacencies
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template <typename TDigitalTopology, typename TDigitalSet, typename Space, typename KSpace>
    static void drawWithAdjacencies( Display3D<Space, KSpace> & display, const DGtal::Object<TDigitalTopology, TDigitalSet> & anObject );

    /**
     * @brief draw
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template <typename TDigitalTopology, typename TDigitalSet, typename Space, typename KSpace>
    static void draw( Display3D<Space, KSpace> & display, const DGtal::Object<TDigitalTopology, TDigitalSet> & anObject );
    // Object


    // PointVector
    /**
     * Default drawing style object.
     * @param str the name of the class
     * @param anObject the object to draw
     * @return the dyn. alloc. default style for this object.
     */
    template<Dimension dim, typename TComponent>
    static DGtal::DrawableWithDisplay3D * defaultStyle( std::string str, const DGtal::PointVector<dim,TComponent> & anObject );

    /**
     * @brief drawAsGrid
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template<Dimension dim, typename TComponent, typename Space, typename KSpace>
    static void drawAsGrid( Display3D<Space, KSpace> & display, const DGtal::PointVector<dim,TComponent> & anObject );

    /**
     * @brief drawAsPaving
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template<Dimension dim, typename TComponent, typename Space, typename KSpace>
    static void drawAsPaving( Display3D<Space, KSpace> & display, const DGtal::PointVector<dim,TComponent> & anObject );

    /**
     * @brief drawAsPavingWired
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template<Dimension dim, typename TComponent, typename Space, typename KSpace>
    static void drawAsPavingWired( Display3D<Space, KSpace> & display, const DGtal::PointVector<dim,TComponent> & anObject );

    /**
     * @brief draw
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template<Dimension dim, typename TComponent, typename Space, typename KSpace>
    static void draw( Display3D<Space, KSpace> & display, const DGtal::PointVector<dim,TComponent> & anObject );

    /**
     * @brief draw
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template<Dimension dim, typename TComponent, typename Space, typename KSpace>
    static void draw( Display3D<Space, KSpace> & display, const DGtal::PointVector<dim,TComponent> & , const DGtal::PointVector<dim,TComponent> & anObject );
    // PointVector


    // SignedKhalimskyCell
    /**
     * Default drawing style object.
     * @param str the name of the class
     * @param anObject the object to draw
     * @return the dyn. alloc. default style for this object.
     */
    template< Dimension dim, typename TInteger >
    static DGtal::DrawableWithDisplay3D * defaultStyle( std::string str, const DGtal::SignedKhalimskyCell<dim, TInteger> & anObject );

    /**
     * @brief draw
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template< Dimension dim, typename TInteger, typename Space, typename KSpace>
    static void draw( Display3D<Space, KSpace> & display, const DGtal::SignedKhalimskyCell<dim, TInteger> & anObject );
    // SignedKhalimskyCell

    // GridCurve
    /**
     * @brief draw
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template< typename TKSpace, typename Space, typename KSpace>
    static void draw( Display3D<Space, KSpace> & display, const DGtal::GridCurve<TKSpace> & anObject );
    // GridCurve

    // SCellsRange
    /**
     * @brief draw
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template < typename TIterator, typename TSCell , typename Space, typename KSpace>
    static void draw( DGtal::Display3D<Space, KSpace> & display,
                      const DGtal::ConstRangeAdapter<TIterator, DGtal::DefaultFunctor, TSCell> & anObject );
    // SCellsRange

    // PointsRange
    /**
     * @brief draw
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template <typename TIterator, typename TKSpace, typename Space, typename KSpace>
    static void draw( Display3D<Space, KSpace> & display,
                      const DGtal::ConstRangeAdapter<TIterator, SCellToPoint<TKSpace>, typename TKSpace::Point> & anObject );
    // PointsRange

    // MidPointsRange
    template <typename TIterator, typename TKSpace, typename Space, typename KSpace>
    /**
     * @brief draw
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    static void draw( Display3D<Space, KSpace> & display,
                      const DGtal::ConstRangeAdapter<TIterator, SCellToMidPoint<TKSpace>,
                      typename TKSpace::Space::RealPoint> & anObject );
    // MidPointsRange

    // ArrowsRange
    /**
     * @brief draw
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template <typename TIterator, typename TKSpace, typename Space, typename KSpace>
    static void draw( Display3D<Space, KSpace> & display,
                      const DGtal::ConstRangeAdapter<TIterator, SCellToArrow<TKSpace>,
                      std::pair<typename TKSpace::Point, typename TKSpace::Vector > > & anObject );
    // ArrowsRange

    // InnerPointsRange
    /**
     * @brief draw
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template <typename TIterator, typename TKSpace, typename Space, typename KSpace>
    static void draw( Display3D<Space, KSpace> & display,
                      const DGtal::ConstRangeAdapter<TIterator, SCellToInnerPoint<TKSpace>, typename TKSpace::Point> & anObject );
    // InnerPointsRange

    // OuterPointsRange
    /**
     * @brief draw
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template <typename TIterator, typename TKSpace, typename Space, typename KSpace>
    static void draw( Display3D<Space, KSpace> & display,
                      const DGtal::ConstRangeAdapter<TIterator, SCellToOuterPoint<TKSpace>, typename TKSpace::Point> & anObject );
    // OuterPointsRange

    // IncidentPointsRange
    /**
     * @brief draw
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template <typename TIterator, typename TKSpace, typename Space, typename KSpace>
    static void draw( Display3D<Space, KSpace> & display,
                      const DGtal::ConstRangeAdapter<TIterator, SCellToIncidentPoints<TKSpace>,
                      std::pair<typename TKSpace::Point, typename TKSpace::Point > > & anObject );
    // IncidentPointsRange

    /**
     * @brief draw
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template < typename Space, typename KSpace>
    static void
    draw( Display3D<Space, KSpace> & display, const DGtal::SetMode3D & anObject );

    /**
     * @brief draw
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template < typename Space, typename KSpace>
    static void
    draw( Display3D<Space, KSpace> & display, const DGtal::CustomStyle3D & anObject );

    /**
     * @brief draw
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template < typename Space, typename KSpace>
    static void
    draw( Display3D<Space, KSpace> & display, const DGtal::CustomColors3D & anObject );

    /**
     * @brief draw
     * @param display the display where to draw
     * @param anObject the object to draw
     */
    template < typename Space, typename KSpace>
    static void
    draw( Display3D<Space, KSpace> & display, const DGtal::ClippingPlane & anObject );


    /**
     * Draw a surfel
     * @param display the display where to draw
     * @param aTransformedSurfelPrism a transformed surfel prism
     */
    template < typename Space, typename KSpace>
    static void
    draw( Display3D<Space, KSpace> & display, const DGtal::TransformedSurfelPrism & aTransformedSurfelPrism);

  }; // end of struct Display3DFactory

} // namespace DGtal

///////////////////////////////////////////////////////////////////////////////
// Includes inline functions/methods

#include "DGtal/io/Display3DFactory.ih"

// //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined Display3DFactory_h

#undef Display3DFactory_RECURSES
#endif // else defined(Display3DFactory_RECURSES)
