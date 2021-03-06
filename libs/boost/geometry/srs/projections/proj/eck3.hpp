#ifndef BOOST_GEOMETRY_PROJECTIONS_ECK3_HPP
#define BOOST_GEOMETRY_PROJECTIONS_ECK3_HPP

// Boost.Geometry - extensions-gis-projections (based on PROJ4)
// This file is automatically generated. DO NOT EDIT.

// Copyright (c) 2008-2015 Barend Gehrels, Amsterdam, the Netherlands.

// This file was modified by Oracle on 2017.
// Modifications copyright (c) 2017, Oracle and/or its affiliates.
// Contributed and/or modified by Adam Wulkiewicz, on behalf of Oracle.

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// This file is converted from PROJ4, http://trac.osgeo.org/proj
// PROJ4 is originally written by Gerald Evenden (then of the USGS)
// PROJ4 is maintained by Frank Warmerdam
// PROJ4 is converted to Boost.Geometry by Barend Gehrels

// Last updated version of proj: 4.9.1

// Original copyright notice:

// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#include <boost/core/ignore_unused.hpp>

#include <boost/geometry/srs/projections/impl/base_static.hpp>
#include <boost/geometry/srs/projections/impl/base_dynamic.hpp>
#include <boost/geometry/srs/projections/impl/projects.hpp>
#include <boost/geometry/srs/projections/impl/factory_entry.hpp>
#include <boost/geometry/srs/projections/impl/aasincos.hpp>

namespace boost { namespace geometry
{

namespace srs { namespace par4
{
    struct eck3 {};
    struct putp1 {};
    struct wag6 {};
    struct kav7 {};

}} //namespace srs::par4

namespace projections
{
    #ifndef DOXYGEN_NO_DETAIL
    namespace detail { namespace eck3
    {

            template <typename T>
            struct par_eck3
            {
                T C_x, C_y, A, B;
            };

            // template class, using CRTP to implement forward/inverse
            template <typename CalculationType, typename Parameters>
            struct base_eck3_spheroid : public base_t_fi<base_eck3_spheroid<CalculationType, Parameters>,
                     CalculationType, Parameters>
            {

                typedef CalculationType geographic_type;
                typedef CalculationType cartesian_type;

                par_eck3<CalculationType> m_proj_parm;

                inline base_eck3_spheroid(const Parameters& par)
                    : base_t_fi<base_eck3_spheroid<CalculationType, Parameters>,
                     CalculationType, Parameters>(*this, par) {}

                // FORWARD(s_forward)  spheroid
                // Project coordinates from geographic (lon, lat) to cartesian (x, y)
                inline void fwd(geographic_type& lp_lon, geographic_type& lp_lat, cartesian_type& xy_x, cartesian_type& xy_y) const
                {
                    xy_y = this->m_proj_parm.C_y * lp_lat;
                    xy_x = this->m_proj_parm.C_x * lp_lon * (this->m_proj_parm.A + asqrt(1. - this->m_proj_parm.B * lp_lat * lp_lat));
                }

                // INVERSE(s_inverse)  spheroid
                // Project coordinates from cartesian (x, y) to geographic (lon, lat)
                inline void inv(cartesian_type& xy_x, cartesian_type& xy_y, geographic_type& lp_lon, geographic_type& lp_lat) const
                {
                    lp_lat = xy_y / this->m_proj_parm.C_y;
                    lp_lon = xy_x / (this->m_proj_parm.C_x * (this->m_proj_parm.A + asqrt(1. - this->m_proj_parm.B * lp_lat * lp_lat)));
                }

                static inline std::string get_name()
                {
                    return "eck3_spheroid";
                }

            };

            template <typename Parameters, typename T>
            inline void setup(Parameters& par, par_eck3<T>& proj_parm) 
            {
                boost::ignore_unused(proj_parm);
                par.es = 0.;
            }


            // Eckert III
            template <typename Parameters, typename T>
            inline void setup_eck3(Parameters& par, par_eck3<T>& proj_parm)
            {
                proj_parm.C_x = .42223820031577120149;
                proj_parm.C_y = .84447640063154240298;
                proj_parm.A = 1.;
                proj_parm.B = 0.4052847345693510857755;
                setup(par, proj_parm);
            }

            // Putnins P1
            template <typename Parameters, typename T>
            inline void setup_putp1(Parameters& par, par_eck3<T>& proj_parm)
            {
                proj_parm.C_x = 1.89490;
                proj_parm.C_y = 0.94745;
                proj_parm.A = -0.5;
                proj_parm.B = 0.30396355092701331433;
                setup(par, proj_parm);
            }

            // Wagner VI
            template <typename Parameters, typename T>
            inline void setup_wag6(Parameters& par, par_eck3<T>& proj_parm)
            {
                proj_parm.C_x = proj_parm.C_y = 0.94745;
                proj_parm.A = 0.;
                proj_parm.B = 0.30396355092701331433;
                setup(par, proj_parm);
            }

            // Kavraisky VII
            template <typename Parameters, typename T>
            inline void setup_kav7(Parameters& par, par_eck3<T>& proj_parm)
            {
                proj_parm.C_x = 0.2632401569273184856851;
                proj_parm.C_x = 0.8660254037844;
                proj_parm.C_y = 1.;
                proj_parm.A = 0.;
                proj_parm.B = 0.30396355092701331433;
                setup(par, proj_parm);
            }

    }} // namespace detail::eck3
    #endif // doxygen

    /*!
        \brief Eckert III projection
        \ingroup projections
        \tparam Geographic latlong point type
        \tparam Cartesian xy point type
        \tparam Parameters parameter type
        \par Projection characteristics
         - Pseudocylindrical
         - Spheroid
        \par Example
        \image html ex_eck3.gif
    */
    template <typename CalculationType, typename Parameters>
    struct eck3_spheroid : public detail::eck3::base_eck3_spheroid<CalculationType, Parameters>
    {
        inline eck3_spheroid(const Parameters& par) : detail::eck3::base_eck3_spheroid<CalculationType, Parameters>(par)
        {
            detail::eck3::setup_eck3(this->m_par, this->m_proj_parm);
        }
    };

    /*!
        \brief Putnins P1 projection
        \ingroup projections
        \tparam Geographic latlong point type
        \tparam Cartesian xy point type
        \tparam Parameters parameter type
        \par Projection characteristics
         - Pseudocylindrical
         - Spheroid
        \par Example
        \image html ex_putp1.gif
    */
    template <typename CalculationType, typename Parameters>
    struct putp1_spheroid : public detail::eck3::base_eck3_spheroid<CalculationType, Parameters>
    {
        inline putp1_spheroid(const Parameters& par) : detail::eck3::base_eck3_spheroid<CalculationType, Parameters>(par)
        {
            detail::eck3::setup_putp1(this->m_par, this->m_proj_parm);
        }
    };

    /*!
        \brief Wagner VI projection
        \ingroup projections
        \tparam Geographic latlong point type
        \tparam Cartesian xy point type
        \tparam Parameters parameter type
        \par Projection characteristics
         - Pseudocylindrical
         - Spheroid
        \par Example
        \image html ex_wag6.gif
    */
    template <typename CalculationType, typename Parameters>
    struct wag6_spheroid : public detail::eck3::base_eck3_spheroid<CalculationType, Parameters>
    {
        inline wag6_spheroid(const Parameters& par) : detail::eck3::base_eck3_spheroid<CalculationType, Parameters>(par)
        {
            detail::eck3::setup_wag6(this->m_par, this->m_proj_parm);
        }
    };

    /*!
        \brief Kavraisky VII projection
        \ingroup projections
        \tparam Geographic latlong point type
        \tparam Cartesian xy point type
        \tparam Parameters parameter type
        \par Projection characteristics
         - Pseudocylindrical
         - Spheroid
        \par Example
        \image html ex_kav7.gif
    */
    template <typename CalculationType, typename Parameters>
    struct kav7_spheroid : public detail::eck3::base_eck3_spheroid<CalculationType, Parameters>
    {
        inline kav7_spheroid(const Parameters& par) : detail::eck3::base_eck3_spheroid<CalculationType, Parameters>(par)
        {
            detail::eck3::setup_kav7(this->m_par, this->m_proj_parm);
        }
    };

    #ifndef DOXYGEN_NO_DETAIL
    namespace detail
    {

        // Static projection
        BOOST_GEOMETRY_PROJECTIONS_DETAIL_STATIC_PROJECTION(srs::par4::eck3, eck3_spheroid, eck3_spheroid)
        BOOST_GEOMETRY_PROJECTIONS_DETAIL_STATIC_PROJECTION(srs::par4::putp1, putp1_spheroid, putp1_spheroid)
        BOOST_GEOMETRY_PROJECTIONS_DETAIL_STATIC_PROJECTION(srs::par4::wag6, wag6_spheroid, wag6_spheroid)
        BOOST_GEOMETRY_PROJECTIONS_DETAIL_STATIC_PROJECTION(srs::par4::kav7, kav7_spheroid, kav7_spheroid)

        // Factory entry(s)
        template <typename CalculationType, typename Parameters>
        class eck3_entry : public detail::factory_entry<CalculationType, Parameters>
        {
            public :
                virtual base_v<CalculationType, Parameters>* create_new(const Parameters& par) const
                {
                    return new base_v_fi<eck3_spheroid<CalculationType, Parameters>, CalculationType, Parameters>(par);
                }
        };

        template <typename CalculationType, typename Parameters>
        class putp1_entry : public detail::factory_entry<CalculationType, Parameters>
        {
            public :
                virtual base_v<CalculationType, Parameters>* create_new(const Parameters& par) const
                {
                    return new base_v_fi<putp1_spheroid<CalculationType, Parameters>, CalculationType, Parameters>(par);
                }
        };

        template <typename CalculationType, typename Parameters>
        class wag6_entry : public detail::factory_entry<CalculationType, Parameters>
        {
            public :
                virtual base_v<CalculationType, Parameters>* create_new(const Parameters& par) const
                {
                    return new base_v_fi<wag6_spheroid<CalculationType, Parameters>, CalculationType, Parameters>(par);
                }
        };

        template <typename CalculationType, typename Parameters>
        class kav7_entry : public detail::factory_entry<CalculationType, Parameters>
        {
            public :
                virtual base_v<CalculationType, Parameters>* create_new(const Parameters& par) const
                {
                    return new base_v_fi<kav7_spheroid<CalculationType, Parameters>, CalculationType, Parameters>(par);
                }
        };

        template <typename CalculationType, typename Parameters>
        inline void eck3_init(detail::base_factory<CalculationType, Parameters>& factory)
        {
            factory.add_to_factory("eck3", new eck3_entry<CalculationType, Parameters>);
            factory.add_to_factory("putp1", new putp1_entry<CalculationType, Parameters>);
            factory.add_to_factory("wag6", new wag6_entry<CalculationType, Parameters>);
            factory.add_to_factory("kav7", new kav7_entry<CalculationType, Parameters>);
        }

    } // namespace detail
    #endif // doxygen

} // namespace projections

}} // namespace boost::geometry

#endif // BOOST_GEOMETRY_PROJECTIONS_ECK3_HPP

