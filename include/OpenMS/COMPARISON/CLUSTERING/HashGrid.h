// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:expandtab
//
// --------------------------------------------------------------------------
//                   OpenMS Mass Spectrometry Framework
// --------------------------------------------------------------------------
//  Copyright (C) 2011 -- Bastian Blank
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// --------------------------------------------------------------------------
// $Maintainer: Lars Nilse $
// $Authors: Lars Nilse, Holger Plattfaut, Steffen Sass $
// --------------------------------------------------------------------------


#include <boost/array.hpp>
#include <boost/unordered/unordered_map.hpp>

#include <OpenMS/COMPARISON/CLUSTERING/Hasher.h>
#include <OpenMS/COMPARISON/CLUSTERING/HashGridCell.h>
#include <OpenMS/CONCEPT/Types.h>

#ifndef OPENMS_COMPARISON_CLUSTERING_HASHGRID_H
#define OPENMS_COMPARISON_CLUSTERING_HASHGRID_H

namespace OpenMS
{
  template <typename Value, std::size_t Dim, typename Hash = boost::hash<Value> >
  class OPENMS_DLLAPI HashGrid
    : public boost::unordered_map<boost::array<UInt, Dim>, OpenMS::HashGridCell<Value, Hash> >
  {
    public:
      typedef boost::array<UInt, Dim> Point;
      typedef boost::unordered_map<boost::array<UInt, Dim>, OpenMS::HashGridCell<Value, Hash> > base_;

      typedef typename base_::key_type key_type;
      typedef typename base_::mapped_type mapped_type;
      typedef typename base_::value_type value_type;

      typedef typename base_::const_iterator const_iterator;
      typedef typename base_::iterator iterator;
      typedef typename base_::size_type size_type;

    protected:
      Point max_key_;

    public:
      HashGrid()
      {
        for (typename Point::iterator it = max_key_.begin(); it != max_key_.end(); ++it) *it = 0;
      }

      const Point &max_key() const
      {
        return max_key_;
      }

      mapped_type& operator[](const key_type& key)
      {
        update_max_key(key);
        return base_::operator[](key);
      }

      std::pair<iterator, bool> insert(const value_type& obj)
      {
        update_max_key(obj.first);
        return base_::insert(obj);
      }

    protected:
      void update_max_key(const Point &d)
      {
        typename Point::const_iterator it1 = d.begin();
        typename Point::iterator it2 = max_key_.begin();
        for (; it1 != d.end(); ++it1, ++it2)
        {
          if (*it1 > *it2)
            *it2 = *it1;
        }
      }
  };
}

#endif /* HASHGRID_H_ */