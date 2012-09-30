// --------------------------------------------------------------------------
//                   OpenMS -- Open-Source Mass Spectrometry
// --------------------------------------------------------------------------
// Copyright The OpenMS Team -- Eberhard Karls University Tuebingen,
// ETH Zurich, and Freie Universitaet Berlin 2002-2012.
//
// This software is released under a three-clause BSD license:
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of any author or any participating institution
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission.
// For a full list of authors, refer to the file AUTHORS.
// --------------------------------------------------------------------------
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL ANY OF THE AUTHORS OR THE CONTRIBUTING
// INSTITUTIONS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// --------------------------------------------------------------------------
// $Maintainer: Hannes Roest $
// $Authors: Hannes Roest $
// --------------------------------------------------------------------------

#ifndef OPENSWATH_DATAACCESS_ISPECTRUMACCESS_H_
#define OPENSWATH_DATAACCESS_ISPECTRUMACCESS_H_

#include "DataStructures.h"
#include <vector>
#include <string>
#include <boost/shared_ptr.hpp>

namespace OpenSwath
{

  class ISpectrumAccess
  {
public:
    virtual ~ISpectrumAccess(){}
    virtual SpectrumPtr getSpectrumById(int id) const = 0;
    virtual std::vector<std::size_t> getSpectraByRT(double RT, double deltaRT) const = 0;
    virtual size_t getNrSpectra() const = 0;
    virtual SpectrumMeta getSpectrumMetaById(int id) const = 0;

    virtual ChromatogramPtr getChromatogramById(int id) const = 0;
    //virtual std::vector<std::size_t> getChromatogramByPrecursorMZ(double mz,
    //    double deltaMZ) const = 0;
    virtual std::size_t getNrChromatograms() const = 0;
    virtual std::string getChromatogramNativeID(int id) const = 0;
  };

  typedef boost::shared_ptr<ISpectrumAccess> SpectrumAccessPtr;
}

#endif