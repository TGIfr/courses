using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OTP_Lab5
{
    public interface IFriend
    {
        // properties
        FriendBase Successor { set; }
    }

    public abstract class FriendBase
    {
        // fields
        protected FriendBase _successor;

        protected decimal _moneyStored;
        // properties
        public FriendBase Successor {
            set { _successor = value; }
        }
        // methods

        public abstract bool AskForMoney(decimal moneyRequired);
    }
    // --- Concrete handlers
    public class RichFriend : FriendBase
    {

        public RichFriend()
        {
            _moneyStored = 1000M;
        }
        // methods
        public override bool AskForMoney(decimal moneyRequired)
        {
            if (moneyRequired < _moneyStored)
            {
                Console.WriteLine("Money found!");
                return true;
            }

            if (_successor != null)
            {
                Console.WriteLine("Money not found, asking other friend. But I don't think you can find someone with more money");
                return _successor.AskForMoney(moneyRequired);
            }
            else
            {
                Console.WriteLine("No way, dude. It's time to stop and take credit");
                return false;
            }


        }
        
    }
    public class NotRichFriend : FriendBase
    {
        public NotRichFriend() {
            _moneyStored = 500M;
        }
        // methods
        public override bool AskForMoney(decimal moneyRequired) {
            if (moneyRequired < _moneyStored) {
                Console.WriteLine("Money found!");
                return true;
            }

            if (_successor != null) {
                Console.WriteLine("Money not found, asking other friend. You still can find someone");
                return _successor.AskForMoney(moneyRequired);
            } else {
                Console.WriteLine("No way, dude. It's time to stop and take credit");
                return false;
            }


        }
    }
    public class DefinetelyNotRichFriend : FriendBase
    {

        public DefinetelyNotRichFriend() {
            _moneyStored = 100M;
        }
        // methods
        public override bool AskForMoney(decimal moneyRequired) {
            if (moneyRequired < _moneyStored) {
                Console.WriteLine("Money found!");
                return true;
            }

            if (_successor != null) {
                Console.WriteLine("Money not found, asking other friend." +
                                  " Anyway, I almost sure that you'l find someone with more money");
                return _successor.AskForMoney(moneyRequired);
            } else {
                Console.WriteLine("No way, dude. It's time to stop and take credit");
                return false;
            }


        }
    }
}
