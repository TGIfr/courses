using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Win32;

namespace PAT_Lab2
{
    // adaptee
    class Greetings
    {
        public string WelcomeUser(User u) {
            return "Welcome, " + u.Name + " " + u.Surname;
        }
        public string HelloUser(User u) {
            return "Hello, " + u.Name;
        }
    }

    //target
    public interface IGreeter
    {
        string GreetUser(User u);
    }


    //adapter
    public class Adapter : IGreeter
    {
        DB db = new DB();

        //adaptee
        Greetings ng = new Greetings();

        public string GreetUser(User u) {
            if (u.Surname == "") u.Surname = db.GetUserSurname(u);
            if (u.Age == 0) u.Age = db.GetUserAge(u);


            if (u.Age < 35 && u.Age != 0)
                return ng.HelloUser(u);
            else
                return ng.WelcomeUser(u);

        }
    }

    public class User
    {
        public string Name;
        public string Surname;
        public int Age;

        public User(string name) {
            Name = name;
        }
    }

    public class OldSystem : IGreeter
    {
        public string GreetUser(User u) {
            return "Hello, " + u.Name;
        }
    }

    class DB
    {
        public string GetUserSurname(User u) {
            switch (u.Name) {
                case "Vasya": return "Smith";
                case "Jane": return "Doe";
                default: return "";
            }
        }

        public int GetUserAge(User u) {
            switch (u.Name) {
                case "Vasya": return 25;
                case "Jane": return 45;
                default: return 0;
            }
        }
    }

}
