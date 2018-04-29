using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OTP_Lab4
{

    public class PayControl
    {
        private int _monthsFromStart;

        private State _currentState;

        State ucState = new UsualClientState();
        State rcState = new RegularClientState();
        State vcState = new VipClientState();
        State rvpState = new RegularVipClientState();

        private State checkState(int monthsSinceLastPayment)
        {
            if (_monthsFromStart > 6 && monthsSinceLastPayment == 1)          
                return rvpState;
            if (_monthsFromStart > 6)
                return rcState;
            if (monthsSinceLastPayment == 1)
                return vcState;
            return ucState;
        }

        public void Pay(int monthsSinceLastPayment)
        {
            if (monthsSinceLastPayment < 0)
            {
                Console.WriteLine("Orly?");
                return;
            }
            _monthsFromStart += monthsSinceLastPayment;
            var newState = checkState(monthsSinceLastPayment);
            if (newState != _currentState)
            {
                Console.WriteLine("You got new state, congrats!!! Now you are " + newState.Type);
                _currentState = newState;
            }
            Console.WriteLine($"You've made payment with {_currentState.Discount()} discount");

        }

        public PayControl()
        {
            _monthsFromStart = 0;
            _currentState = ucState;
        }
    }

    public abstract class State
    {
        protected int _discount;
        public string Type { get; protected set; }

        public virtual int Discount() {
            Console.WriteLine($"As {Type} client you got {_discount} discount");
            return _discount;
        }
    }

    public class UsualClientState : State
    {
        public UsualClientState()
        {
            Type = "Usual";
            _discount = 0;
        }       
    }

    public class RegularClientState : State
    {
        public RegularClientState() {
            Type = "Regular";
            _discount = 5;
        }
    }

    public class VipClientState : State
    {
        public VipClientState() {
            Type = "VIP";
            _discount = 10;
        }
    }

    public class RegularVipClientState : State
    {
        public RegularVipClientState() {
            Type = "Regular VIP";
            _discount = 15;
        }
    }
}
