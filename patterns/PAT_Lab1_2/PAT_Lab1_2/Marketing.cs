using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PAT_Lab1_2
{


    abstract class SellerComponent
    {
        protected string name;


        // Constructor
        public SellerComponent(string name)
        {
            this.name = name;
        }

        public abstract void Add(SellerComponent c);
        public abstract void Remove(SellerComponent c);
        public abstract void SellCosmetics(double maxCost, double startCost);
        public abstract void Display(int depth);
    }

    /// <summary>
    /// The 'UsualSeller' class
    /// </summary>
    class UsualSeller : SellerComponent
    {
        private List<SellerComponent> _children = new List<SellerComponent>();

        // Constructor
        public UsualSeller(string name) : base(name)
        {
          
        }

        public override void Add(SellerComponent component)
        {
            _children.Add(component);
        }

        public override void Remove(SellerComponent component)
        {
            _children.Remove(component);
        }

        public override void SellCosmetics(double maxCost, double startCost) {
            if (maxCost < 0 || startCost < 0)
            {
                Console.WriteLine("Invalid input");
                return;
            }

            Random r = new Random();
            double newCost = startCost * (1.0 +  r.Next(5, 15) / 100.0);
            newCost = newCost >= maxCost ? maxCost : newCost; 

            if(_children.Count > 0)
                Console.WriteLine("I am " + name + " and I'm selling cosmetics to my crew at "  + $"{newCost:0.00}");
            else 
                Console.WriteLine("I am " + name + ". Got nobody to sell my dich");

            foreach (SellerComponent component in _children)
                component.SellCosmetics(maxCost, newCost);
        }
        public override void Display(int depth)
        {
            Console.WriteLine(new String('-', depth) + name + ", usual seller");
            // Recursively display child nodes
            foreach (SellerComponent component in _children)
                component.Display(depth + 2);
        }

    }

    class EndSeller : SellerComponent
    {
        public EndSeller(string name) : base(name)
        {
            
        }

        public override void Add(SellerComponent c)
        {
            Console.WriteLine("Impossible operation");
        }

        public override void Remove(SellerComponent c)
        {
            Console.WriteLine("Impossible operation");
        }

        public override void SellCosmetics(double maxCost, double startCost) {

            if (maxCost < 0 || startCost < 0) {
                Console.WriteLine("Invalid input");
                return;
            }

            Random r = new Random();
            double newCost = startCost * (1 + r.Next(10, 30) / 100.0);
            newCost = newCost > maxCost ? maxCost : newCost;
      
            Console.WriteLine("I am " + name + " and I'm selling cosmetics to people at " + $"{newCost:0.00}");
           
        }
        public override void Display(int depth)
        {
            Console.WriteLine(new String('-', depth) + name + ", end seller" );
        }

       
    }
}

