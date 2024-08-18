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

void Imprime(vector<pii> vect) {
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
bool resuelto;

int recorre (int nodo_init, vector<vector<pii>>& conexiones, vector<pii>& parent, vi& bloqueados, int& turno){
    if (debugging){
        cout << "Nodo_init: " << nodo_init << endl;
    }
    bloqueados[nodo_init] = turno;
    for (auto u: conexiones[nodo_init]){
        if (debugging){
            cout << "TRY " << (u.first) << endl;
        }
        if (bloqueados[u.first] != 0){ // Está bloqueado
            if (debugging){
                cout << "Block " << (u.first) << endl;
            }
            if (turno%2 == bloqueados[u.first]%2 && !resuelto) { // Ciclo impar, tenemos el valor de todos los estudiantes del arbol
                if (debugging){
                    cout << "Padre " << parent[padre].second << endl;
                }
                parent[padre].second = (parent[nodo_init].second + parent[u.first].second);
                if (debugging){
                    cout << "Padre " << parent[padre].second << endl;
                }
                if (bloqueados[u.first]%2 == 1){
                    parent[padre].second += u.second;
                } else {
                    parent[padre].second -= u.second;
                }
                if (debugging){
                    cout << "Padre " << parent[padre].second << endl;
                }
                resuelto = true;
            }
            continue;
        }
        if (debugging){
            cout << "NOT_BLOCKED " << (u.first) << endl;
        }
        if (nodo_init != padre){
            if (turno % 2 == 1){
                parent[u.first].second = parent[nodo_init].second + u.second;
            } else {
                parent[u.first].second = parent[nodo_init].second - u.second;
            }
        } else {
              parent[u.first].second = u.second;
        }
        parent[u.first].first = padre;
        turno++;
        recorre(u.first, conexiones, parent, bloqueados, turno);
        turno--;
    }
    if (debugging){
        cout << "exit" << endl;
    }
    return 0;
}

bool solve() {
    // Code aquí
    int e, n, m;
    cin >> e >> n >> m;
    if (e == 0 && n == 0 && m == 0){
      return false;
    }

    vector<vector<pii>> conexiones (e+1);
    vector<pii> parent(e+1, {-1, -1});
    vi bloqueados(e+1, 0);

    int p, x, y, w;
    pii par;
    for (int i = 0; i<n; i++){
        cin >> p;
        if (p == 1){
            cin >> x >> w;
            y = x;
            w*=2;
        } else {
            cin >> x >> y >> w;
        }
        par.first = x;
        par.second = w;
        conexiones[y].PB(par);
        par.first = y;
        conexiones[x].PB(par);
    }
    if (debugging){
        Imprime2d(conexiones);
    }

    for (int i = 1; i<=e; i++){
        if (bloqueados[i] == 0){
            if (debugging){
                cout << "NEW " << i << endl;
            }

            padre = i;
            parent[i].first = i;
            parent[i].second = 0;
            resuelto = false;
            int turno = 1;
            recorre(i, conexiones, parent, bloqueados, turno);
            if (!resuelto){
                parent[i].second = -1;
            }
        }
    }
    if (debugging){
        Imprime(parent);
        cout << endl;
        Imprime2d(conexiones);
        cout << endl;
    }
    while (m--){
        cin >> p;
        if (p == 1){
            cin >> x;
            y = x;
        } else {
            cin >> x >> y;
        }
        //Los casos se dividen en dos: Pertenecen al mismo arbol (tienen mismo padre) o no
        int sol = -1;
        if (parent[x].first == parent[y].first){ // Mismo arbol
            // En caso de estar en el mismo arbol debemos ver si pueden enlazarse o no
            // Si sabemos el valor exacto del padre no tendremos ningún problema
            
            if (parent[parent[x].first].second != -1){
                // A partir del padre sumamos ambos resultados
                // p+x = k --> x = k-p
                if (bloqueados[x]%2 == 1){
                    sol = abs(parent[parent[x].first].second/2-parent[x].second);
                } else {
                    sol = parent[x].second-parent[parent[x].first].second/2;
                }
                if (bloqueados[y]%2 == 1){
                    sol += abs(parent[parent[y].first].second/2-parent[y].second);
                } else {
                    sol += parent[y].second-parent[parent[y].first].second/2;
                }
            } else {
                //Si no tenemos el valor de sus padres va a ser más difiil, necesitamos que los numeros almacenados en bloqueados mod 2 sean distintos.
                if (bloqueados[x]%2 != bloqueados[y]%2){
                    // Si son distintos sabemos el resultado de la siguiente forma:
                    // p+x - (p-y) = x+y; Siendo p la incognita del padre, x la del primer alumno e y la del segundo
                    if (parent[x].second != -1){
                        if (bloqueados[x]%2 == 1){
                            sol = (-1)*parent[x].second;
                        } else {
                            sol = parent[x].second;
                        }
                    } else {
                        sol = 0;
                    }
                    if (parent[y].second != -1){
                        if (bloqueados[y]%2 == 1){
                            sol += (-1)*parent[y].second;
                        } else {
                            sol += parent[y].second;
                        }
                    }
                } else {
                    // En caso de que sean iguales nos será imposible predecir el resultado
                    cout << "CUIDADO" << endl;
                }
            }
        } else { // Diferente arbol
            // Esta opción solo hay una forma de obtener el resultado, debemos tener el valor de los nodos padres de ambos casos
            if (parent[parent[x].first].second != -1 && parent[parent[y].first].second != -1){
                // La forma de saber el resultado en esta situación es obteniendo el valor del nodo a partir de la relación entre ellos
                // p+x = k --> x = k-p
                if (bloqueados[x]%2 == 1){
                    sol = abs(parent[parent[x].first].second/2-parent[x].second);
                } else {
                    sol = parent[x].second-parent[parent[x].first].second/2;
                }
                if (bloqueados[y]%2 == 1){
                    sol += abs(parent[parent[y].first].second/2-parent[y].second);
                } else {
                    sol += parent[y].second-parent[parent[y].first].second/2;
                }
            } else {
                cout << "CUIDADO" << endl;
            }
        }
        if (sol != -1){
            if (p == 1){
                sol /= 2;
            }
            cout << sol << endl;
        }
    }
    
    cout << "---" << endl;
    return true;
}

int main() {
  /*ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr); */
  bool T = true;
  while (T) {
    T = solve();
  }
  return 0;
}

//Eliminar comentario si el proyecto está terminado (Dinámica empezó el 21/06/2024)