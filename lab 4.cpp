/*minimul global*/

#include<iostream>
#include<math.h>

using namespace std;

const int a=3,b=5;

double f(double x,double y) {
  return a*x*x+2*x*y+b*y*y-2*x-3*y;
}

double fd_x(double x,double y) {
  return 2*a*x+2*y-2;
}

double fd_y(double x,double y) {
  return 2*x+2*b*y-3;
}

double norma(double x,double y) {
  return sqrt(x*x+y*y);
}

// Metoda Gradientului cu Fractionarea Pasului
int metodaGFP(double &x,double &y,double eps,int &nEvF,int &nEvG) {
  const double alpha=1,delta=0.06,gamma=0.5;
  double alpha_k,f_k,fdx_k,fdy_k,nrm,nrm_2,zx,zy;
  int k=0;
  nEvF=0;
  nEvG=1;
  while((nrm=norma(fdx_k=fd_x(x,y),fdy_k=fd_y(x,y))) >= eps) {
    f_k=f(x,y);
    ++nEvF;
    ++nEvG;
    nrm_2=nrm*nrm;
    alpha_k=alpha/gamma;
    do {
      alpha_k*=gamma;
      zx=x-alpha_k*fdx_k;
      zy=y-alpha_k*fdy_k;
      ++nEvF;
    } while(f(zx,zy)-f_k>-delta*alpha_k*nrm_2);
    x-=alpha_k*fdx_k;
    y-=alpha_k*fdy_k;
    ++k;
  }
  return k;
}



int main() {
  double x,y,xs,ys;
  int nEvF,nEvG,k;
  cout<<"Introduceti punctul initial:\n";
  cout<<"   x = ";
  cin>>x;
  cout<<"   y = ";
  cin>>y;

cout<<"\n    ***   Metoda Gradietului cu fractionarea pasului ***\n";
 k=metodaGFP(x,y,0.00001,nEvF,nEvG);
  cout<<"min f(x,y) = f("<<x<<","<<y<<") = "<<f(x,y)<<endl
      <<"Numarul de iteratii: "<<k<<endl
      <<"Gradientul a fost evaluat de "<<nEvG<<" ori"<<endl;
  system("pause");
}

