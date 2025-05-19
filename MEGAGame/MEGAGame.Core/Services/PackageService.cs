using System.Text.Json;
using MEGAGame.Core.Models;

namespace MEGAGame.Core.Services;

public static class PackageService
{
    public static Package Load(string path)
    {
        var json = File.ReadAllText(path);
        return JsonSerializer.Deserialize<Package>(json);
    }
}