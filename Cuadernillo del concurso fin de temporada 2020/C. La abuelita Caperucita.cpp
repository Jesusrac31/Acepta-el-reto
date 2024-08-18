//Librerías incluidas en #include<bitstdc++.h>
#include<algorithm>
#include <limits.h>
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
typedef pair<long long int, long long int> pii;
typedef map<string, lli> msi;
typedef map<lli, vector<lli>> miv;

// Funciones vector
#define PB(a) push_back(a);

bool sort_func(lli a, lli b) {
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
double log2(lli a) { return (log(a) / log_2); }

void Imprime(vll vect) {
  for (lli i = 0; i < vect.size(); i++) {
    cout << vect[i] << " ";
  }
  cout << "\n";
}

void Imprime2d(vector<vll> vect) {
  for (lli j = 1; j<vect.size(); j+=2){
    cout << j/2 << ": ";
    for (lli i = 0; i < vect[j].size(); i++) {
        cout << vect[j][i] << " ";
    }
    cout << "\n";
  }
}

void Imprime2d_bool(vector<vector<bool>> vect) {
  for (lli j = 0; j<vect.size(); j++){
    for (lli i = 0; i < vect[j].size(); i++) {
        cout << vect[j][i] << "\t";
    }
    cout << "\n";
  }
}

void Imprime_set(set<lli> s) {
  copy(s.begin(), s.end(), ostream_iterator<lli>(cout, " "));
  cout << endl;
}

lli maximo_comun_divllsor(lli a, lli b) {
  lli temporal; // Para no perder b
  while (b != 0) {
    temporal = b;
    b = a % b;
    a = temporal;
  }
  return a;
}

lli minimo_comun_multiplo(lli a, lli b) {
  return (a * b) / maximo_comun_divllsor(a, b);
}

bool isNumeric(string const &str) {
  auto it = str.begin();
  while (it != str.end() && isdigit(*it)) {
    it++;
  }
  return !str.empty() && it == str.end();
}

vll lee(lli n) {
  lli el;
  vll vect;
  for (lli i = 0; i < n; i++) {
    cin >> el;
    vect.PB(el);
  }
  return (vect);
}

lli Pair2Int (pii par, lli m){
  return((par.first*m)+par.second);
}

bool inv = false;

lli bfs(lli source,lli target,vector<lli>& parent,vector<bool>& visited, vector<vll>& conexiones){
    //Update the parent vector as each node value to be -1
        fill(parent.begin(),parent.end(),-1);
    //parent of source node to be -2
        parent[source] = -2;
    //Initializing queue for storing and min capacity so far
        queue<lli> q;
        //vll registro;
    //Source node min capacity to be 1e9
        q.push(source);
        //registro.PB(source);
        
    //Looping while queue is not empty 
        while(!q.empty()){
            //storing top node and min capacity so far
            lli u = q.front();
            //Removing top node from queue
            q.pop();
            //borra(registro, 0);
            //Looping all edges from u
            for(int i = 0; i<conexiones[u].size(); i++){
                //finding v node has edge from u
                int v;
                if (inv){
                  v = conexiones[u][conexiones[u].size()-1-i];
                } else {
                  v = conexiones[u][i];
                }
                //Imprime(registro);
                if(u!=v && !visited[v] && parent[v]==-1){
                    //storing parent v to be u
                    parent[v] = u;
                    //If v is the target node then return minimum capacity
                    if(v==target){
                        return 1;
                    }
                    //if we didn't find target node
                    //Insert the v node and minimum capacity so far in queue
                    q.push(v);
                    //registro.PB(v);
                }
            }
        }
    //if we didn't find path between source to target return 0
        return 0;
}

lli dfs (lli source,lli target,vector<lli>& parent,vector<bool>& visited, vector<vll>& conexiones){
  lli sol;
  visited[source] = true;
  //cout << "source: " << source << endl;
  for (auto i: conexiones[source]){
    if (!visited[i]){
      parent[i]=source;
      if (i == target){
        return 1;
      }
      sol = dfs(i, target, parent, visited, conexiones);
      if (sol == 1){
        return 1;
      }
      visited[i] = false;
    }
  }
  return 0;
}

lli Ford_Fulkerson(lli source,lli target,lli n,vector<bool> visited, vector<vll>& conexiones){
    //Initializing parent vector for finding the path from source to target
    //In which we add parent of the node
        vector<lli> parent(n,-1);
    //Initializing maximum flow for storing ans
        lli max_flow = 0;
        lli min_cap = 0;   //storing minimum capacity in each path
        
    //looping while minimum capacity become zero 
    //For finding path and minimum capacity we call function bfs()
        while(min_cap = bfs(source,target,parent,visited, conexiones)){
            //cout << "Si" << endl;
            //Adding the min_cap from this path 
            max_flow += min_cap;
            //cout << "max_flow " << max_flow << endl;
            //storing target node in v
            lli v = target;
            
            //while we didn't find the source node
            //Looping through path stored in parent 
            int contador = 0;
            while(v!=source){
                cout << v << " ";
                //finding parent of v node
                lli u = parent[v];
                if (contador >= 2){
                  visited[v] = true;
                } else {
                  visited[v] = false;
                }
                //Update the v node to it's parent
                v=u;
                contador++;
            }
            cout << endl;
        }
    //Returning maximum flow in the graph
        return max_flow;
    }

lli solve() {
  // Code aquí
  string el;
  pii caperucita, lobo;
  lli n, m;
  cin >> n >> m;

  vector<vll> conexiones;
  vector<bool> visited;
  for(lli i = 0; i<n; i++){
    cin >> el;
    for (lli j = 0; j<m; j++){
        conexiones.PB({});
        //cout << i << " " << j << endl;

        // Cada casilla consta de dos nodos, uno recibirá el flujo y otro lo sacará, limitando así que salga tan solo 1 unidad

        if (el[j] != '#'){
          visited.PB(false);
          if (i != 0){
            conexiones[(i*m+j)].PB(((i-1)*m+j));
          }
          if (j != 0){
            conexiones[(i*m+j)].PB(((i)*m+j-1));
          }
          if (j != m-1){
            conexiones[(i*m+j)].PB(((i)*m+j+1));
          }
          if (i != n-1){
            conexiones[(i*m+j)].PB(((i+1)*m+j));
          }
        } else {
          visited.PB(true);
        }

        if (el[j] == 'L'){
            lobo.first = i;
            lobo.second = j;
        }
        if (el[j] == 'C'){
            caperucita.first = i;
            caperucita.second = j;
        }
    }
  }

  if (abs(caperucita.first-lobo.first) + abs(caperucita.second-lobo.second) < 2){
    cout << "IMPOSIBLE" << endl;
    return 0;
  }
  if (abs(caperucita.first-lobo.first) + abs(caperucita.second-lobo.second) == 2 && abs(caperucita.second-lobo.second) == 1){
    if (!visited[caperucita.first*m+lobo.second] || !visited[lobo.first*m+caperucita.second]){
        cout << "IMPOSIBLE" << endl;
        return 0;
    } else {
      cout << 0 << endl;
      return 0;
    }
  }
  if (abs(caperucita.first-lobo.first) + abs(caperucita.second-lobo.second) == 2){
    if (!visited[(caperucita.first-(caperucita.first-lobo.first)/2)*m+(caperucita.second-(caperucita.second-lobo.second)/2)]){
        cout << "IMPOSIBLE" << endl;
        return 0;
    } else {
      cout << 0 << endl;
      return 0;
    }
  }
  
  //cout << caperucita.first << " " << caperucita.second << endl;
  inv = false;
  lli sol = Ford_Fulkerson((lobo.first*m+lobo.second), (caperucita.first*m+caperucita.second),n*m, visited, conexiones);
  cout << "---------------" << endl;
  inv = true;
  lli sol2 = Ford_Fulkerson((lobo.first*m+lobo.second), (caperucita.first*m+caperucita.second),n*m, visited, conexiones);
  cout << max(sol, sol2) << endl;

  //cout << "-------------------" << endl;
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr); 
  lli T;
  cin >> T; // Número de casos
  while (T--) {
    solve();
  }

  return 0;
}

// Pequeño fallo solucionado en el otro archivo