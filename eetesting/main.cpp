#include <iostream>
using namespace std;
//this function tells us whether the P(x) is prime for all values of x from 0 to //49 – if the value of P(x) is negative, it returns false
bool areFirstFiftyPrimes(int i,int j,int k, int isPrime[], int primes[])
{
	for (int x=0;x<50;x++)
if ((isPrime[i*x*x+j*x+primes[k]]==0) || (i*x*x+j*x+primes[k]<0))
return false;
return true;
}

int main()
{
//this is the maximum value of i in P(x)
int max_i = 10;
//this is the maximum value of j in P(x) – we use it also with minus as the //minimum value of j in P(x)
int maxmin_j = 200;
//this is the number of numbers which we can check directly – we have primes only //from 1 to 100000
	int total = 100000;
//this is the number of primes between 1 and 30000 – found using Wolfram Alpha, //30000 is the upper limit for the value of p in P(x)
int numprimes30000 = 3245;
//the primes below are from this website - we did not generate them by ourselves
//http://www.free-online-calculator-use.com/prime-number-generator.html
//this is the list of all primes between 1 and 100 000

int  primes [] = {
2, 3, 5, 7, 11, 13, /*list of primes omitted here*/, 99989, 99991
	};
//this is the size of the array with primes
    	int primearsize = 9592;
//this array is used for checking whether a particular number is a prime
    	int isPrime [total];
	for (int i=0;i<total;i++)
		isPrime[i]=0;
//if a certain number is prime, we use 1 to signalise this number is a prime
//if a given number is not prime, the value signalizing whether it is prime is 0
	for (int i=0;i<primearsize;i++)
		isPrime[primes[i]]=1;
//this serves for counting how many suitable polynomials we have found
    	int numberofqpgps=0;
//for odd constants a and b in P(x)
//for every possible value of i, j in the given interval and the primes p based on //their placement in the array signalised by k
    	for (int i=1;i<max_i+1;i++)
		for (int j=-maxmin_j+1;j<maxmin_j+1;j++)
//we start from k equal 1 because the constant term in P(x) must not be 2 as we //have shown
            		for (int k=1;k<numprimes30000;k++)
                	 if (areFirstFiftyPrimes(2*i-1,2*j-1,k, isPrime,primes)==true)
                     {
                     cout<<2*i-1<<"x^2"<<"+"<<2*j-1<<"x"<<"+"<<primes[k]<<endl;
                     numberofqpgps++;
                     }
cout<<"Odd constants finished -"<<" number of odd qpgps found:"<<numberofqpgps<<endl;
    	numberofqpgps=0;

//even constants a and b in P(x)
	for (int i=1;i<max_i+1;i++)
		for (int j=-maxmin_j;j<maxmin_j+1;j++)
            		for (int k=1;k<numprimes30000;k++)
               	 if (areFirstFiftyPrimes(2*i,2*j,k, isPrime,primes)==true)
                     {
                     cout<<2*i<<"x^2"<<"+"<<2*j<<"x"<<"+"<<primes[k]<<endl;
                     numberofqpgps++;
                     }
cout<<"Even constants finished -"<<" number of even qpgps found: "<<numberofqpgps<<endl;
    return 0;
}
