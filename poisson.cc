#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

 double poisson(double mu, int k)
  {
   double P;
   P= (exp((-1)*mu)*pow(mu,k))/ (tgamma(k+1));
   return (P);
  }

int main() 
{

 double mu=3.11538;
 using namespace std;
vector<int>v;

    ifstream fin("datensumme.txt");
    ofstream fout("hist.txt");
    ofstream fout1 ("histpoi.txt");
    int n_i,i,k;
    int counter[11]={0};
    for(int i = 0 ; i < 234 ; i++)
     {
       fin >> n_i;
       v.push_back(n_i);
     }
     fin.close();
     
     for (int k = 0 ; k < v.size(); k++) 
    { 
      
        counter[v[k]]+=1;
     }     
        for (int k=0; k<11; k++) {
          double result = 234* poisson(mu, k);
        //cout << k << ":" << counter[k] << endl ;
        fout << k << " " << counter[k] << endl ;
        cout << result << endl;
        fout1 << k << " " << counter[k]<< " " << result << endl;

        }
     
      fout.close();
      fout1.close();
     
    
     
     
}
