#include<iostream>

using namespace std;

int main()
{
    cout << "Wellcome" << endl;
    try
    {
        throw(10);
        cout << "In try After try" << endl;
    }
    catch(int e)
    {
        cout << "Exception no :- " << e << endl;
    }
    catch(double e)
    {
        cout << "Exception no :- " << e << endl;
    }
    catch(...)
    {
        cout << "Default Exception";
    }
    cout << "Last line";
}
