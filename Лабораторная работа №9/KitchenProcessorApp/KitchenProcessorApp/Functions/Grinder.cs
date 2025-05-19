using KitchenProcessorApp.Abstract;

namespace KitchenProcessorApp.Functions
{
    public class Grinder : IProcessorFunction
    {
        public void Process(string name) => Console.WriteLine($"{name} измельчает продукты.");
    }
}
