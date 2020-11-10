#include <iostream>
#include <random>

using namespace std;

int main() {
  random_device rd{};
  mt19937 rng{rd()};
  uniform_real_distribution<float> dist{0, 1};
  auto random = [&]() { return dist(rng); };

  for (int i = 0; i < 10; ++i)
    // cout << dist(rng) << '\n';
    cout << random() << '\n';
}
