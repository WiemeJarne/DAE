using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace demoW2
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private double _scale = 1.2;

        public MainWindow()
        {
            InitializeComponent();
        }

        private void Image_MouseEnter(object sender, MouseEventArgs e)
        {
            //image.Width *= _scale;
            //image.Height *= _scale;
            //image.Visibility = Visibility.Collapsed;
            image.Opacity = 0.0;
        }

        private void Image_MouseLeave(object sender, MouseEventArgs e)
        {
            //image.Width /= _scale;
            //image.Height /= _scale;
            //image.Visibility = Visibility.Visible;
            image.Opacity = 1.0;
        }
    }
}