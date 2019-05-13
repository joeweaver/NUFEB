/* ----------------------------------------------------------------------
   NUFEB package - A LAMMPS user package for Individual-based Modelling of Microbial Communities
   Contributing authors: Bowen Li & Denis Taniguchi (Newcastle Univeristy, UK)
   Email: bowen.li2@newcastle.ac.uk & denis.taniguchi@newcastle.ac.uk

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.
------------------------------------------------------------------------- */

#ifdef COMPUTE_CLASS

ComputeStyle(surface,ComputeNufebSurface)

#else

#ifndef LMP_COMPUTE_SURFACE_H
#define LMP_COMPUTE_SURFACE_H

#include "compute.h"
#include <vector>

namespace LAMMPS_NS {

class ComputeNufebSurface : public Compute {
 public:
  ComputeNufebSurface(class LAMMPS *, int, char **);
  virtual ~ComputeNufebSurface();
  virtual double compute_scalar();
  void init(){};
  double xlo, xhi, ylo, yhi, zlo, zhi, bzhi;
  void neighbor_list ();
  std::vector< std::vector<int> > nlist;
  int *visit;
};

}

#endif
#endif

/* ERROR/WARNING messages:

E: Illegal ... command

Self-explanatory.  Check the input script syntax and compare to the
documentation for the command.  You can use -echo screen as a
command-line option when running LAMMPS to see the offending line.

E: Temperature compute degrees of freedom < 0

This should not happen if you are calculating the temperature
on a valid set of atoms.

*/
