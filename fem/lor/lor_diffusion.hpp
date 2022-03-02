// Copyright (c) 2010-2021, Lawrence Livermore National Security, LLC. Produced
// at the Lawrence Livermore National Laboratory. All Rights reserved. See files
// LICENSE and NOTICE for details. LLNL-CODE-806117.
//
// This file is part of the MFEM library. For more information and source code
// availability visit https://mfem.org.
//
// MFEM is free software; you can redistribute it and/or modify it under the
// terms of the BSD-3 license. We welcome feedback and contributions, see file
// CONTRIBUTING.md for details.

#ifndef MFEM_LOR_DIFFUSION
#define MFEM_LOR_DIFFUSION

#include "lor_batched.hpp"

namespace mfem
{

class BatchedLORDiffusion : public BatchedLORAssembly
{
protected:
   Vector d_buffer; ///< Device buffer used for intermediate computations.
   // TODO: for now only supporting constant coefficients
   double mass_coeff, diffusion_coeff;
public:
   template <int ORDER> void AssembleDiffusion2D(SparseMatrix &A);
   template <int ORDER, bool USE_SMEM=true>
   void AssembleDiffusion3D(SparseMatrix &A);
   void AssemblyKernel(SparseMatrix &A) override;
   BatchedLORDiffusion(BilinearForm &a_,
                       FiniteElementSpace &fes_ho_,
                       const Array<int> &ess_dofs_);
};

}

#endif
