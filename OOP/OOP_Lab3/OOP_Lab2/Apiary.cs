using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab3
{
    class Apiary : IEnumerable
    {
        private List<Hive> hives;

        public Apiary()
        {
            hives = new List<Hive>();
        }

        public Apiary(Hive hive) : this()
        {
            hives.Add(hive);
        }

        public int Count => hives.Count;

        public void Add(Hive toAdd)
        {
            hives.Add(toAdd);
        }

        public void Sort()
        {
            hives.Sort();
        }

        public void RemoveAt(int i)
        {
            hives.RemoveAt(i);
        }
        public void Clear() {
            hives.Clear();
        }

        public Hive this[string breed] => hives.Find(x => x.Breed == breed);
        public Hive this[int i] => hives[i];

        public void Tick()
        {
            foreach (Hive h in hives)
            {
                h.Tick();         
            }
        }

        public IEnumerator GetEnumerator()
        {
            //return hives.GetEnumerator();
            foreach (Hive h in hives)
                yield return h;
        }

        //IEnumerator IEnumerable.GetEnumerator() { return new Enumerator(this); }

        //class Enumerator : IEnumerator
        //{
        //    int currentIndex = -1;
        //    Apiary collection;
        //    public Enumerator(Apiary collection) {
        //        this.collection = collection;
        //    }
        //    public Hive Current => collection[currentIndex];
        //    object IEnumerator.Current => Current;
        //    public bool MoveNext() => ++currentIndex < collection.Count;
        //    public void Reset() => currentIndex = -1;

        //}
    }
}
