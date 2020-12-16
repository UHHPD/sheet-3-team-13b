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

double prob_1(vector<int> daten_1, int i) 
{
  double L_1;
  if (daten_1[i] != 0) 
  {
   L_1=pow(daten_1[i],daten_1[i])*exp((-1)*daten_1[i])/tgamma(daten_1[i]+1);
  }
  else 
  {
   L_1=pow(daten_1[i],daten_1[i])*exp((-1)*daten_1[i])/1;  
  }
  return L_1;
}

int main() 
{ 
  vector<int> daten;
  vector<int> daten_1;
  ifstream fin("datensumme.txt");
  ifstream fin1("datensumme.txt");
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

  
  double result0 = 1;
   for (int i=0;i<234;++i) 
    { 
      double mu=3.11538;
      result0 = result0*prob(daten, mu, i);
    }
   cout << result0 << endl;

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
 
  //Exercise 2(e)
  for(int i=0;i<234;++i) 
   {
     fin1 >> n_i;
     daten_1.push_back(n_i);
   }
  fin1.close();
  double result4 = 1;
  double Lambda;
  double nDoF=233;
  double result = 7.76841e-195;

  for(int i=0;i<234;++i) 
  {
    result4 = result4*prob_1(daten_1,i);
    Lambda = result/result4;
  }
  double del_Lambda = (-2)*log(Lambda);
  cout << del_Lambda << endl;

}