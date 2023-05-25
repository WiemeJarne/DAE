#include "JsonToObj.h"
#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
    : m_InputFileChooser("Select input file", File(), "*.json")
    , m_OutputFileChooser("Select output file", File(), "*.obj")
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

    m_InputFileSelectButton.setButtonText("Input");
    addAndMakeVisible(m_InputFileSelectButton);

    m_InputFileSelectButton.onClick = 
        [&]()
    {
        m_InputFileChooser.launchAsync(0,
            [&](const juce::FileChooser& fileChooser) 
            {
                auto fileName{ fileChooser.getResult().getFullPathName() };

                if(fileName != "")
                    m_InputFilePath = fileName;
            });
    };

    m_OutputFileSelectButton.setButtonText("Output");
    addAndMakeVisible(m_OutputFileSelectButton);

    m_OutputFileSelectButton.onClick =
        [&]()
    {
        m_OutputFileChooser.launchAsync(0,
            [&](const juce::FileChooser& fileChooser)
            {
                auto fileName{ fileChooser.getResult().getFullPathName() };

                if (fileName != "")
                    m_OutputFilePath = fileName;
            });
    };

    m_GenerateOutputButton.setButtonText("start file conversion");
    addAndMakeVisible(m_GenerateOutputButton);

    m_GenerateOutputButton.onClick =
        [&]()
    {
        if (m_InputFilePath == L"")
            return;

        JsonToObj(m_InputFilePath.toWideCharPointer(), m_OutputFilePath.toWideCharPointer());

        juce::String outputFilePath{};
        if (m_OutputFilePath != "")
            outputFilePath = m_OutputFilePath;
        else
            outputFilePath = m_InputFilePath;

        std::wstring wStrOutputFilePath{ outputFilePath.toWideCharPointer() };
        wStrOutputFilePath.erase(wStrOutputFilePath.find(L"json")).append(L"obj");
        CreateReport(wStrOutputFilePath);
    };
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
    m_DataTable.setBounds(0, 0, getWidth(), getHeight() - 60);
    m_InputFileSelectButton.setBounds(10, getHeight() - 50, 60, 40);
    m_OutputFileSelectButton.setBounds(10 + 65, getHeight() - 50, 60, 40);
    m_GenerateOutputButton.setBounds(10 + 65 * 2, getHeight() - 50, 120, 40);
}

void MainComponent::CreateReport(const std::wstring& objFile)
{
    m_pTableModel->Clear();

    std::ifstream is{ objFile };

    std::string command{};

    while (!is.eof())
    {
        is >> command;

        if (command == "v")
        {
            int x{}, y{}, z{};
            is >> x;
            is >> y;
            is >> z;

            m_pTableModel->AddVector({ "v", static_cast<float>(x), static_cast<float>(y), static_cast<float>(z) });
        }
        
        if (command == "vn")
        {
            float x{}, y{}, z{};
            is >> x;
            is >> y;
            is >> z;

            m_pTableModel->AddVector({ "vn", x, y, z });
        }

        if (command == "vt")
        {
            float x{}, y{};
            is >> x;
            is >> y;

            m_pTableModel->AddVector({ "vt", x, y });
        }
    }

    m_DataTable.updateContent();
}