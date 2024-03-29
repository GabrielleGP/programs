/*Hestenes Stiefel's method of unconstrained linear optimization*/
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

// Hestenes Stiefel's method
int metHS(double &x,double &y,double eps,int &nEvG) {
  double fdx_k,fdy_k,nrm_k,dx_k,dy_k,alpha_k,beta_k,nrm_k1;
  int k=0;
  nEvG=0;
 //First step
  fdx_k=fd_x(x,y);
  fdy_k=fd_y(x,y);
  if((nrm_k=norma(fdx_k,fdy_k))>=eps) {
    dx_k=-fdx_k;
    dy_k=-fdy_k;
    while(true) {
      ++k;
     // Second step
      alpha_k=-(fdx_k*dx_k+fdy_k*dy_k)/(2*(a*dx_k*dx_k+2*dx_k*dy_k+b*dy_k*dy_k));
   cout << endl << "Alfa" << alpha_k << endl;
     // Third step
      x+=alpha_k*dx_k;
      y+=alpha_k*dy_k;
      fdx_k=fd_x(x,y);
      fdy_k=fd_y(x,y);
      nEvG+=1;
      if((nrm_k1=norma(fdx_k,fdy_k))<eps) break;
     // Fourth step
      beta_k=(nrm_k1*nrm_k1)/(nrm_k*nrm_k);
      dx_k=-fdx_k+beta_k*dx_k;
      dy_k=-fdy_k+beta_k*dy_k;
      nrm_k=nrm_k1;


    }
  }
  return k;
}

int main() {
  double x,y,xs,ys;
  int nEvF,nEvG,k;
  cout<<"Enter the starting point:\n";
  cout<<"   x = ";
  cin>>x;
  cout<<"   y = ";
  cin>>y;

  cout<<"\n    ***   The Hestenes Stiefel method ***\n";
  k=metHS(x,y,0.00001,nEvG);
  cout<<"min f(x,y) = f("<<x<<","<<y<<") = "<<f(x,y)<<endl;
  cout<<"N: "<<k<<endl
      <<"The gradient was evaluated by "<<nEvG<<" times"<<endl;
  system("pause");
}
