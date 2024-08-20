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

void Imprime(vi vect) {
  for (int i = 0; i < vect.size(); i++) {
    cout << vect[i] << " ";
  }
  cout << "\n";
}

void Imprime2d(vector<vi> vect) {
  for (int j = 0; j<vect.size(); j++){
    for (int i = 0; i < vect[j].size(); i++) {
        cout << vect[j][i] << " ";
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

/*vector<bool> chosen = {false, false, false, false, false, false, false, false, false};
vi permutation;
int sol;*/

/*void procesa(lli N, lli D){
    lli N2 = 0, D2 = 0;
    N2 += permutation[0];
    for (int i = permutation.size()-1; i>0; i--){
        D2*=10;
        D2+=permutation[i];
    }
    for (int i = 1; N2*D<=D2*N; i++){
        //cout << N2 << " " << D2 << endl;
        if (N2*D == D2*N){
            sol++;
        }
        N2*=10;
        N2+=permutation[i];
        D2-=permutation[i];
        D2/=10;
    }
}*/

/*void search(lli N, lli D, int tamano) {
    if (permutation.size() == tamano) {
        // process permutation
    } else {
        for (int i = 0; i < 9; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i+1);
            search(N, D, tamano);
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}*/

bool solve() {
  // Code aquí
  int N = 0; 
  int D = 0;
  cin >> N >> D;
  if (N == 0 && D == 0){
    return false;
  }
  int k = 0;
  //cout << N << " " << D << endl;
  for (int b = 10000/2; b >= 1; b /= 2) {
    //cout << (k+b) << " " << floor(log10(N*(k+b)))+1 << " " << floor(log10(D*(k+b)))+1 << endl;
    while (k+b < 10000 &&  (floor(log10(N*(k+b)))+floor(log10(D*(k+b)))+2) < 9) k += b;
  }
  //cout << "minimo: " << k+1 << endl;
  int minimo = k+1;
  k = 0;
  for (int b = 10000/2; b >= 1; b /= 2) {
    //cout << (k+b) << " " << floor(log10(N*(k+b)))+1 << " " << floor(log10(D*(k+b)))+1 << endl;
    while (k+b < 10000 &&  (floor(log10(N*(k+b)))+floor(log10(D*(k+b)))+2) <= 9) k += b;
  }
  //cout << "maximo: " << k << endl;

  int N2, D2;
  vector<bool> chosen;
  int len, sol = 0;
  for (int i = max(minimo,2); i<=k; i++){
    N2 = N*i;
    D2 = D*i;
    chosen.clear();
    chosen = {false, false, false, false, false, false, false, false, false};
    len = 0;
    //cout << "i: " << i << endl;
    while (N2>0){
        //cout << N2%10 << endl;
        if (N2%10 == 0 || chosen[N2%10-1]){
            break;
        }
        chosen[N2%10-1] = true;
        N2/=10;
        len++;
    }
    while (D2>0){
        //cout << D2%10 << endl;
        if (D2%10 == 0 || chosen[D2%10-1]){
            break;
        }
        chosen[D2%10-1] = true;
        D2/=10;
        len++;
    }
    if (len == 9){
        sol++;
    }
  }
  cout << sol << endl;

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