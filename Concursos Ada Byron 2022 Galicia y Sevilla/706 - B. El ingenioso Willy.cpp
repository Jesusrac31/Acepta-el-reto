//Librerías incluidas en #include<bitstdc++.h>
#include<algorithm>
#include<array>
#include<atomic>
#include<bitset>
#include<ccomplex>
#include<cerrno>
#include<cfenv>
#include<cfloat>
#include<chrono>
#include<cinttypes>
#include<ciso646>
#include<climits>
#include<clocale>
#include<cmath>
#include<complex>
#include<condition_variable>
#include<csetjmp>
#include<csignal>
#include<cstdalign>
#include<cstdarg>
#include<cstdbool>
#include<cstddef>
#include<cstdint>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctgmath>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<forward_list>
#include<fstream>
#include<functional>
#include<future>
#include<initializer_list>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include <limits.h>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<mutex>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<random>
#include<ratio>
#include<regex>
#include<scoped_allocator>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<system_error>
#include<thread>
#include<tuple>
#include<type_traits>
#include<typeindex>
#include<typeinfo>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<valarray>
#include<vector>
#include <stdlib.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef long long int lli;
typedef pair<lli, lli> pii;
typedef map<string, int> msi;
typedef map<int, vector<int>> miv;

// Funciones vector
#define PB(a) push_back(a);

bool sort_func(int a, int b) {
  if (a < b) {
    return true;
  } else {
    return false;
  }
}
#define ord(vect) sort(vect.begin(), vect.end(), sort_func);

#define borra_el(vect, el) vect.erase(vect.find(el));
#define borra_range(vect, a, b) vect.erase(a, b);
#define borra(vect, n) vect.erase(vect.begin() + n);
#define B begin();
#define E end();
#define copia(v1, v2)                                                          \
  ;                                                                            \
  copy(v1.begin(), v1.end(), back_inserter(v2));

// Funciones map
#define F first;
#define S second;

#define INF 0x3f3f3f3f

// Logaritmo de 2
double log_2 = log(2);
double log2(int a) { return (log(a) / log_2); }

void Imprime(vi vect) {
  for (int i = 0; i < vect.size(); i++) {
    cout << vect[i] << " ";
  }
  cout << "\n";
}

void Imprime2d(vector<vll> vect) {
  for (int j = 0; j<vect.size(); j++){
    for (int i = 0; i < vect[j].size(); i++) {
        cout << vect[j][i]+1 << " ";
    }
    cout << "\n";
  }
}

void Imprime_set(set<int> s) {
  copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}

int maximo_comun_divisor(int a, int b) {
  int temporal; // Para no perder b
  while (b != 0) {
    temporal = b;
    b = a % b;
    a = temporal;
  }
  return a;
}

int minimo_comun_multiplo(int a, int b) {
  return (a * b) / maximo_comun_divisor(a, b);
}

bool isNumeric(string const &str) {
  auto it = str.begin();
  while (it != str.end() && isdigit(*it)) {
    it++;
  }
  return !str.empty() && it == str.end();
}

vi lee(int n) {
  int el;
  vi vect;
  for (int i = 0; i < n; i++) {
    cin >> el;
    vect.PB(el);
  }
  return (vect);
}

lli shortestPath(lli src, lli destino, lli n, vector<vector<pii>>& adj, vector<vll>& parent, map<pii, lli>& conexiones) {
  priority_queue<pii, vector<pii>, greater<pii>>pq;

  vector<lli> dist(n, INF);

  pq.push(make_pair(0, src));
  dist[src] = 0;

  while (!pq.empty()) {
    lli u = pq.top().second;
    pq.pop();

    for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
      lli v = (*i).first;
      lli weight = (*i).second;
      //cout << u << " " << v << " " << dist[v] << " " << dist[u] << " " << weight << endl;
      if (conexiones[make_pair(u, v)] != -1){
        if (dist[v] > dist[u] + weight) {
          //cout << "CHANGE" << endl;
          dist[v] = dist[u] + weight;
          //cout << dist[v] << endl;
          parent[v].clear();
          parent[v].PB(u);
          pq.push(make_pair(dist[v], v));
        } else if (dist[v] == dist[u] + weight) {
          parent[v].PB(u);
        }
      }
    }
  }

  // Print shortest distances stored in dist[]
  /*cout << "Vertex Distance from Source\n";
  for (int i = 0; i < n; ++i)
      cout << i << "\t\t" << dist[i] << "\n";*/

  return dist[destino];
}

void Block (lli source, lli destino, vector<vll>& parent, map<pii, lli>& conexiones){
  for (int i = 0; i<parent[source].size(); i++){
    if (conexiones[make_pair(parent[source][i], source)] != -1){
      conexiones[make_pair(parent[source][i], source)] = -1;
      conexiones[make_pair(source, parent[source][i])] = -1;
      Block(parent[source][i], destino, parent, conexiones);
    }
  }
}


lli solve(lli ni, lli nc) {
  // Code aquí
  vector<vector<pii>> adj (ni, vector<pii> {});
  vector<vll> parent (ni, vll {});
  map<pii, lli> conexiones;
  
  lli x, y, w;
  pii par;
  while(nc--){
    cin >> x >> y >> w;
    x--;
    y--;
    adj[x].PB(make_pair(y, w));
    adj[y].PB(make_pair(x, w));
    conexiones[make_pair(x, y)] = w;
    conexiones[make_pair(y, x)] = w;
  }

  shortestPath(0, ni-1, ni, adj, parent, conexiones);
  Imprime2d(parent);
  Block(ni-1, 0, parent, conexiones);
  lli sol = shortestPath(0, ni-1, ni, adj, parent, conexiones);
  
  if (sol == INF){
    cout << "IMPOSIBLE" << endl;
  } else {
    cout << sol << endl;
  }

  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr); 
  lli ni, nc;
  while (cin >> ni >> nc) {
    solve(ni, nc);
  }
  return 0;
}

//Eliminar comentario si el proyecto está terminado (Dinámica empezó el 21/06/2024)