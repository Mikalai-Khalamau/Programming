using KitchenProcessorApp.Abstract;

namespace KitchenProcessorApp.Functions
{
    public class Shredder : IProcessorFunction
    {
        public void Process(string name) => Console.WriteLine($"{name} шинкует продукты.");
    }
}
