#pragma once

#include <JuceHeader.h>
#include "TableModel.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::AnimatedAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void update() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...
    juce::TableListBox m_DataTable;
    TableModel* m_pTableModel;
    juce::TextButton m_InputFileSelectButton;
    juce::TextButton m_OutputFileSelectButton;
    juce::TextButton m_GenerateOutputButton;
    juce::FileChooser m_InputFileChooser;
    juce::FileChooser m_OutputFileChooser;
    std::wstring m_InputFilePath;
    std::wstring m_OutputFilePath;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)

    void CreateReport(const std::wstring& objFile);
};
