#include "wavetable_toggle_section.h"

#define TEXT_HEIGHT 20

WavetableToggleSection::WavetableToggleSection(String name) : SynthSection(name)
{
  addSubSection(oscillator_ = new OscillatorSection("OSCILLATORS"));
  addSubSection(wavetable_osc_ = new WavetableOscillatorSection("WAVETABLE OSCILLATOR"));
  
  addButton(wavetable_toggle_ = new SynthButton("distortion_on"));
  wavetable_toggle_->addButtonListener(bt_listener_ = new ButtonListener());
}

WavetableToggleSection::~WavetableToggleSection()
{
  oscillator_ = nullptr;
  wavetable_osc_ = nullptr;
  wavetable_toggle_ = nullptr;
}

void WavetableToggleSection::paintBackground(Graphics& g)
{
  static const DropShadow section_shadow(Colour(0xcc000000), 3, Point<int>(0, 1));

  section_shadow.drawForRectangle(g, oscillator_->getBounds());
  section_shadow.drawForRectangle(g, wavetable_osc_->getBounds());
  section_shadow.drawForRectangle(g, wavetable_toggle_->getBounds());

  paintChildrenBackgrounds(g);
}

void WavetableToggleSection::resized()
{
  int column_1_x = padding_;
  int oscillators_height = size_ratio_ * 180.0f;
  int button_height = size_ratio_ * TEXT_HEIGHT;

  oscillator_->setBounds(0, 0, section_one_width_, oscillators_height);
  wavetable_osc_->setBounds(0, 0, section_one_width_, oscillators_height);
  wavetable_toggle_->setBounds(0, 0, button_height, button_height);

  SynthSection::resized();
}

void WavetableToggleSection::reset()
{
  oscillator_->reset();
  wavetable_osc_->reset();

  SynthSection::reset();
}
