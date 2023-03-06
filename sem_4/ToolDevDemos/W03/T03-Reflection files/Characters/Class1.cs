using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using ToolDevPluginLIB;

namespace Characters
{
    public class Jarne : ToolDevPluginLIB.ICharacterPlugin
    {
        public string Name { get { return "Jarne"; } }

        public string Description { get { return "discription here"; } }

        private int _health = 100;
        public int Health { get { return _health; } set { _health = value; } }

        private int _damage = 50;
        public int Damage { get { return _damage; } set { _damage = value; } }

        public void Attack(ICharacterPlugin target)
        {
            Console.WriteLine($"{Name} is attacking");
            target.Health = target.Health - _damage;
        }

        public void Die()
        {
            Console.WriteLine("character1 died");
        }
    }
}
