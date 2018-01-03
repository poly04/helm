#pragma once
#ifndef WAVETABLE_TOGGLE_SECTION_H
#define WAVETABLE_TOGGLE_SECTION_H

#include "JuceHeader.h"
#include "synth_section.h"
#include "wavetable_oscillator_section.h"
#include "oscillator_section.h"

class WavetableToggleSection : public SynthSection
{
  public:
    WavetableToggleSection(String name);
    ~WavetableToggleSection();

    void paintBackground(Graphics& g) override;
    void resized() override;
    void reset() override;

    void setPadding(int padding) { padding_ = padding; }
    void setSectionOneWidth(int width) { section_one_width_ = width; }

  private:
    ScopedPointer<OscillatorSection> oscillator_;
    ScopedPointer<WavetableOscillatorSection> wavetable_osc_;

    int padding_;
    int section_one_width_;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(WavetableToggleSection)
};

#endif //WAVETABLE_TOGGLE_SECTION_H
