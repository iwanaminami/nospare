#include <R.h>
/* a trick to keep up with the parameters */

static double parms[3];

#define beta parms[0]
#define gamma parms[1]
#define delta parms[2]



/* initializers */
void initparms( void (* odeparms)(int *, double *) ) {
  int N = 3;
  odeparms(&N,parms);
}
/* names for states and derivatives */
#define TC var[0]
#define VL var[1]

#define dTCdt vardot[0]
#define dVLdt vardot[1]


void derivs( int *neq, double *t, double *var, double *vardot, double *varout, int *ip ) {
  if( ip[0]<1 ) {
    error("nout should be at least 1");
  }
  
  
  dTCdt = - beta*TC*VL;
  dVLdt = gamma*TC*VL - delta*VL;
  
  
}