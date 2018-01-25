
#include <include/symbolic_functions.h>
#include <include/amici_defines.h> //realtype definition
typedef amici::realtype realtype;
#include <cmath> 

void deltasx_model_neuron_o2(double *deltasx, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h, const realtype *w, const int ip, const int ie, const realtype *xdot, const realtype *xdot_old, const realtype *sx, const realtype *stau) {
switch (ip) {
  case 0: {
              switch(ie) { 
              case 0: {
  deltasx[0] = -sx[0]-stau[0]*(xdot[0]-xdot_old[0])-stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2);
  deltasx[1] = -stau[0]*(xdot[1]-xdot_old[1]);
  deltasx[2] = -(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))*((x[2]*(x[0]*(2.0/2.5E1)+5.0))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[2]*(x[0]*(2.0/2.5E1)+5.0)*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))-stau[0]*(xdot[2]-xdot_old[2])-((sx[2]-stau[0]*(x[3]-w[1]*x[2]))*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[2]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1));
  deltasx[3] = -stau[0]*(xdot[3]-xdot_old[3])-((p[0]*p[1]*x[2])/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[2]*(x[0]*(2.0/2.5E1)+5.0)*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0))*(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))-((p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*(sx[2]-stau[0]*(x[3]-w[1]*x[2])))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-(x[2]*(p[3]+p[1]*p[2]+p[1]*x[0]))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[2]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0);
  deltasx[4] = -(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))*((x[4]*(x[0]*(2.0/2.5E1)+5.0))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[4]*(x[0]*(2.0/2.5E1)+5.0)*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))-stau[0]*(xdot[4]-xdot_old[4])-((sx[4]-stau[0]*(x[5]-w[1]*x[4]))*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[4]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1));
  deltasx[5] = -stau[0]*(xdot[5]-xdot_old[5])-((p[0]*p[1]*x[4])/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[4]*(x[0]*(2.0/2.5E1)+5.0)*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0))*(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))-((p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*(sx[4]-stau[0]*(x[5]-w[1]*x[4])))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-(x[4]*(p[3]+p[1]*p[2]+p[1]*x[0]))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[4]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0);
  deltasx[6] = -(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))*((x[6]*(x[0]*(2.0/2.5E1)+5.0))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[6]*(x[0]*(2.0/2.5E1)+5.0)*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))-stau[0]*(xdot[6]-xdot_old[6])-((sx[6]-stau[0]*(x[7]-w[1]*x[6]))*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[6]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1));
  deltasx[7] = -stau[0]*(xdot[7]-xdot_old[7])-((p[0]*p[1]*x[6])/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[6]*(x[0]*(2.0/2.5E1)+5.0)*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0))*(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))-((p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*(sx[6]-stau[0]*(x[7]-w[1]*x[6])))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-(x[6]*(p[3]+p[1]*p[2]+p[1]*x[0]))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[6]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0);
  deltasx[8] = -(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))*((x[8]*(x[0]*(2.0/2.5E1)+5.0))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[8]*(x[0]*(2.0/2.5E1)+5.0)*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))-stau[0]*(xdot[8]-xdot_old[8])-((sx[8]-stau[0]*(x[9]-w[1]*x[8]))*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[8]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1));
  deltasx[9] = -stau[0]*(xdot[9]-xdot_old[9])-((p[0]*p[1]*x[8])/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[8]*(x[0]*(2.0/2.5E1)+5.0)*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0))*(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))-((p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*(sx[8]-stau[0]*(x[9]-w[1]*x[8])))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-(x[8]*(p[3]+p[1]*p[2]+p[1]*x[0]))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[8]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0);

              } break;

              } 

  } break;

  case 1: {
              switch(ie) { 
              case 0: {
  deltasx[0] = -sx[0]-stau[0]*(xdot[0]-xdot_old[0])-stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2);
  deltasx[1] = -stau[0]*(xdot[1]-xdot_old[1]);
  deltasx[2] = -(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))*((x[2]*(x[0]*(2.0/2.5E1)+5.0))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[2]*(x[0]*(2.0/2.5E1)+5.0)*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))-stau[0]*(xdot[2]-xdot_old[2])-((sx[2]-stau[0]*(x[3]-w[1]*x[2]))*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[2]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1));
  deltasx[3] = -stau[0]*(xdot[3]-xdot_old[3])-((p[0]*p[1]*x[2])/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[2]*(x[0]*(2.0/2.5E1)+5.0)*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0))*(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))-((p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*(sx[2]-stau[0]*(x[3]-w[1]*x[2])))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-(x[2]*(p[0]*p[2]+p[0]*x[0]))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[2]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0);
  deltasx[4] = -(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))*((x[4]*(x[0]*(2.0/2.5E1)+5.0))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[4]*(x[0]*(2.0/2.5E1)+5.0)*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))-stau[0]*(xdot[4]-xdot_old[4])-((sx[4]-stau[0]*(x[5]-w[1]*x[4]))*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[4]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1));
  deltasx[5] = -stau[0]*(xdot[5]-xdot_old[5])-((p[0]*p[1]*x[4])/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[4]*(x[0]*(2.0/2.5E1)+5.0)*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0))*(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))-((p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*(sx[4]-stau[0]*(x[5]-w[1]*x[4])))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-(x[4]*(p[0]*p[2]+p[0]*x[0]))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[4]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0);
  deltasx[6] = -(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))*((x[6]*(x[0]*(2.0/2.5E1)+5.0))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[6]*(x[0]*(2.0/2.5E1)+5.0)*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))-stau[0]*(xdot[6]-xdot_old[6])-((sx[6]-stau[0]*(x[7]-w[1]*x[6]))*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[6]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1));
  deltasx[7] = -stau[0]*(xdot[7]-xdot_old[7])-((p[0]*p[1]*x[6])/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[6]*(x[0]*(2.0/2.5E1)+5.0)*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0))*(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))-((p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*(sx[6]-stau[0]*(x[7]-w[1]*x[6])))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-(x[6]*(p[0]*p[2]+p[0]*x[0]))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[6]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0);
  deltasx[8] = -(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))*((x[8]*(x[0]*(2.0/2.5E1)+5.0))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[8]*(x[0]*(2.0/2.5E1)+5.0)*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))-stau[0]*(xdot[8]-xdot_old[8])-((sx[8]-stau[0]*(x[9]-w[1]*x[8]))*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[8]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1));
  deltasx[9] = -stau[0]*(xdot[9]-xdot_old[9])-((p[0]*p[1]*x[8])/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[8]*(x[0]*(2.0/2.5E1)+5.0)*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0))*(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))-((p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*(sx[8]-stau[0]*(x[9]-w[1]*x[8])))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-(x[8]*(p[0]*p[2]+p[0]*x[0]))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[8]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0);

              } break;

              } 

  } break;

  case 2: {
              switch(ie) { 
              case 0: {
  deltasx[0] = -sx[0]-stau[0]*(xdot[0]-xdot_old[0])-stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-1.0;
  deltasx[1] = -stau[0]*(xdot[1]-xdot_old[1]);
  deltasx[2] = -(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))*((x[2]*(x[0]*(2.0/2.5E1)+5.0))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[2]*(x[0]*(2.0/2.5E1)+5.0)*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))-stau[0]*(xdot[2]-xdot_old[2])+(x[2]*(p[2]*(2.0/2.5E1)-5.0))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-((sx[2]-stau[0]*(x[3]-w[1]*x[2]))*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[2]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1));
  deltasx[3] = -stau[0]*(xdot[3]-xdot_old[3])-((p[0]*p[1]*x[2])/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[2]*(x[0]*(2.0/2.5E1)+5.0)*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0))*(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))-((p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*(sx[2]-stau[0]*(x[3]-w[1]*x[2])))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-(p[0]*p[1]*x[2])/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[2]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0);
  deltasx[4] = -(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))*((x[4]*(x[0]*(2.0/2.5E1)+5.0))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[4]*(x[0]*(2.0/2.5E1)+5.0)*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))-stau[0]*(xdot[4]-xdot_old[4])+(x[4]*(p[2]*(2.0/2.5E1)-5.0))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-((sx[4]-stau[0]*(x[5]-w[1]*x[4]))*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[4]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1));
  deltasx[5] = -stau[0]*(xdot[5]-xdot_old[5])-((p[0]*p[1]*x[4])/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[4]*(x[0]*(2.0/2.5E1)+5.0)*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0))*(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))-((p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*(sx[4]-stau[0]*(x[5]-w[1]*x[4])))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-(p[0]*p[1]*x[4])/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[4]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0);
  deltasx[6] = -(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))*((x[6]*(x[0]*(2.0/2.5E1)+5.0))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[6]*(x[0]*(2.0/2.5E1)+5.0)*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))-stau[0]*(xdot[6]-xdot_old[6])+(x[6]*(p[2]*(2.0/2.5E1)-5.0))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-((sx[6]-stau[0]*(x[7]-w[1]*x[6]))*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[6]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1));
  deltasx[7] = -stau[0]*(xdot[7]-xdot_old[7])-((p[0]*p[1]*x[6])/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[6]*(x[0]*(2.0/2.5E1)+5.0)*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0))*(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))-((p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*(sx[6]-stau[0]*(x[7]-w[1]*x[6])))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-(p[0]*p[1]*x[6])/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[6]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0);
  deltasx[8] = -(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))*((x[8]*(x[0]*(2.0/2.5E1)+5.0))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[8]*(x[0]*(2.0/2.5E1)+5.0)*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))-stau[0]*(xdot[8]-xdot_old[8])+(x[8]*(p[2]*(2.0/2.5E1)-5.0))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-((sx[8]-stau[0]*(x[9]-w[1]*x[8]))*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[8]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1));
  deltasx[9] = -stau[0]*(xdot[9]-xdot_old[9])-((p[0]*p[1]*x[8])/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[8]*(x[0]*(2.0/2.5E1)+5.0)*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0))*(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))-((p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*(sx[8]-stau[0]*(x[9]-w[1]*x[8])))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-(p[0]*p[1]*x[8])/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[8]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0);

              } break;

              } 

  } break;

  case 3: {
              switch(ie) { 
              case 0: {
  deltasx[0] = -sx[0]-stau[0]*(xdot[0]-xdot_old[0])-stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2);
  deltasx[1] = -stau[0]*(xdot[1]-xdot_old[1])+1.0;
  deltasx[2] = -(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))*((x[2]*(x[0]*(2.0/2.5E1)+5.0))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[2]*(x[0]*(2.0/2.5E1)+5.0)*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))-stau[0]*(xdot[2]-xdot_old[2])-x[2]/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-((sx[2]-stau[0]*(x[3]-w[1]*x[2]))*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[2]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1));
  deltasx[3] = -stau[0]*(xdot[3]-xdot_old[3])-((p[0]*p[1]*x[2])/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[2]*(x[0]*(2.0/2.5E1)+5.0)*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0))*(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))-((p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*(sx[2]-stau[0]*(x[3]-w[1]*x[2])))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-(p[0]*x[2])/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[2]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0);
  deltasx[4] = -(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))*((x[4]*(x[0]*(2.0/2.5E1)+5.0))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[4]*(x[0]*(2.0/2.5E1)+5.0)*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))-stau[0]*(xdot[4]-xdot_old[4])-x[4]/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-((sx[4]-stau[0]*(x[5]-w[1]*x[4]))*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[4]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1));
  deltasx[5] = -stau[0]*(xdot[5]-xdot_old[5])-((p[0]*p[1]*x[4])/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[4]*(x[0]*(2.0/2.5E1)+5.0)*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0))*(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))-((p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*(sx[4]-stau[0]*(x[5]-w[1]*x[4])))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-(p[0]*x[4])/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[4]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0);
  deltasx[6] = -(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))*((x[6]*(x[0]*(2.0/2.5E1)+5.0))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[6]*(x[0]*(2.0/2.5E1)+5.0)*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))-stau[0]*(xdot[6]-xdot_old[6])-x[6]/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-((sx[6]-stau[0]*(x[7]-w[1]*x[6]))*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[6]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1));
  deltasx[7] = -stau[0]*(xdot[7]-xdot_old[7])-((p[0]*p[1]*x[6])/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[6]*(x[0]*(2.0/2.5E1)+5.0)*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0))*(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))-((p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*(sx[6]-stau[0]*(x[7]-w[1]*x[6])))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-(p[0]*x[6])/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[6]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0);
  deltasx[8] = -(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))*((x[8]*(x[0]*(2.0/2.5E1)+5.0))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[8]*(x[0]*(2.0/2.5E1)+5.0)*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))-stau[0]*(xdot[8]-xdot_old[8])-x[8]/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-((sx[8]-stau[0]*(x[9]-w[1]*x[8]))*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1)))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[8]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0)*(p[2]*5.0+p[3]+x[0]*5.0-(p[2]*p[2])*(1.0/2.5E1)+(x[0]*x[0])*(1.0/2.5E1));
  deltasx[9] = -stau[0]*(xdot[9]-xdot_old[9])-((p[0]*p[1]*x[8])/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[8]*(x[0]*(2.0/2.5E1)+5.0)*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0))*(sx[0]+stau[0]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2))-((p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*(sx[8]-stau[0]*(x[9]-w[1]*x[8])))/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-(p[0]*x[8])/(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-x[8]*(sx[1]-p[0]*stau[0]*(x[1]-p[1]*x[0]))*(p[0]*(p[3]+x[1]+p[1]*p[2])-p[0]*(x[1]-p[1]*x[0]))*1.0/pow(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2,2.0);

              } break;

              } 

  } break;

}
}

