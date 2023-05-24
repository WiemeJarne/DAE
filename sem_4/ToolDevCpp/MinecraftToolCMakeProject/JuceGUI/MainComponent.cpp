#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (800, 600);
    setFramesPerSecond (60); // This sets the frequency of the update calls.

    addAndMakeVisible(m_DataTable);
    m_pTableModel = new TableModel();
    m_DataTable.setModel(m_pTableModel);
    m_DataTable.getHeader().addColumn("Name", 1, 100, 50, 200);
    m_DataTable.getHeader().addColumn("x", 2, 50, 20, 60);
    m_DataTable.getHeader().addColumn("y", 3, 50, 20, 60);
    m_DataTable.getHeader().addColumn("z", 4, 50, 20, 60);
}

MainComponent::~MainComponent()
{
    delete m_pTableModel;
}

//==============================================================================
void MainComponent::update()
{
    // This function is called at the frequency specified by the setFramesPerSecond() call
    // in the constructor. You can use it to update counters, animate values, etc.
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    m_DataTable.setBounds(0, 0, getWidth(), getHeight());
}
