#pragma once
#ifndef WAVETABLE_TOGGLE_SECTION_H
#define WAVETABLE_TOGGLE_SECTION_H

#include "JuceHeader.h"
#include "synth_section.h"
#include "synth_button.h"
#include "wavetable_oscillator_section.h"
#include "oscillator_section.h"

class WavetableButtonListener : public SynthButton::ButtonListener {
  public:
    virtual ~WavetableButtonListener();
    virtual void guiChanged(SynthButton* button);
};

class WavetableToggleSection : public SynthSection
{
  public:
    WavetableToggleSection(String name);
    ~WavetableToggleSection();

    void paintBackground(Graphics& g) override;
    void resized() override;
    void reset() override;

    void toggleWavetable();

    void setPadding(int padding) { padding_ = padding; }
    void setSectionOneWidth(int width) { section_one_width_ = width; }

  private:
    ScopedPointer<OscillatorSection> oscillator_;
    ScopedPointer<WavetableOscillatorSection> wavetable_osc_;
    ScopedPointer<SynthButton> wavetable_toggle_;
    ScopedPointer<WavetableButtonListener> bt_listener_;

    int padding_;
    int section_one_width_;

    bool toggled = false;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(WavetableToggleSection)
};

#endif //WAVETABLE_TOGGLE_SECTION_H
