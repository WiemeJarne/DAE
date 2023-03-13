using CommunityToolkit.Mvvm.ComponentModel;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media.Imaging;

namespace T04_MVVM.Model
{
    public class Hero : ObservableObject
    {

        private string _name;

        public string Name
        {
            get { return _name; }
            set
            {
                _name = value;
                OnPropertyChanged(nameof(Name));
            }
        }

        private string _realName;

        public string RealName
        {
            get { return _realName; }
            set
            {
                _realName = value;
                OnPropertyChanged(nameof(RealName));
            }
        }

        private string _description;

        public string Description
        {
            get { return _description; }
            set
            {
                _description = value;
                OnPropertyChanged(nameof(Description));
            }
        }

        public BitmapImage Image { get { return new BitmapImage(new Uri("pack://application:,,,/Resources/superhero.jpg", UriKind.Absolute)); } }

        public override string ToString()
        {
            return $"Hero details: \n- Name: {Name}\n - Real name: {RealName}\n - Description: {Description}";
        }
    }
}
