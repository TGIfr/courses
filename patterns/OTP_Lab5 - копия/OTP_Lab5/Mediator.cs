using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OTP_Lab5
{
    public enum Cost
    {
        Low,
        Mid,
        High
    }

    public enum Quality
    {
        Low,
        Mid,
        High
    }
    public abstract class AbstractAgency
    {
        public abstract void Register(User User);

        public abstract void FindSellers(Buyer from);
        public abstract void FindBuyers(Seller from);
    }
    // The 'ConcreteMediator' class
    public class Agency : AbstractAgency
    {
        public InterAgency InterAgency;
        private List<Buyer> _buyers = new List<Buyer>();
        private List<Seller> _sellers = new List<Seller>();

        public override void Register(User user) {
            if (user is Buyer)
            {
                if (!_buyers.Contains(user))
                {
                    _buyers.Add(user as Buyer);
                }
            }
            else
            {
                if (!_sellers.Contains(user)) {
                    _sellers.Add(user as Seller);
                }
            }
            user.Agency = this;
        }

        public override void FindSellers(Buyer from)
        {
            var list = InterAgency.GetSellersFromAllAgencies(this, from.QualityWish, from.CostWish);
            from.Receive(list);
        }

        public void FindUser(User from)
        {
            if (from == null)            
                return;
            
            if (from is Seller)
            {
                FindBuyers(from as Seller);
            }
            else
            {
                FindSellers(from as Buyer);
            }
        }

        public override void FindBuyers(Seller from)
        {
            List<User> res = new List<User>();

            foreach (var buyer in _buyers) {               
                if (buyer.QualityWish == from.QualityWish &&
                    buyer.CostWish == from.CostWish)
                    res.Add(buyer);
            }

            from.Receive(res);
        }
        public List<User> GetSellersFromThisDb(Quality q, Cost c)
        {
            List<User> res = new List<User>();
            foreach (var seller in _sellers)
            {
                if(seller.Agency == this)
                    if(seller.QualityWish == q && seller.CostWish == c)
                        res.Add(seller);
            }
            return res;
        }
    }

    public class InterAgency
    {
        private List<Agency> _agencies = new List<Agency>();

        public void Register(Agency a)
        {
            if (a != null && !_agencies.Contains(a))
            {
                _agencies.Add(a);
            }
            a.InterAgency = this;
        }

        public List<User> GetSellersFromAllAgencies(Agency caller, Quality q, Cost c)
        {
            List<User> res = new List<User>();
            foreach (var agency in _agencies)
            {            
                    res.AddRange(agency.GetSellersFromThisDb(q, c));            
            }
            return res;
        }

    }

    public class User
    {
        public Cost CostWish;
        public Quality QualityWish;

        private Agency _agency;
        private string _name;
        // Constructor
        public User(string name, Cost c = Cost.Low, Quality q = Quality.Low) {
            this._name = name;
            CostWish = c;
            QualityWish = q;
        }

        // Gets User name
        public string Name {
            get { return _name; }
        }
        // Gets chatroom
        public Agency Agency {
            set { _agency = value; }
            get { return _agency; }
        }

        public override string ToString()
        {
            return "I am " + _name + ", and I'm a " + GetType().Name;
        }

        // Sends message to given User
        public void GetContacts() {
            _agency.FindUser(this);
        }
        // Receives message from given User
        public virtual void Receive(List<User> list) {
            if(list.Count != 0) {
                Console.WriteLine("Received needed contacts");
                foreach (var user in list)
                {
                    Console.WriteLine(user);
                }             
            }
            else
            {
                Console.WriteLine("Needed contacts not found");
            }
            
        }


    }

    // A 'ConcreteColleague' class
    public class Seller : User
    {
        // Constructor
        public Seller(string name, Cost c = Cost.Low, Quality q = Quality.Low)
            : base(name, c, q) {
        }
      
    }
    // A 'ConcreteColleague' class
    public class Buyer : User
    {
        
        // Constructor
        public Buyer(string name, Cost c = Cost.Low, Quality q = Quality.Low )
            : base(name, c, q) {
        }

    }
}
