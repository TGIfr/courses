using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PAT_Lab3
{
    class Program
    {
        static void Main(string[] args) {
            var cardContainer = new CardContainer();
            var spade = cardContainer.GetSpades();
            Spades sevenSpade = (Spades) spade.Clone();
            sevenSpade.Value = Values.Seven;

            Spades kingSpade = (Spades)spade.Clone();
            kingSpade.Value = Values.King;

            var heart = cardContainer.GetHearts();
            Hearts sevenHearts = (Hearts)heart.Clone();
            sevenHearts.Value = Values.Seven;

            Hearts kingHearts = (Hearts)heart.Clone();
            kingHearts.Value = Values.King;

            List<Card> deck = new List<Card>();

            deck.Add(sevenSpade);
            deck.Add(sevenHearts);
            deck.Add(kingSpade);
            deck.Add(kingHearts);

            foreach (var card in deck)
            {
                Console.WriteLine(card);
            }

            Console.ReadKey();
            Console.Clear();

            Participant p = new Participant(PaperTypes.Diploma, 90, "138", 11, "chess competition");
            var maker = new PapersMaker(new List<PapersFactory>
            {
                CheapPapersFactory.GetPapersFactory(),
                DorogobogatoPapersFactory.GetPapersFactory()
            });

            Console.WriteLine(maker.MakePapers(p).Text);
            Console.WriteLine(maker.MakePapers(p).Text);
            Console.WriteLine(maker.MakePapers(p));

            p.Type = PaperTypes.CharterInterschool;
            p.MoneyForPapers = 90;
            p.Achievement = "1'st place";
            Console.WriteLine(maker.MakePapers(p).Text);
            Console.WriteLine(maker.MakePapers(p).Text);
            Console.WriteLine(maker.MakePapers(p));

            Console.ReadKey();
        }
    }
}
