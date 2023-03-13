using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using T04_MVVM.Model;

namespace T04_MVVM.ViewModel
{
    internal class HeroPageVM : ObservableObject
    {
        private string userName = "ozikov";

        public string UserName
        {
            get { return userName; }
            set
            { 
                userName = value; 
                OnPropertyChanged(nameof(UserName));
            }
        }
        public Hero CurrentHero { get; set; }
        = new Hero()
        {
            Name = "",
            RealName = "Real name of me",
            Description = "this is the discription"
        };

        public RelayCommand ResetCommand { get; private set; }
        public RelayCommand SaveCommand { get; private set; }

        public HeroPageVM()
        {
            ResetCommand = new RelayCommand(ResetHero);
            SaveCommand = new RelayCommand(SaveHero, CanSaveHero);

            CurrentHero.PropertyChanged += CurrentHero_PropertyChanged;
        }

        private void CurrentHero_PropertyChanged(object sender, System.ComponentModel.PropertyChangedEventArgs e)
        {
            SaveCommand.NotifyCanExecuteChanged();
        }

        void ResetHero()
        {
            UserName = "no user";
            CurrentHero.Name = "(no name)";
            CurrentHero.RealName = "(no real name)";
            CurrentHero.Description = "(this ain't no hero)";
        }

        void SaveHero()
        {
            Console.WriteLine("User has saved the hero");
            Console.WriteLine(CurrentHero);
        }

        bool CanSaveHero()
        {
            return !string.IsNullOrWhiteSpace(CurrentHero.Name)
                && !string.IsNullOrWhiteSpace(CurrentHero.RealName);
        }
    }
}
