/* Copyright 2013-2017 Matt Tytel
 *
 * mopo is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * mopo is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with mopo.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#ifndef WAVETABLE_TOGGLER_H
#define WAVETABLE_TOGGLER_H

#include "processor.h"

#include <complex>

namespace mopo {

  class WavetableToggler : public Processor {
    public:
      enum Inputs {
        kOn,
        kNumInputs
      };

      enum Type {
        kNumTypes
      };

      WavetableToggler();
      virtual ~WavetableToggler() { }

      virtual Processor* clone() const override {
        return new WavetableToggler(*this);
      }

      virtual void process() override;

    private:

  };
} // namespace mopo

#endif // WAVETABLE_TOGGLER_H
