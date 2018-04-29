using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PAT_Lab3
{
    public enum Values
    {
        Ace,
        Six = 5, 
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King
    }

    public class CardContainer
    {
        Card spades = new Spades();
        Card hearts = new Hearts();
        Card clubs = new Clubs();
        Card diamonds = new Diamonds();
       
        public Card GetHearts()
        {
            return hearts.Clone();
        }

        public Card GetSpades() {
            return spades.Clone();
        }

        public Card GetDiamonds() {
            return diamonds.Clone();
        }

        public Card GetClubs() {
            return clubs.Clone();
        }
    }
    public abstract class Card
    {
        
        // Constructor
        public Card(string suit, Values value = Values.Ace) {
            this.Suit = suit;
            this.Value = value;
        }

        public Values Value;

        protected string Color;
        // Property
        public string Suit { get; private set; }

        public virtual Card Clone() {
            // Shallow copy
            return (Card)this.MemberwiseClone();
        }

        public override string ToString()
        {
            return $"Suit: {Suit}, Value: {Value}, Color: {Color}";
        }
    }

    // "Hearts" 
    public class Hearts : Card
    {
        // Constructor
        public Hearts(Values value = Values.Six) : base("Hearts", value)
        {
            Color = "Red";
        }
    }

    // "Spades" 
    public class Spades : Card
    {
        // Constructor
        public Spades(Values value = Values.Ace) : base("Spades", value) {
            Color = "Black";
        }
    }

    // "Diamonds" 
    public class Diamonds : Card
    {
        // Constructor
        public Diamonds(Values value = Values.Six) : base("Diamonds", value) {
            Color = "Red";
        }
    }
    // "Clubs" 
    public class Clubs : Card
    {
        // Constructor
        public Clubs(Values value = Values.Six) : base("Clubs", value) {
            Color = "Black";
        }
    }
}
