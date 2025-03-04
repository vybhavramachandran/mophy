// Copyright (c) 2005-2014 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis Tools CC gives
// permission to link this program with the Xerces-C++ library (or with
// modified versions of Xerces-C++ that use the same license as Xerces-C++),
// and distribute linked combinations including the two. You must obey
// the GNU General Public License version 2 in all respects for all of
// the code used other than Xerces-C++. If you modify this copy of the
// program, you may extend this exception to your version of the program,
// but you are not obligated to do so. If you do not wish to do so, delete
// this exception statement from your version.
//
// Furthermore, Code Synthesis Tools CC makes a special exception for
// the Free/Libre and Open Source Software (FLOSS) which is described
// in the accompanying FLOSSE file.
//

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/pre.hxx>

#include "BioGearsEnvironment.hxx"

namespace mil
{
  namespace tatrc
  {
    namespace physiology
    {
      namespace datamodel
      {
        // BioGearsEnvironmentData
        // 

        const BioGearsEnvironmentData::PatientEquivalentDiameter_m_type& BioGearsEnvironmentData::
        PatientEquivalentDiameter_m () const
        {
          return this->PatientEquivalentDiameter_m_.get ();
        }

        BioGearsEnvironmentData::PatientEquivalentDiameter_m_type& BioGearsEnvironmentData::
        PatientEquivalentDiameter_m ()
        {
          return this->PatientEquivalentDiameter_m_.get ();
        }

        void BioGearsEnvironmentData::
        PatientEquivalentDiameter_m (const PatientEquivalentDiameter_m_type& x)
        {
          this->PatientEquivalentDiameter_m_.set (x);
        }
      }
    }
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

#include <xsd/cxx/tree/type-factory-map.hxx>

namespace _xsd
{
  static
  const ::xsd::cxx::tree::type_factory_plate< 0, char >
  type_factory_plate_init;
}

namespace mil
{
  namespace tatrc
  {
    namespace physiology
    {
      namespace datamodel
      {
        // BioGearsEnvironmentData
        //

        BioGearsEnvironmentData::
        BioGearsEnvironmentData ()
        : ::mil::tatrc::physiology::datamodel::EnvironmentData (),
          PatientEquivalentDiameter_m_ (this)
        {
        }

        BioGearsEnvironmentData::
        BioGearsEnvironmentData (const PatientEquivalentDiameter_m_type& PatientEquivalentDiameter_m)
        : ::mil::tatrc::physiology::datamodel::EnvironmentData (),
          PatientEquivalentDiameter_m_ (PatientEquivalentDiameter_m, this)
        {
        }

        BioGearsEnvironmentData::
        BioGearsEnvironmentData (const BioGearsEnvironmentData& x,
                                 ::xml_schema::flags f,
                                 ::xml_schema::container* c)
        : ::mil::tatrc::physiology::datamodel::EnvironmentData (x, f, c),
          PatientEquivalentDiameter_m_ (x.PatientEquivalentDiameter_m_, f, this)
        {
        }

        BioGearsEnvironmentData::
        BioGearsEnvironmentData (const ::xercesc::DOMElement& e,
                                 ::xml_schema::flags f,
                                 ::xml_schema::container* c)
        : ::mil::tatrc::physiology::datamodel::EnvironmentData (e, f | ::xml_schema::flags::base, c),
          PatientEquivalentDiameter_m_ (this)
        {
          if ((f & ::xml_schema::flags::base) == 0)
          {
            ::xsd::cxx::xml::dom::parser< char > p (e, true, false, true);
            this->parse (p, f);
          }
        }

        void BioGearsEnvironmentData::
        parse (::xsd::cxx::xml::dom::parser< char >& p,
               ::xml_schema::flags f)
        {
          this->::mil::tatrc::physiology::datamodel::EnvironmentData::parse (p, f);

          for (; p.more_content (); p.next_content (false))
          {
            const ::xercesc::DOMElement& i (p.cur_element ());
            const ::xsd::cxx::xml::qualified_name< char > n (
              ::xsd::cxx::xml::dom::name< char > (i));

            // PatientEquivalentDiameter_m
            //
            if (n.name () == "PatientEquivalentDiameter_m" && n.namespace_ () == "uri:/mil/tatrc/physiology/datamodel")
            {
              if (!PatientEquivalentDiameter_m_.present ())
              {
                this->PatientEquivalentDiameter_m_.set (PatientEquivalentDiameter_m_traits::create (i, f, this));
                continue;
              }
            }

            break;
          }

          if (!PatientEquivalentDiameter_m_.present ())
          {
            throw ::xsd::cxx::tree::expected_element< char > (
              "PatientEquivalentDiameter_m",
              "uri:/mil/tatrc/physiology/datamodel");
          }
        }

        BioGearsEnvironmentData* BioGearsEnvironmentData::
        _clone (::xml_schema::flags f,
                ::xml_schema::container* c) const
        {
          return new class BioGearsEnvironmentData (*this, f, c);
        }

        BioGearsEnvironmentData& BioGearsEnvironmentData::
        operator= (const BioGearsEnvironmentData& x)
        {
          if (this != &x)
          {
            static_cast< ::mil::tatrc::physiology::datamodel::EnvironmentData& > (*this) = x;
            this->PatientEquivalentDiameter_m_ = x.PatientEquivalentDiameter_m_;
          }

          return *this;
        }

        BioGearsEnvironmentData::
        ~BioGearsEnvironmentData ()
        {
        }

        static
        const ::xsd::cxx::tree::type_factory_initializer< 0, char, BioGearsEnvironmentData >
        _xsd_BioGearsEnvironmentData_type_factory_init (
          "BioGearsEnvironmentData",
          "uri:/mil/tatrc/physiology/datamodel");
      }
    }
  }
}

#include <ostream>

#include <xsd/cxx/tree/std-ostream-map.hxx>

namespace _xsd
{
  static
  const ::xsd::cxx::tree::std_ostream_plate< 0, char >
  std_ostream_plate_init;
}

namespace mil
{
  namespace tatrc
  {
    namespace physiology
    {
      namespace datamodel
      {
        ::std::ostream&
        operator<< (::std::ostream& o, const BioGearsEnvironmentData& i)
        {
          o << static_cast< const ::mil::tatrc::physiology::datamodel::EnvironmentData& > (i);

          o << ::std::endl << "PatientEquivalentDiameter_m: " << i.PatientEquivalentDiameter_m ();
          return o;
        }

        static
        const ::xsd::cxx::tree::std_ostream_initializer< 0, char, BioGearsEnvironmentData >
        _xsd_BioGearsEnvironmentData_std_ostream_init;
      }
    }
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace mil
{
  namespace tatrc
  {
    namespace physiology
    {
      namespace datamodel
      {
      }
    }
  }
}

#include <ostream>
#include <xsd/cxx/tree/error-handler.hxx>
#include <xsd/cxx/xml/dom/serialization-source.hxx>

#include <xsd/cxx/tree/type-serializer-map.hxx>

namespace _xsd
{
  static
  const ::xsd::cxx::tree::type_serializer_plate< 0, char >
  type_serializer_plate_init;
}

namespace mil
{
  namespace tatrc
  {
    namespace physiology
    {
      namespace datamodel
      {
        void
        operator<< (::xercesc::DOMElement& e, const BioGearsEnvironmentData& i)
        {
          e << static_cast< const ::mil::tatrc::physiology::datamodel::EnvironmentData& > (i);

          // PatientEquivalentDiameter_m
          //
          {
            ::xercesc::DOMElement& s (
              ::xsd::cxx::xml::dom::create_element (
                "PatientEquivalentDiameter_m",
                "uri:/mil/tatrc/physiology/datamodel",
                e));

            s << ::xml_schema::as_double(i.PatientEquivalentDiameter_m ());
          }
        }

        static
        const ::xsd::cxx::tree::type_serializer_initializer< 0, char, BioGearsEnvironmentData >
        _xsd_BioGearsEnvironmentData_type_serializer_init (
          "BioGearsEnvironmentData",
          "uri:/mil/tatrc/physiology/datamodel");
      }
    }
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

