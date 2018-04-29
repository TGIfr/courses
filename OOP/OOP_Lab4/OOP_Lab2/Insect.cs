using System;
using System.Runtime.Serialization;

namespace OOP_Lab3
{
    [Serializable]
    public abstract class Insect
    {
        protected abstract void Eat();
    }
}
