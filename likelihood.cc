#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;


double prob(vector<int> daten, double mu, int i) 
{
  double L;
  if (daten[i] != 0) 
  {
   L=pow(mu,daten[i])*exp((-1)*mu)/tgamma(daten[i]+1);
  }
  else
  {
   L=pow(mu,daten[i])*exp((-1)*mu)/1;  
  }
  return L;
}

int main() 
{ 
  vector<int> daten;
  ifstream fin("datensumme.txt");
  ofstream fout1("likelihood.txt");
  ofstream fout2("nll.txt");
  ofstream fout3("deltanll.txt");
  int n_i,i;
  for(int i=0;i<234;++i) 
   {
     fin >> n_i;
     daten.push_back(n_i);
   }
  fin.close();
  //Exercise 2(a)

  /*double mu=3.11538;
  double result = 1;
   for (int i=0;i<234;++i) 
    { 
      result = result*prob(daten, mu, i);
    }
   cout << result << endl;*/

  //Exercise 2(b),2(c),2(d) 
  double mu;
  for(mu=0;mu<6;mu=mu+0.1)
  { 
   double result1 = 1;
   double result2 = 1;
   double result = 7.76841e-195;
   double result3= 0;
   for (int i=0;i<234;++i) 
    { 
      result1 = result1*prob(daten, mu, i);
    }
    result2 = result2*((-2)*log(result1));
    result3 = result2 - ((-2)*log(result));
    fout1 << mu << " " << result1 << endl;
    fout2 << mu << " " << result2 << endl;
    fout3 <<mu << " " << result3 << endl;
 }

   
  fout1.close(); 
  fout2.close(); 
  fout3.close();



  
}