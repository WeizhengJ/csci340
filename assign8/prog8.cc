/*********************************************************************
    PROGRAM:    CSCI 340 Assignment 8
    PROGRAMMER: 
    LOGON ID:   
    DUE DATE:   
    PURPOSE:    
 **********************************************************************/

#include "/home/cs340/progs/17f/p8/prog8.h"

int main ( )
{
    vector < int >    v1;   // heap of integers
    vector < float >  v2;   // heap of floating-pt nums
    vector < string > v3;   // heap of strings

    // print header message
    cout << "\t\t\t*** CSCI 340: Program 8 - Output ***\n\n";

    // first heap

    cout << "first heap - ascending order:\n\n";
    get_list ( v1, D1 );
    construct_heap ( v1, less < int > ( ) );
    print_list < int > print1 ( v1.size ( ), INT_SZ, INT_LN );
    for_each ( v1.begin ( ), v1.end ( ), print1 );

    cout << "first heap - descending order:\n\n";
    get_list ( v1, D1 );
    construct_heap ( v1, greater < int > ( ) );
    for_each ( v1.begin ( ), v1.end ( ), print1 );

    // second heap

    cout << "second heap - ascending order:\n\n";
    get_list ( v2, D2 );
    construct_heap ( v2, less < float > ( ) );
    print_list < float > print2 ( v2.size ( ), FLT_SZ, FLT_LN );
    for_each ( v2.begin ( ), v2.end ( ), print2 );

    cout << "second heap - descending order:\n\n";
    get_list ( v2, D2 );
    construct_heap ( v2, greater < float > ( ) );
    for_each ( v2.begin ( ), v2.end ( ), print2 );

    // third heap

    cout << "third heap - ascending order:\n\n";
    get_list ( v3, D3 );
    construct_heap ( v3, less < string > ( ) );
    print_list < string > print3 ( v3.size ( ), STR_SZ, STR_LN );
    for_each ( v3.begin ( ), v3.end ( ), print3 );

    cout << "third heap - descending order:\n\n";
    get_list ( v3, D3 );
    construct_heap ( v3, greater < string > ( ) );
    for_each ( v3.begin ( ), v3.end ( ), print3 );

    // print termination message
    cout << "\t\t\t*** end of program execution ***\n\n";
    return 0;
}

/***************************************************************
Function: get_list()
Use: takes input from a file and stores it in a vector
Parameters: v: a vector container for T data type
	    path: const char pointer to the path of the file to read from
Returns: nothing
***************************************************************/
template <class T>
void get_list(vector <T>& v, const char* path)
	{
	v.clear();
	T data;
	ifstream inFile;
	inFile.open(path);

	if(inFile.fail())
		{
		cout << "FAILURE TO OPEN" << path;
		exit(1);
		}

	inFile >> data;
	while(inFile)
		{
		v.push_back(data);
		inFile >> data;
		}

	inFile.close();
	}

/***************************************************************
Function: construct_heap()
Use: makes and sorts a heap
Parameters: v: a vector container for T data type
            pred: predicate for comparing items while building and sorting the heap
Returns: nothing
***************************************************************/
template <class T, class P>
void construct_heap(vector <T>& v, P pred)
	{
	make_heap(v.begin(), v.end(), pred);
	sort_heap(v.begin(), v.end(), pred);
	}

/***************************************************************
Function: print_list()
Use: constructor for print_list class
Parameters: s: cosnt unsigned reference to store size
	    w: const unsigned reference to store width
	    l: const unsigned reference to store length
	    c: const unsigned reference to store count starting at 0
Returns: nothing
***************************************************************/
template <class T>
print_list<T>::print_list(const unsigned& s, const unsigned& w, const unsigned& l, const unsigned& c)
	{
	sz = s;
	wid = w;
	len = l;
	cnt = c;
	}


/***************************************************************
Function: operator()
Use: prints x from a heap in stdout
Parameters: x: cosnt reference to a T data type
Returns: nothing
***************************************************************/
template <class T>
void print_list<T>::operator()(const T& x)
	{
	cout.width(wid); cout.precision(2);
	cout << fixed << showpoint;

	if(cnt <= sz)
		{
		if(cnt%len == 0)
			cout << endl;

		cout << x << " ";
		cnt++;
		}

	if(cnt == sz)
		cout << endl << endl;
	}
