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

bool sort_func(pii a, pii b) {
  if (a.first < b.first) {
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

bool solve(int n) {
    // Code aquí
    vi dias(400, 0);
    vector<pii> cursos;

    string el;
    int dia, mes;
    pii par;
    for (int i = 0; i<n; i++){
        cin >> el;
        dia = stoi(el.substr(0,2));
        mes = stoi(el.substr(3,4));
        dias[(mes-1)*31+dia]++;
        par.first = (mes-1)*31+dia;
        cin >> el;
        dia = stoi(el.substr(0,2));
        mes = stoi(el.substr(3,4));
        dias[(mes-1)*31+dia+1]--;
        par.second = (mes-1)*31+dia+1;
        cursos.PB(par);
    }
    ord(cursos);
    par.first = 401;
    par.second = 401;
    cursos.PB(par);
    //Imprime(dias);
    int contador = 0, index = 0;
    multiset<int> act;
    auto it = act.begin();
    int sol = n;
    for (int i = 0; i<dias.size(); i++){
        contador+=dias[i];
        while (cursos[index].first<=i){
            act.insert(cursos[index].second);
            index++;
        }
        while (contador>4){
            /*cout << "HEY " << i << endl;
            for (auto j = act.begin(); j != act.end(); j++){
                cout << (*j) << " ";
            }
            cout << endl;*/
            sol--;
            contador--;
            it=act.end();
            it--;
            //cout << (*it) << endl;
            dias[(*it)]++;
            act.erase(it);
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
    int n;
    while (cin >> n) {
        T = solve(n);
    }
    return 0;
}
