#include <iostream>
using namespace std;



template <bool... digits>
struct Solver;
    
template <bool Head, bool... Tail>
struct Solver<Head, Tail...>
{
    static int value()
    {
        return Head + 2 * Solver<Tail...>::value();
        cout << "from solver " << Head << endl;
    }
};

template <>
struct Solver<>
{
    static int value()
    {
        return 0;
    }
};

template <bool... digits>
int reversed_binary_value()
{
    return Solver<digits...>::value();
}

template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
        cout << "from check in   (n-1) =  " << n-1 <<  endl;
    	CheckValues<n-1, 0, digits...>::check(x, y);
    	CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
        cout << "from check in   only pools =  "  ;
    	int z = reversed_binary_value<digits...>();
    	std::cout <<z;// (z+64*y==x);
        cout << endl;
  	}
};

int main()
{
  	int t; std::cin >> t;

  	for (int i=0; i!=t; ++i) {
		int x, y;
    	cin >> x >> y;
    	CheckValues<6>::check(x, y);
    	cout << "\n";
  	}
        
        }
