#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Проверяет, можно ли перейти от снимка i к j
bool can_transition(const vector<tuple<int,int,int,int>>& shots, int i, int j) {
    auto [x1_i, y1_i, x2_i, y2_i] = shots[i];
    auto [x1_j, y1_j, x2_j, y2_j] = shots[j];

    // Проверяем все возможные переходы между клетками
    for (int x_i = x1_i; x_i <= x2_i; ++x_i) {
        for (int y_i = y1_i; y_i <= y2_i; ++y_i) {
            for (int x_j = x1_j; x_j <= x2_j; ++x_j) {
                for (int y_j = y1_j; y_j <= y2_j; ++y_j) {
                    // Проверяем соседство клеток
                    if (abs(x_i - x_j) + abs(y_i - y_j) == 1) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

// Рекурсивная функция для поиска гамильтонова пути
bool hamiltonian_path(vector<vector<bool>>& graph, vector<bool>& visited, int current, int count) {
    if (count == graph.size()) {
        return true;
    }

    for (int next = 0; next < graph.size(); ++next) {
        if (graph[current][next] && !visited[next]) {
            visited[next] = true;
            if (hamiltonian_path(graph, visited, next, count + 1)) {
                return true;
            }
            visited[next] = false;
        }
    }
    return false;
}

int main() {
    int W, H;
    cin >> W >> H;

    int N;
    cin >> N;

    vector<tuple<int,int,int,int>> shots(N);
    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        shots[i] = make_tuple(x1, y1, x2, y2);
    }

    // Строим матрицу смежности
    vector<vector<bool>> graph(N, vector<bool>(N, false));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i != j && can_transition(shots, i, j)) {
                graph[i][j] = true;
            }
        }
    }

    // Проверяем существование гамильтонова пути
    vector<bool> visited(N, false);
    bool exists = false;

    // Пробуем начать с каждой вершины
    for (int start = 0; start < N; ++start) {
        fill(visited.begin(), visited.end(), false);
        visited[start] = true;
        if (hamiltonian_path(graph, visited, start, 1)) {
            exists = true;
            break;
        }
    }

    cout << (exists ? "Yes" : "No") << endl;
    return 0;
}