
////////////////////////////////////////////////////////////////////////////
// Model model2.cc                SIMLIB/C++
//
// Simple test model of queuing system 
//

#include "simlib.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// global objects:
Facility  Box("Box");
Histogram Table("Table",0,25,20);

class Customer : public Process { 
  double Prichod;                 // atribute of each customer
  void Behavior() {               // --- behavoir specification ---
  }
};

class Generator : public Event {  // model of system's input
  void Behavior() {               // --- behavior specification ---
    (new Customer)->Activate();   // new customer
    Activate(Time+Exponential(1e3/150));  //
  }
};



int main(int argc, char **argv) {                 // experiment description

  /* kapacity Store */
  int peceKapacita    = 3;
  int vakuoveLiatie    = 3;
  int tlakoveLiatie    = 36;
  int liateVodice     = 2;
  int bandazVinutie   = 2;
  int kableVinutie    = 6;
  int chystanie        = 10;
  int skuskaKapacita  = 5;
  int navijaky        = 9;
  /* /kapacity */
  
  /* pravdepodobnosti */
  float Pvakuove    = 0.85;
  float Ptlakove    = 0.15;
  float Pkabel      = 0.7;
  float Pbandaz     = 0.15;
  float Pliatie      = 0.15;
  /* /pravdepodobnosti */

  
  int c;

  while ((c = getopt (argc, argv, "n:s:c:k:b:l:t:v:p:V:T:K:B:L:")) != -1)
    switch (c)
    {
      case 'n':
        navijaky = atoi(optarg);
        break;
      case 's':
        skuskaKapacita = atoi(optarg);
        break;
      case 'c':
        chystanie = atoi(optarg);
        break;
      case 'k':
        kableVinutie = atoi(optarg);
        break;
      case 'b':
        bandazVinutie = atoi(optarg);
        break;
      case 'l':
        liateVodice = atoi(optarg);
        break;
      case 't':
        tlakoveLiatie = atoi(optarg);
        break;
      case 'v':
        vakuoveLiatie = atoi(optarg);
        break;
      case 'p':
        peceKapacita = atoi(optarg);
        break;
      case 'V':
        Pvakuove = atof(optarg);
        break;
      case 'T':
        Ptlakove = atof(optarg);
        break;
      case 'K':
        Pkabel = atof(optarg);
        break;
      case 'B':
        Pbandaz = atof(optarg);
        break;
      case 'L':
        Pliatie = atof(optarg);
        break;
      default:
        return 1;
  }


  return 0;
}




}