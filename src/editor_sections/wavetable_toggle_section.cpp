#include "wavetable_toggle_section.h"

#define TEXT_HEIGHT 20

WavetableToggleSection* instance;

WavetableButtonListener::~WavetableButtonListener()
{

}

void WavetableButtonListener::guiChanged(SynthButton* button)
{
  instance->toggleWavetable();
}

WavetableToggleSection::WavetableToggleSection(String name) : SynthSection(name)
{
  setBufferedToImage(true);

  addSubSection(oscillator_ = new OscillatorSection("OSCILLATOR"));
  addSubSection(wavetable_osc_ = new WavetableOscillatorSection("OSCILLATORS"));

  addButton(wavetable_toggle_ = new SynthButton("wavetable_on"));
  wavetable_toggle_->addButtonListener(bt_listener_ = new WavetableButtonListener());

  instance = this;
}

WavetableToggleSection::~WavetableToggleSection()
{
  oscillator_ = nullptr;
  wavetable_osc_ = nullptr;
  wavetable_toggle_ = nullptr;

  instance = nullptr;
}

void WavetableToggleSection::paintBackground(Graphics& g)
{
  static const DropShadow section_shadow(Colour(0xcc000000), 3, Point<int>(0, 1));

  if(wavetable_toggle_->getToggleState()) {
    oscillator_->setVisible(false);
    wavetable_osc_->setVisible(true);
    section_shadow.drawForRectangle(g, wavetable_osc_->getBounds());
  } else {
    oscillator_->setVisible(true);
    wavetable_osc_->setVisible(false);
    section_shadow.drawForRectangle(g, oscillator_->getBounds());
  }

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

void WavetableToggleSection::toggleWavetable()
{
  toggled = !toggled;
  if(wavetable_toggle_->getToggleState()) {
    oscillator_->setVisible(false);
    wavetable_osc_->setVisible(true);
  } else {
    oscillator_->setVisible(true);
    wavetable_osc_->setVisible(false);
  }

  repaint();
}
