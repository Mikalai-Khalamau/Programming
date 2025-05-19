using KitchenProcessorApp.Abstract;

namespace KitchenProcessorApp.Functions
{
    public class MeatGrinder : IProcessorFunction
    {
        public void Process(string name) => Console.WriteLine($"{name} превращает мясо в фарш.");
    }
}
