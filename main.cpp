#include <chrono>
#include <iostream>
#include <random>

using namespace std;

int main() {
  random_device rd{};
  mt19937 rng{rd()};
  uniform_real_distribution<float> dist{0, 1};
  auto random = [&]() { return dist(rng); };

  const auto start = chrono::high_resolution_clock::now();

  int n = 100;
  int c = 0;

  for (int i = 0; i < 10; ++i) {
    const auto x = random();
    const auto y = random();
    const auto r2 = x * y + y * y;
    if (r2 < 1) ++c;
  }

  const auto end = chrono::high_resolution_clock::now();

  const auto time = chrono::duration<float>(end - start).count();

  auto monte_carlo_pi = 4 * float(c) / float(n);
  cout << "pi=" << monte_carlo_pi << '\n';
  cout << "time =" << time << "s\n";
  // cout << dist(rng) << '\n';
  // cout << random() << '\n';
}
