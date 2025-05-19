using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Windows;
using System.Windows.Input;
using CommunityToolkit.Mvvm.Input;
using MEGAGame.Core.Models;
using MEGAGame.Core.Services;

namespace MEGAGame.Client;

public class MainViewModel : INotifyPropertyChanged
{
    public ObservableCollection<PlayerScore> Players { get; } =
        new() { new PlayerScore("Игрок 1"), new PlayerScore("Игрок 2") };

    private Package _package;
    private Round _currentRound;
    private int _roundIndex;

    public Round CurrentRound
    {
        get => _currentRound;
        set { _currentRound = value; OnPropertyChanged(); }
    }

    public ICommand PickQuestionCommand { get; }

    public MainViewModel()
    {
        try
        {
            var path = System.IO.Path.Combine(
                AppDomain.CurrentDomain.BaseDirectory,
                "Resources", "demo.json");

            _package = PackageService.Load(path);
            CurrentRound = _package.Rounds[0];
        }
        catch (Exception ex)
        {
            System.Windows.MessageBox.Show(
                "Не удалось загрузить пакет вопросов:\n" + ex.Message,
                "Ошибка", MessageBoxButton.OK, MessageBoxImage.Error);
            // создаём пустой пакет, чтобы окно всё-таки открылось
            _package = new Package { Rounds = new List<Round>() };
        }

        Players = new ObservableCollection<PlayerScore>
    {
        new PlayerScore("Игрок 1"),
        new PlayerScore("Игрок 2")
    };

        PickQuestionCommand = new RelayCommand<Question>(OnPickQuestion);
    }

    private void OnPickQuestion(Question q)
    {
        var topic = CurrentRound.Topics.First(t => t.Questions.Contains(q));
        topic.Questions.Remove(q);

        if (CurrentRound.Topics.All(t => t.Questions.Count == 0))
            NextRound();
    }

    private void NextRound()
    {
        _roundIndex++;
        if (_roundIndex < _package.Rounds.Count)
            CurrentRound = _package.Rounds[_roundIndex];
        else
            System.Windows.MessageBox.Show("Игра окончена!");
    }

    public event PropertyChangedEventHandler PropertyChanged;
    private void OnPropertyChanged([CallerMemberName] string? prop = null) =>
        PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(prop));
}

/// <summary>Счёт игрока</summary>
public class PlayerScore : INotifyPropertyChanged
{
    public PlayerScore(string name) => _name = name;

    private string _name;
    private int _score;

    public string Name
    {
        get => _name; set { _name = value; OnPropertyChanged(); }
    }
    public int Score
    {
        get => _score; set { _score = value; OnPropertyChanged(); }
    }

    public event PropertyChangedEventHandler PropertyChanged;
    private void OnPropertyChanged([CallerMemberName] string? prop = null) =>
        PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(prop));
}

public class RelayCommand<T> : ICommand
{
    private readonly Action<T> _execute;
    public RelayCommand(Action<T> exec) => _execute = exec;

    public event EventHandler CanExecuteChanged;
    public bool CanExecute(object _) => true;

    public void Execute(object parameter) => _execute((T)parameter);
}