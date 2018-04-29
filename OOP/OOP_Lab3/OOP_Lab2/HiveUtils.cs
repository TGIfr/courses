using System;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Runtime.Serialization.Json;
using System.Xml;
using System.Xml.Serialization;

namespace OOP_Lab3
{
    class HiveUtils
    {
        private HiveUtils() { }

        public static void CheckIfSuccessul(Hive hive)
        {
            Console.WriteLine(hive.StoredHoney > 110 ? "Successful" : "Not successful");
        }

        public static void SerializeHiveBinary(Hive hive)
        {           
            BinaryFormatter formatter = new BinaryFormatter();
            using (FileStream fs = new FileStream("hive.dat", FileMode.Create)) {
                formatter.Serialize(fs, hive);
                Console.WriteLine("Serialized");
            }            
        }

        public static Hive DeserializeHiveBinary()
        {
            BinaryFormatter formatter = new BinaryFormatter();
            using (FileStream fs = new FileStream("hive.dat", FileMode.OpenOrCreate)) {
                return (Hive)formatter.Deserialize(fs);
            }
        }

        public static void SerializeHiveXml(Hive hive) {
            var xmlFormatter = new XmlSerializer(typeof(Hive));

            
            using (FileStream fs = new FileStream("hive.xml", FileMode.Create)) {
                xmlFormatter.Serialize(fs, hive);
            }
        }

        public static Hive DeserializeHiveXml() {
            var xmlFormatter = new XmlSerializer(typeof(Hive));
            using (FileStream fs = new FileStream("hive.xml", FileMode.OpenOrCreate)) {
               return (Hive)xmlFormatter.Deserialize(fs);
            }
        }
    }
}
