using System;

namespace OOP_Lab3
{
    class Program
    {
        static void Main(string[] args) {

            //
            //Hive hive1 = new Hive();

            //Console.WriteLine("Life of hive1 has started");
            //for (int i = 0; i < 3; i++) {
            //    hive1.Tick();
            //    Console.WriteLine(hive1.BeesAmount);
            //    HiveUtils.CheckIfSuccessul(hive1);
            //    Console.ReadKey();
            //}
            //Console.WriteLine("Life of hive1 has ended");
            //Queen directQueen = new Queen();
            //Hive hive2 = new Hive(directQueen);

            //Apiary ap = new Apiary();

            //ap.Add(hive1);
            //ap.Add(hive2);

            //for (int i = 0; i < 3; i++) {
            //    ap.Tick();
            //    Console.ReadKey();
            //}

            //for (int i = 0; i < 3; i++) {
            //    ap.TickWithData();
            //    Console.ReadKey();
            //}

            //HiveUtils.SerializeHiveXml(ap[0]);
            //HiveUtils.SerializeHiveBinary(ap[0]);

            //ap.Clear();
            //ap.Add(HiveUtils.DeserializeHiveBinary());

            //for (int i = 0; i < 3; i++) {
            //    ap.TickWithData();
            //    Console.ReadKey();
            //}
            //Console.WriteLine(ap.Count);
            //Console.ReadKey();;
            Console.WriteLine("Start of the Lab 4.");

            // Creating an object.
            Console.WriteLine("Start of the test case: {0}", GC.GetTotalMemory(true));
            Hive s = new Hive("dich");
            for (int i = 0; i < 0xffffff; i++) {
                s.AcceptBee(new Worker(s));
            }
            Console.WriteLine("After creating an object: {0}", GC.GetTotalMemory(true));

            // Weak reference test.
            WeakReference wr = new WeakReference(new Hive("dich"));
            s = null;
            Console.WriteLine("Before garbage collecting an object: {0}", GC.GetTotalMemory(true));
            GC.Collect();
            GC.WaitForPendingFinalizers();
            Console.WriteLine("After garbage collecting an object: {0}", GC.GetTotalMemory(true));
            s = (Hive)wr.Target;
            if (s != null)
                Console.WriteLine("Hive is not collected!");
            else
                Console.WriteLine("Object has been collected.");

            // Dispose test.
            // Dispose is a command, that flags an object, that a program does not need it anymore.
            Console.WriteLine("Disposing an object.");
            Console.WriteLine("Before: {0}", GC.GetTotalMemory(true));
            s.Dispose();
            if (s != null)
            {
                Console.WriteLine("Hive is not collected!");
                Console.WriteLine("Before garbage collecting an object: {0}", GC.GetTotalMemory(true));
                GC.Collect();
                GC.WaitForPendingFinalizers();
                Console.WriteLine("After garbage collecting an object: {0}", GC.GetTotalMemory(true));
            }
            //delete part that never happens(gc & r)
            else
                Console.WriteLine("Object has been collected.");

            Console.WriteLine(GC.GetTotalMemory(true));

            // A destructor test.
            Hive tmp = new Hive("tmp");
            tmp = null;
            GC.Collect();
            GC.WaitForPendingFinalizers();

            // End of the Lab 4 test case.
            Console.WriteLine("End of the Lab 4.");
            Console.ReadLine();


            Console.ReadKey();
        }
    }

    
}
