using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using ToolDevPluginLIB; //custom library shared with plugins

namespace PluginLoader
{
    internal class Program
    {
        static List<ICharacterPlugin> _allCharacters = new List<ICharacterPlugin>();
        static Random _rnd = new Random();

        static void Main(string[] args)
        {
            //1. Load all (I)Characters from plugins (dll files)
            //      TODO: change this to the location of your plugin folder,
            //        avoid spaces or special characters in your path.
            LoadCharacters(@"..\..\..\plugins");

            //2. Keeps attacking until only one is left:
            while (_allCharacters.Count > 1)
            {
                GenerateAttack();
                System.Threading.Thread.Sleep(2000); //wait a sec or 2 before attacking again
            }

            //3. Print the last one standing:
            PrintWinner();

            //4. Wait before closing:
            Console.ReadLine();
        }

        private static void LoadCharacters(string pluginPath)
        {
            Console.WriteLine("******* CHARACTERS IN THE GAME ********");

            //get all dll files (System.IO):
            string[] pluginFiles = Directory.GetFiles(pluginPath, "*.dll");

            // Loop through all .dll files and try to turn into characters:
            foreach (string pluginFile in pluginFiles)
            {
                AnalysePlugin(pluginFile);
            }

            Console.WriteLine();
        }

        private static void GenerateAttack()
        {
            Console.WriteLine("******* FIGHT! FIGHT! FIGHT!! ********");

            //random victim + attacker
            ICharacterPlugin attacker = _allCharacters[_rnd.Next(0, _allCharacters.Count)];
            ICharacterPlugin victim;
            do
            {
                victim = _allCharacters[_rnd.Next(0, _allCharacters.Count)];
            } while (victim == attacker || victim.Health < 0); //ensure victim is alive and != attacker
            attacker.Attack(victim);

            //print stats of victim after attack
            PrintStats(victim);

            //check if victim is still alive
            if (victim.Health <= 0)
            {
                PrintDefeat(victim);
            }
        }

        /// <summary>
        /// Prints a red message that shows which victim was defeated 
        ///+ executes its "Die" method
        /// </summary>
        /// <param name="victim">the victim that died</param>
        private static void PrintDefeat(ICharacterPlugin victim)
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("++++++++++ DEFEAT ++++++++++");
            //////////
            ///TODO: Execute the Die() method of the victim
            victim.Die();
            //////////
            _allCharacters.Remove(victim);

            Console.WriteLine($"=> {_allCharacters.Count} characters are left in the game!");
            Console.ResetColor();
            Console.WriteLine();
        }

        private static void PrintWinner()
        {
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("******* WINNER!! ********");
            Console.WriteLine(_allCharacters[0].Name);
        }

        private static void PrintStats(ICharacterPlugin character)
        {
            Console.WriteLine($"{character.Name.ToUpper()} [Health: {character.Health}, Attack: {character.Damage}]");
            Console.WriteLine();
        }

        /// <summary>
        /// Searches for all .dll files in a directory 
        /// </summary>
        /// <param name="filePath"></param>
        static void AnalysePlugin(string filePath)
        {

            // REFLECTION: TODO: Load the assembly into memory based on file path:
            System.Reflection.Assembly pluginAssembly = Assembly.LoadFrom(filePath);

            //REFLECTION//////////////////////////
            IEnumerable<Type> characterPlugins;
            // TODO: Try to get all classes (types) from pluginAssembly that implement the ICharacterPlugin 
            //          -> put the result in characterPlugins
            characterPlugins = pluginAssembly.GetTypes().Where(type => typeof(ICharacterPlugin).IsAssignableFrom(type));
            //////////////////////////////////////

            // Loops through all plugins that implement ICharacterPlugin (see TODO)
            foreach (Type pluginType in characterPlugins)
            {
                ////////////////////////////
                ICharacterPlugin plugin;
                // REFLECTION: TODO: Instantiate the plugin
               plugin = (ICharacterPlugin)Activator.CreateInstance(pluginType);

                // Add it to the given _allCharacters list:
                _allCharacters.Add(plugin);
                ////////////////////////////

                // TODO: Printing the actual character name + its description:
                Console.ForegroundColor = ConsoleColor.Yellow;
                Console.WriteLine($"{plugin.Name}");
                Console.ResetColor();
                Console.WriteLine($"{plugin.Description}");
            }
        }
    }
}