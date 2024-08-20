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
typedef pair<int, int> pii;
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

// Logaritmo de 2
double log_2 = log(2);
double log2(int a) { return (log(a) / log_2); }

void Imprime(vector<int> vect) {
  for (int i = 0; i < vect.size(); i++) {
    cout << vect[i] << " ";
  }
  cout << "\n";
}

void ImprimePar(vector<pii> vect) {
  for (int i = 0; i < vect.size(); i++) {
    cout << "(" << vect[i].first << " " << vect[i].second << ") ";
  }
  cout << "\n";
}

void Imprime2d(vector<vector<pii>> vect) {
  for (int j = 0; j<vect.size(); j++){
    for (int i = 0; i < vect[j].size(); i++) {
        cout << "(" << vect[j][i].first << " " << vect[j][i].second << ") ";
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

bool debugging = false;

int padre;
int peso;
bool resuelto;

void dfs(int s, vector<vector<pii>>& adj, vector<bool>& visited, vector<pii>& parent, vector<int>& operacion, int turno = 1) {
    parent[s].first = padre;
    visited[s] = true;
    // process node s
    if(debugging){
        cout << s << endl;
    }
    for (auto u: adj[s]) {
        if (visited[u.first]){ // Ciclo
            if (debugging){
                cout << "BLOCK " << u.first << endl;
            }
            if (operacion[u.first] != (turno%2)*2-1 && !resuelto){ // operacion distinta, resuelve el sistema
                resuelto = true;
                if (debugging){
                    cout << parent[u.first].second << " " << peso+((turno%2)*2-1)*u.second << endl;
                }
                parent[padre].second = parent[u.first].second+peso+((turno%2)*2-1)*u.second;
                operacion[padre] = 1;
            }
            continue;
        }
        operacion[u.first] = (turno%2)*2-1;
        peso += operacion[u.first]*u.second;

        parent[u.first].second = peso;
        if (debugging){
            cout << turno << " " << u.first << " " << peso << endl;
        }
        dfs(u.first, adj, visited, parent, operacion, turno+1);

        peso -= operacion[u.first]*u.second;
    }
}

bool solve() {
  // Code aquí

  int e, n, m;
  cin >> e >> n >> m;
  if (e == 0 && n == 0 && m == 0){
    return false;
  }
  
  vector<vector<pii>> adj (e+1, vector<pii>{});
  vector<bool> visited (e+1, false);
  vector<int> operacion (e+1, -1); // True es que suma y false es que resta
  vector<pii> parent (e+1, {-1, 0});
  pii par;

  int p, x, y, w;
  for (int i = 0; i<n; i++){
    cin >> p;
    if (p == 1){
        cin >> x >> w;
        par.first = x;
        par.second = 2*w;
        adj[x].PB(par);
    } else {
        cin >> x >> y >> w;
        par.first = y;
        par.second = w;
        adj[x].PB(par);
        par.first = x;
        adj[y].PB(par);
    }
  }
  for (int i = 1; i<visited.size(); i++){
    if (!visited[i]){
        padre = i;
        peso = 0;
        resuelto = false;
        dfs(i ,adj, visited, parent, operacion);
    }
  }

  if (debugging){
    Imprime2d(adj);
    ImprimePar(parent);
    for (int i = 0; i<operacion.size(); i++){
        cout << operacion[i] << " ";
    }
    cout << endl;
  }

  for (int i = 0; i<m; i++){
    cin >> p;
    if (p == 1){
        cin >> x;
        y = x;
    } else {
        cin >> x >> y;
    }

    // Debemos resolver el sistema, todos los numeros en el vector parent se disponen de la siguiente forma:
    // {nodo con el que opera, resultado de operacion}
    // La operación la rige el vector operacion

    /* 
    Situaciones en las que SÍ hay respuesta posible:

    - Tienen el mismo padre y hacen operaciones contrarias con respecto a dicho padre, necesita dos alumnos
    x+y=n; x-z=m; --> x+y-(x-z) = n-m --> y+z=n-m
    - Se conoce el valor de su padre, respuesta valida para un solo alumno o para dos
    x+x=n; x+y=m; --> 2x+2y=2m --> n+2y=2m --> y=(2m-n)/2 
    x+x=n; x-y=m; --> 2x-2y=2m --> n-2y=2m --> y=-(2m-n)/2
    - Tienen padres distintos o iguales pero dichos padres son conocidos, necesitas dos nodos y aplicas la lógica anterior
    */


    if (p == 1 && operacion[parent[x].first] == 1){
        cout << operacion[x]*(2*parent[x].second-parent[parent[x].first].second)/2 << endl;
    } else if (p == 2 && operacion[parent[x].first] == 1 && operacion[parent[y].first] == 1){
        cout << operacion[x]*(2*parent[x].second-parent[parent[x].first].second)/2 + operacion[y]*(2*parent[y].second-parent[parent[y].first].second)/2 << endl;
    } else if (p == 2 && parent[x].first == parent[y].first && operacion[x] != operacion[y]){
        cout << (parent[x].second-parent[y].second)*operacion[x] << endl;
    } else {
        cout << "CUIDADO" << endl;
    }
  }

  cout << "---" << endl;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  bool T = true;
  while (T) {
    T = solve();
  }
  return 0;
}