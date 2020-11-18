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

#include "Inhaler.hxx"

namespace mil
{
  namespace tatrc
  {
    namespace physiology
    {
      namespace datamodel
      {
        // InhalerData
        // 

        const InhalerData::State_optional& InhalerData::
        State () const
        {
          return this->State_;
        }

        InhalerData::State_optional& InhalerData::
        State ()
        {
          return this->State_;
        }

        void InhalerData::
        State (const State_type& x)
        {
          this->State_.set (x);
        }

        void InhalerData::
        State (const State_optional& x)
        {
          this->State_ = x;
        }

        void InhalerData::
        State (::std::unique_ptr< State_type > x)
        {
          this->State_.set (std::move (x));
        }

        const InhalerData::Substance_optional& InhalerData::
        Substance () const
        {
          return this->Substance_;
        }

        InhalerData::Substance_optional& InhalerData::
        Substance ()
        {
          return this->Substance_;
        }

        void InhalerData::
        Substance (const Substance_type& x)
        {
          this->Substance_.set (x);
        }

        void InhalerData::
        Substance (const Substance_optional& x)
        {
          this->Substance_ = x;
        }

        void InhalerData::
        Substance (::std::unique_ptr< Substance_type > x)
        {
          this->Substance_.set (std::move (x));
        }

        const InhalerData::MeteredDose_optional& InhalerData::
        MeteredDose () const
        {
          return this->MeteredDose_;
        }

        InhalerData::MeteredDose_optional& InhalerData::
        MeteredDose ()
        {
          return this->MeteredDose_;
        }

        void InhalerData::
        MeteredDose (const MeteredDose_type& x)
        {
          this->MeteredDose_.set (x);
        }

        void InhalerData::
        MeteredDose (const MeteredDose_optional& x)
        {
          this->MeteredDose_ = x;
        }

        void InhalerData::
        MeteredDose (::std::unique_ptr< MeteredDose_type > x)
        {
          this->MeteredDose_.set (std::move (x));
        }

        const InhalerData::NozzleLoss_optional& InhalerData::
        NozzleLoss () const
        {
          return this->NozzleLoss_;
        }

        InhalerData::NozzleLoss_optional& InhalerData::
        NozzleLoss ()
        {
          return this->NozzleLoss_;
        }

        void InhalerData::
        NozzleLoss (const NozzleLoss_type& x)
        {
          this->NozzleLoss_.set (x);
        }

        void InhalerData::
        NozzleLoss (const NozzleLoss_optional& x)
        {
          this->NozzleLoss_ = x;
        }

        void InhalerData::
        NozzleLoss (::std::unique_ptr< NozzleLoss_type > x)
        {
          this->NozzleLoss_.set (std::move (x));
        }

        const InhalerData::SpacerVolume_optional& InhalerData::
        SpacerVolume () const
        {
          return this->SpacerVolume_;
        }

        InhalerData::SpacerVolume_optional& InhalerData::
        SpacerVolume ()
        {
          return this->SpacerVolume_;
        }

        void InhalerData::
        SpacerVolume (const SpacerVolume_type& x)
        {
          this->SpacerVolume_.set (x);
        }

        void InhalerData::
        SpacerVolume (const SpacerVolume_optional& x)
        {
          this->SpacerVolume_ = x;
        }

        void InhalerData::
        SpacerVolume (::std::unique_ptr< SpacerVolume_type > x)
        {
          this->SpacerVolume_.set (std::move (x));
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
        // InhalerData
        //

        InhalerData::
        InhalerData ()
        : ::mil::tatrc::physiology::datamodel::SystemData (),
          State_ (this),
          Substance_ (this),
          MeteredDose_ (this),
          NozzleLoss_ (this),
          SpacerVolume_ (this)
        {
        }

        InhalerData::
        InhalerData (const InhalerData& x,
                     ::xml_schema::flags f,
                     ::xml_schema::container* c)
        : ::mil::tatrc::physiology::datamodel::SystemData (x, f, c),
          State_ (x.State_, f, this),
          Substance_ (x.Substance_, f, this),
          MeteredDose_ (x.MeteredDose_, f, this),
          NozzleLoss_ (x.NozzleLoss_, f, this),
          SpacerVolume_ (x.SpacerVolume_, f, this)
        {
        }

        InhalerData::
        InhalerData (const ::xercesc::DOMElement& e,
                     ::xml_schema::flags f,
                     ::xml_schema::container* c)
        : ::mil::tatrc::physiology::datamodel::SystemData (e, f | ::xml_schema::flags::base, c),
          State_ (this),
          Substance_ (this),
          MeteredDose_ (this),
          NozzleLoss_ (this),
          SpacerVolume_ (this)
        {
          if ((f & ::xml_schema::flags::base) == 0)
          {
            ::xsd::cxx::xml::dom::parser< char > p (e, true, false, true);
            this->parse (p, f);
          }
        }

        void InhalerData::
        parse (::xsd::cxx::xml::dom::parser< char >& p,
               ::xml_schema::flags f)
        {
          this->::mil::tatrc::physiology::datamodel::SystemData::parse (p, f);

          for (; p.more_content (); p.next_content (false))
          {
            const ::xercesc::DOMElement& i (p.cur_element ());
            const ::xsd::cxx::xml::qualified_name< char > n (
              ::xsd::cxx::xml::dom::name< char > (i));

            // State
            //
            {
              ::std::unique_ptr< ::xsd::cxx::tree::type > tmp (
                ::xsd::cxx::tree::type_factory_map_instance< 0, char > ().create (
                  "State",
                  "uri:/mil/tatrc/physiology/datamodel",
                  &::xsd::cxx::tree::factory_impl< State_type >,
                  false, true, i, n, f, this));

              if (tmp.get () != 0)
              {
                if (!this->State_)
                {
                  ::std::unique_ptr< State_type > r (
                    dynamic_cast< State_type* > (tmp.get ()));

                  if (r.get ())
                    tmp.release ();
                  else
                    throw ::xsd::cxx::tree::not_derived< char > ();

                  this->State_.set (::std::move (r));
                  continue;
                }
              }
            }

            // Substance
            //
            {
              ::std::unique_ptr< ::xsd::cxx::tree::type > tmp (
                ::xsd::cxx::tree::type_factory_map_instance< 0, char > ().create (
                  "Substance",
                  "uri:/mil/tatrc/physiology/datamodel",
                  &::xsd::cxx::tree::factory_impl< Substance_type >,
                  false, true, i, n, f, this));

              if (tmp.get () != 0)
              {
                if (!this->Substance_)
                {
                  ::std::unique_ptr< Substance_type > r (
                    dynamic_cast< Substance_type* > (tmp.get ()));

                  if (r.get ())
                    tmp.release ();
                  else
                    throw ::xsd::cxx::tree::not_derived< char > ();

                  this->Substance_.set (::std::move (r));
                  continue;
                }
              }
            }

            // MeteredDose
            //
            {
              ::std::unique_ptr< ::xsd::cxx::tree::type > tmp (
                ::xsd::cxx::tree::type_factory_map_instance< 0, char > ().create (
                  "MeteredDose",
                  "uri:/mil/tatrc/physiology/datamodel",
                  &::xsd::cxx::tree::factory_impl< MeteredDose_type >,
                  false, true, i, n, f, this));

              if (tmp.get () != 0)
              {
                if (!this->MeteredDose_)
                {
                  ::std::unique_ptr< MeteredDose_type > r (
                    dynamic_cast< MeteredDose_type* > (tmp.get ()));

                  if (r.get ())
                    tmp.release ();
                  else
                    throw ::xsd::cxx::tree::not_derived< char > ();

                  this->MeteredDose_.set (::std::move (r));
                  continue;
                }
              }
            }

            // NozzleLoss
            //
            {
              ::std::unique_ptr< ::xsd::cxx::tree::type > tmp (
                ::xsd::cxx::tree::type_factory_map_instance< 0, char > ().create (
                  "NozzleLoss",
                  "uri:/mil/tatrc/physiology/datamodel",
                  &::xsd::cxx::tree::factory_impl< NozzleLoss_type >,
                  false, true, i, n, f, this));

              if (tmp.get () != 0)
              {
                if (!this->NozzleLoss_)
                {
                  ::std::unique_ptr< NozzleLoss_type > r (
                    dynamic_cast< NozzleLoss_type* > (tmp.get ()));

                  if (r.get ())
                    tmp.release ();
                  else
                    throw ::xsd::cxx::tree::not_derived< char > ();

                  this->NozzleLoss_.set (::std::move (r));
                  continue;
                }
              }
            }

            // SpacerVolume
            //
            {
              ::std::unique_ptr< ::xsd::cxx::tree::type > tmp (
                ::xsd::cxx::tree::type_factory_map_instance< 0, char > ().create (
                  "SpacerVolume",
                  "uri:/mil/tatrc/physiology/datamodel",
                  &::xsd::cxx::tree::factory_impl< SpacerVolume_type >,
                  false, true, i, n, f, this));

              if (tmp.get () != 0)
              {
                if (!this->SpacerVolume_)
                {
                  ::std::unique_ptr< SpacerVolume_type > r (
                    dynamic_cast< SpacerVolume_type* > (tmp.get ()));

                  if (r.get ())
                    tmp.release ();
                  else
                    throw ::xsd::cxx::tree::not_derived< char > ();

                  this->SpacerVolume_.set (::std::move (r));
                  continue;
                }
              }
            }

            break;
          }
        }

        InhalerData* InhalerData::
        _clone (::xml_schema::flags f,
                ::xml_schema::container* c) const
        {
          return new class InhalerData (*this, f, c);
        }

        InhalerData& InhalerData::
        operator= (const InhalerData& x)
        {
          if (this != &x)
          {
            static_cast< ::mil::tatrc::physiology::datamodel::SystemData& > (*this) = x;
            this->State_ = x.State_;
            this->Substance_ = x.Substance_;
            this->MeteredDose_ = x.MeteredDose_;
            this->NozzleLoss_ = x.NozzleLoss_;
            this->SpacerVolume_ = x.SpacerVolume_;
          }

          return *this;
        }

        InhalerData::
        ~InhalerData ()
        {
        }

        static
        const ::xsd::cxx::tree::type_factory_initializer< 0, char, InhalerData >
        _xsd_InhalerData_type_factory_init (
          "InhalerData",
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
        operator<< (::std::ostream& o, const InhalerData& i)
        {
          o << static_cast< const ::mil::tatrc::physiology::datamodel::SystemData& > (i);

          {
            ::xsd::cxx::tree::std_ostream_map< char >& om (
              ::xsd::cxx::tree::std_ostream_map_instance< 0, char > ());

            if (i.State ())
            {
              o << ::std::endl << "State: ";
              om.insert (o, *i.State ());
            }
          }

          {
            ::xsd::cxx::tree::std_ostream_map< char >& om (
              ::xsd::cxx::tree::std_ostream_map_instance< 0, char > ());

            if (i.Substance ())
            {
              o << ::std::endl << "Substance: ";
              om.insert (o, *i.Substance ());
            }
          }

          {
            ::xsd::cxx::tree::std_ostream_map< char >& om (
              ::xsd::cxx::tree::std_ostream_map_instance< 0, char > ());

            if (i.MeteredDose ())
            {
              o << ::std::endl << "MeteredDose: ";
              om.insert (o, *i.MeteredDose ());
            }
          }

          {
            ::xsd::cxx::tree::std_ostream_map< char >& om (
              ::xsd::cxx::tree::std_ostream_map_instance< 0, char > ());

            if (i.NozzleLoss ())
            {
              o << ::std::endl << "NozzleLoss: ";
              om.insert (o, *i.NozzleLoss ());
            }
          }

          {
            ::xsd::cxx::tree::std_ostream_map< char >& om (
              ::xsd::cxx::tree::std_ostream_map_instance< 0, char > ());

            if (i.SpacerVolume ())
            {
              o << ::std::endl << "SpacerVolume: ";
              om.insert (o, *i.SpacerVolume ());
            }
          }

          return o;
        }

        static
        const ::xsd::cxx::tree::std_ostream_initializer< 0, char, InhalerData >
        _xsd_InhalerData_std_ostream_init;
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
        ::std::unique_ptr< ::mil::tatrc::physiology::datamodel::InhalerData >
        Inhaler (const ::std::string& u,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p)
        {
          ::xsd::cxx::xml::auto_initializer i (
            (f & ::xml_schema::flags::dont_initialize) == 0,
            (f & ::xml_schema::flags::keep_dom) == 0);

          ::xsd::cxx::tree::error_handler< char > h;

          ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
            ::xsd::cxx::xml::dom::parse< char > (
              u, h, p, f));

          h.throw_if_failed< ::xsd::cxx::tree::parsing< char > > ();

          return ::std::unique_ptr< ::mil::tatrc::physiology::datamodel::InhalerData > (
            ::mil::tatrc::physiology::datamodel::Inhaler (
              std::move (d), f | ::xml_schema::flags::own_dom, p));
        }

        ::std::unique_ptr< ::mil::tatrc::physiology::datamodel::InhalerData >
        Inhaler (const ::std::string& u,
                 ::xml_schema::error_handler& h,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p)
        {
          ::xsd::cxx::xml::auto_initializer i (
            (f & ::xml_schema::flags::dont_initialize) == 0,
            (f & ::xml_schema::flags::keep_dom) == 0);

          ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
            ::xsd::cxx::xml::dom::parse< char > (
              u, h, p, f));

          if (!d.get ())
            throw ::xsd::cxx::tree::parsing< char > ();

          return ::std::unique_ptr< ::mil::tatrc::physiology::datamodel::InhalerData > (
            ::mil::tatrc::physiology::datamodel::Inhaler (
              std::move (d), f | ::xml_schema::flags::own_dom, p));
        }

        ::std::unique_ptr< ::mil::tatrc::physiology::datamodel::InhalerData >
        Inhaler (const ::std::string& u,
                 ::xercesc::DOMErrorHandler& h,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p)
        {
          ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
            ::xsd::cxx::xml::dom::parse< char > (
              u, h, p, f));

          if (!d.get ())
            throw ::xsd::cxx::tree::parsing< char > ();

          return ::std::unique_ptr< ::mil::tatrc::physiology::datamodel::InhalerData > (
            ::mil::tatrc::physiology::datamodel::Inhaler (
              std::move (d), f | ::xml_schema::flags::own_dom, p));
        }

        ::std::unique_ptr< ::mil::tatrc::physiology::datamodel::InhalerData >
        Inhaler (::std::istream& is,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p)
        {
          ::xsd::cxx::xml::auto_initializer i (
            (f & ::xml_schema::flags::dont_initialize) == 0,
            (f & ::xml_schema::flags::keep_dom) == 0);

          ::xsd::cxx::xml::sax::std_input_source isrc (is);
          return ::mil::tatrc::physiology::datamodel::Inhaler (isrc, f, p);
        }

        ::std::unique_ptr< ::mil::tatrc::physiology::datamodel::InhalerData >
        Inhaler (::std::istream& is,
                 ::xml_schema::error_handler& h,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p)
        {
          ::xsd::cxx::xml::auto_initializer i (
            (f & ::xml_schema::flags::dont_initialize) == 0,
            (f & ::xml_schema::flags::keep_dom) == 0);

          ::xsd::cxx::xml::sax::std_input_source isrc (is);
          return ::mil::tatrc::physiology::datamodel::Inhaler (isrc, h, f, p);
        }

        ::std::unique_ptr< ::mil::tatrc::physiology::datamodel::InhalerData >
        Inhaler (::std::istream& is,
                 ::xercesc::DOMErrorHandler& h,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p)
        {
          ::xsd::cxx::xml::sax::std_input_source isrc (is);
          return ::mil::tatrc::physiology::datamodel::Inhaler (isrc, h, f, p);
        }

        ::std::unique_ptr< ::mil::tatrc::physiology::datamodel::InhalerData >
        Inhaler (::std::istream& is,
                 const ::std::string& sid,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p)
        {
          ::xsd::cxx::xml::auto_initializer i (
            (f & ::xml_schema::flags::dont_initialize) == 0,
            (f & ::xml_schema::flags::keep_dom) == 0);

          ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
          return ::mil::tatrc::physiology::datamodel::Inhaler (isrc, f, p);
        }

        ::std::unique_ptr< ::mil::tatrc::physiology::datamodel::InhalerData >
        Inhaler (::std::istream& is,
                 const ::std::string& sid,
                 ::xml_schema::error_handler& h,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p)
        {
          ::xsd::cxx::xml::auto_initializer i (
            (f & ::xml_schema::flags::dont_initialize) == 0,
            (f & ::xml_schema::flags::keep_dom) == 0);

          ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
          return ::mil::tatrc::physiology::datamodel::Inhaler (isrc, h, f, p);
        }

        ::std::unique_ptr< ::mil::tatrc::physiology::datamodel::InhalerData >
        Inhaler (::std::istream& is,
                 const ::std::string& sid,
                 ::xercesc::DOMErrorHandler& h,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p)
        {
          ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
          return ::mil::tatrc::physiology::datamodel::Inhaler (isrc, h, f, p);
        }

        ::std::unique_ptr< ::mil::tatrc::physiology::datamodel::InhalerData >
        Inhaler (::xercesc::InputSource& i,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p)
        {
          ::xsd::cxx::tree::error_handler< char > h;

          ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
            ::xsd::cxx::xml::dom::parse< char > (
              i, h, p, f));

          h.throw_if_failed< ::xsd::cxx::tree::parsing< char > > ();

          return ::std::unique_ptr< ::mil::tatrc::physiology::datamodel::InhalerData > (
            ::mil::tatrc::physiology::datamodel::Inhaler (
              std::move (d), f | ::xml_schema::flags::own_dom, p));
        }

        ::std::unique_ptr< ::mil::tatrc::physiology::datamodel::InhalerData >
        Inhaler (::xercesc::InputSource& i,
                 ::xml_schema::error_handler& h,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p)
        {
          ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
            ::xsd::cxx::xml::dom::parse< char > (
              i, h, p, f));

          if (!d.get ())
            throw ::xsd::cxx::tree::parsing< char > ();

          return ::std::unique_ptr< ::mil::tatrc::physiology::datamodel::InhalerData > (
            ::mil::tatrc::physiology::datamodel::Inhaler (
              std::move (d), f | ::xml_schema::flags::own_dom, p));
        }

        ::std::unique_ptr< ::mil::tatrc::physiology::datamodel::InhalerData >
        Inhaler (::xercesc::InputSource& i,
                 ::xercesc::DOMErrorHandler& h,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p)
        {
          ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
            ::xsd::cxx::xml::dom::parse< char > (
              i, h, p, f));

          if (!d.get ())
            throw ::xsd::cxx::tree::parsing< char > ();

          return ::std::unique_ptr< ::mil::tatrc::physiology::datamodel::InhalerData > (
            ::mil::tatrc::physiology::datamodel::Inhaler (
              std::move (d), f | ::xml_schema::flags::own_dom, p));
        }

        ::std::unique_ptr< ::mil::tatrc::physiology::datamodel::InhalerData >
        Inhaler (const ::xercesc::DOMDocument& doc,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p)
        {
          if (f & ::xml_schema::flags::keep_dom)
          {
            ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
              static_cast< ::xercesc::DOMDocument* > (doc.cloneNode (true)));

            return ::std::unique_ptr< ::mil::tatrc::physiology::datamodel::InhalerData > (
              ::mil::tatrc::physiology::datamodel::Inhaler (
                std::move (d), f | ::xml_schema::flags::own_dom, p));
          }

          const ::xercesc::DOMElement& e (*doc.getDocumentElement ());
          const ::xsd::cxx::xml::qualified_name< char > n (
            ::xsd::cxx::xml::dom::name< char > (e));

          ::std::unique_ptr< ::xsd::cxx::tree::type > tmp (
            ::xsd::cxx::tree::type_factory_map_instance< 0, char > ().create (
              "Inhaler",
              "uri:/mil/tatrc/physiology/datamodel",
              &::xsd::cxx::tree::factory_impl< ::mil::tatrc::physiology::datamodel::InhalerData >,
              true, true, e, n, f, 0));

          if (tmp.get () != 0)
          {
            ::std::unique_ptr< ::mil::tatrc::physiology::datamodel::InhalerData > r (
              dynamic_cast< ::mil::tatrc::physiology::datamodel::InhalerData* > (tmp.get ()));

            if (r.get ())
              tmp.release ();
            else
              throw ::xsd::cxx::tree::not_derived< char > ();

            return r;
          }

          throw ::xsd::cxx::tree::unexpected_element < char > (
            n.name (),
            n.namespace_ (),
            "Inhaler",
            "uri:/mil/tatrc/physiology/datamodel");
        }

        ::std::unique_ptr< ::mil::tatrc::physiology::datamodel::InhalerData >
        Inhaler (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties&)
        {
          ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > c (
            ((f & ::xml_schema::flags::keep_dom) &&
             !(f & ::xml_schema::flags::own_dom))
            ? static_cast< ::xercesc::DOMDocument* > (d->cloneNode (true))
            : 0);

          ::xercesc::DOMDocument& doc (c.get () ? *c : *d);
          const ::xercesc::DOMElement& e (*doc.getDocumentElement ());

          const ::xsd::cxx::xml::qualified_name< char > n (
            ::xsd::cxx::xml::dom::name< char > (e));

          if (f & ::xml_schema::flags::keep_dom)
            doc.setUserData (::xml_schema::dom::tree_node_key,
                             (c.get () ? &c : &d),
                             0);

          ::std::unique_ptr< ::xsd::cxx::tree::type > tmp (
            ::xsd::cxx::tree::type_factory_map_instance< 0, char > ().create (
              "Inhaler",
              "uri:/mil/tatrc/physiology/datamodel",
              &::xsd::cxx::tree::factory_impl< ::mil::tatrc::physiology::datamodel::InhalerData >,
              true, true, e, n, f, 0));

          if (tmp.get () != 0)
          {

            ::std::unique_ptr< ::mil::tatrc::physiology::datamodel::InhalerData > r (
              dynamic_cast< ::mil::tatrc::physiology::datamodel::InhalerData* > (tmp.get ()));

            if (r.get ())
              tmp.release ();
            else
              throw ::xsd::cxx::tree::not_derived< char > ();

            return r;
          }

          throw ::xsd::cxx::tree::unexpected_element < char > (
            n.name (),
            n.namespace_ (),
            "Inhaler",
            "uri:/mil/tatrc/physiology/datamodel");
        }
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
        operator<< (::xercesc::DOMElement& e, const InhalerData& i)
        {
          e << static_cast< const ::mil::tatrc::physiology::datamodel::SystemData& > (i);

          // State
          //
          {
            ::xsd::cxx::tree::type_serializer_map< char >& tsm (
              ::xsd::cxx::tree::type_serializer_map_instance< 0, char > ());

            if (i.State ())
            {
              const InhalerData::State_type& x (*i.State ());
              if (typeid (InhalerData::State_type) == typeid (x))
              {
                ::xercesc::DOMElement& s (
                  ::xsd::cxx::xml::dom::create_element (
                    "State",
                    "uri:/mil/tatrc/physiology/datamodel",
                    e));

                s << x;
              }
              else
                tsm.serialize (
                  "State",
                  "uri:/mil/tatrc/physiology/datamodel",
                  false, true, e, x);
            }
          }

          // Substance
          //
          {
            ::xsd::cxx::tree::type_serializer_map< char >& tsm (
              ::xsd::cxx::tree::type_serializer_map_instance< 0, char > ());

            if (i.Substance ())
            {
              const InhalerData::Substance_type& x (*i.Substance ());
              if (typeid (InhalerData::Substance_type) == typeid (x))
              {
                ::xercesc::DOMElement& s (
                  ::xsd::cxx::xml::dom::create_element (
                    "Substance",
                    "uri:/mil/tatrc/physiology/datamodel",
                    e));

                s << x;
              }
              else
                tsm.serialize (
                  "Substance",
                  "uri:/mil/tatrc/physiology/datamodel",
                  false, true, e, x);
            }
          }

          // MeteredDose
          //
          {
            ::xsd::cxx::tree::type_serializer_map< char >& tsm (
              ::xsd::cxx::tree::type_serializer_map_instance< 0, char > ());

            if (i.MeteredDose ())
            {
              const InhalerData::MeteredDose_type& x (*i.MeteredDose ());
              if (typeid (InhalerData::MeteredDose_type) == typeid (x))
              {
                ::xercesc::DOMElement& s (
                  ::xsd::cxx::xml::dom::create_element (
                    "MeteredDose",
                    "uri:/mil/tatrc/physiology/datamodel",
                    e));

                s << x;
              }
              else
                tsm.serialize (
                  "MeteredDose",
                  "uri:/mil/tatrc/physiology/datamodel",
                  false, true, e, x);
            }
          }

          // NozzleLoss
          //
          {
            ::xsd::cxx::tree::type_serializer_map< char >& tsm (
              ::xsd::cxx::tree::type_serializer_map_instance< 0, char > ());

            if (i.NozzleLoss ())
            {
              const InhalerData::NozzleLoss_type& x (*i.NozzleLoss ());
              if (typeid (InhalerData::NozzleLoss_type) == typeid (x))
              {
                ::xercesc::DOMElement& s (
                  ::xsd::cxx::xml::dom::create_element (
                    "NozzleLoss",
                    "uri:/mil/tatrc/physiology/datamodel",
                    e));

                s << x;
              }
              else
                tsm.serialize (
                  "NozzleLoss",
                  "uri:/mil/tatrc/physiology/datamodel",
                  false, true, e, x);
            }
          }

          // SpacerVolume
          //
          {
            ::xsd::cxx::tree::type_serializer_map< char >& tsm (
              ::xsd::cxx::tree::type_serializer_map_instance< 0, char > ());

            if (i.SpacerVolume ())
            {
              const InhalerData::SpacerVolume_type& x (*i.SpacerVolume ());
              if (typeid (InhalerData::SpacerVolume_type) == typeid (x))
              {
                ::xercesc::DOMElement& s (
                  ::xsd::cxx::xml::dom::create_element (
                    "SpacerVolume",
                    "uri:/mil/tatrc/physiology/datamodel",
                    e));

                s << x;
              }
              else
                tsm.serialize (
                  "SpacerVolume",
                  "uri:/mil/tatrc/physiology/datamodel",
                  false, true, e, x);
            }
          }
        }

        static
        const ::xsd::cxx::tree::type_serializer_initializer< 0, char, InhalerData >
        _xsd_InhalerData_type_serializer_init (
          "InhalerData",
          "uri:/mil/tatrc/physiology/datamodel");


        void
        Inhaler (::std::ostream& o,
                 const ::mil::tatrc::physiology::datamodel::InhalerData& s,
                 const ::xml_schema::namespace_infomap& m,
                 const ::std::string& e,
                 ::xml_schema::flags f)
        {
          ::xsd::cxx::xml::auto_initializer i (
            (f & ::xml_schema::flags::dont_initialize) == 0);

          ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
            ::mil::tatrc::physiology::datamodel::Inhaler (s, m, f));

          ::xsd::cxx::tree::error_handler< char > h;

          ::xsd::cxx::xml::dom::ostream_format_target t (o);
          if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
          {
            h.throw_if_failed< ::xsd::cxx::tree::serialization< char > > ();
          }
        }

        void
        Inhaler (::std::ostream& o,
                 const ::mil::tatrc::physiology::datamodel::InhalerData& s,
                 ::xml_schema::error_handler& h,
                 const ::xml_schema::namespace_infomap& m,
                 const ::std::string& e,
                 ::xml_schema::flags f)
        {
          ::xsd::cxx::xml::auto_initializer i (
            (f & ::xml_schema::flags::dont_initialize) == 0);

          ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
            ::mil::tatrc::physiology::datamodel::Inhaler (s, m, f));
          ::xsd::cxx::xml::dom::ostream_format_target t (o);
          if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
          {
            throw ::xsd::cxx::tree::serialization< char > ();
          }
        }

        void
        Inhaler (::std::ostream& o,
                 const ::mil::tatrc::physiology::datamodel::InhalerData& s,
                 ::xercesc::DOMErrorHandler& h,
                 const ::xml_schema::namespace_infomap& m,
                 const ::std::string& e,
                 ::xml_schema::flags f)
        {
          ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
            ::mil::tatrc::physiology::datamodel::Inhaler (s, m, f));
          ::xsd::cxx::xml::dom::ostream_format_target t (o);
          if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
          {
            throw ::xsd::cxx::tree::serialization< char > ();
          }
        }

        void
        Inhaler (::xercesc::XMLFormatTarget& t,
                 const ::mil::tatrc::physiology::datamodel::InhalerData& s,
                 const ::xml_schema::namespace_infomap& m,
                 const ::std::string& e,
                 ::xml_schema::flags f)
        {
          ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
            ::mil::tatrc::physiology::datamodel::Inhaler (s, m, f));

          ::xsd::cxx::tree::error_handler< char > h;

          if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
          {
            h.throw_if_failed< ::xsd::cxx::tree::serialization< char > > ();
          }
        }

        void
        Inhaler (::xercesc::XMLFormatTarget& t,
                 const ::mil::tatrc::physiology::datamodel::InhalerData& s,
                 ::xml_schema::error_handler& h,
                 const ::xml_schema::namespace_infomap& m,
                 const ::std::string& e,
                 ::xml_schema::flags f)
        {
          ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
            ::mil::tatrc::physiology::datamodel::Inhaler (s, m, f));
          if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
          {
            throw ::xsd::cxx::tree::serialization< char > ();
          }
        }

        void
        Inhaler (::xercesc::XMLFormatTarget& t,
                 const ::mil::tatrc::physiology::datamodel::InhalerData& s,
                 ::xercesc::DOMErrorHandler& h,
                 const ::xml_schema::namespace_infomap& m,
                 const ::std::string& e,
                 ::xml_schema::flags f)
        {
          ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
            ::mil::tatrc::physiology::datamodel::Inhaler (s, m, f));
          if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
          {
            throw ::xsd::cxx::tree::serialization< char > ();
          }
        }

        void
        Inhaler (::xercesc::DOMDocument& d,
                 const ::mil::tatrc::physiology::datamodel::InhalerData& s,
                 ::xml_schema::flags)
        {
          ::xercesc::DOMElement& e (*d.getDocumentElement ());
          const ::xsd::cxx::xml::qualified_name< char > n (
            ::xsd::cxx::xml::dom::name< char > (e));

          if (typeid (::mil::tatrc::physiology::datamodel::InhalerData) == typeid (s))
          {
            if (n.name () == "Inhaler" &&
                n.namespace_ () == "uri:/mil/tatrc/physiology/datamodel")
            {
              e << s;
            }
            else
            {
              throw ::xsd::cxx::tree::unexpected_element < char > (
                n.name (),
                n.namespace_ (),
                "Inhaler",
                "uri:/mil/tatrc/physiology/datamodel");
            }
          }
          else
          {
            ::xsd::cxx::tree::type_serializer_map_instance< 0, char > ().serialize (
              "Inhaler",
              "uri:/mil/tatrc/physiology/datamodel",
              e, n, s);
          }
        }

        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
        Inhaler (const ::mil::tatrc::physiology::datamodel::InhalerData& s,
                 const ::xml_schema::namespace_infomap& m,
                 ::xml_schema::flags f)
        {
          ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d;

          if (typeid (::mil::tatrc::physiology::datamodel::InhalerData) == typeid (s))
          {
            d = ::xsd::cxx::xml::dom::serialize< char > (
              "Inhaler",
              "uri:/mil/tatrc/physiology/datamodel",
              m, f);
          }
          else
          {
            d = ::xsd::cxx::tree::type_serializer_map_instance< 0, char > ().serialize (
              "Inhaler",
              "uri:/mil/tatrc/physiology/datamodel",
              m, s, f);
          }

          ::mil::tatrc::physiology::datamodel::Inhaler (*d, s, f);
          return d;
        }
      }
    }
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

