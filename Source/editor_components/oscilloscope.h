/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_3190D8EC0F31F326__
#define __JUCE_HEADER_3190D8EC0F31F326__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "memory.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Oscilloscope  : public AnimatedAppComponent
{
public:
    //==============================================================================
    Oscilloscope (int num_samples);
    ~Oscilloscope();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void update() override;
    void resetWavePath();
    void setOutputMemory(const mopo::Memory* memory) { output_memory_ = memory; }
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    const mopo::Memory* output_memory_;
    int samples_to_show_;
    Path wave_path_;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscilloscope)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_3190D8EC0F31F326__
